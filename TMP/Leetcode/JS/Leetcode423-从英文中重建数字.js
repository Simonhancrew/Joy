var originalDigits = function(s) {
    let name = ["zero", "one", "two", "three", "four", "five",
            "six", "seven", "eight", "nine"];
    let ord = [0, 8, 3, 2, 6, 4, 5, 1, 7, 9];
    let mp = new Map();
    for(const ch of s) mp.set(ch,(mp.get(ch) || 0) + 1);
    let res = []
    for(const x of ord){
        let flag = true;
        while(flag){
            for(const ch of name[x]){
                if(!mp.get(ch)){
                    flag = false;
                    break;
                } 
            }
            if(flag) {
                res.push(String.fromCharCode('0'.charCodeAt() + x));
                for(let ch of name[x]) mp.set(ch,mp.get(ch) - 1);
            }
        }
    }
    res.sort()
    return res.join('');
};