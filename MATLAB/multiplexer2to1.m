function z = multiplexer2to1(input1, input2, selector)
if (selector == 0 )
    z = input1;
elseif (selector == 1)
    z = input2;
end
end