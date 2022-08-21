var isPrefixOfWord = function(sentence, searchWord) {
    let [ans,rec,idx] = [-1,sentence.split(' '),0];
    let check = function(s,p) {
        if(p.length > s.length) {
            return false;
        }
        for(let i = 0;i < p.length;i++) {
            if(s[i] != p[i]) return false;
        }
        return true;
    }
    for(const s of rec) {
        idx++;
        if(check(s,searchWord)) {
            ans = idx;
            break;
        }
    }
    return ans; 
};