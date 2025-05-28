impl Solution {
    pub fn max_target_nodes(edges1: Vec<Vec<i32>>, edges2: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
        // Helper function to build the graph
        fn build_graph(edges: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
            let mut g = vec![vec![]; edges.len() + 1];
            for e in edges.iter() {
                g[e[0] as usize].push(e[1]);
                g[e[1] as usize].push(e[0]);
            }
            g
        }
        // DFS function to count nodes within distance `d` from node `x`
        fn dfs(
            x: usize,
            fa: usize,
            g: &Vec<Vec<i32>>,
            d: i32,
            k: i32,
        ) -> i32 {
            if d > k {
                return 0;
            }
            let mut cnt = 1;
            for &ne in g[x].iter() {
                let ne = ne as usize;
                if ne == fa {
                    continue;
                }
                cnt += dfs(ne, x, g, d + 1, k);
            }
            cnt
        }
        let n = edges1.len() + 1;
        let m = edges2.len() + 1;
        // Build graphs for both edge lists
        let g1 = build_graph(edges1);
        let g2 = build_graph(edges2);
        let mut ans = vec![0; n];
        // Calculate the maximum reachable nodes in the second graph
        let mut mx2 = 0;
        for i in 0..m {
            mx2 = mx2.max(dfs(i as usize, usize::MAX, &g2, 0, k - 1));
        }
        // Calculate the result for each node in the first graph
        for i in 0..n {
            ans[i] = mx2 + dfs(i, usize::MAX, &g1, 0, k);
        }
        ans
    }
}