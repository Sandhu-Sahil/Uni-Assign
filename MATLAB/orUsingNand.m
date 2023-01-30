function z = orUsingNand(x, y)
p = nand(x,x);
q = nand(y,y);
z = nand(p,q);
end