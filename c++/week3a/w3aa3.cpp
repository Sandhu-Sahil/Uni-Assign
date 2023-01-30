#include<iostream>
using namespace std;

class Complex
{
    public:
        int real;
        int imag;
        void setvalue()
        {
            cout<<"Input real part"<<endl;
            cin>>real;
            cout<<"Input imagnary part"<<endl;
            cin>>imag;
        }
        void display()
        {
            cout<<real<<"+"<<imag<<"i"<<endl;
        }    
        void sum(Complex c1, Complex c2)
        {
            real=c1.real+c2.real;
            imag=c1.imag+c2.imag;
        }
        void product(Complex c1, Complex c2)
        {
            real=(c1.real*c2.real)-(c1.imag*c2.imag);
            imag=(c1.real*c2.imag)+(c1.imag*c2.real);
        }
};
int main()
{
    Complex c1,c2,s12,p12;
    cout<<"Enter real and imaginary part of first complex number"<<endl;
    c1.setvalue();
    cout<<"Enter real and imaginary part of second complex number"<<endl;
    c2.setvalue();
    cout<<"Sum of two complex numbers is"<<endl;
    s12.sum(c1,c2);
    s12.display();
    cout<<"Product of two complex numbers is"<<endl;
    p12.product(c1,c2);
    p12.display();
    return 0;
}