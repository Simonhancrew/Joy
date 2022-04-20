var lengthLongestPath = function (input) {
    const stk = [];
    let res = 0;
    for (let i = 0, sum = 0; i < input.length; i++) {
        let k = 0;
        while (i < input.length && input[i] == '\t') i++, k++;
        while (k < stk.length) sum -= stk.pop();
        let j = i;
        while (j < input.length && input[j] != '\n') j++;
        let len = j - i;
        stk.push(len), sum += len;
        if (input.substr(i, len).indexOf('.') != -1) {
            res = Math.max(res, sum + stk.length - 1);
        }
        i = j;
    }
    return res;
};