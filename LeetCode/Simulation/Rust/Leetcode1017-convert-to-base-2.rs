impl Solution {
  pub fn base_neg2(mut n: i32) -> String {
    if n == 0 {
      return String::from("0");
    }
    let mut res = Vec::new();
    while n != 0 {
      res.push(b'0' + (n % 2) as u8);
      n /= 2;
    }
    let mut n = res.len();
    let mut cnt = 0;
    for i in 0..n {
      let cur = cnt + res[i] - b'0';
      res[i] = b'0' + cur % 2;
      cnt = cur / 2;
      if (i & 1 == 1 && cur & 1 == 1) {
        cnt += 1;
      }
    }
    while cnt != 0 {
      res.push(b'1');
      if n % 2 == 0 {
        cnt -= 1;
      }
      n += 1;
    }
    res.reverse();
    String::from_utf8(res).unwrap()
  }
}
