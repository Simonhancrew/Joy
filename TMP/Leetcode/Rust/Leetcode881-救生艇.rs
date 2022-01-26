impl Solution {
    pub fn num_rescue_boats(mut people: Vec<i32>, limit: i32) -> i32 {
        let mut res = 0;
        people.sort_unstable();
        let (mut i,mut j) = (0,people.len() - 1);
        while i <= j {
            if j > people.len() {
                break;
            }
            if people[i] + people[j] <= limit{
                i += 1;
            }
            res += 1;
            j -= 1;
        }
        res
    }
}