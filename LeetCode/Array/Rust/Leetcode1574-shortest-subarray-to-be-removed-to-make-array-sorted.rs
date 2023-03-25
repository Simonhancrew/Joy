impl Solution {
  pub fn find_length_of_shortest_subarray(arr: Vec<i32>) -> i32 {
      let n = arr.len();
      let mut j = n - 1;
      while j > 0 && arr[j] >= arr[j - 1] {
          j -= 1;
      }
      let mut ll = n - j;
      for i in 0..n {
          if i > 0 && arr[i] < arr[i - 1] {
              break;
          }
          while i >= j || (j < n && arr[i] > arr[j]) {
              j += 1
          }
          ll = ll.max(i + 1 + n - j);
      }
      (n - ll) as i32
  }
}