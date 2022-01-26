impl Solution {
    pub fn majority_element(nums: Vec<i32>) -> Vec<i32> {
        let mut ans = vec![];
        let (mut c1,mut c2,mut r1,mut r2) = (0,0,0,0);
        for &x in nums.iter(){
            if r1 != 0 && x == c1{
                r1 += 1;
            }else if r2 != 0 && x == c2{
                r2 += 1;
            }else if r1 == 0{
                r1 = 1;
                c1 = x;
            }else if r2 == 0{
                r2 = 1;
                c2 = x;
            }else{
                r1 -= 1;
                r2 -= 1;
            }
        } 
        let (mut r1,mut r2) = (0,0);
        for &x in nums.iter(){
            if x == c1 {
                r1 += 1;
            }else if x == c2{
                r2 += 1;
            }
        }
        if r1 > nums.len() as i32 / 3{
            ans.push(c1);
        }
        if r2 > nums.len() as i32 / 3{
            ans.push(c2);
        }
        ans
    }
}