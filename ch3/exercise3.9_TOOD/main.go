package main

import (
	"image"
	"image/color"
	"image/png"
	"log"
	"math/cmplx"
	"net/http"
	"os"
	"strconv"
)

func main() {
	http.HandleFunc("/", handler)
	log.Fatal(http.ListenAndServe("localhost:8000", nil))
}

func handler(w http.ResponseWriter, r *http.Request) {
	var x, y int
	var zoom complex128
	if err := r.ParseForm; err != nil {
		log.Print(err)
	}
	var err error
	if r.Form["x"] != nil {
		x, err = strconv.Atoi(r.Form["x"][0])
	}
	if r.Form["y"] != nil {
		y, err = strconv.Atoi(r.Form["y"][0])
	}
	if r.Form["zoom"] != nil {
		zoom, err = strconv.Atoi(r.Form["zoom"][0])
	}
	deal(float64(x), float64(y), complex128(zoom))
}

func deal(x, y float64, zoom complex128) {
	const (
		xmin, ymin, xmax, ymax = -2, -2, +2, +2
		width, height          = 1024, 1024
	)

	img := image.NewRGBA(image.Rect(0, 0, width, height))
	for py := 0; py < height; py++ {
		for px := 0; px < width; px++ {
			img.Set(px, py, mandelbrot(zoom))
		}
	}
	png.Encode(os.Stdout, img)
}

func mandelbrot(z complex128) color.Color {
	const iterations = 200
	const contrast = 15

	var v complex128
	for n := uint8(0); n < iterations; n++ {
		v = v*v + z
		if cmplx.Abs(v) > 2 {
			return color.Gray{255 - contrast*n}
		}
	}
	return color.Black
}
