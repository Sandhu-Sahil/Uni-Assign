#include<iostream>
using namespace std;

class Student
{
    public:
        float marks;
        Student(int x)
        {
            marks = x;
        }
        Student()
        {
            //for average
        }
        float calculateAverage(Student s1, Student s2)
        {
            float avg = (s1.marks + s2.marks)/2;
            return avg;
        }
};

int main()
{
    Student st1(86), st2(92), avg;
    cout<<"Average marks of these students is "<<avg.calculateAverage(st1, st2)<<endl;
    return 0;
}