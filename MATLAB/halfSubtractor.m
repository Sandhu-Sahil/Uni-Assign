function z = halfSubtractor(x,y)
difference = xorCustom(x,y);
borrow = ~x&y;
z = [difference; borrow];
end
