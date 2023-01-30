#include<iostream>
#include<map>
#include<string.h>
#include<math.h>
#include <fstream>
using namespace std;

//-----global parameters----- 
int p; 
char c;
//---------------------------
class sphere{
    public:
    double R;
    double r;
    double n;
    const double e= 1.6 * pow(10,-19);
    const double E= 8.8541 * pow(10,-12);
    sphere(){
        cout<<" A VIRTUAL SPHERE WITHOUT BOUNDARIES CREATED "<<endl;
    }

    void setparameter_sphere(){
        int a,b,c;
        cout<<"ENTER THE RADIUS OF THE SPHERE ( <100 )"<<endl;
        cin>>R;
        cout<<"ENTER THE DISTANCE OF POINT FROM CENTRE WHERE YOU HAVE TO CALCULATE ELECTRIC FIELD "<<endl;
        cin>>r;
        cout<<"ENTER A NATURAL NO. WHICH WILL BE A MULTIPLE OF ELECTRONIC CHARGE "<<endl;
        cin>>n;
    }

    double efield_sphere(){
          if (c=='a'){
              cout<<"CALCULATING ELECTRIC FIELD OF SPHERE OF NON CONDUCTING TYPE... "<<endl;
              if(r<R){
                  cout<<(n*e*r)/(4*(3.14)*E*(R*R*R));
                  return (r/(R*R*R));
              }

              else if(r==R){
                  cout<<(n*e)/(4*(3.14)*E*(R*R));
                  return (1.00/(R*R));
              }

              else if(r>R){
                  cout<<(n*e)/(4*(3.14)*E*(r*r));
                  return (1.00/(r*r));
              }
          }

          else if(c=='b'){
              cout<<"CALCULATING ELECTRIC FIELD OF SPHERE OF CONDUCTING TYPE... "<<endl;
              if(r<R){
                  cout<<0;
                  return 0.00; 
              }

              else if(r==R){
                  cout<<(n*e)/(4*(3.14)*E*(R*R));
                  return (1.00/(R*R));
              }

              else {
                  cout<<(n*e)/(4*(3.14)*E*(r*r));
                  return (1.00/(r*r));
              }
    }
    }
};

class cylinder{
    public:
    double R;
    double r;
    double n;
    double h;
    const double e= 1.6 * pow(10,-19);
    const double E= 8.8541 * pow(10,-12);
    cylinder(){
        cout<<" A VIRTUAL CYLINDER WITHOUT BOUNDARIES CREATED "<<endl;
    }

    void setparameter_cylinder(){
        int a,b,c,d;
        cout<<"ENTER THE RADIUS OF THE CYLINDER ( <100 )"<<endl;
        cin>>R;
        cout<<"ENTER THE DISTANCE OF POINT FROM CENTRE WHERE YOU HAVE TO CALCULATE ELECTRIC FIELD "<<endl;
        cin>>r;
        cout<<"ENTER A NATURAL NO. WHICH WILL BE A MULTIPLE OF ELECTRONIC CHARGE "<<endl;
        cin>>n;
        cout<<"ENTER THE HEIGHT OF THE CYLINDER "<<endl;
        cin>>h;

    }

    double efield_cylinder(){
          if (c=='a'){
              cout<<"CALCULATING ELECTRIC FIELD OF CYLINDER OF NON CONDUCTING TYPE... "<<endl;
              if(r<R){
                  cout<<(n*e*r)/(2*(3.14)*E*h*(R*R)); 
                  return (r/(R*R)); 
              }

              else if(r==R){
                  cout<<(n*e)/(2*(3.14)*E*R*h);
                  return (1.00/R);
              }

              else if(r>R){
                  cout<<(n*e)/(2*(3.14)*E*r*h);
                  return (1.00/r);
              }
          }

          else if(c=='b'){
              cout<<"CALCULATING ELECTRIC FIELD OF CYLINDER OF CONDUCTING TYPE... "<<endl;
              if(r<R){
                  cout<<0; 
                  return 0;
              }

              else if(r==R){
                  cout<<(n*e)/(2*(3.14)*E*R*h);
                  return (1.00/R);
              }

              else if(r>R){
                  cout<<(n*e)/(2*(3.14)*E*r*h);
                  return (1.00/r);
              }
    }
    }
};

