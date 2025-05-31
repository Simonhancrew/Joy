impl Solution {
  pub fn odd_cells(m: i32, n: i32, indices: Vec<Vec<i32>>) -> i32 {
    let (mut row, mut col) = (vec![0; m as usize], vec![0; n as usize]);
    for pos in indices {
      let (r, c) = (pos[0] as usize, pos[1] as usize);
      row[r] += 1;
      col[c] += 1;
    }
    let mut cnt = 0;
    for i in 0..m {
      for j in 0..n {
        if (row[i as usize] + col[j as usize]) & 1 == 1 {
          cnt += 1;
        }
      }
    }
    cnt
  }
}
