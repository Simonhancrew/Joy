impl Solution {
    pub fn number_of_lines(widths: Vec<i32>, s: String) -> Vec<i32> {
        let (mut line,mut cnt) = (1,0);
        for x in s.as_bytes() {
            let t = widths[(x - 97) as usize];
            cnt += t;
            if cnt > 100 {
                cnt = t;
                line += 1;
            }
        }
        vec![line,cnt]
    }
}