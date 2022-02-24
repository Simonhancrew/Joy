impl Solution {
    pub fn find_ball(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let (n,m,mut ans) = (grid.len(),grid[0].len(),Vec::new());
        for i in 0..m {
            let (mut x,mut y,mut z) = (0,i as i32,0);
            while x < n {
                if z == 0 {
                    if grid[x][y as usize] == 1 {
                        if y as usize + 1 >= m || grid[x][y as usize + 1] == -1 {
                            y = -1
                        }else{
                            y += 1;
                            z = 1;
                        }
                    }else{
                        if y - 1 < 0 || grid[x][y as usize - 1] == 1 {
                            y = -1
                        }else{
                            y -= 1;
                            z = 1;
                        }
                    }                    
                }else{
                    x += 1;
                    z = 0;
                }
                if y == -1 {
                    break
                }
            }
            ans.push(y as i32);
        }
        ans
    }
}