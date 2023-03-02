function z = decoder3to8(x,y,z)
o1 = ~x&~y&~z;
o2 = ~x&~y&z;
o3 = ~x&y&~z;
o4 = ~x&y&z;
o5 = x&~y&~z;
o6 = x&~y&z;
o7 = x&y&~z;
o8 = x&y&z;

z = [o1;o2;o3;o4;o5;o6;o7;o8];
end