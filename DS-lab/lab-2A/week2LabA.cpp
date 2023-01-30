#include<cstdlib>
#include<iostream>
using namespace std;

int* createArray(int l){
    int* arr = new int[l];
    for (int i = 0; i < l; i++){
        arr[i] =rand()%100;
        // int a;
        // cin>>a;
        // arr[i]=a;
    }
    return arr;
}

int* createResult(int* a, int l){
    for (int i = 0; i < (l*l); i++){
        int index;
        for (int j = 0; j < l; j++){
            if (a[j]%2 != 0){
                if((j+1) > l ){
                    break;
                }
                if (a[j+1]%2 == 0){
                    index = j;
                    break;
                }else{
                    index = 2147483647;
                }
            }
        }
        if (index == 2147483647){continue;}
        int temp = a[index];
        a[index] = a[index + 1];
        a[index + 1] = temp;
    }
    return a;
}

int main(){
    cout<<"Enter length of array: ";
    int length;
    cin>>length;
    int* array = createArray(length);
    int* arrayResult = createResult(array,length);

    for (int i = 0; i < length ; i++){
        cout<<arrayResult[i]<<" ";
    }
}