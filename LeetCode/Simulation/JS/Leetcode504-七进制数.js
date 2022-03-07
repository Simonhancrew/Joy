var convertToBase7 = function (num) {
    if (num == 0) return "0";
    const ans = [];
    let flag = false;
    if (num < 0) {
        flag = true;
        num = -num;
    }
    while (num > 0) {
        ans.push(num % 7);
        num = Math.floor(num / 7);
    }
    if (flag) ans.push('-');
    ans.reverse();
    return ans.join('');
};