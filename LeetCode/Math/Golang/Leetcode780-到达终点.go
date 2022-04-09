package sbgo

func reachingPoints(sx int, sy int, tx int, ty int) bool {
	for tx > sx && ty > sy {
		if tx > ty {
			tx %= ty
		} else {
			ty %= tx
		}
	}

	if tx < sx || ty < sy {
		return false
	}
	if sx == tx {
		return (ty-sy)%tx == 0
	}
	return (tx-sx)%sy == 0
}
