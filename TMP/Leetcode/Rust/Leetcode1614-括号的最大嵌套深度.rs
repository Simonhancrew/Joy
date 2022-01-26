impl Solution {
    pub fn max_depth(s: String) -> i32 {
        let (mut ans,mut cnt) = (0,0);
        for ch in s.chars(){
            if ch == '('{
                cnt += 1;
                ans = ans.max(cnt);
            }else if ch ==')'{
                cnt -= 1;
            }
        }
        ans
    }
}