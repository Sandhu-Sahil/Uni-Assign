#include <iostream>
#include <string>
using namespace std;

class Books
{
    public:
        string bookno;
        string bookname;
        string author;
        string publisher;
        string price;
        int copies;

        void input()
        {
            getline(cin, bookno);
            getline(cin, bookname);
            getline(cin, author);
            getline(cin, publisher);
            getline(cin, price);
            cin>>copies;
        }
        void display()
        {
            cout<< bookno<<endl;
            cout<<bookname<<endl;
            cout<<author<<endl;
            cout<<publisher<<endl;
            cout<<price<<endl;
            cout<<copies<<endl;
        }
        void returnbook()
        {
            copies++;
            cout<<"copy returned successfully";
        }
        void issue()
        {
            if (copies == 0)
            {
                cout<<"no copies available of this book"<<endl;
            }
            else
            {
               copies--; 
               cout<<"Copy sucessfully issued"<<endl;
            }
        }
};

int main()
{
    cout<<"Input no of books you want to add in library"<<endl;
    int n;
    cin>>n;
    Books books[n];
    for (int i = 0; i < n; i++)
    {
        cout<<i<<" book"<<endl;
        books[i].input();
    }
    cout<<"Input book no to display"<<endl;
    int a;
    cin>>a;
    books[a].display();
    cout<<"Input book number to issue that book"<<endl;
    int b;
    cin>>b;
    books[b].issue(); 
    cout<<"Input book number to return that book"<<endl;
    int c;
    cin>>c;
    books[c].issue();
    return 0;
}