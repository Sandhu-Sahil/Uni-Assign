function a = fullAdder(x,y,z)
sum = xorCustom(x,xorCustom(y,z));
carry = (x&y) | (y&z) | (x&z);
a = [sum; carry];
end