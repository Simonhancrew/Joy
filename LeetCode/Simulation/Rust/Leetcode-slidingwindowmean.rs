use std::collections::VecDeque;

struct MovingAverage {
    sum:i32,
    arr:VecDeque<i32>,
    size:usize
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MovingAverage {

    /** Initialize your data structure here. */
    fn new(size: i32) -> Self {
        MovingAverage{sum : 0,arr : VecDeque::new(),size: size as usize}
    }
    
    fn next(&mut self, val: i32) -> f64 {
        self.arr.push_back(val);
        self.sum += val;
        if self.size < self.arr.len() {
            self.sum -= self.arr.pop_front().unwrap();
        }
        self.sum as f64 / self.arr.len() as f64
    }
}