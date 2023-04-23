impl Solution {
    pub fn min_height_shelves(books: Vec<Vec<i32>>, shelf_width: i32) -> i32 {
        let n = books.len();
        let mut f = vec![i32::MAX;n + 1];
        f[0] = 0;
        for i in 1..=n {
            let (mut s, mut h) = (0, 0);
            for j in (1..=i).rev() {
                s += books[j - 1][0];
                if s > shelf_width {
                    break;
                }
                h = h.max(books[j - 1][1]);
                f[i] = f[i].min(f[j - 1] + h);
            }
        }
        f[n]
    }   
}
