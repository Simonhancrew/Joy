impl Solution {
    pub fn number_of_arithmetic_slices(mut nums: Vec<i32>) -> i32 {
        let(mut res,mut n) = (0,nums.len());
        for i in (1..n).rev(){
            nums[i] -= nums[i - 1];
        }
        let mut i = 1;
        while i < n {
            let mut j = i;
            while j < n && nums[j] == nums[i]{
                j += 1;
            }
            let k = j - i;
            res += (k - 1) * k / 2;
            i = j;
        } 
        res as i32
    }
}