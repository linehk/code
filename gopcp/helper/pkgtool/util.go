package pkgtool

// appendIfAbsent 的行为像针对 string 类型值的 append 函数
// 但不会追加已存在的元值。
func appendIfAbsent(s []string, t ...string) []string {
	emap := map[string]struct{}{}
	for _, se := range s {
		emap[se] = struct{}{}
	}
	for _, te := range t {
		if _, ok := emap[te]; ok {
			continue
		}
		s = append(s, te)
		emap[te] = struct{}{}
	}
	return s
}
