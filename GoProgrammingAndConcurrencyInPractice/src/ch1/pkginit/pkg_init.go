package main // 命令源码文件必须在这里声明自己属于 main 包。

import ( // 引入了代码包 fmt 和 runtime。
	"fmt"
	"runtime"
)

func init() { // 代码包初始化函数。
	fmt.Printf("Map: %v\n", m) // 格式化的打印。
	// 通过调用 runtime 包的代码获取当前机器的操作系统和计算结构。
	// 而后通过 fmt 包的 Sprintf 方法进行格式化字符串生成并赋值给变量 info。
	info = fmt.Sprintf("OS: %s, Arch: %s", runtime.GOOS, runtime.GOARCH)
}

// 非局部变量，map 类型，且已初始化。
var m = map[int]string{1: "A", 2: "B", 3: "C"}

// 非局部变量，string 类型，未被初始化。
var info string

func main() { // 命令源码文件必须有的入口函数，也称主函数。
	fmt.Println(info) // 打印变量 info。
}
