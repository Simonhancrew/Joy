impl Solution {
    pub fn largest_triangle_area(points: Vec<Vec<i32>>) -> f64 {
        let mut ans = -1_f64;
        for p in &points {
            for p1 in &points {
                for p2 in &points {
                    let (x1, y1) = (p[0], p[1]);
                    let (x2, y2, x3, y3) = (p1[0] - x1, p1[1] - y1, p2[0] - x1, p2[1] - y1);
                    ans = ans.max((x2 * y3 - x3 * y2).abs() as f64 / 2_f64);
                }
            }
        }
        ans
    }
}
