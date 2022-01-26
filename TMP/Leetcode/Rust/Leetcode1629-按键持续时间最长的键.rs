impl Solution {
    pub fn slowest_key(release_times: Vec<i32>, keys_pressed: String) -> char {
        let keys_pressed = keys_pressed.chars().collect::<Vec<_>>();
        let (mut ans,mut time) = (keys_pressed[0],release_times[0]);
        for i in 1..keys_pressed.len(){
            let t =  release_times[i] - release_times[i - 1];
            if t > time || (t == time && keys_pressed[i] > ans){
                ans = keys_pressed[i];
                time = t;
            }
        }
        ans
    }
}