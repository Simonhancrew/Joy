impl Solution {
    pub fn is_prefix_of_word(sentence: String, search_word: String) -> i32 {
        let (mut ans,mut idx) = (-1,0);
        let rec:Vec<&str> = sentence.split(' ').collect();
        let check = |s : &str,p : &str| -> bool {
            if p.len() > s.len() {
                return false;
            }
            for i in 0..p.len() {
                if p[i..i + 1] != s[i..i + 1] {
                    return false;
                }
            }
            true
        };
        for s in rec {
            idx += 1;
            if check(s,&search_word) {
                ans = idx;
                break;
            }
        }
        ans
    }
}