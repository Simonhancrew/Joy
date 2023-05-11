impl Solution {
    pub fn query_string(s: String, n: i32) -> bool {
        use std::collections::HashSet;
        let (m, mut st) = (s.len(), HashSet::new());
        for i in 0..m {
            let mut acc = 0;
            for j in i..m {
                acc = 2 * acc + (s.as_bytes()[j] - b'0') as i32;
                if acc > n {
                    break;
                }
                if acc > 0 {
                    st.insert(acc);
                }
            }
        }
        st.len() == n as usize
    }
}
