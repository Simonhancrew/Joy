impl Solution {
    pub fn best_coordinate(towers: Vec<Vec<i32>>, radius: i32) -> Vec<i32> {
        let (mut mx ,mut my) = (-1, -1);
        for t in &towers {
            mx = mx.max(t[0]);
            my = my.max(t[1]);
        }
        let (mut tx, mut ty, mut qua) = (0, 0, 0);
        for x in 0..=mx {
            for y in 0..=my {
                let mut q = 0;
                for t in &towers {
                    let d = (t[0] - x) * (t[0] - x) + (t[1] - y) * (t[1] - y);
                    if d <= radius * radius {
                        q += (t[2] as f64 / (1 as f64 + (d as f64).sqrt())) as i32;
                    }
                }
                if q > qua {
                    tx = x;
                    ty = y;
                    qua = q;
                }
            }
        }
        vec![tx, ty]
    }
}
