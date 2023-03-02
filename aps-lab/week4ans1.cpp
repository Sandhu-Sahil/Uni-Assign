#include <iostream>
using namespace std;

bool checkPath(int n, int path[]){
    for (int i = 0; i < n; i++){
        if (path[i] == 0){
            return false;
        }
    }
    return true;
}

void printPath(int n , int path[]){
    for (int i = 0; i < n; i++){
        cout<<"->"<<path[i];
    }
}

void getHamiltonianPath(int n, int m, int current, bool **arr, int path[], int pathInt){
    if (current > n){
        return;
    }

    bool check = true;

    for (int i = 0; i < m; i++){
        if (arr[current][m] == true){
            path[pathInt] = current+1;
            pathInt++;
            path[pathInt] = m+1;

            check == false;
        }
        if (pathInt != 0) {
            pathInt++;
            current = m;
            getHamiltonianPath(n,m,current,arr,path,pathInt);
        }
    }

    if (checkPath(n,path)) {
        current++;
        getHamiltonianPath(n,m,current,arr,path,pathInt);
    }

    if (checkPath(n,path)){
        printPath(n,path);
        return;
    }
}

int main (){
    int n = 0, m = 0;
    cout<<"Input n and m: "<<endl;
    cout<<"input n: ";
    cin>>n;
    cout<<"input m: ";
    cin>>m;

    bool **mat;
    mat = new bool *[m];
    for (int i = 0; i < n; i++){
        mat[i] = new bool[n];
    }

    cout<<"Input number of edges: ";
    int edges = 0;
    cin>>edges;
    for (int i = 0; i < edges; i++){
        int x = 0, y = 0;
        cout<<"Input 2 points"<<i+1<<"edge :"<< endl;
        cout<<"Point 1 : ";
        cin>>x;
        cout<<"Point 2 : ";
        cin>>y;
        mat[x-1][y-1]=true;
    }

    int path[n] = {0};

    getHamiltonianPath(n,m,0,mat,path,0);

    return 0;
}
