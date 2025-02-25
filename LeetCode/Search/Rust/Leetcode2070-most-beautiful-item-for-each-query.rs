impl Solution {
  pub fn maximum_beauty(mut items: Vec<Vec<i32>>, queries: Vec<i32>) -> Vec<i32> {
      let mut ans = vec![];
      items.sort();  
      for i in 1..items.len() {
          items[i][1] = items[i][1].max(items[i - 1][1]);
      }
      for q in &queries {
          let (mut l, mut r) = (-1, items.len() as i32);
          while l + 1 < r {
              let mid = (l + r) >> 1;
              if items[mid as usize][0] <= *q {
                  l = mid;
              } else {
                  r = mid;
              }
          }
          if l == -1 {
              ans.push(0);
              continue;
          }
          ans.push(items[l as usize][1]);
      }
      ans
  }
}
