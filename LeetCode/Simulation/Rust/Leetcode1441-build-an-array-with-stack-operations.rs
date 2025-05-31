impl Solution {
  pub fn build_array(target: Vec<i32>, n: i32) -> Vec<String> {
    let mut ans = vec![];
    let mut j = 0;
    for i in 1..=n {
      if i == target[j] {
        ans.push(String::from("Push"));
        j += 1;
      } else {
        ans.push(String::from("Push"));
        ans.push(String::from("Pop"));
      }
      if i == target[target.len() - 1] {
        break;
      }
    }
    ans
  }
}
