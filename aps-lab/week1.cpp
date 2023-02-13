#include <iostream>
using namespace std;

int swapCount = 0;
int compCount = 0;

void bubbleSort(char b, int arr[], int n)
{
    if (b == 'a'){
        int i, j;
        for (i = 0; i < n - 1; i++){
            for (j = 0; j < n - 1; j++){
                compCount += 1;
                if (arr[j] > arr[j + 1]){
                    swap(arr[j], arr[j + 1]);
                    swapCount += 1;
                }
            }
        }
    }
    else if ( b == 'd'){
        int i, j;
        for (i = 0; i < n - 1; i++){
            for (j = 0; j < n - 1; j++){
                compCount += 1;
                if (arr[j] < arr[j + 1]){
                    swap(arr[j], arr[j + 1]);
                    swapCount += 1;
                }
            }
        }
    }
}

void selectionSort(char s, int arr[], int n)
{
    if (s == 'a'){
        int i, j, min_idx;

        for (i = 0; i < n-1; i++)
        {
            min_idx = i;
            for (j = i+1; j < n; j++){
                compCount += 1;
                if (arr[j] < arr[min_idx]){
                    min_idx = j;
                }
            }

            if(min_idx!=i){
                swap(arr[min_idx], arr[i]);
                swapCount += 1;
            }
        }
    }
    else if (s == 'd'){
        int i, j, max_idx;

        for (i = 0; i < n-1; i++)
        {
            max_idx = i;
            for (j = i+1; j < n; j++){
                compCount += 1;
                if (arr[j] > arr[max_idx]){
                    max_idx = j;
                }
            }

            if(max_idx!=i){
                swap(arr[max_idx], arr[i]);
                swapCount += 1;
            }
        }
    }
}

void insertionSort(char c, int arr[], int n)
{
    if (c == 'a'){
        int i, key, j;
        for (i = 1; i < n; i++)
        {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                compCount += 1;
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            swapCount += 1;
            arr[j + 1] = key;
        }
    }
    else if (c == 'd'){
        int i, key, j;
        for (i = 1; i < n; i++)
        {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] < key)
            {
                compCount += 1;
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            swapCount += 1;
            arr[j + 1] = key;
        }
    }
}

int partition(char c, int arr[], int low, int high)
{
    if (c == 'a'){
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            compCount += 1;
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
                swapCount += 1;
            }
        }
        swap(arr[i + 1], arr[high]);
        swapCount += 1;
        return (i + 1);
    }
    else if (c == 'd'){
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            compCount += 1;
            if (arr[j] > pivot) {
                i++;
                swap(arr[i], arr[j]);
                swapCount += 1;
            }
        }
        swap(arr[i + 1], arr[high]);
        swapCount += 1;
        return (i + 1);
    }else{
        return 0;
    }
}


void quickSort(char q, int arr[], int low, int high)
{
    if (low < high) {

        int pi = partition(q, arr, low, high);

        quickSort(q, arr, low, pi - 1);
        quickSort(q, arr, pi + 1, high);
    }
}

