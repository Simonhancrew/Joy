#[allow(unused_imports)]
use std::cmp::{max, min};
use std::io::{stdin, stdout, BufWriter, Write};
// const INF: i64 = 0x3f3f3f3f;

#[derive(Default)]
struct Scanner {
  buffer: Vec<String>,
}
impl Scanner {
  fn next<T: std::str::FromStr>(&mut self) -> T {
    loop {
      if let Some(token) = self.buffer.pop() {
        return token.parse().ok().expect("Failed parse");
      }
      let mut input = String::new();
      stdin().read_line(&mut input).expect("Failed read");
      self.buffer = input.split_whitespace().rev().map(String::from).collect();
    }
  }
}

fn main() {
  let mut scan = Scanner::default();
  let out = &mut BufWriter::new(stdout());
  let n: usize = scan.next();
  let mut arr: Vec<i32> = vec![0; n + 1];
  for i in 1..=n {
    arr[i] = scan.next();
  }
  let s: i32 = arr.iter().sum();
  let mut f = vec![0; n + 1];
  for i in 1..=n {
    f[i] = 0.max(arr[i].max(f[i - 1] + arr[i]));
  }
  let mut mx = 0;
  for x in &f[1..] {
    mx = mx.max(*x);
  }
  writeln!(out, "{}", 2 * mx - s).ok();
}
