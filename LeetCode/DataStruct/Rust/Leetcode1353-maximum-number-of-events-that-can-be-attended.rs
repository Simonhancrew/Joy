// 找一个值开始第一个没有被标记的值--->并查集
// 针对每一个会议，找到能加入的时间
// #[cfg(false)]
// impl Solution {
//   pub fn max_events(mut events: Vec<Vec<i32>>) -> i32 {
//     events.sort_unstable_by_key(|e| e[1]);
//     let mx = events[events.len() - 1][1];
//     let mut fa: Vec<i32> = (0..mx + 2).collect();
//     fn find(x: i32, fa: &mut Vec<i32>) -> i32 {
//       if (fa[x as usize] != x) {
//         fa[x as usize] = find(fa[x as usize], fa);
//       }
//       return fa[x as usize];
//     }
//     let mut ans = 0;
//     for e in events {
//       let x = find(e[0], &mut fa);
//       if x <= e[1] {
//         ans += 1;
//         fa[x as usize] = x + 1;
//       }
//     }
//     ans
//   }
// }


// 枚举天数，当前天下取最小能用的
use std::collections::BinaryHeap;
use std::cmp::Reverse;
impl Solution {
    pub fn max_events(events: Vec<Vec<i32>>) -> i32 {
        let mut mx = 0;
        for event in &events {
            mx = mx.max(event[1]);
        }

        // 构建按开始时间分组的事件列表
        let mut mp = vec![Vec::new(); (mx + 1) as usize];
        for event in &events {
            mp[event[0] as usize].push(event[1]);
        }

        let mut heap = BinaryHeap::new();
        let mut ans = 0;

        for day in 1..=mx {
            // 移除那些结束时间早于当前日期的事件
            while let Some(&Reverse(end)) = heap.peek() {
                if end < day {
                    heap.pop();
                } else {
                    break;
                }
            }

            // 将当天的所有事件加入堆中（这里要包装成 Reverse）
            for &end in &mp[day as usize] {
                heap.push(Reverse(end));
            }

            // 如果堆不为空，选择一个事件
            if let Some(Reverse(end)) = heap.pop() {
                ans += 1;
            }
        }

        ans
    }
}
