impl Solution {
  pub fn makesquare(mut arr: Vec<i32>) -> bool {
    let acc = arr.iter().sum();
    if acc % 4 != 0 {
      return false;
    }
    let mut edge = [0; 4];
    arr.sort_by(|a, b| b.cmp(a));
    fn dfs(u: usize, arr: &Vec<i32>, edge: &mut [i32; 4], acc: i32) -> bool {
      if u == arr.len() {
        return true;
      }
      for i in 0..4 {
        edge[i] += arr[u];
        if edge[i] <= acc / 4 && dfs(u + 1, arr, edge, acc) {
          return true;
        }
        edge[i] -= arr[u];
      }
      return false;
    }
    dfs(0, &arr, &mut edge, acc)
  }
}
