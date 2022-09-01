impl Solution {
    pub fn final_prices(mut prices: Vec<i32>) -> Vec<i32> {
        let mut stk = vec![];
        let n = prices.len();
        for i in (0..n).rev() {
            while !stk.is_empty() && stk[stk.len() - 1] > prices[i] {
                stk.pop();
            }
            let t = prices[i];
            if !stk.is_empty() {
                prices[i] -= stk[stk.len() - 1];
            }
            stk.push(t);
        }
        prices
    }
}
