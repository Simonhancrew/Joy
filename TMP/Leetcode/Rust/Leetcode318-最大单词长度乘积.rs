impl Solution {
    pub fn max_product(words: Vec<String>) -> i32 {
        let mut bitmask = vec![0;words.len()];
        for i in 0..words.len(){
            for ch in words[i].as_bytes(){
                let t = ch - b'a';
                bitmask[i] |= 1 << t;
            }
        }
        let mut res = 0;
        for i in 0..words.len(){
            for j in (i + 1)..words.len(){
                if bitmask[i] & bitmask[j] == 0{
                    res = res.max((words[i].len() * words[j].len()) as i32);
                }
            }
        }
        return res;
    }
}