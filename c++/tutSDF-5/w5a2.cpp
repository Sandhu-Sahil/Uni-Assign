#include <iostream>
using namespace std;

class Count {
   private:
    int value;

   public:

    Count() : value(5) {}

    void operator ++ () {
        ++value;
    }

    void operator ++ (int) {
        value++;
    }

    void operator << (int a) {
        value<<a;
    }

    void operator >> (int a) {
        value>>a;
    }

    void operator == (Count a){
        if (value == a.value){
            cout<<"True"<<endl;
        }
        else{
            cout<<"False"<<endl;
        }
    }

    void display() {
        cout << "Count: " << value << endl;
    }
};

int main() {
    Count count1;

    count1++;
    count1.display();

    ++count1;
    count1.display();

    Count count2;

    count1 == count2;

    count1>>1;
    count1.display();

    count1<<1;
    count1.display();
    
    return 0;
}