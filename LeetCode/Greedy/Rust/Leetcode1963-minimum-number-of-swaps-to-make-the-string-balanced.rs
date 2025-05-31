// [ +1, ] -1, 0的时候遇到]就要换了，尽可能的跟最后的[换，越晚遇到], -1得到正数的概率就越大
// 另外如果不换的话，假设继续往后遍历遇到了没换的[，那么后面的其实全部是都]了，这个时候不会影响结果。
// 后面的已经全部平衡了，继续+不会增大答案的
impl Solution {
  pub fn min_swaps(s: String) -> i32 {
    let (mut ans, mut cnt) = (0, 0);
    for c in s.chars() {
      if c == '[' {
        cnt += 1;
      } else if (cnt > 0) {
        cnt -= 1;
      } else {
        cnt += 1;
        ans += 1;
      }
    }
    ans
  }
}
