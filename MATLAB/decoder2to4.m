function z = decoder2to4(x,y)
output1 = ~x&~y;
output2 = ~x&y;
output3 = x&~y;
output4 = x&y;
z = [output1; output2; output3; output4]; 
end