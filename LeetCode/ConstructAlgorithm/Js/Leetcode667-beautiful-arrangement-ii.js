var constructArray = function(n, k) {
    let ans = [];
    for(let i = 1;i < n - k;i++) ans.push(i);
    for(let [i,j] = [n - k,n];i <= j;i++,j--){
        ans.push(i);
        if(i != j) ans.push(j);
    }
    return ans;
};
