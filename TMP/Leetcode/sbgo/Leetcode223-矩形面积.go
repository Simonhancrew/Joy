package sbgo

func computeArea(ax1 int, ay1 int, ax2 int, ay2 int, bx1 int, by1 int, bx2 int, by2 int) int {
	mixl, mixw := max(0, min(ax2, bx2)-max(ax1, bx1)), max(0, min(by2, ay2)-max(ay1, by1))
	return (ax2-ax1)*(ay2-ay1) + (bx2-bx1)*(by2-by1) - mixl*mixw
}
