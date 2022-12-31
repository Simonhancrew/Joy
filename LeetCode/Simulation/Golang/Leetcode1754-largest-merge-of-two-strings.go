package sbgo

func minMovesToSeat(seats []int, students []int) int {
    sort.Ints(seats)
    sort.Ints(students)
    ans := 0
    abs := func(i int) int {
        if i < 0 {
            return -i
        }
        return i
    }
    for i := 0;i < len(students);i++ {
        ans += abs(students[i] - seats[i])
    }
    return ans
}
