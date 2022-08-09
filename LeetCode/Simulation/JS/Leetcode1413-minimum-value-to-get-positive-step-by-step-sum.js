var minStartValue = function(nums) {
    let [ans,acc] = [1,0];
    for(const num of nums) {
        acc += num;
        let nag = 1 - acc;
        if(nag > ans) {
            ans = nag;
        }
    }
    return ans;
};
