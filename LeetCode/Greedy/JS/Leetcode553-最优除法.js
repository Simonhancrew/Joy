var optimalDivision = function(nums) {
    const n = nums.length;
    if(n == 0) return '';
    if(n == 1) return '' + nums[0];
    if(n == 2) return '' + nums[0] + '/' + nums[1];
    const res = [nums[0],"/("];
    for(let i = 1;i < n - 1;i++) {
        res.push(nums[i] + '/');
    }
    res.push(nums[n - 1] + ')');
    return res.join('');
};