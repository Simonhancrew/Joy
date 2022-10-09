package sbgo

func scoreOfParentheses(s string) int {
  n, stk := len(s),make([]int,1)
  for i := 0;i < n;i++ {
    if s[i] == '(' {
      stk = append(stk, 0)
    } else {
      t := stk[len(stk) - 1]
      stk = stk[:len(stk) - 1]
      if t == 0 {
        stk[len(stk) - 1] += 1
      } else {
        stk[len(stk) - 1] += 2 * t
      }
    }
  }
  return stk[0]
}
