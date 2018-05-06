package main_test

import (
	. "ch8/test_ginkgo"
	"encoding/json"
	"net/http"
	"net/http/httptest"

	. "github.com/onsi/ginkgo"
	. "github.com/onsi/gomega"
)

var _ = Describe("Get a post", func() {
	var mux *http.ServeMux
	var post *FakePost
	var writer *httptest.ResponseRecorder

	BeforeEach(func() {
		post = &FakePost{}
		mux = http.NewServeMux()
		mux.HandleFunc("/post/", HandleRequest(post))
		writer = httptest.NewRecorder()
	})

	Context("using an id", func() {
		It("should get a post", func() {
			request, _ := http.NewRequest("GET", "/post/1", nil)
			mux.ServeHTTP(writer, request)

			Expect(writer.Code).To(Equal(200))

			var post Post
			json.Unmarshal(writer.Body.Bytes(), &post)

			Expect(post.Id).To(Equal(1))
		})
	})

	Context("using a non-integer id", func() {
		It("should get a HTTP 500 response", func() {
			request, _ := http.NewRequest("GET", "/post/hello", nil)
			mux.ServeHTTP(writer, request)

			Expect(writer.Code).To(Equal(500))
		})
	})

})
