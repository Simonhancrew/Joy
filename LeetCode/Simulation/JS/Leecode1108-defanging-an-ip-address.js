var defangIPaddr = function (address) {
    let res = '';
    for (const ch of address) {
        if (ch == '.') res += "[.]";
        else res += ch;
    }
    return res;
};