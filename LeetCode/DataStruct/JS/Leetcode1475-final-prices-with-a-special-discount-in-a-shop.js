var finalPrices = function(prices) {
    let [ans,n] = [[],prices.length];
    for(let i = n - 1;i >= 0;i--) {
        while(ans.length && ans[ans.length - 1] > prices[i]) {
            ans.pop();
        }
        const t = prices[i];
        if(ans.length) prices[i] -= ans[ans.length - 1];
        ans.push(t);
    }
    return prices;
};
