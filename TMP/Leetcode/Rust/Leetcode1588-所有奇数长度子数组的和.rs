impl Solution {
    pub fn sum_odd_length_subarrays(mut arr: Vec<i32>) -> i32 {
        let mut a = vec![0;1];
        a.append(&mut arr);
        let n = a.len();
        for i in 1..n{
            a[i] += a[i - 1];
        }
        let mut res = 0;
        for i in 1..n{
            for j in i..n{
                if (j - i + 1) & 1 == 1{
                    res += a[j] - a[i - 1];
                }
            }
        }
        res
    }
}