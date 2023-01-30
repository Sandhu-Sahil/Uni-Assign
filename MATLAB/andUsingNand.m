function z = andUsingNand(x, y)
p = nand(x,y);
z = nand(p,p);
end