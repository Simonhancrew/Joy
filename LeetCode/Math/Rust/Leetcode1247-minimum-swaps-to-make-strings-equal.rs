// 总共有x-x, x-y, y-x, y-y这四种从s1->s2的映射
// 针对已经相等的不再考虑， 一对x-y,x-y做交换能够改变两者的位置
// 而x-y, y-x需要两次交换，所以尽可能交换同一个映射
// 多出来的奇数部分单独处理
impl Solution {
  pub fn minimum_swap(s1: String, s2: String) -> i32 {
      let (mut a, mut b) = (0, 0);
      for i in 0..s1.len() {
          if s1.as_bytes()[i] != s2.as_bytes()[i] {
              if s1.as_bytes()[i] == b'x' {
                  a += 1;
              } else {
                  b += 1;
              }
          }
      }
      if (a + b) % 2 != 0 {
          return -1;
      }
      a / 2 + b / 2 + a % 2 + b % 2
  }
}