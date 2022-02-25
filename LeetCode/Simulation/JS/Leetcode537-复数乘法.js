var complexNumberMultiply = function(num1, num2) {
    const c1 = [num1.split('+')[0],num1.split('+')[1].split('i')[0]];
    const c2 = [num2.split('+')[0],num2.split('+')[1].split('i')[0]];
    const r1 = parseInt(c1[0]),i1 = parseInt(c1[1]);
    const r2 = parseInt(c2[0]),i2 = parseInt(c2[1]);
    return '' + r1 * r2 - i1 * i2 + '+' + (r1 * i2 + r2 * i1) + 'i';
}