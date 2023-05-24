package sbgo

func frogPosition(n int, edges [][]int, t int, target int) float64 {
    g := make([][]int, n + 1)
    for _, e := range edges {
        g[e[0]] = append(g[e[0]], e[1])
        g[e[1]] = append(g[e[1]], e[0])
    }
    dis, chance:= make([]int, n + 1), make([]float64, n + 1)
    for i := 2;i < n + 1;i++ {
        dis[i] = 200
    }
    chance[1] = 1.0
    q := []int{1}
    for len(q) != 0 {
        fa := q[0]
        q = q[1:]
        if dis[fa] >= t {
            continue
        }
        for _, ne := range g[fa] {
            if dis[ne] > dis[fa] + 1 {
                dis[ne] = dis[fa] + 1
                sub := 0
                if fa != 1 {
                    sub = 1
                }
                chance[ne] = chance[fa] / float64(len(g[fa]) - sub)
                q = append(q, ne)
            }
        } 
    }
    if dis[target] < t {
        if target == 1 && len(g[target]) > 0 || len(g[target]) > 1 {
            return 0
        }
    }
    return chance[target]
}

