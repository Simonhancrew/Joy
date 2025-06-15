impl Solution {
    pub fn max_diff(num: i32) -> i32 {
        let mut s = num.to_string();
        for c in s.chars() {
            if c == '9' {
                continue;
            }
            s = s.replace(c, "9");
            println!("{}", s);
            break;
        }
        let mx = s.parse::<i32>().unwrap();
        s = num.to_string();
        let first = s.chars().next().unwrap();
        if first != '1' {
            s = s.replace(first, "1");
        } else {
            for c in s.chars() {
                if c > '1' {
                    s = s.replace(c, "0");
                    break;
                }
            }
        }
        let mn = s.parse::<i32>().unwrap();
        mx - mn
    }
}
