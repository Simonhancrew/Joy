impl Solution {
    pub fn corp_flight_bookings(bookings: Vec<Vec<i32>>, n: i32) -> Vec<i32> {
        let mut ans = vec![0;n as usize];
        for bk in bookings.iter(){
            let (l,r,w) = (bk[0],bk[1],bk[2]);
            ans[l as usize - 1] += w;
            if r < n{
                ans[r as usize] -= w;
            }
        }
        let n = n as usize;
        for i in 1..n{
            ans[i] += ans[i - 1];
        }
        ans
    }
}