impl Solution {
    pub fn num_subarray_product_less_than_k(nums: Vec<i32>, k: i32) -> i32 {
        let (mut res,n,mut acc,mut i) = (0,nums.len(),1,0);
        for j in 0..n {
            acc *= nums[j];
            while i <= j && acc >= k {
                acc /= nums[i];
                i += 1;
            }
            res += j - i + 1
        }
        res as i32
    }
}