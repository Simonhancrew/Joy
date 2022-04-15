var deserialize = function (s) {
    let u = 0;
    let dfs = function (s) {
        let res = new NestedInteger();
        if (s[u] == '[') {
            u++;
            while (s[u] != ']') res.add(dfs(s))
            u++;
            if (u < s.length && s[u] == ',') u++;
        } else {
            let k = u;
            while (k < s.length && s[k] != ']' && s[k] != ',') k++;
            res.setInteger(s.substr(u, k - u));
            if (k < s.length && s[k] == ',') k++;
            u = k;
        }
        return res;
    }
    return dfs(s)
};