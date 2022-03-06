var goodDaysToRobBank = function (security, time) {
    const n = security.length, ans = [];
    const l = new Array(n).fill(0), r = new Array(n).fill(0);
    let cnt = 0;
    for (let i = 1; i < n; i++) {
        if (security[i] <= security[i - 1]) cnt++;
        else cnt = 0;
        l[i] = cnt;
    }
    cnt = 0;
    for (let i = n - 2; i >= 0; i--) {
        if (security[i] <= security[i + 1]) cnt++;
        else cnt = 0;
        r[i] = cnt;
    }
    for (let i = 0; i < n; i++) {
        if (l[i] >= time && r[i] >= time) ans.push(i);
    }
    return ans;
};