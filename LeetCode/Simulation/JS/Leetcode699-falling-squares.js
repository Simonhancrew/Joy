var fallingSquares = function (positions) {
    const n = positions.length;
    const ans = new Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        const [l1, r1] = [positions[i][0], positions[i][1] + positions[i][0] - 1];
        ans[i] = positions[i][1];
        for (let j = 0; j < i; j++) {
            const [l2, r2] = [positions[j][0], positions[j][1] + positions[j][0] - 1];
            if (r1 >= l2 && r2 >= l1) {
                ans[i] = Math.max(ans[i], ans[j] + positions[i][1]);
            }
            // console.log(l1,r1,l2,r2,ans[i]);
        }
    }
    for (let i = 1; i < n; i++) ans[i] = Math.max(ans[i], ans[i - 1]);
    return ans;
};