var dayOfYear = function(date) {
    let nums = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
    const y = +date.slice(0,4);
    const m = +date.slice(5,7);
    const d = +date.slice(8)
    let is_leap = false;
    if(y % 400 == 0 || (y % 4 ==0 && y % 100 != 0)) is_leap = true;
    let ans = 0;
    for(let i = 0;i < m - 1;i++){
        ans += nums[i];
        if(is_leap && i == 1) {
            ans += 1;
        }
    }
    return ans + d;
};