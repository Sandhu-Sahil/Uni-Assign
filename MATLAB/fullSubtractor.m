function z = fullSubtractor(x,y,z)
difference = xorCustom(x,xorCustom(y,z));
borrow = (~x&z) | (~x&y) | (y&z);
z = [difference; borrow];
end