/**
 * @param {number} n
 * @return {number}
 */
var nextGreaterElement = function (n) {
    let s = String(n).split('');
    let i = s.length - 1;
    while (i && s[i - 1] >= s[i]) i--;
    if (!i) return -1;
    let j = i;
    while (j + 1 < s.length && s[j + 1] > s[i - 1]) j++;
    [s[i - 1], s[j]] = [s[j], s[i - 1]]
    let reverse = (s, st) => {
        for (let i = st, j = s.length - 1; i < j; i++) {
            [s[i], s[j]] = [s[j], s[i]];
            j--;
        }
    }
    reverse(s, i)
    if (s.join('') > 2147483647) {
        return -1;
    }
    return s.join('');
};