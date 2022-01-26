impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let (mut res,n) = (0,nums.len());
        for num in nums.iter(){
            res ^= num;
        }
        for i in 0..=n{
            res ^= i as i32;
        }
        return res;
    }
}