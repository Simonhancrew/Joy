var maxDepth = function(s) {
    let ans = 0,cnt = 0;
    for(const ch of s){
        if(ch == '(')  cnt += 1,ans = Math.max(ans,cnt);
        else if(ch == ')') cnt--;
    }
    return ans;
};