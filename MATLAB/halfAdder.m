function z = halfAdder(x,y)
sum = xorCustom(x,y);
carry = x & y;
z = [sum; carry];
end