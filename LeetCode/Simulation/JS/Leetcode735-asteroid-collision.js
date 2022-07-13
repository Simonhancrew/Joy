var asteroidCollision = function (asteroids) {
    let ans = [];
    for (const ast of asteroids) {
        let flag = true;
        while (flag && ans.length && ans[ans.length - 1] > 0 && ast < 0) {
            flag = -ast > ans[ans.length - 1];
            if (-ast >= ans[ans.length - 1]) ans.pop();
        }
        if (flag) ans.push(ast);
    }
    return ans;
};