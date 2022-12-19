struct UnionFind {
    parent: Vec<i32>,
}

impl UnionFind {
    fn new(n: i32) -> Self {
        UnionFind{ parent: (0..n).collect::<Vec<_>>() }
    }

    fn find(&mut self, x: i32) -> i32 {
        let next = self.parent[x as usize];
        if (x != next) { self.parent[x as usize] = self.find(next); }
        return self.parent[x as usize];
    }

    fn union(&mut self, x: i32, y: i32) {
        let (x, y) = (self.find(x) as usize, self.find(y) as usize);
        self.parent[x] = self.parent[y];
    }
}

impl Solution {
    pub fn valid_path(n: i32, edges: Vec<Vec<i32>>, source: i32, destination: i32) -> bool {
        let mut uf = UnionFind::new(n);
        for edge in edges { uf.union(edge[0], edge[1]); }
        uf.find(source) == uf.find(destination)
    }
}
