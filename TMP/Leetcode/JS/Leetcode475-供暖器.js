var findRadius = function(houses, heaters) {
    houses.sort((a,b)=> a - b);
    heaters.sort((a,b) => a - b);
    let l = 0,r = 1e9;
    let check = function(len){
        for(let i = 0,j = 0;i < houses.length;i++){
            while(j < heaters.length && Math.abs(houses[i] - heaters[j]) > len){
                j++; 
            } 
            if(j >= heaters.length) return false;
        }
        return true;
    }
    while(l < r){
        let mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    return r;
};