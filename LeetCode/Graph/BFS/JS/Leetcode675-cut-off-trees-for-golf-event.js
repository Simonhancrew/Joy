var cutOffTree = function (forest) {
    const [n, m] = [forest.length, forest[0].length];
    let trees = new Array();
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < m; j++) {
            if (forest[i][j] > 1) trees.push([i, j, forest[i][j]]);
        }
    }
    trees.sort((a, b) => a[2] - b[2]);

    let bfs = function (st, to) {
        if (st[0] == to[0] && st[1] == to[1]) return 0;
        let [q, dist] = [[], new Array(n).fill(0).map(() => new Array(m).fill(1000000))];
        let [x, y] = [st[0], st[1]];
        const [dx, dy] = [[1, 0, -1, 0], [0, 1, 0, -1]];
        dist[x][y] = 0;
        q.push([x, y]);
        while (q.length != 0) {
            let t = q.shift();
            for (let i = 0; i < 4; i++) {
                const [nx, ny] = [t[0] + dx[i], t[1] + dy[i]];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && forest[nx][ny] != 0) {
                    if (dist[nx][ny] > dist[t[0]][t[1]] + 1) {
                        dist[nx][ny] = dist[t[0]][t[1]] + 1;
                        if (nx == to[0] && ny == to[1]) {
                            return dist[nx][ny];
                        }
                        q.push([nx, ny]);
                    }
                }
            }
        }
        return -1;
    }

    let [st, res] = [[0, 0], 0];
    for (const to of trees) {
        const t = bfs(st, to);
        if (t == -1) return -1;
        res += t;
        st = to
    }
    return res;
};