package sbgo

func reachNumber(target int) int {
  acc, cnt := 0, 0 
  abs := func(i int) int {
    if i < 0 {
      return -i;
    }
    return i;
  }
  target = abs(target)
  for acc < target || (acc - target) & 1 == 1 {
    cnt++
    acc += cnt
  }
  return cnt
}
