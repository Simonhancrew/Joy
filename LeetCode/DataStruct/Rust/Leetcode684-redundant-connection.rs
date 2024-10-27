impl Solution {
  fn find(fa: &mut Vec<usize>, x: usize) -> usize {
      if fa[x] != x {
          fa[x] = Self::find(fa, fa[x]);
      }
      fa[x]
  }

  fn merge(fa: &mut Vec<usize>, x: usize, y: usize) {
      let fx = Self::find(fa, x);
      let fy = Self::find(fa, y);
      if fx != fy {
          fa[fx] = fy;
      }
  }

  pub fn find_redundant_connection(edges: Vec<Vec<i32>>) -> Vec<i32> {
      let n = edges.len();
      let mut fa: Vec<usize> = (0..=n).collect();

      for edge in edges {
          let x = edge[0] as usize;
          let y = edge[1] as usize;

          if Self::find(&mut fa, x) == Self::find(&mut fa, y) {
              return edge.iter().map(|&e| e).collect();
          }
          Self::merge(&mut fa, x, y);
      }
      vec![]
  }
}
