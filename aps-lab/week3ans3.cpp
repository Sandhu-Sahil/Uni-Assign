#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    int x;
    int y;
    float distance;

    point(){}
    point(int xtemp, int ytemp){
        x = xtemp;
        y = ytemp;
        distance = sqrt(pow(x,2.0)+pow(y,2.0));
    }
};

void arrangeCo(vector <point> arr, int size){
    for (int i = 0; i < size; i++)
    {
        
    }
}

int main(){
    cout<<"Input number of cordinates you want to enter: ";
    int n;
    cin>>n;
    
    vector <point> coOrdinates;
    for (int i = 0; i < n; i++)
    {
        cout<<"For cordinate "<<i+1<<endl;
        cout<<"input x: ";
        int x;
        cin>>x;
        cout<<"input y: ";
        int y;
        cin>>y;

        point temp(x,y);
        coOrdinates.push_back(temp);
    }

    cout<<"Input k (number of minimum distances you need) [k<number of co-ordinates]: ";
    int k;
    cin>>k;

    arrangeCo(coOrdinates, n);


    return 0;
}