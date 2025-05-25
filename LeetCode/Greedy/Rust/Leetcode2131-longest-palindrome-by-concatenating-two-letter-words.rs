impl Solution {
    pub fn longest_palindrome(words: Vec<String>) -> i32 {
        let mut cnt = vec![vec![0;26];26];
        for s in words {
            let s = s.as_bytes();
            cnt[(s[0] - b'a') as usize][(s[1] - b'a') as usize] += 1;
        }
        let (mut ans, mut odd) = (0, 0);
        for i in 0..26 {
            let c = cnt[i][i];
            ans += c - c % 2;
            odd |= if c % 2 == 0 { 0 } else { 1 };
            for j in i + 1..26 {
                ans += cnt[i][j].min(cnt[j][i]) * 2;
            }
        }
        (ans + odd) * 2
    }
}
