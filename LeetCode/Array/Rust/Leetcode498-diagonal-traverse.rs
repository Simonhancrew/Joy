impl Solution {
    pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
        let (n, m, mut ans) = (mat.len() as i32, mat[0].len() as i32, Vec::new());
        for i in 0..(n + m - 1) {
            if i % 2 == 1 {
                let (mut x, mut y) = (0, i);
                if i >= m {
                    x = i - m + 1;
                    y = m - 1;
                }
                while x < n && y >= 0 {
                    // println!("{},{}", x, y);
                    ans.push(mat[x as usize][y as usize]);
                    x += 1;
                    y -= 1;
                }
            } else {
                let (mut x, mut y) = (i, 0);
                if x >= n {
                    x = n - 1;
                    y = i - n + 1;
                }
                while x >= 0 && y < m {
                    ans.push(mat[x as usize][y as usize]);
                    x -= 1;
                    y += 1;
                }
            }
        }
        ans
    }
}
