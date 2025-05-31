impl Solution {
  pub fn maximum_tastiness(mut price: Vec<i32>, k: i32) -> i32 {
    price.sort_unstable();
    let (n, mut l, mut r) = (price.len(), 0, price[price.len() - 1] - price[0]);
    let check = |diff: i32| -> bool {
      let (mut cnt, mut num) = (1, price[0]);
      for i in 1..n {
        if price[i] - num >= diff {
          num = price[i];
          cnt += 1;
        }
        if cnt >= k {
          return true;
        }
      }
      false
    };
    while l < r {
      let mid = (l + r + 1) >> 1;
      if check(mid) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    l
  }
}
