var visiblePoints = function(points, angle, location) {
    let degree = new Array();
    let st = 0;
    for(const point of points) {
        if(point[0] == location[0] && point[1] == location[1]) {
            st++;
            continue;
        }
        let dx = point[0] - location[0],dy = point[1] - location[1];
        let dg = Math.atan2(dy,dx);
        degree.push(dg);
    }
    degree.sort((a,b)=>a-b);
    let n = degree.length;
    for(let i = 0;i < n;i++){
        degree.push(degree[i] + 2 * Math.PI);
    }
    let cnt = 0;
    let angled = angle * Math.PI / 180;
    for(let i = 0, j = 0;i < n;i++){
        while(j < degree.length && degree[j] - degree[i] <= angled) j++;
        cnt = Math.max(cnt,j - i);
    }
    return st + cnt;
};