impl Solution {
  pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
    let n = numbers.len();
    let (mut i, mut j) = (0, n - 1);
    while i < j {
      let sum = numbers[i] + numbers[j];
      if sum == target {
        break;
      }
      if sum > target {
        j -= 1;
        continue;
      }
      i += 1;
    }
    vec![i as i32 + 1, j as i32 + 1]
  }
}
