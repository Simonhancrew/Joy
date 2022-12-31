impl Solution {
    pub fn min_moves_to_seat(mut seats: Vec<i32>, mut students: Vec<i32>) -> i32 {
        seats.sort_unstable();
        students.sort_unstable();
        let mut ans = 0;
        for i in 0..seats.len() {
            ans += (students[i] - seats[i]).abs();
        }
        ans
    }
}