void merge(char m, int array[], int const left, int const mid, int const right){

    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
 
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    for (auto i = 0; i < subArrayOne; i++){
        leftArray[i] = array[left + i];
    }
    
    for (auto j = 0; j < subArrayTwo; j++){
        rightArray[j] = array[mid + 1 + j];
    }
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0; 
    int indexOfMergedArray = left; 
    
    if (m == 'a'){
        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {

            compCount += 1;
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                swapCount += 1;
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else {
                swapCount += 1;
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
    }
    else if(m == 'd'){
        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {

            compCount += 1;
            if (leftArray[indexOfSubArrayOne] >= rightArray[indexOfSubArrayTwo]) {
                swapCount += 1;
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else {
                swapCount += 1;
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }
    }

    while (indexOfSubArrayOne < subArrayOne) {
        compCount += 1;
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        swapCount += 1;
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        compCount += 1;
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        swapCount += 1;
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
 
void mergeSort(char m, int array[], int const begin, int const end)
{
    if (begin >= end){
        return;
    }
 
    auto mid = begin + (end - begin) / 2;
    mergeSort(m, array, begin, mid);
    mergeSort(m, array, mid + 1, end);
    merge(m, array, begin, mid, end);
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void kPartAss(int arr[], int size){
    int evenCount, oddCount;
    if (size%2 == 0){
        evenCount = size/2;
        oddCount = size/2;
    }else{
        evenCount = size/2 + 1;
        oddCount = size/2;
    }
    int evenArr[evenCount];
    int oddArr[oddCount];
    int even = 0, odd = 0;
    for (int i = 0; i < size; i++){
        if (i%2 == 0){
            evenArr[even] = arr[i];
            even++;
        }else{
            oddArr[odd] = arr[i];
            odd++;
        }
    }
    insertionSort('a', evenArr, evenCount);
    insertionSort('d', oddArr, oddCount);
    // printArray(evenArr, evenCount);
    // printArray(oddArr, oddCount);

    even = 0;
    odd = 0;
    for (int i = 0; i < size; i++)
    {
        if(even < evenCount){
            arr[i] = evenArr[even];
            even++;
        }else{
            arr[i] = oddArr[odd];
            odd++;
        }        
    }
}

void lPartAss(int arr[], int size){
    int firstCount, secondCount;
    if (size%2 == 0){
        firstCount = size/2;
        secondCount = size/2;
    }else{
        firstCount = size/2 + 1;
        secondCount = size/2;
    }
    int firstArr[firstCount];
    int secondArr[secondCount];
    int first = 0, second = 0;
    for (int i = 0; i < size; i++)
    {
        if (first < firstCount){
            firstArr[first] = arr[i];
            first++;
        }else{
            secondArr[second] = arr[i];
            second++;
        }
    }
    // printArray(firstArr,firstCount);
    // printArray(secondArr,secondCount);

    first = 0;
    second = 0;
    for (int i = 0; i < size; i++)
    {
        if (firstArr[first] > secondArr[second])
        {
            arr[i] = secondArr[second];
            second++;
        }else{
            arr[i]= firstArr[first];
            first++;
        }
    }
}

int main()
{
    char order = 'a'; // ascending 'a' decending 'd'

    int arrB[] = { 1,2,3,4,5,6 };
    int N = sizeof(arrB) / sizeof(arrB[0]);
    bubbleSort(order, arrB, N);
    cout << "Bubble Sort Swaps: "<<swapCount<<endl;
    cout << "Bubble Sort Comparisons: "<<compCount<<endl;
    printArray(arrB, N);
    cout<<endl;

    swapCount = 0;
    compCount = 0;
    int arrS[] = { 1,2,3,4,5,6 };
    N = sizeof(arrS) / sizeof(arrS[0]);
    selectionSort(order, arrS, N);
    cout << "Selection Sort Swaps: "<<swapCount<<endl;
    cout << "Selection Sort Comparisons: "<<compCount<<endl;
    printArray(arrS, N);
    cout<<endl;

    swapCount = 0;
    compCount = 0;
    int arrI[] = { 1,2,3,4,5,6 };
    N = sizeof(arrI) / sizeof(arrI[0]);
    insertionSort(order, arrI, N);
    cout << "Insertion Sort Swaps: "<<swapCount<<endl;
    cout << "Insertion Sort Comparisons: "<<compCount<<endl;
    printArray(arrI, N);
    cout<<endl;

    swapCount = 0;
    compCount = 0;
    int arrQ[] = { 1,2,3,4,5,6 };
    N = sizeof(arrQ) / sizeof(arrQ[0]);
    quickSort(order, arrQ, 0, N - 1);
    cout << "Quick Sort Swaps: "<<swapCount<<endl;
    cout << "Quick Sort Comparisons: "<<compCount<<endl;
    printArray(arrQ, N);
    cout<<endl;

    swapCount = 0;
    compCount = 0;
    int arrM[] = { 1,2,3,4,5,6 };
    N = sizeof(arrM) / sizeof(arrM[0]);
    mergeSort(order, arrM, 0, N - 1);
    cout << "Merge Sort Swaps: "<<swapCount<<endl;
    cout << "Merge Sort Comparisons: "<<compCount<<endl;
    printArray(arrM, N);
    cout<<endl;

    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    N = sizeof(arr) / sizeof(arr[0]);
    cout<<"k-> Part even places ascending order and odd places decending order"<<endl;
    cout<<"input:";
    printArray(arr, N);
    kPartAss(arr, N);
    cout<<"output:";
    printArray(arr, N);
    cout<<endl;

    int arr2[] = { 2 ,3 , 8 ,-1 ,7 ,10 }; //{-4 , 6, 9 , -1 , 3 };
    cout<<"l-> part of assignment"<<endl;
    N = sizeof(arr2) / sizeof(arr2[0]);
    cout<<"input:";
    printArray(arr2, N);
    lPartAss(arr2, N);
    cout<<"output:";
    printArray(arr2, N);
    cout<<endl;

    return 0;
    //testing vs code by sahil sandhu
}
