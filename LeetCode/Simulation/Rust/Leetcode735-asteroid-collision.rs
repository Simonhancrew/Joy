impl Solution {
  pub fn asteroid_collision(asteroids: Vec<i32>) -> Vec<i32> {
    let mut ans = vec![];
    for &ast in &asteroids {
      let mut flag = true;
      while flag && ast < 0 && !ans.is_empty() && ans[ans.len() - 1] > 0 {
        flag = -ast > ans[ans.len() - 1];
        if -ast >= ans[ans.len() - 1] {
          ans.pop();
        }
      }
      if flag {
        ans.push(ast);
      }
    }
    ans
  }
}
