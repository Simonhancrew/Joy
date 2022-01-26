impl Solution {
    pub fn find_poisoned_duration(time_series: Vec<i32>, duration: i32) -> i32 {
        let (mut ans,mut last) = (0,-1);
        for x in time_series.iter(){
            let t = x + duration - 1;
            if *x > last{
                ans += duration;
            }else{
                ans += t - last;
            }
            last = t;
        }
        ans
    }
}