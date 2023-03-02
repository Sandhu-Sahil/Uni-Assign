#include<iostream>
using namespace std;

void showColors(int color[], int V) {
   cout << "Assigned Colors are: " <<endl;
   for (int i = 0; i < V; i++)
      cout << color[i] << " ";
   cout << endl;
}

bool isValid(int v,int color[], int c, bool **graph, int V) {
   for (int i = 0; i < V; i++)
      if (graph[v][i] && c == color[i])
         return false;
   return true;
}

bool graphColoring(int colors, int color[], int vertex, bool **graph, int V) {
   if (vertex == V)
      return true;

   for (int col = 1; col <= colors; col++) {
      if (isValid(vertex,color, col, graph, V)) {
         color[vertex] = col;
         if (graphColoring (colors, color, vertex+1, graph, V) == true)
            return true;

         color[vertex] = 0;
      }
   }
   return false;
}

bool checkSolution(int m, bool **graph, int V) {
   int *color = new int[V];

   for (int i = 0; i < V; i++)
      color[i] = 0;

   if (graphColoring(m, color, 0, graph, V) == false) {
      cout << "Solution does not exist.";
      return false;
   }
   showColors(color, V);
   return true;
}

void printMatrix(int row, int column, bool **mat){
    cout<<"{ ";
    for(int i = 0; i < row; i++){
        cout<<"{";
        for (int j = 0 ; j < column; j++){
            cout<<mat[i][j]<<", ";
        }
        cout<<"}"<<endl;
    }
    cout<<"}"<<endl;
}

int main() {
   int colors = 3;

   int n, e;
   cout<<"Input number of points of graph : ";
   cin>>n;
   cout<<"Input number of edges : ";
   cin>>e;

   bool **graph;
   graph = new bool *[n];
   for (int i = 0; i < n; i++){
    graph[i] = new bool[n];
   }

    printMatrix(n,n,graph);
   cout<<"Input edges for graph:"<<endl;
   for (int i =0; i<e; i++){
        int x=0,y=0;
        cout<<"Input points of the edge"<<endl;
        cout<<"x = ";
        cin>>x;
        cout<<"y = ";
        cin>>y;
        graph[x][y] = true;
   }
    printMatrix(n,n,graph);

   checkSolution (colors, graph, n);
}
