/**
 * @param {number[]} nums
 * @return {number}
 */
 var missingNumber = function(nums) {
    var res = 0;
    for(let i = 0;i < nums.length;i++){
        res ^= nums[i];
    }
    for(let i = 0;i <= nums.length;i++){
        res ^= i;
    }
    return res;
};