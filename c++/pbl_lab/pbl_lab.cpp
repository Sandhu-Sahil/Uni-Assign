#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <fstream>

//For png graph formation

using namespace std;

class Case
{
    public:
    double distance;
    double current;
    double constant;

    public:
        Case(){}
        Case(double a, double b){
            distance = a;
            current = b;
            constant = a * a* b;
        }
        void setDistance()
        {
            cout<<"Input Distance (m) for this case:"<<endl;
            cin>>distance;
        }
        void setCurrent()
        {
            cout<<"Input Current (.uA) for this case:"<<endl;
            cin>>current;
        }
        void calDistance(Case const &a)
        {
            cout<<"\nApproximate Distance for this case is "<<sqrt( a.constant / (current) )<<endl;
        }
        void calCurrent(Case const &a)
        {
            cout<<"\nApproximate Current for this case is "<<( a.constant / (distance * distance) )<<endl;
        }
};

void Header()
{
    system("cls");
    cout<<"\n"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|                                                                                                               |"<<endl;
    cout<<"|                                           THE INVERSE SQUARE LAW                                              |"<<endl;
    cout<<"|                                                                                                               |"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------\n"<<endl;
    system("PAUSE");
    cout<<"\n\nTheory:\n\tA photovoltaic cell is semiconductor which is able to convert radiant energy into voltage. In the initial \nforms, these device were known as barrier layer cells but now these are called solar cells as they are generally \nused to convert solar energy electrical energy."<<endl;
    cout<<"\nThe basic principle of these cells is that when a radiant energy is incident on semiconductor, produces electron-\nhole pairs and if the radiant energy exceeds the band gap of the semiconductor, the recombination of electron hole \npair can not take place as in this case the electron is conducted to conduction band. If the external circuit is \ncompleted with the semiconductor, the current starts flowing because of electron hole creation by radiant energy. \nThe voltage this generated dependence directly on band gap of semiconductor."<<endl;
    cout<<"\nIf light from the lamp be incident on the photo - voltaic cell placed at a distance d from it and if theta be the \ncorresponding deflection shown by the galvanometer (or .u-ammeter) then"<<endl;
    cout<<"\n                                        (theta) x (d)^2 = constant    \n"<<endl;
    system("PAUSE");
}

Case SetConst()
{
    system("cls");
    cout<<"\n"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|                                                                                                               |"<<endl;
    cout<<"|                                           THE INVERSE SQUARE LAW                                              |"<<endl;
    cout<<"|                                                                                                               |"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"\nInput experimental value of Distance and Current for one case for a perticular setup in laboratory"<<endl;
    double a, b;
    cout<<"Distance (m): ";
    cin>>a;
    cout<<"Current (.uA): ";
    cin>>b;
    Case obj(a,b);
    return obj;
}

void Calculate()
{
    system("cls");
    cout<<"\n"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|                                                                                                               |"<<endl;
    cout<<"|                                           THE INVERSE SQUARE LAW                                              |"<<endl;
    cout<<"|                                                                                                               |"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"|                                             Give your choice :                                                |"<<endl;
    cout<<"|                                             1. Calculate Distance                                             |"<<endl;
    cout<<"|                                             2. Calculate Current                                              |"<<endl;
    cout<<"|                                             3. Draw Graph for given values                                    |"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                                 Your choice: ";
}

double conv(double a)
{
    return (1/(a*a));
}

void fileUpdate(Case arr[], int j)
{
    ofstream fout;
    fout.open("transfer.txt", ios::out);
    fout.clear();
    for (int i = 0; i < j ; i++)
    {
        fout<<arr[i].current<<",";
    }
    fout<<"\n";
    for (int i = 0; i < j; i++)
    {
        fout<<conv(arr[i].distance)<<",";
    }
    fout.close();
}

int main(void)
{
    Header();
    Case constobj = SetConst();
    while (1)
    {
        Calculate();
        Case obj;
        int x = 0;
        cin>>x;
        if (x == 1)
        {
            obj.setCurrent();
            obj.calDistance(constobj);
        }
        else if (x == 2)
        {
            obj.setDistance();
            obj.calCurrent(constobj);
        }
        else if (x == 3)
        {
            cout<<"\nEnter the number of cases you have created for creating graph: ";
            int y;
            cin>>y;
            Case arrobj[y];
            
            for (int i = 0; i < y; i++)
            {
                cout<<"\n";
                cout<<"Readings for case :  "<<i+1<<endl;
                arrobj[i].setDistance();
                arrobj[i].setCurrent();
            }

            fileUpdate(arrobj, y);
            system("Python plot.py ok go");

        }
        else
        {
            cout<<"\nInvalid Input..............."<<endl;
        }
        cout<<"\n\n";
        system("PAUSE");        
    }
}