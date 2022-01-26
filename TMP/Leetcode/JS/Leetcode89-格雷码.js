var grayCode = function(n) {
    const ans = [0];
    while(n--){
        for(let i = ans.length - 1;i >= 0;i--){
            ans[i] *= 2;
            ans.push(ans[i] + 1);
        }
    }
    return ans;
};