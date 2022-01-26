var simplifyPath = function(path) {
    let res = '',name = '';
    if(path[path.length - 1] != '/') path += '/';
    for(const ch of path){
        if(ch != '/') name += ch;
        else{
            if(name == '..'){
                while(res.length && res[res.length - 1] != '/') res = res.slice(0,res.length - 1);
                if(res.length) res = res.slice(0,res.length - 1);
            }else if(name != '.' && name != ''){
                res += '/' + name;
            }
            name = '';
        }
    }
    if(res.length == 0) res = '/';
    return res;
};