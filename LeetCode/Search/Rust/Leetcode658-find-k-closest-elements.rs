impl Solution {
  pub fn find_closest_elements(arr: Vec<i32>, mut k: i32, x: i32) -> Vec<i32> {
    let (mut l, mut r) = (-1, arr.len() as i32);
    while (l + 1 < r) {
      let mid = l + r >> 1;
      if arr[mid as usize] < x {
        l = mid;
      } else {
        r = mid;
      }
    }
    while k > 0 {
      if l < 0 {
        r += 1;
      } else if r as usize >= arr.len() {
        l -= 1;
      } else if x - arr[l as usize] <= arr[r as usize] - x {
        l -= 1;
      } else {
        r += 1;
      }
      k -= 1;
    }
    arr[(l + 1) as usize..r as usize].to_vec()
  }
}
