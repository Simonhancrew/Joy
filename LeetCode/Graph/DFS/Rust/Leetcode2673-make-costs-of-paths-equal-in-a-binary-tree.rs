// 从叶开始，同父节点的子节点变最大
// 最下层处理完之后，倒数第二层变成最后一层，可以看作叶子节点层，将之前子节点的最大值往上传，并加到当前节点中
// 此时重复之前一次的操作
impl Solution {
  pub fn min_increments(n: i32, mut cost: Vec<i32>) -> i32 {
      let mut ans = 0;
      for i in (1..=n / 2).rev() {
          if let (Some(&cost1), Some(&cost2)) = (cost.get((i * 2) as usize - 1), cost.get(i as usize * 2)) {
              ans += i32::abs(cost1 - cost2);
              if let Some(cost_i_minus_1) = cost.get_mut((i - 1) as usize) {
                  *cost_i_minus_1 += cost1.max(cost2);
              }
          }
      }
      ans
  }
}
