impl Solution {
  pub fn closest_meeting_node(edges: Vec<i32>, node1: i32, node2: i32) -> i32 {
    let n = edges.len();
    let get = |mut x: i32| -> Vec<i32> {
      let mut d = 0;
      let mut res = vec![n as i32; n];
      while x != -1 && res[x as usize] == n as i32 {
        res[x as usize] = d;
        x = edges[x as usize];
        d += 1;
      }
      res
    };
    let d1 = get(node1);
    let d2 = get(node2);
    let (mut ans, mut mn) = (-1, n as i32);
    for i in 0..n {
      let tmp = d1[i].max(d2[i]);
      if tmp < mn {
        mn = tmp;
        ans = i as i32;
      }
    }
    ans
  }
}
