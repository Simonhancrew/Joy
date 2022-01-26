use std::f32;
impl Solution {
    pub fn construct_rectangle(area: i32) -> Vec<i32> {
        let n = f32::sqrt(area as f32) as i32;
        for i in (1..=n).rev() {
            if area % i == 0{
                return vec![area / i,i];
            }
        }
        vec![]
    }
}