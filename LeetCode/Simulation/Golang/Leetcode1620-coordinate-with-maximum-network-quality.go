pacage sbgo

func bestCoordinate(towers [][]int, radius int) []int {
  mx, my := -1, -1
  max := func(i, j int) int {
    if i < j {
      return j
    }
    return i
  }
  for _, t := range towers {
    mx = max(mx, t[0])
    my = max(my, t[1])
  }
  tx, ty, qua := 0,0,0
  for x := 0;x <= mx;x++ {
    for y := 0;y <= my;y++ {
      q := 0
      for _, t := range towers {
        d := (x-t[0])*(x-t[0]) + (y-t[1])*(y-t[1])
        if d <= radius*radius {
          q += int(float64(t[2]) / (1 + math.Sqrt(float64(d))))
        }
      }
      if q > qua {
        tx, ty, qua = x, y, q
      }
    }
  }
  return []int{tx, ty}
}

