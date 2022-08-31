var validateStackSequences = function(pushed, popped) {
  let [ans,n] = [[],pushed.length];
  for(let [i,j] = [0,0];i < n;i++) {
    ans.push(pushed[i]);
    while(ans.length != 0 && ans[ans.length - 1] == popped[j]) {
      j++;
      ans.pop();
    }
  }
  return ans.length == 0;
};
