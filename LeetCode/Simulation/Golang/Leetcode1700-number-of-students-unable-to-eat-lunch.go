package sbgo

func countStudents(students []int, sandwiches []int) int {
	s0, s1 := 0, 0
	for _, val := range students {
		s1 += val
	}
	s0 = len(students) - s1
	for _, val := range sandwiches {
		if val == 0 {
			if s0 != 0 {
				s0--
			} else {
				break
			}
		} else {
			if s1 != 0 {
				s1--
			} else {
				break
			}
		}
	}
	return s1 + s0
}
