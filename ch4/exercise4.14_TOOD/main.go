package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
)

func main() {
	http.HandleFunc("/", Handle)
	log.Fatal(http.ListenAndServe("localhost:8000", nil))
}

func Handle(w http.ResponseWriter, r *http.Request) {
	if err := r.ParseForm; err != nil {
		log.Print(err)
	}
	if r.Form["issues"] != nil {
		s := r.Form["issues"][0]
		result, err := GetInfo(s)
		if err != nil {
			log.Print(err)
		}
		fmt.Fprintf(w, "count = %d", result.TotalCount)
		for _, item := range result.Items {
			fmt.Fprintf(w, "MilestoneURL = %s, OpenIssues = %d, ClosedIssues = %d",
				item.Milestone.HTMLURL, item.Milestone.OpenIssues,
				item.Milestone.ClosedIssues)
		}
	}
}

func GetInfo(q string) (*Issues, error) {
	resp, err := http.Get(IssuesURL + "?q=" + q)
	if err != nil {
		return nil, err
	}

	if resp.StatusCode != http.StatusOK {
		resp.Body.Close()
		return nil, fmt.Errorf("search query failed: %s", resp.Status)
	}

	var result Issues
	if err := json.NewDecoder(resp.Body).Decode(&result); err != nil {
		resp.Body.Close()
		return nil, err
	}
	resp.Body.Close()
	return &result, nil
}
