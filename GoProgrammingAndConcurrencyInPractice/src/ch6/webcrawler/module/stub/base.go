package stub

import (
	"ch6/webcrawler/module"
)

// ModuleInternal 代表组件的内部基础接口类型。
type ModuleInternal interface {
	module.Module
	// IncrCalledCount 会把调用计数增 1。
	IncrCalledCount()
	// IncrAcceptedCount 会把接受计数增 1。
	IncrAcceptedCount()
	// IncrCompletedCount 会把成功完成计数增 1。
	IncrCompletedCount()
	// IncrHandlingNumber 会把实时处理数增 1。
	IncrHandlingNumber()
	// DecrHandlingNumber 会把实时处理数减 1。
	DecrHandlingNumber()
	// Clear 用于清空所有计数。
	Clear()
}
