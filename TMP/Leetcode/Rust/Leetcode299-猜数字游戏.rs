impl Solution {
    pub fn get_hint(secret: String, guess: String) -> String {
        let mut st = vec![0;26];
        let (mut bull,mut cow) = (0,0);
        let (secret,guess) = (secret.as_bytes(),guess.as_bytes());
        for i in 0..secret.len(){
            if secret[i] == guess[i]{
                bull += 1;
            }else{
                st[(secret[i] - b'0') as usize] += 1;
            }
        }
        for i in 0..guess.len(){
            if guess[i] != secret[i] && st[(guess[i] - b'0') as usize] > 0{
                st[(guess[i] - b'0') as usize] -= 1;
                cow += 1;
            }
        }
        bull.to_string() + "A" + &cow.to_string() + "B"
    }
}