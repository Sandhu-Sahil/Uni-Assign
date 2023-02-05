#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void mergeOrArangeDistributedArray(int arr[], int start1, int end1, int start2, int end2){
    while(true){
        if (start1 > end1){
            return;
        }
        if (start2 > end2){
            return;
        }
        if (arr[start1] > arr[start2]){
            swap(arr[start1],arr[start2]);
            start1++;
            start2++;
            continue;
        }else{
            start1++;
            start2++;
        }
    }
}

void algo__1(int arr[], int start, int end){
    int n = end - start;
    
    cout<<start<<end<<"fuck"<<arr<<endl;
    printArray(arr, end);

    if ((n == 2) && (arr[start] > arr[start + 1])){
        swap(arr[start], arr[start + 1]);
    }else if (n > 2){
        int m = 2*n/3;
        algo__1(arr, start, (end - m));
        algo__1(arr, (end - m), end); // modification 1) as last element is not touched (end - 1) replaced with end
        // algo__1(arr, start, (end - m)); modification 2) (don't need this to be done twice)

        mergeOrArangeDistributedArray(arr, start, end-m, end-m, end); // modification 3) arranging the distributed array
    }
}

int main (){
    int array[] = {2, 1, 5, 4, 3};

    int n = sizeof(array)/sizeof(array[1]);
    algo__1(array, 0 , n);

    printArray(array, n);

    return 0;
}