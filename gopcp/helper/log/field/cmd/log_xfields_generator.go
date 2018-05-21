package main

import (
	"flag"
	"fmt"
	"log"
	"os"
)

// field_decl_template 代表日志字段类型的声明的内容模板。
const field_decl_template = `
// 拥有{{if eq . "object"}}interface{}{{else}}{{.}}{{end}}类型的值的日志字段。
type {{.}}Field struct {
	name string
	fieldType FieldType
	value {{if eq . "object"}}interface{}{{else}}{{.}}{{end}}
}

func (field *{{.}}Field) Name() string {
	return field.name
}

func (field *{{.}}Field) Type() FieldType {
	return field.fieldType
}
func (field *{{.}}Field) Value() interface{} {
	return field.value
}

func {{title .}}(name string, value {{if eq . "object"}}interface{}{{else}}{{.}}{{end}}) Field{
	return &{{.}}Field{name: name, fieldType: {{title .}}Type, value: value}
}

`

var (
	inputPath  string
	outputPath string
)

func init() {
	flag.StringVar(&inputPath, "input", "",
		"The path that contains the target go source files.")
	flag.StringVar(&outputPath, "output", "",
		"The path for output the go source file.")
}

func Usage() {
	fmt.Fprintf(os.Stderr, "Usage of %s:\n", os.Args[0])
	fmt.Fprintf(os.Stderr, "\tlog_xfields_generator [flags] \n")
	fmt.Fprintf(os.Stderr, "Flags:\n")
	flag.PrintDefaults()
}

func main() {
}

// isDir 用于判断指定的路径是否为目录。
func isDir(name string) bool {
	info, err := os.Stat(name)
	if err != nil {
		log.Fatal(err)
	}
	return info.IsDir()
}

// findField
