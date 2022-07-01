var diffWaysToCompute = function (expression) {
    let [res, n] = [[], expression.length];
    for (let i = 0; i < n; i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
            let left = diffWaysToCompute(expression.substr(0, i));
            let right = diffWaysToCompute(expression.substr(i + 1));
            for (const lhs of left) {
                for (const rhs of right) {
                    if (expression[i] == '+') {
                        res.push(lhs + rhs);
                    } else if (expression[i] == '-') {
                        res.push(lhs - rhs);
                    } else {
                        res.push(lhs * rhs);
                    }
                }
            }
        }
    }
    if (res.length == 0) {
        res.push(parseInt(expression));
    }
    return res;
};  