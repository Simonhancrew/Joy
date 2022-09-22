use std::collections::HashMap;
impl Solution {
    pub fn can_form_array(arr: Vec<i32>, pieces: Vec<Vec<i32>>) -> bool {
        let mut mp = HashMap::new();
        for i in 0..pieces.len() {
            mp.insert(pieces[i][0],i);
        }
        let mut i = 0;
        let n = arr.len();
        while i < n {
            if !mp.contains_key(&arr[i]) {
                return false;
            }
            let t = &pieces[*mp.get(&arr[i]).unwrap()];
            for j in 0..t.len() {
                if arr[i] != t[j] {
                    return false;
                }
                i += 1;
            }
        }
        true
    }
}
