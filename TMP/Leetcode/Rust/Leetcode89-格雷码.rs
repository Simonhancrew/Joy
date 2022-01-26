impl Solution {
    pub fn gray_code(mut n: i32) -> Vec<i32> {
        let mut ans = vec![0;1];
        while n != 0 {
            let t = ans.len();
            for i in (0..t).rev(){
                ans[i] *= 2;
                ans.push(ans[i] + 1);
            }
            n -= 1;
        }
        ans
    }
}