impl Solution {
    pub fn get_maximum_generated(n: i32) -> i32 {
        if n == 0{
            return 0;
        }
        let mut res = vec![0;n as usize + 1];
        res[1] = 1;
        for i in 2..=n as usize{
            res[i] = res[i / 2] + (i & 1) * res[i / 2 + 1]; 
        }
        res[0..=n as usize].iter().max().unwrap().to_owned() as i32
    }
}