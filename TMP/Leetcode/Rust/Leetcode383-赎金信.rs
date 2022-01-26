impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut mp = vec![0;26];
        for ch in magazine.bytes(){
            let ch = (ch - b'a') as usize;
            mp[ch] += 1;
        }
        for ch in ransom_note.bytes(){
            let ch = (ch - b'a') as usize;      
            mp[ch] -= 1;
            if mp[ch] < 0 {
                return false;
            }
        }
        true
    }
}