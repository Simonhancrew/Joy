package sbgo

func oddCells(m int, n int, indices [][]int) int {
	row, col := make([]int, m), make([]int, n)
	for _, pos := range indices {
		r, c := pos[0], pos[1]
		row[r]++
		col[c]++
	}
	cnt := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if (row[i]+col[j])&1 == 1 {
				cnt++
			}
		}
	}
	return cnt
}
