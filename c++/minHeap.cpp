#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i)
{
	int smallest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (l < n && arr[l] < arr[smallest])
		smallest = l;

	if (r < n && arr[r] < arr[smallest])
		smallest = r;

	if (smallest != i) {
		swap(arr[i], arr[smallest]);
		heapify(arr, n, smallest);
	}
}

void buildHeap(int arr[], int N)
{
    int startIdx = (N / 2) - 1;
 
    // Perform reverse level order traversal
    // from last non-leaf node and heapify
    // each node
    for (int i = startIdx; i >= 0; i--) {
        heapify(arr, N, i);
    }
}

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void deleteRoot(int arr[], int& n)
{
    int lastElement = arr[n - 1];
 
    arr[0] = lastElement;
 
    n = n - 1;
 
    heapify(arr, n, 0);
}

void insertNode(int arr[], int& n, int Key)
{
    n = n + 1;
 
    arr[n - 1] = Key;
 
    heapify(arr, n, n - 1);
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7, 17, 16 };
	int n = sizeof(arr) / sizeof(arr[0]);

	buildHeap(arr, n);
    int key = 15;
	printArray(arr, n);
 
    insertNode(arr, n, key);
	buildHeap(arr, n);
	printArray(arr, n);

    deleteRoot(arr, n);
    buildHeap(arr, n);
    printArray(arr, n);

	heapSort(arr, n);
	cout << "Sorted array is \n";
	printArray(arr, n);
}