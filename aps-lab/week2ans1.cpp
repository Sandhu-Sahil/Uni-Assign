#include <iostream>
using namespace std;

int findIndex(int arr[], int f, int end){
    int mid, start = 0;
    
    while (end - start > 1) {
        mid = (end + start) / 2;
        if (arr[mid] < f) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    if (arr[start] == f) {
        return start;
    }
    else if (arr[end] == f) {
        return end;
    }
    else {
        return -1;
    }
}

int main(){
    int array[] = {2, 3, 4, 5, 6, 7, 0, 0, 0, 0};
    int toFind = 5;
    int N = sizeof(array)/sizeof(array[1]);
    int found = findIndex(array, toFind, N);

    if (found == -1){
        cout<<"Not found"<<endl;
        return 0;
    }

    cout<<"Index:"<<found<<endl;

    return 0;
}