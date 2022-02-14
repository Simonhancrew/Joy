var singleNonDuplicate = function(nums) {
    nums.push(nums[-1] + 1);
    let l = 0,r = Math.floor(nums.length / 2 - 1);
    while(l < r)
    {
        let mid = (l + r) >> 1;
        if(nums[mid * 2] != nums[mid * 2 + 1]) r = mid;
        else l = mid + 1;
    }
    return nums[l * 2];
};