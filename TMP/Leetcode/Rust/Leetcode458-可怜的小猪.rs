impl Solution {
    pub fn poor_pigs(buckets: i32, minutes_to_die: i32, minutes_to_test: i32) -> i32 {
        let k:f32 = minutes_to_test as f32 / minutes_to_die as f32;
        let buckets:f32 = buckets as f32;
        (buckets.log(2.0) / (k + 1.0).log(2.0)).ceil() as i32 
    }
}