impl Solution {
    pub fn reach_number(mut target: i32) -> i32 {
        let (mut acc, mut cnt) = (0, 0);
        target = target.abs();
        while acc < target || (acc - target) & 1 == 1 {
            cnt += 1;
            acc += cnt;
        }
        cnt
    }
}
