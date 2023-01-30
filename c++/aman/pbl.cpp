#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>
using namespace std;

//global variables----------------
int p=1;
int t=1;
//----------------------------------

void graphplot(float *x, float *y, int a)
{
    ofstream fout;
    fout.open("transfer.txt", ios::out);
    fout.clear();
    for (int i = 0; i < a ; i++)
    {
        fout<<x[i]<<",";
    }
    fout<<"\n";
    for (int i = 0; i < a; i++)
    {
        fout<<y[i]<<",";
    }
    fout.close();
    system("Python plot.py ok go");
    system("PAUSE");
}

int main(){
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"|                     PHYSICS LAB PROJECT                          |"<<endl<<endl;
    cout<<"|      -TEAM MEMBERS-                                              |"<<endl;
    cout<<"|  1.) AMAN DIXIT                                                  |"<<endl;
    cout<<"|  2.) SARTHAK CHAWLA                                              |"<<endl;
    cout<<"|  3.) ADITYA JAIN                                                 |"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;

    cout<<endl<<endl<<endl;

    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"|                      INVERSE SQUARE LAW                         |"<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;

    cout<<endl<<endl;
    cout<<"--------------------------------------------------------------------------------------------------"<<endl;
    cout<<"| A photovoltaic cell is semiconductor which is able to convert radiant energy into               |"<<endl;
    cout<<"| voltage. In the initial forms, these device were known as barrier layer cells but now these are |"<<endl;
    cout<<"| called solar cells as they are generally used to convert solar energy electrical energy.        |"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------"<<endl;

    cout<<endl<<endl;
    cout<<"--------------------------------------------------------------------------------------------------"<<endl;
    cout<<"| The basic principle of these cells is that when a radiant energy is incident on semiconductor, |"<<endl;
    cout<<"| produces electron-hole pairs and if the radiant energy exceeds the band gap of the             |"<<endl;
    cout<<"| semiconductor, the recombination of electron hole pair can not take place as in this case the  |"<<endl;
    cout<<"| electron is conducted to conduction band. If the external circuit is completed with the        |"<<endl;
    cout<<"| semiconductor, the current starts flowing because of electron hole creation by radiant energy. |"<<endl;
    cout<<"| The voltage this generated dependence directly on band gap of semiconductor.                   |"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------"<<endl;

    cout<<endl<<endl;

    cout<<"---------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"| If I be the luminous intensity of an electric lamp and E the illumines at a point distance d    |"<<endl;
    cout<<"| from it, then according to inverse square law E = 1/(d**2).                                           |"<<endl;
    cout<<"| If light from the lamp be incident on the photo - voltaic cell placed at a distance d from it and if  |"<<endl;
    cout<<"| theta be the corresponding deflection shown by the galvanometer (or μ-ammeter) then                  |"<<endl;
    cout<<"|                                   theta is directly proportional to I                                 |"<<endl;
    cout<<"|                                or theta is directly proportional to 1/(d**2)                          |"<<endl;
    cout<<"|                                or theta x (d**2) = constant                                           |"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------|"<<endl;

    cout<<endl;

    int n;
    cout<<"ENTER THE NO. OF READINGS "<<endl;
    cin>>n;
    float distarr[n];
    float currarr[n];

    cout<<endl;

    cout<<"ENTER THE DISTANCE VALUES "<<endl;
    for(int i=0;i<n;i++){
        cout<<p<<".)";
        cin>>distarr[i];
        p++;
    }

    cout<<endl;

    cout<<"ENTER THE CURRENT VALUES "<<endl;
    for(int i=0;i<n;i++){
        cout<<t<<".)";
        cin>>currarr[i];
        t++;
    }

    cout<<endl;

    cout<<" OBSERVATIONS "<<endl;

    cout<<"---------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|  S.NO    |     DISTANCE(IN CM)     |       1/(r**2)        |         CURRENT(theta)(in mA)      |"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------"<<endl;
    for(int i=1;i<=n;i++){
        cout<<"|  "<<i<<setw(12)<<"|    "<<distarr[i-1]<<setw(22)<<"|"<<setw(8)<<1/(pow(distarr[i-1],2))<<setw(14)<<"|"<<setw(8)<<currarr[i-1]<<setw(28)<<"|"<<endl;
    }
    cout<<"---------------------------------------------------------------------------------------------------"<<endl;

    cout<<" PLOTTING THE GRAPH BETWEEN (1/r^2) and theta ... "<<endl;
    
    for (int i = 0; i < n; i++)
    {
        distarr[i] = 1/(pow(distarr[i],2));
    }
    system("PAUSE");
    graphplot(currarr, distarr, n);    

}