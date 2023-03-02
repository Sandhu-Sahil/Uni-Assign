function z = multiplexer2to1UserInput()
prompt = "Input 1 : ";
input1 = input(prompt);
prompt = "Input 2 : ";
input2 = input(prompt);
prompt = "Input Selector value : ";
selector = input(prompt);

if (selector == 0)
    z = input1;
elseif (selector == 1)
    z = input2;
end
end