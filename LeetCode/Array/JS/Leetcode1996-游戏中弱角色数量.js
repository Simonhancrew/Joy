var numberOfWeakCharacters = function(properties) {
    properties.sort((a,b) => {
        return a[0] == b[0] ? a[1] - b[1] : b[0] - a[0];
    });
    let ans = 0,mx = 0;
    for(const ps of properties) {
        if(ps[1] < mx) ans++;
        else if(ps[1] > mx) mx = ps[1];
    }
    return ans;
};