void ask_object(void){
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|        HELLO PHYSICS ENTHUSIASTS !!! I AM ELECTRO , SPECIFICALLY DESIGNED TO COMPUTE ELECTRIC FIELD OF SPHERICAL AND CYLINDRICAL SYMMETRIES      |"<<endl;
    cout<<"|                                             -----So What do you want to choose -----                                                             |"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<"|    LIST OF OBJECTS YOU CAN CHOOSE          |"<<endl;
    cout<<"|        Press 1 for CYLINDER                |"<<endl;
    cout<<"|        Press 2 for SPHERE                  |"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cin>>p;
    map<int,string> m;
    m.insert({1,"CYLINDER"});
    m.insert({2,"SPHERE"});

    if(p!=1 && p!=2){
        cout<<" INVALID INPUT "<<endl;
        cout<<" ENTER AGAIN   "<<endl;
        ask_object();
    }

    else{
        if(p==1){
            cout<<"YOU CHOSE "<<m[p]<<endl;
        }
        
        else{
            cout<<"YOU CHOSE "<<m[p]<<endl;
        }
    }

}

void ask_type(){
    cout<<" ENTER THE TYPE OF OBJECT "<<endl;
    cout<<"------------------------------------------------------"<<endl;
    cout<<"|          Press a for NON CONDUCTING TYPE            |"<<endl;
    cout<<"|          Press b for CONDUCTING TYPE                |"<<endl;
    cout<<"-------------------------------------------------------"<<endl;
    cin>>c;
    map<char,string> t;
    t.insert({'a',"NON CONDUCTING TYPE"});
    t.insert({'b',"CONDUCTING TYPE"});

    if(c!='a' && c!='b'){
        cout<<" INVALID INPUT "<<endl;
        cout<<" ENTER AGAIN   "<<endl;
        ask_type();
    }

    else{
        if(c=='a'){
            cout<<"YOU CHOSE "<<t[c]<<endl;
        }
        
        else{
            cout<<"YOU CHOSE "<<t[c]<<endl;
        }
    }

}

void Graph(sphere &a)
{
    int r[200];
    int j = 0;
    for (int i = 0; i < 200; i++)
    {
        r[i] = i;
    }
    double e[200];
    for (int i = 0; i < 200; i++)
    {
        a.r = r[i];
        e[i] = a.efield_sphere();
    }
    
    ofstream fout;
    fout.open("transfer.txt", ios::out);
    fout.clear();
    for (int i = 0; i < 200 ; i++)
    {
        fout<<r[i]<<",";
    }
    fout<<"\n";
    for (int i = 0; i < 200; i++)
    {
        fout<<e[i]<<",";
    }
    fout.close();
    system("cls");
    system("Python plot.py ok go");
    system("PAUSE");
}

void Graph(cylinder &a)
{
    int r[200];
    int j = 0;
    for (int i = 0; i < 200; i++)
    {
        r[i] = i;
    }
    double e[200];
    for (int i = 0; i < 200; i++)
    {
        a.r = r[i];
        e[i] = a.efield_cylinder();
    }
    
    ofstream fout;
    fout.open("transfer.txt", ios::out);
    fout.clear();
    for (int i = 0; i < 200 ; i++)
    {
        fout<<r[i]<<",";
    }
    fout<<"\n";
    for (int i = 0; i < 200; i++)
    {
        fout<<e[i]<<",";
    }
    fout.close();
    system("cls");
    system("Python plot.py ok go");
    system("PAUSE");
}

int main(){
    ask_object();
    ask_type();
    if(p==1){
        cylinder c1;
        c1.setparameter_cylinder();
        c1.efield_cylinder();
        cout<<"\n\npress 'g' for the graph.......";
        char g;
        cin>>g;
        if (g=='g')
        {
            Graph(c1);
        }
    }

    else if(p==2){
        sphere s1;
        s1.setparameter_sphere();
        s1.efield_sphere();
        cout<<"\n\npress 'g' for the graph.......";
        char g;
        cin>>g;
        if (g=='g')
        {
            Graph(s1);
        }
    }

    return 0;

}