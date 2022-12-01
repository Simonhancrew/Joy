impl Solution {
    pub fn nearest_valid_point(x: i32, y: i32, points: Vec<Vec<i32>>) -> i32 {
        let (mut dis, n, mut tar) = (1000000, points.len(), -1);
        for i in 0..n {
            let (nx, ny) = (points[i][0], points[i][1]);
            if nx == x {
                let dist = (ny - y).abs();
                if dist < dis {
                    dis = dist;
                    tar = i as i32;
                }
            } else if ny == y {
                let dist = (nx - x).abs();
                if dist < dis {
                    dis = dist;
                    tar = i as i32;
                }
            }
        }
        tar
    }   
}
