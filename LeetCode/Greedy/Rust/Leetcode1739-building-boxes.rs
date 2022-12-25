// 找规律，优先墙角的。
// 针对不能放满一层的，尽量贴着放，让其能构建新的能堆叠的块
impl Solution {
    pub fn minimum_boxes(n: i32) -> i32 {
        let (mut sum, mut k) = (0, 1);
        while sum + k * (k + 1) / 2 <= n {
            sum += k * (k + 1) / 2;
            k += 1;
        }
        let mut res = k * (k - 1) / 2;
        k = 1;
        while sum < n {
            sum += k;
            k += 1;
            res += 1;
        }
        res
    }
}