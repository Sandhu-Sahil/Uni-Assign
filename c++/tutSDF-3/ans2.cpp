#include<iostream>
#include<string>
using namespace std;

class Bank
{
    public:
        string name;
        string accNo;
        char accType;
        float balance;
        void initialize()
        {
            getline(cin,name);
            getline(cin,accNo);
            cin>>accType;
            cin>>balance;
        }
        void deposit(float amount)
        {
            balance = balance + amount;            
        }
        void withdraw(float amount)
        {
            if (balance < 1000)
            {
                cout<<"Minimum balance reached"<<endl;
            }
            else
            {
                if((balance-amount) <= 1000)
                {
                    cout<<"You can only withdraw "<<balance - 1000<<" because your balance is "<<balance<<endl;
                    balance = 1000;
                }
                else
                {
                    balance = balance - amount;
                }
            }
        }
        void display()
        {
            cout<<name<<"\n"<<accNo<<"\n"<<accType<<"\n"<<balance<<endl;
        }
}

int main()
{
    Bank account[10];
}