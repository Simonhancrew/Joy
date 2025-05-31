impl Solution {
  pub fn duplicate_zeros(arr: &mut Vec<i32>) {
    let (n, mut cnt, mut i) = (arr.len(), 0, 0);
    while cnt < n {
      if arr[i] == 0 {
        cnt += 2;
      } else {
        cnt += 1;
      }
      i += 1;
    }
    i -= 1;
    let mut j = n - 1;
    if cnt == n + 1 {
      arr[j] = arr[i];
      j -= 1;
      i -= 1;
    }
    while j >= 0 {
      // println!("{},{}",i,j);
      arr[j] = arr[i];
      if j == 0 || i == 0 {
        break;
      }
      j -= 1;
      if arr[i] == 0 {
        arr[j] = arr[i];
        j -= 1;
      }
      i -= 1;
    }
  }
}
