var reverseOnlyLetters = function(s) {
    const sr = [...s],n = s.length;
    let judge = function(s) {
        if(s >= 'a' && s <= 'z') return true;
        if(s >= 'A' && s <= 'Z') return true;
        return false;
    }

    for(let i = 0,j = n - 1;i < j;i++,j--){
        while(i < j && !judge(sr[i])) i++;
        while(i < j && !judge(sr[j])) j--;
        tmp = sr[i]
        sr[i] = s[j],sr[j] = tmp;
    } 
    return sr.join('');
};