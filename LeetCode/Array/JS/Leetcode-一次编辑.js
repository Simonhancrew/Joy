var oneEditAway = function (first, second) {
    let [n, m] = [first.length, second.length];
    if (Math.abs(n - m) > 1) return false;
    if (n > m) {
        [first, second] = [second, first];
        [n, m] = [m, n];
    }
    let [i, j, cnt] = [0, 0, 0];
    while (i < n && j < m && cnt <= 1) {
        if (first[i] === second[j]) {
            i++, j++;
        } else {
            if (n == m) {
                i++, j++, cnt++;
            } else {
                j++, cnt++;
            }
        }
    }
    return cnt <= 1;
};