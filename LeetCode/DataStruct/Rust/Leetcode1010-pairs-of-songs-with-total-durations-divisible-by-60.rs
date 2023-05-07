impl Solution {
    pub fn num_pairs_divisible_by60(time: Vec<i32>) -> i32 {
        use std::collections::HashMap;
        let mut mp = HashMap::new();
        let mut res = 0;
        for &x in &time {
            let y = x % 60;
            let tar = (60 - y) % 60;
            if let Some(z) = mp.get(&tar) {
                res += z;
            }
            mp.entry(y).and_modify(|x| *x += 1).or_insert(1); 
        }
        res
    }
}
