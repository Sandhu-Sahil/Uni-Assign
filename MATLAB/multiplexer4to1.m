function z = multiplexer4to1()

prompt = "Input 1 : ";
input1 = input(prompt);

prompt = "Input 2 : ";
input2 = input(prompt);

prompt = "Input 3 : ";
input3 = input(prompt);

prompt = "Input 4 : ";
input4 = input(prompt);

prompt = "Input selector 1 : ";
selector1 = input(prompt);

prompt = "Input selector 2 : ";
selector2 = input(prompt);

if ((selector1 == 0) && (selector2 == 0))
    z = input1;
elseif ((selector1 == 0) && (selector2 == 1))
    z = input2;
elseif ((selector1 == 1) && (selector2 == 0))
    z = input3;
elseif ((selector1 == 1) && (selector2 == 1))
    z = input4;
end

end