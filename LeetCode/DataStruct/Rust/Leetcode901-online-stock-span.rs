struct StockSpanner {
    prices: Vec<i32>,
    day: Vec<i32>,
    idx: i32,
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl StockSpanner {

    fn new() -> Self {
        StockSpanner{
            prices: vec![i32::MAX],
            idx: 0,
            day: vec![-1],
        }   
    }
    
    fn next(&mut self, price: i32) -> i32 {
        while price >= self.prices[self.prices.len() - 1] {
            self.prices.pop();
            self.day.pop();
        }
        let res = self.idx - self.day[self.day.len() - 1];
        self.day.push(self.idx);
        self.prices.push(price);
        self.idx += 1;
        res
    }   
}
