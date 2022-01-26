impl Solution {
    pub fn single_number(nums: Vec<i32>) -> Vec<i32> {
        let (mut diff,mut mask) = (1,0);
        for num in nums.iter(){
            mask ^= num;
        }
        while (diff & mask) == 0 {
            diff <<= 1;
        }
        let (mut a,mut b) = (0,0);
        for num in nums.iter(){
            if (diff & num) != 0{
                a ^= num;
            }else{
                b ^= num;
            }
        }
        return vec![a,b];
    }
}