var removeOuterParentheses = function (s) {
    let [ans, n] = [[], s.length];
    for (let i = 0; i < n; i++) {
        let [j, cnt] = [i + 1, 1];
        while (j < n && cnt != 0) {
            if (s[j] == '(') cnt++;
            else cnt--;
            j++
        }
        ans.push(s.slice(i + 1, j - 1));
        i = j - 1;
    }
    return ans.join('');
};