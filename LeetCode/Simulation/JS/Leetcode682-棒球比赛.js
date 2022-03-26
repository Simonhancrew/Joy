var calPoints = function(ops) {
    const rec = [];
    let ans = 0;
    for(const op of ops) {
        const n = rec.length;
        switch(op[0]) {
            case 'D':
                ans += rec[n - 1] * 2;
                rec.push(rec[n - 1] * 2);
                break;
            case 'C':
                ans -= rec[n - 1];
                rec.pop();
                break;
            case '+':
                ans += rec[n - 1] + rec[n - 2];
                rec.push(rec[n - 1] + rec[n - 2]);
                break;
            default:
                ans += parseInt(op);
                rec.push(parseInt(op));
                break;
        }
    }
    return ans;
};