package sbgo

import "math/rand"

type Solution struct {
	x, y, r float64
}

func Constructor(radius float64, x_center float64, y_center float64) Solution {
	return Solution{
		x: x_center,
		y: y_center,
		r: radius,
	}
}

func (this *Solution) RandPoint() []float64 {
	a, b := rand.Float64()*2-1, rand.Float64()*2-1
	if a*a+b*b > 1 {
		return this.RandPoint()
	}
	return []float64{
		this.x + this.r*a, this.y + this.r*b,
	}
}
