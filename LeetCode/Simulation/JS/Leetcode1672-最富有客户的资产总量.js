var maximumWealth = function (accounts) {
    let mx = 0;
    for (const x of accounts) {
        mx = Math.max(mx, x.reduce((sum, cur) => sum + cur), 0);
    }
    return mx;
};