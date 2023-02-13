#include <iostream>
using namespace std;

int findElement(int arr[], int pviot){
    if (pviot%2 == 0){
        if (arr[pviot + 1] == arr[pviot]){
            int toReturn = findElement(arr, 3*pviot/2);
            return toReturn;
        } else if (arr[pviot - 1] == arr[pviot]){
            int toReturn = findElement(arr, pviot/2);
            return toReturn;
        }else{
            return pviot;
        }
    }else{
        if (arr[pviot + 1] == arr[pviot]){
            int toReturn = findElement(arr, pviot/2);
            return toReturn;
        } else if (arr[pviot - 1] == arr[pviot]){
            int toReturn = findElement(arr, 3*pviot/2);
            return toReturn;
        }else{
            return pviot;
        }
    }
    // if (arr[pviot + 1] == arr[pviot]){
    //     findElement(arr, pviot/2);
    // } else if (arr[pviot - 1] == arr[pviot]){
    //     findElement(arr, 3*pviot/2);
    // }else{
    //     return pviot;
    // }
    // return pviot;
}

int main(){
    int arr[] = {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8};

    int arrLen = sizeof(arr)/sizeof(arr[1]);
    if(arrLen%2 == 0){
        cout<<"No single element"<<endl;
    }else{
        int x = findElement(arr, arrLen/2);
        cout<<"Single element is "<<arr[x]<<endl;
    }
    return 0;
}
