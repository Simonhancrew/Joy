impl Solution {
    pub fn check_record(s: String) -> bool {
        if s.contains("LLL"){
            return false;
        }
        let mut cnt = 0;
        for ch in s.chars(){
            if ch == 'A'{
                cnt += 1;
            }
        }
        if cnt >= 2{
            return false;
        }
        true
    }
}