impl Solution {
    pub fn most_frequent_even(nums: Vec<i32>) -> i32 {
        use std::collections::HashMap;
        let mut mp = HashMap::new();
        for num in nums {
            if num % 2 == 1 {
                continue;
            }
            mp.entry(num).and_modify(|v| *v += 1).or_insert(1);
        }
        let (mut ans, mut cnt) = (-1, 0);
        for (k, v) in mp.iter() {
            if v > &cnt {
                cnt = *v;
                ans = *k;
            } else if *v == cnt && ans > *k {
                ans = *k
            }            
        }
        ans
    }
}
