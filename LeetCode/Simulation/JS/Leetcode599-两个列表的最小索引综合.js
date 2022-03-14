var findRestaurant = function (list1, list2) {
    let ans = [];
    const mp = new Map();
    for (let i = 0; i < list1.length; i++) mp.set(list1[i], i);
    let sum = 1e9 + 10;
    for (let i = 0; i < list2.length; i++) {
        s = list2[i];
        if (mp.has(s)) {
            const k = mp.get(s) + i;
            if (k < sum) {
                sum = k;
                ans = [s];
            } else if (k == sum) {
                ans.push(s);
            }
        }
    }
    return ans;
};