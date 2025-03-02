use std::collections::HashMap;
struct TimeMap {
    mp: HashMap<String, Vec<(i32, String)>>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TimeMap {

    fn new() -> Self {
        Self {
            mp: HashMap::new()
        }
    }
    
    fn set(&mut self, key: String, value: String, timestamp: i32) {
        self.mp.entry(key).or_default().push((timestamp, value.clone()));
    }
    
    fn get(&self, key: String, timestamp: i32) -> String {
        if let Some(vec) = self.mp.get(&key) {
            let (mut l, mut r) = (-1, vec.len() as i32);
            while l + 1 < r {
                let mid = l + r >> 1;
                if vec[mid as usize].0 <= timestamp {
                    l = mid;
                } else {
                    r = mid
                }
            }
            if l == -1 || vec[l as usize].0 > timestamp {
                return "".to_string();
            }
            return vec[l as usize].1.clone();
        }
        "".to_string()
    }
}
/**
 * Your TimeMap object will be instantiated and called as such:
 * let obj = TimeMap::new();
 * obj.set(key, value, timestamp);
 * let ret_2: String = obj.get(key, timestamp);
 */
