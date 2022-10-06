impl Solution {
  pub fn three_equal_parts(arr: Vec<i32>) -> Vec<i32> {
      let acc: i32 = arr.iter().sum();
      if acc == 0 {
          return vec![0,2];
      }
      if acc % 3 != 0 {
          return vec![-1,-1];
      }
      let (mut j,mut c,n,avg) = (0,0, arr.len(),acc / 3);
      let (s,mut p) = (vec![1, avg, avg + 1, 2 * avg, 2*avg + 1, 3 * avg],vec![0;6]);
      for i in 0..n {
          if arr[i] == 0 {
              continue
          }
          c += 1;
          while j < 6 && s[j] == c {
              p[j] = i as usize;
              j += 1;
          }
      }
      let last0 = n - 1 - p[5];
      let (dis1,dis2) = (p[2] - p[1] - 1,p[4] - p[3] - 1);
      if dis1 < last0 || dis2 < last0 {
          return vec![-1,-1];
      }
      if arr[p[0]..p[1]] != arr[p[2]..p[3]] || arr[p[2]..p[3]] != arr[p[4]..p[5]] {
          return vec![-1,-1];
      }
      vec![(p[1] + last0) as i32,(p[3] + last0 + 1) as i32]
  }
}