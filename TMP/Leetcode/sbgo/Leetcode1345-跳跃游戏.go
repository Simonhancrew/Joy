package sbgo

func minJumps(arr []int) int {
	mp := map[int][]int{}
	for i, t := range arr {
		mp[t] = append(mp[t], i)
	}
	q := []int{}
	dist := make([]int, len(arr))
	for i, _ := range dist {
		dist[i] = -1
	}
	dist[0] = 0
	q = append(q, 0)
	n := len(arr)
	for len(q) != 0 {
		t := q[0]
		q = q[1:]
		if t == n-1 {
			return dist[n-1]
		}
		for _, ne := range mp[arr[t]] {
			if dist[ne] == -1 {
				dist[ne] = dist[t] + 1
				q = append(q, ne)
			}
		}
		delete(mp, arr[t])
		if t+1 < n && dist[t+1] == -1 {
			dist[t+1] = dist[t] + 1
			q = append(q, t+1)
		}
		if t-1 >= 0 && dist[t-1] == -1 {
			dist[t-1] = dist[t] + 1
			q = append(q, t-1)
		}
	}
	return dist[n-1]
}
