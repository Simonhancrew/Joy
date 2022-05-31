use std::collections::{HashMap, VecDeque};
impl Solution {
    pub fn alien_order(words: Vec<String>) -> String {
        let (mut din, mut g) = (vec![0; 26], vec![vec![]; 26]);
        let mut vis = vec![false; 26];
        let (mut cnt, mut n) = (0, words.len());
        fn build(l: &str, r: &str, g: &mut Vec<Vec<u8>>, din: &mut Vec<i32>) -> bool {
            let n = l.len().min(r.len());
            for i in 0..n {
                let (a, b) = (l.as_bytes()[i], r.as_bytes()[i]);
                if a != b {
                    g[(a - b'a') as usize].push((b - b'a') as u8);
                    din[(b - b'a') as usize] += 1;
                    return true;
                }
            }
            l.len() <= r.len()
        }

        for i in 0..n {
            for &ch in words[i].as_bytes() {
                if !vis[(ch - b'a') as usize] {
                    vis[(ch - b'a') as usize] = true;
                    cnt += 1;
                }
            }

            for j in 0..i {
                if !build(&words[j], &words[i], &mut g, &mut din) {
                    return "".to_owned();
                }
            }
        }
        let mut q = VecDeque::new();
        for i in 0..26 {
            if vis[i] && din[i] == 0 {
                q.push_back(i as u8);
            }
        }
        let mut rec = vec![];
        while q.len() != 0 {
            let t = q.pop_front().unwrap();
            rec.push(t + b'a');
            for &ne in &g[t as usize] {
                din[ne as usize] -= 1;
                if din[ne as usize] == 0 {
                    q.push_back(ne as u8);
                }
            }
        }
        if cnt != rec.len() {
            return "".to_owned();
        }
        String::from_utf8(rec).unwrap()
    }
}
