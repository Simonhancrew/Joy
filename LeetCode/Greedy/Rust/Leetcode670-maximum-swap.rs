impl Solution {
    pub fn maximum_swap(mut num: i32) -> i32 {
        let mut rec = vec![];
        while num != 0 {
            rec.push(num % 10);
            num /= 10;
        }
        let n = rec.len();
        for i in (0..n).rev() {
            let (mut rmx,mut idx) = (rec[i],i);
            for j in (0..i).rev() {
                if rec[j] >= rmx {
                    rmx = rec[j];
                    idx = j;
                }
            }
            if rmx > rec[i] {
                rec[idx] = rec[i];
                rec[i] = rmx;
                break
            }
        }
        let mut ans = 0;
        for i in (0..n).rev() {
            ans = ans * 10 + rec[i];
        }
        ans 
    }
}
