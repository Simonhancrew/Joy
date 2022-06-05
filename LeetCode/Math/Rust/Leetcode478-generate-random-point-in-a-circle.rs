struct Solution {
    x: f64,
    y: f64,
    r: f64,
}

use rand::prelude::*;

impl Solution {
    fn new(radius: f64, x_center: f64, y_center: f64) -> Self {
        Self {
            x: x_center,
            y: y_center,
            r: radius,
        }
    }

    fn rand_point(&self) -> Vec<f64> {
        let mut rng = rand::thread_rng();
        let a = rng.gen_range(-1.0, 1.0);
        let b = rng.gen_range(-1.0, 1.0);
        if a * a + b * b > 1_f64 {
            return self.rand_point();
        }
        vec![self.x + self.r * a, self.y + self.r * b]
    }
}
