impl Solution {
    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
        let (mut l,mut r) = (1,-1);
        for &pile in &piles {
            r = r.max(pile);
        }
        let check = |k:i32| -> bool {
            let mut cnt = 0;
            for pile in &piles {
                cnt += (pile + k - 1) / k;
            }
            cnt <= h
        };
        while l < r {
            let mid = (l + r) >> 1;
            if check(mid) {
                r = mid;
            }else{
                l = mid + 1
            }
        }
        l
    }
}