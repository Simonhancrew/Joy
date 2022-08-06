var stringMatching = function (words) {
    let [ans, n] = [[], words.length];
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (i != j && words[j].search(words[i]) != -1) {
                ans.push(words[i]);
                break;
            }
        }
    }
    return ans;
};