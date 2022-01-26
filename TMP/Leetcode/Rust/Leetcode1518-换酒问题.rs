impl Solution {
    pub fn num_water_bottles(num_bottles: i32, num_exchange: i32) -> i32 {
        if num_bottles >= num_exchange {
            return (num_bottles - num_exchange) / (num_exchange - 1) + 1 + num_bottles;
        }
        num_bottles
    }
}