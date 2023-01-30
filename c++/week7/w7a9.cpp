#include<iostream>
using namespace std;

void myFunction(int test) {
try{
if (test)
throw test;
else
throw "Value is zero";
}
catch (int i) {
cout << "CaughtOne " ;
}
catch (const char *str) {
cout << "CaughtString ";
}
}
int main() {
myFunction(1);
myFunction(2);
myFunction(0);
myFunction(3);
return 0;
}