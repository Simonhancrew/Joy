var toGoatLatin = function (sentence) {
    const s = sentence.split(' '), st = new Set();
    st.add('a'), st.add('e'), st.add('i'), st.add('o'), st.add('u');
    let res = '', cur = 'a';
    for (let i = 0; i < s.length; i++) {
        if (i) res += ' ';
        if (st.has(s[i][0]) || st.has(s[i][0].toLowerCase())) {
            res += s[i] + "ma";
        } else {
            res += s[i].substr(1) + s[i][0] + "ma";
        }
        res += cur;
        cur += 'a';
    }
    return res;
};