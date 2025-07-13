impl Solution {
    pub fn match_players_and_trainers(mut players: Vec<i32>, mut trainers: Vec<i32>) -> i32 {
        players.sort_unstable();
        trainers.sort_unstable();
        let (mut j, mut ans) = (0, 0);
        for p in players {
            while j < trainers.len() && trainers[j] < p {
                j += 1;
            }
            if j == trainers.len() {
                break;
            }
            ans += 1;
            j += 1;
        }
        ans
    }
}