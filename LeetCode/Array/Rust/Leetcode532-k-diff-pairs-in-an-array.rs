impl Solution {
    pub fn find_pairs(mut nums: Vec<i32>, k: i32) -> i32 {
        let (mut ans,n) = (0,nums.len());
        let (mut i,mut j) = (0,0);
        nums.sort();
        while i < n {
            while i < n - 1 && nums[i + 1] == nums[i] {
                i += 1;
            }
            while j < i && nums[i] - nums[j] > k {
                j += 1;
            }
            if j < i && nums[i] - nums[j] == k {
                ans += 1;
            }
            i += 1; 
        }
        ans
    }
}