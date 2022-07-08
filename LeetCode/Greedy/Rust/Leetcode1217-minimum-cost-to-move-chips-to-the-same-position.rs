impl Solution {
    pub fn min_cost_to_move_chips(position: Vec<i32>) -> i32 {
        let (mut o, mut e) = (0, 0);
        for p in &position {
            if p % 2 == 0 {
                o += 1;
            } else {
                e += 1;
            }
        }
        if o == 0 || e == 0 {
            return 0;
        }
        o.min(e)
    }
}
