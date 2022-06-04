var numUniqueEmails = function (emails) {
    let st = new Set();
    for (const s of emails) {
        let t = '';
        for (let i = 0; i < s.length; i++) {
            if (s[i] == '.') continue;
            if (s[i] == '@') {
                t += s.substr(i);
                break;
            }
            if (s[i] == '+') {
                while (s[i] != '@') i++;
                t += s.substr(i);
                break;
            }
            t += s[i];
        }
        st.add(t);
    }
    return st.size;
};