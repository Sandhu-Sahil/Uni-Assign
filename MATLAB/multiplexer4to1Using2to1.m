function z = multiplexer4to1Using2to1()

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

z = multiplexer2to1(multiplexer2to1(input1, input2, selector1), multiplexer2to1(input3, input4, selector1), selector2);

end
