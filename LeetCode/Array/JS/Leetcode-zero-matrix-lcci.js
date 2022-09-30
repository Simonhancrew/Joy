var setZeroes = function(matrix) {
  const [n,m] = [matrix.length,matrix[0].length];
  let [row,col] = [new Array(n).fill(0),new Array(m).fill(0)];
  for(let i = 0;i < n;i++) {
      for (let j = 0;j < m;j++) {
          if (matrix[i][j] == 0) {
              row[i] = col[j] = 1;
          }
      }  
  }
  for (let i = 0;i < n;i++) {
      for (let j = 0;j < m;j++) {
          if (row[i] || col[j]) {
              matrix[i][j] = 0;
          }
      }
  }
};