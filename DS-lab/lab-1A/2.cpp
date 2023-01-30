// #include<iostream>
// using namespace std;
// template<class T>
// class mat
// {
//     public:
//     T arr[50][50];
//     T transpose[50][50];
//     int r,c;
//     int sum=0;

//     void takeinput()
//     {
//         cout<<"Enter the number of rows and columns : "<<endl;
//         cin>>r>>c;
//         cout<<"Enter the elements of the array : "<<endl;
//         for(int i=0;i<r;i++)
//     {
//         for(int j=0;j<c;j++)
//         {
//             cout<<"a["<<i<<"]["<<j<<"] : ";
//             cin>>arr[i][j];
//         }
//     }
//     }

//     void print_matrix()
//     {
//         cout<<endl;
//        for(int i=0;i<r;i++)
//     {
//         for(int j=0;j<c;j++)
//         {
//             cout<<arr[i][j];
//             cout<<"  ";
//         }
//         cout<<endl;
//     }
//     }
//     void calcsum()
//     {
//         for(int i=0;i<r;i++)
//     {
//         for(int j=0;j<c;j++)
//         {
//            sum=sum+arr[i][j];
//         }
//     }
//     cout<<"Sum of all terms = "<<sum<<endl;
//     }
//     void findtranspose()
//     {
//         for(int i=0;i<r;i++)
//     {
//         for(int j=0;j<c;j++)
//         {
//           transpose[j][i]=arr[i][j];
//         }
//     }
//     cout<<endl<<"Transpose of the given matrix : "<<endl;

//        for(int i=0;i<c;i++)
//     {
//         for(int j=0;j<r;j++)
//         {
//             cout<<transpose[i][j];
//             cout<<"  ";
//         }
//         cout<<endl;
//     }

//     }
// };
// int main()
// {
//     cout<<"Case of integer : "<<endl;
//     mat<int>x;
//     mat<float>y;
//     x.takeinput();
//     x.print_matrix();
//     x.calcsum();
//     x.findtranspose();
//      cout<<"Case of float : "<<endl;
//     y.takeinput();
//     y.print_matrix();
//     y.calcsum();
//     y.findtranspose();
//  return 0;
// }

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head,*tail;
void addnode()
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    int val;
    printf("Enter the value : ");
    scanf("%d",&val);
    newnode->data=val;
    if(head==NULL)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->next=head;
    }
}
void traversal()
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    struct node* prt=(struct node*)malloc(sizeof(struct node));
    p=head;
    while(p->next!=head)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
int main()
{
    for(int i=0;i<5;i++)
    {
        addnode();
    }
    traversal();
}
