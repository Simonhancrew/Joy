impl Solution {
    pub fn increasing_triplet(nums: Vec<i32>) -> bool {
        let INF = i32::MAX;
        let mut f = vec![INF,INF];
        for &num in nums.iter(){
            let mut k:usize = 2;
            while k > 0 && f[k - 1] >= num {
                k -= 1;
            }
            if k == 2 {
                return true;
            }
            f[k] = num;
        }
        false
    }
}