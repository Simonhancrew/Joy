var pancakeSort = function(arr) {
    const n = arr.length,res = [];
    let rev = function(arr,end) {
        for(let l = 0,r = end;l < r;l++,r--){
            let t = arr[r];
            arr[r] = arr[l];
            arr[l] = t;
        }
    }
    for(let i = n - 1;i >= 0;i--){
        let mx = 0;
        for(let j = 0;j <= i;j++)
        {
            if(arr[j] > arr[mx]) mx = j;
        }
        if(mx == i) continue;
        rev(arr,mx);
        res.push(mx + 1)
        rev(arr,i);
        res.push(i + 1)
    }
    return res;
};
