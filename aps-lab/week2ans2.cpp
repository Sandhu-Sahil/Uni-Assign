#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct block
{
    int num;
    string color;

    block(){}
    block(int n, string c){
        num = n; 
        color = c;
    }
    void blockSet(int n, string c){
        num = n; 
        color = c;
    }
};

void printArr(block arr[], int size){
    for (int i = 0; i < size; i++){
        cout<<"( "<< arr[i].num << ", "<<arr[i].color<<" )"<<endl;
    }
    cout << endl;
}

void arrangeBlocks(block arr[], int size){
    vector<block> red,blue,yellow;

    for (int i = 0; i < size; i++)
    {
        if(arr[i].color == "red"){
            block temp(arr[i].num, arr[i].color);
            red.push_back(temp);
        }else if (arr[i].color == "blue"){
            block temp(arr[i].num, arr[i].color);
            blue.push_back(temp);
        }else if (arr[i].color == "yellow"){
            block temp(arr[i].num, arr[i].color);
            yellow.push_back(temp);
        }
    }

    for (int i = 0; i < red.size(); i++)
    {
        arr[i].blockSet(red[i].num, red[i].color);
    }
    for (int i = red.size(); i < (red.size() + blue.size()); i++)
    {
        arr[i].blockSet(blue[i - red.size()].num, blue[i - red.size()].color);
    }
    for (int i = (red.size() + blue.size()); i < (red.size() + blue.size() + yellow.size()); i++)
    {
        arr[i].blockSet(yellow[i - red.size() - blue.size()].num, yellow[i - red.size() - blue.size()].color);
    }
    
}

int main(){
    block pairs[5];
    pairs[0].blockSet(1, "blue");
    pairs[1].blockSet(3, "red");
    pairs[2].blockSet(4, "blue");
    pairs[3].blockSet(6, "yellow");
    pairs[4].blockSet(9, "red");

    cout<<"Before Sorting->"<<endl;
    printArr(pairs, 5);
    arrangeBlocks(pairs, 5);
    cout<<"After Sorting->"<<endl;
    printArr(pairs, 5);
}