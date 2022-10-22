impl Solution {
  pub fn job_scheduling(start_time: Vec<i32>, end_time: Vec<i32>, profit: Vec<i32>) -> i32 {
      let (n, mut arr) = (start_time.len(), Vec::new());
      for i in 0..n {
          arr.push(vec![start_time[i], end_time[i], profit[i]]);
      }
      arr.sort_by(|a, b| a[1].cmp(&b[1]));
      let mut f = vec![0;n];
      f[0] = arr[0][2];
      for i in 1..n {
          f[i] = f[i - 1].max(arr[i][2]);
          if arr[i][0] >= arr[0][1] {
              let (mut l, mut r) = (0, i - 1);
              while l < r {
                  let mid = (l + r + 1) >> 1;
                  if arr[mid][1] <= arr[i][0] {
                      l = mid;
                  } else {
                      r = mid - 1;
                  }
              }
              f[i] = f[i].max(f[r] + arr[i][2]);
          }
      }
      f[n - 1]
  }
}