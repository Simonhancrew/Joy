impl Solution {
  pub fn find_even_numbers(digits: Vec<i32>) -> Vec<i32> {
    let mut cnt = [0; 10];
    for x in digits {
      cnt[x as usize] += 1;
    }
    let mut res = vec![];
    for i in (100..1000).step_by(2) {
      let (mut tmp, mut ok) = ([0; 10], true);
      let mut x = i;
      while x > 0 {
        let d = (x % 10) as usize;
        tmp[d] += 1;
        if tmp[d] > cnt[d] {
          ok = false;
          break;
        }
        x /= 10;
      }
      if ok {
        res.push(i);
      }
    }
    res
  }
}
