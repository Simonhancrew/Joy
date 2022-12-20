impl Solution {
    pub fn minimum_size(nums: Vec<i32>, max_operations: i32) -> i32 {
        let (mut l, mut r) = (1, 1e9 as i32);
        let check = |mid : i32| -> bool {
            let mut res = 0;
            for num in &nums {
                res += (num + mid - 1) / mid - 1;
                if res > max_operations {
                    return false;
                }
            }
            true
        };
        while l < r {
            let mid = (l + r) >> 1;
            if check(mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        l
    }
}
