var findClosestElements = function(arr, k, x) {
    let [l,r] = [0,arr.length - 1];
    while(l < r) {
        const mid = (l + r) >> 1;
        if(arr[mid] > x) r--;
        else l++;
    }
    l = r - 1;
    for(let i = 0;i < k;i++) {
        if(l < 0) r++;
        else if(r >= arr.length || x - arr[l] <= arr[r] - x) l--;
        else r++;
    }

    let ans = [];
    for(let i = l + 1;i < r;i++) ans.push(arr[i]);
    return ans;
};