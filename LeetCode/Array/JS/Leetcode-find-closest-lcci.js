var findClosest = function (words, word1, word2) {
    let [l, r, n] = [-1, -1, words.length];
    let ans = 100000;
    for (let i = 0; i < n; i++) {
        if (words[i] == word1) l = i;
        if (words[i] == word2) r = i;
        if (l >= 0 && r >= 0) {
            ans = Math.min(ans, Math.abs(l - r));
        }
    }
    return ans;
};