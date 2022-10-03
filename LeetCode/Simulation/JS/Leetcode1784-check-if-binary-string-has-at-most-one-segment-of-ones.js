var checkOnesSegment = function(s) {
  let [cnt,flag] = [0, false];
  for(const ch of s) {
      if (ch == '1') {
          if(flag) {
              continue;
          } else {
              cnt += 1;
              if( cnt > 1) return false;
              flag = true;
          }
      }else {
          flag = false;
      }
  }
  return true;
};