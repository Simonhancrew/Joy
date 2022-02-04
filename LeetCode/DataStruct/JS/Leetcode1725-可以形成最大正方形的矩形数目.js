var countGoodRectangles = function(rectangles) {
    let mx = -1,cnt = 0;
    for(const edge of rectangles) {
        let key = Math.min(edge[0],edge[1]);
        if(mx == key) cnt++;
        else if(mx < key) {
            cnt = 1;
            mx = key;
        }
    }
    return cnt;
};