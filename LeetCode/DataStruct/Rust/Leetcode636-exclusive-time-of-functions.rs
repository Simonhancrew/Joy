impl Solution {
    pub fn exclusive_time(n: i32, logs: Vec<String>) -> Vec<i32> {
        let (mut ans,mut stk,mut last) = (vec![0;n as usize],vec![],0);
        for log in logs.iter() {
            let pii:Vec<&str> = log.split(':').collect();
            let (id,ts) = (pii[0].parse::<usize>().unwrap(),pii[2].parse::<usize>().unwrap());
            if pii[1] == "start" {
                if !stk.is_empty() {
                    ans[stk[stk.len() - 1]] += (ts - last) as i32;
                }
                stk.push(id);
                last = ts;
            } else {
                ans[stk[stk.len() - 1]] += (ts - last + 1) as i32;
                last = ts + 1;
                stk.pop();
            }
        }
        ans
    }   
}