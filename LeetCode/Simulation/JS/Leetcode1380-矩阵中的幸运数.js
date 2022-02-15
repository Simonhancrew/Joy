var luckyNumbers  = function(matrix) {
    const n = matrix.length,m = matrix[0].length;
    const row = new Array(n).fill(100000),col = new Array(m).fill(0);
    for(let i = 0;i < n;i++)
    {
        for(let j = 0;j < m;j++)
        {
            row[i] = Math.min(row[i],matrix[i][j]);
            col[j] = Math.max(col[j],matrix[i][j]);
        }
    }
    const ans = [];
    for(let i = 0;i < n;i++)
    {
        for(let j = 0;j < m;j++)
        {
            if(matrix[i][j] == col[j] && matrix[i][j] == row[i]) ans.push(col[j]);
        }
    }
    return ans;
};