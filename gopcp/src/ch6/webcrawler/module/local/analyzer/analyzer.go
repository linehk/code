package analyzer

import (
	"github.com/linehk/gopcp/ch6/webcrawler/module"
	"github.com/linehk/gopcp/ch6/webcrawler/module/stub"
	"github.com/linehk/gopcp/helper/log"
)

// logger 代表日志记录器。
var logger = log.DLogger()

// New 用于创建一个分析器实例。
func New(mid module.MID, respParser []module.ParseResponse,
	scoreCalculator module.CalculateScore) (module.Analyzer, error) {
	moduleBase, err := stub.NewModuleInternal(mid, scoreCalculator)
}
