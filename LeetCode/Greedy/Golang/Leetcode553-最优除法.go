package sbgo

import (
	"fmt"
	"strconv"
	"strings"
)

func optimalDivision(nums []int) string {
	n := len(nums)
	if n == 0 {
		return ""
	}
	if n == 1 {
		return strconv.Itoa(nums[0])
	}
	if n == 2 {
		return fmt.Sprintf("%d/%d", nums[0], nums[1])
	}
	ans := &strings.Builder{}
	ans.WriteString(fmt.Sprintf("%d/(%d", nums[0], nums[1]))
	for i := 2; i < n; i++ {
		ans.WriteByte('/')
		ans.WriteString(strconv.Itoa(nums[i]))
	}
	ans.WriteByte(')')
	return ans.String()
}
