var minSubsequence = function(nums) {
    const n = nums.length;
    nums.sort((a,b)=> a - b);
    let [acc,sum,ans] = [0,nums.reduce((item,x)=>x + item,0),[]];
    for(let i = n - 1;i >= 0 && acc <= sum;i--) {
        acc += nums[i];
        sum -= nums[i];
        ans.push(nums[i]);
    }
    return ans;
};
