impl Solution {
    pub fn reinitialize_permutation(n: i32) -> i32 {
        let (mut perm, mut res) = (vec![0;n as usize], 0);
        let n = n as usize;
        for i in 0..n {
            perm[i as usize] = i;
        }
        let mut arr = perm.clone();
        let trans = |mut arr : &mut Vec<usize>| {
            let base = arr.clone();
            for i in 0..n {
                if i % 2 == 0 {
                    arr[i] = base[i / 2];
                } else {
                    arr[i] = base[n / 2 + (i - 1) / 2];
                }
            }
            // print!("{:?}", arr);
        };
        loop {
            res += 1;
            trans(&mut arr);
            if arr == perm {
                break;
            }
        }
        res
    }
}
