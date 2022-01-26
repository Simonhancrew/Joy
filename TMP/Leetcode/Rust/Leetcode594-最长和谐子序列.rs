use std::collections::HashMap;
impl Solution {
    pub fn find_lhs(nums: Vec<i32>) -> i32 {
        let mut mp = HashMap::new();
        for x in nums.iter(){
            *mp.entry(x).or_insert(0) += 1;
        }
        let mut res = 0;
        for (&k,&v) in mp.iter(){
            match mp.get(&(k - 1)){
                Some(x) => res = res.max(x + v),
                None => {},
            }
        } 
        res
    }
}