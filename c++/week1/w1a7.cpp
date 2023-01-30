#include <iostream>
#include<string>
using namespace std;
struct Person
{
    string name;
    int age;
    struct S //Salary
    {
        float basic;
        float hra;
        float BA;
        float FA;
        float SA;
    }S;
};
int main()
{
    Person p1;

    cout << "Enter Full name: ";
    getline(cin , p1.name );
    cout << "Enter age: ";
    cin >> p1.age;
    cout << "Enter Basic: ";
    cin >> p1.S.basic;
    cout << "Enter HRA: ";
    cin >> p1.S.hra;
    cout << "Enter BOOK Allowance: ";
    cin >> p1.S.BA;
    cout << "Enter Furniture Allowance: ";
    cin >> p1.S.FA;
    cout << "Enter Special Allowance: ";
    cin >> p1.S.SA;

    cout << "\nDisplaying Information." << endl;

    cout << "Name: " << p1.name << endl;
    cout <<"Age: " << p1.age << endl;
    cout << "Salary: " << (p1.S.basic + p1.S.hra + p1.S.BA + p1.S.FA + p1.S.SA);
    
    return 0;
} 
