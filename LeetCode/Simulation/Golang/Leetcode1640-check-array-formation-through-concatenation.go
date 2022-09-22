package sbgo

func canFormArray(arr []int, pieces [][]int) bool {
  mp := map[int]int{}
  for i,p := range pieces {
    mp[p[0]] = i
  }
  i,n := 0,len(arr)
  for i < n {
    if _,ok := mp[arr[i]];!ok {
      return false
    }
    t := pieces[mp[arr[i]]]
    size := len(t)
    for j := 0;j < size;j++ {
      if arr[i] != t[j] {
        return false;
      }
      i++
    }
  }
  return true
}
