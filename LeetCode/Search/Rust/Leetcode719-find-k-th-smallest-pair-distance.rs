impl Solution {
    pub fn smallest_distance_pair(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort();
        let (mut l, mut r) = (0, 1e6 as i32);
        let get = |mid: i32| -> i32 {
            let mut res = 0;
            let mut j = 0;
            for i in 0..nums.len() {
                while nums[i] - nums[j] > mid {
                    j += 1;
                }
                res += i - j;
            }
            res as i32
        };
        while l < r {
            let mid = (l + r) >> 1;
            if get(mid) >= k {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
}
