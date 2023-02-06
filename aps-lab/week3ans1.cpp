#include <iostream>
using namespace std;

int findInt(int num, int temp){
    int x = temp * temp * temp;

    if (x > num){
        findInt(num, temp/2);
    }else {
        int check = (temp + 1) * (temp + 1) * (temp + 1);
        if (check > num){
            return temp;
        }else{
            int check2 = 3*temp/2;
            if(check2 == 1){
                findInt(num, temp+1);
            }else{
                findInt(num, check2);
            }
        }
    }
}

int main(){
    int n;
    cout<<"Input integer : ";
    cin>>n;

    int x = findInt(n,n/2);

    cout<<"Number x is "<<x<<endl;

    return 0;
}
