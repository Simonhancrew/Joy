impl Solution {
    pub fn height_checker(heights: Vec<i32>) -> i32 {
        let mut rec = heights.clone();
        rec.sort();
        let (mut ans,n) = (0,heights.len());
        for i in 0..n {
            if rec[i] != heights[i] {
                ans += 1;
            }
        }
        ans
    }
}