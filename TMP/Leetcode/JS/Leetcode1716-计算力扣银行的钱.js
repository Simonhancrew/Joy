var totalMoney = function(n) {
    let ans = 0;
    for(let i = 0,cnt = 1;i < n;i++){
        if(i && i % 7 == 0) cnt++;
        ans += (cnt + i % 7);
    }
    return ans;
};