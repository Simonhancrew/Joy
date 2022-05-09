var diStringMatch = function(s) {
    const n = s.length;
    let [l,r,ans] = [0,n,new Array(n + 1).fill(0)];
    for(let i = 0;i < n;i++){
        if(s[i] == 'I') ans[i] = l++;
        else ans[i] = r--;
    }
    ans[n] = l;
    return ans;
};