package sbgo

type StockSpanner struct {
  prices, day []int
  idx int 
}


func Constructor() StockSpanner {
  return StockSpanner{
    prices:[]int{int(1e6)},
    day: []int{-1},
    idx: 0,
  }
}


func (this *StockSpanner) Next(price int) int {
  for price >= this.prices[len(this.prices) - 1] {
    this.prices = this.prices[:len(this.prices) - 1]
    this.day = this.day[:len(this.day) - 1]
  }
  res := this.idx - this.day[len(this.day) - 1]
  this.day = append(this.day, this.idx)
  this.prices = append(this.prices, price)
  this.idx++
  return res
}
