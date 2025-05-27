// num1 - num2 = (all -num2) - num2
// num2 = m + 2 m + ... km = (1 ... k) m = (k + 1) k / 2 * m
// res = all - 2 * num2 = all - (k + 1)k/2 * m
impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        (n + 1) * n / 2 - n / m * (n / m + 1) * m
    }
}