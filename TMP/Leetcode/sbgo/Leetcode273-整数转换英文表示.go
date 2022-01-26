package sbgo

import "strings"

// 全局变量只能var
var (
	// 换行可以，但是要逗号结尾
	num19 = []string{"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
		"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"}
	num20   = []string{"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}
	num1000 = []string{"Billion ", "Million ", "Thousand ", ""}
)

func numberToWords(num int) string {
	if num == 0 {
		return num19[0]
	}
	// 可以使用strings.Builder{}
	res := strings.Builder{}
	for i, j := int(1e9), 0; i >= 1; i, j = i/1000, j+1 {
		if num >= i {
			res.WriteString(get(num / i))
			res.WriteString(num1000[j])
			// res += get(num/i) + num1000[j]
			num %= i
		}
	}
	return strings.TrimSpace(res.String())
}

func get(x int) string {
	res := strings.Builder{}
	if x >= 100 {
		res.WriteString(num19[x/100])
		res.WriteString(" Hundred ")
		x %= 100
	}
	if x >= 20 {
		res.WriteString(num20[x/10-2])
		res.WriteByte(' ')
		x %= 10
	}
	if x != 0 {
		res.WriteString(num19[x])
		res.WriteByte(' ')
	}
	return res.String()
}
