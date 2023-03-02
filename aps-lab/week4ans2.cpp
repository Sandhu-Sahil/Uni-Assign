#include <cstring>
#include <iostream>
using namespace std;

bool isWord(string& str, string dic[], int size)
{
	for (int i = 0; i < size; i++)
		if (str.compare(dic[i]) == 0)
			return true;
	return false;
}

void findWordsUtil(char **boggle, int r, int c, bool **visited, int i, int j, string& str, string dic[], int size)
{
	visited[i][j] = true;
	str = str + boggle[i][j];

	if (isWord(str,dic,size))
		cout << str << endl;

	for (int row = i - 1; row <= i + 1 && row < r; row++)
		for (int col = j - 1; col <= j + 1 && col < c; col++)
			if (row >= 0 && col >= 0 && !visited[row][col])
				findWordsUtil(boggle, r, c, visited, row, col, str, dic, size);

	str.erase(str.length() - 1);
	visited[i][j] = false;
}

void findWords(char **boggle, int row, int column, string dic[], int size)
{
	bool **visited;
	visited = new bool *[column];
	for(int i = 0; i <row; i++){
        visited[i] = new bool[row];
    }

	string str = "";

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
			findWordsUtil(boggle, row, column, visited, i, j, str, dic, size);
}

void printDictionary(string dic[], int size){
    cout<<"[";
    for (int i =0; i<size; i++){
        cout<<dic[i]<<", ";
    }
    cout<<" ]"<<endl;
}

void printMatrix(int row, int column, char **mat){
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

int main()
{
    int n =0;
    cout<<"Input the number of words in dictionary: ";
    cin>>n;

    string dictionary[n];
    cout<<"Input "<<n<<" words for dictionary"<<endl;
    for (int i = 0; i < n; i++){
        cin>>dictionary[i];
    }
    printDictionary(dictionary, n);

    cout<<"Input R (rows) and C (column) for the matrix"<<endl;
    int r=0, c=0;
    cout<<"Input R : ";
    cin>>r;
    cout<<"Input C : ";
    cin>>c;
	char **boggle;
    boggle = new char *[c];
    for(int i = 0; i <r; i++){
        boggle[i] = new char[r];
    }

    cout<<"Input matrix:"<<endl;
    for (int i =0; i<r; i++){
        for (int j =0; j<c; j++){
            cout<<"Input ["<<i<<"]["<<j<<"] : ";
            cin>>boggle[i][j];
        }
    }
    printMatrix(r, c, boggle);

	cout << "Following words of dictionary are present\n";
	findWords(boggle, r, c, dictionary, n);
	return 0;
}
