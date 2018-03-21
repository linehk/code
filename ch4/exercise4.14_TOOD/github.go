package main

const IssuesURL = "https://api.github.com/search/issues"

type Issues struct {
	TotalCount int     `json:"total_count"`
	Items      []*Info `json:"itmes"`
}

type Info struct {
	Milestone *MilestoneInfo `json:"milestone"`
}

type MilestoneInfo struct {
	HTMLURL      string `json:"html_url"`
	OpenIssues   int    `json:"open_issues"`
	ClosedIssues int    `json:"closed_issues"`
}
