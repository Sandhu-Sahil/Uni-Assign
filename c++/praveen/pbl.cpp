#include <fstream>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class pn
{
    public:
    double temp[5];
    double current[5];
    double tempk[5];
    double tempexp[5];
    double currexp[5];
    double result;
    void gettemp()
    {
        cout<<" Enter the Temperatures : "<<endl;
        for(int i=0;i<5;i++)
        {
            cout<<i+1<<". ";
            cin>>temp[i];
        }
    }
    void getcurrent()
    {
        cout<<" Enter the Currents : "<<endl;
        for(int i=0;i<5;i++)
        {
            cout<<i+1<<". ";
            cin>>current[i];
        }
    }
    void docalculations()
    {
        for(int i=0;i<5;i++)
        {
            tempk[i]=temp[i]+273;
            tempexp[i]=(10*10*10)/tempk[i];
            currexp[i]=log10(current[i]);
        }
    }
    void printtheory()
    {
        cout<<"-------"<<endl;
        cout<<"| AIM | "<<endl;
        cout<<"-------"<<endl;
        cout<<"          To determine the band gap in a semiconductor using a PN junction diode. "<<endl<<endl;
        cout<<"---------------------- "<<endl;
        cout<<"| APPARATUS REQUIRED | "<<endl;
        cout<<"---------------------- "<<endl;
        cout<<"          Power supply (DC-3 volts for Ge diode and DC-6 volts for Si diode),"<<endl;
        cout<<"          Microammeter, Electrically heated oven, Thermometer, Semiconductor diode,"<<endl;
        cout<<"          connecting wires etc."<<endl<<endl;
        cout<<"--------------------"<<endl;
        cout<<"| FORMULA REQUIRED | "<<endl;
        cout<<"--------------------"<<endl;
        cout<<"          A graph is plotted between Log10 Is and (10^3 /T) that comes out to be a straight line."<<endl;
        cout<<"          Its slope is found. Band gap, ΔE, in electron volts, is given by"<<endl;
        cout<<"                ---------------------------------------"<<endl;
        cout<<"                | ΔE = [(slope of the line)/5.038] eV |"<<endl;
        cout<<"                ---------------------------------------"<<endl<<endl;
        cout<<"----------"<<endl;
        cout<<"| THEORY | "<<endl;
        cout<<"----------"<<endl;
        cout<<"          In a semiconductor there is an energy gap between its conduction and valence band. "<<endl;
        cout<<"          For  conduction of electricity a certain amount of energy is to be given to the electron so that it goes from the "<<endl;
        cout<<"          valence band to the conduction band. The energy so needed is the measure of the energy gap, ΔE, between two bands."<<endl<<endl;
        cout<<"          When a PN junction is reverse biased then current is due to minority carriers whose concentration"<<endl;
        cout<<"          is  dependent on the energy gap, ΔE. The reverse current, Is (saturated value) is a function of the"<<endl;
        cout<<"          temperature of the junction diode. For small range of temperature, the relation is expressed as"<<endl<<endl;
        cout<<"                                -------------------------"<<endl;
        cout<<"                                | Is = I0 exp (-ΔE/ηkT) |"<<endl;
        cout<<"                                -------------------------"<<endl;

        cout<<"          Therefore, η Log10 Is = constant – 5.038 ΔE (103/T)"<<endl;
        cout<<"                 where, temperature T is in Kelvin ΔE is in electron volts (eV), k = Boltzman constant, and "<<endl;
        cout<<"                 η =  ideality factor (lies between 1 & 2)."<<endl<<endl;
        cout<<"          A graph in Log10 Is and (103/T) is plotted which comes out to be a straight line. The slope of this line  will be 5.038 ΔE,"<<endl;
        cout<<"          giving the value of band gap for the semiconductor. "<<endl<<endl;
        cout<<"---------------- "<<endl;
        cout<<"| CALCULATIONS |"<<endl;
        cout<<"---------------- "<<endl;
        cout<<"          Plot a graph between Log10 Is and (103/T) and calculate the slope. Then find  ΔE = [(slope of the line)/5.038] eV "<<endl<<endl;
        cout<<"----------"<<endl;
        cout<<"| RESULT |"<<endl;
        cout<<"----------"<<endl;
        cout<<"          Band gap for given semiconductor PN diode =  ev"<<endl<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"| SOURCE OF ERROR AND PRECAUTIONS |"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"          1. Maximum temperature should not exceed 80°C in case of Ge diode and 200°C in case of Si diode."<<endl;
        cout<<"          2. Silicon diode, if used, will require a maximum temperature of the order of 200°C."<<endl;
        cout<<"             Therefore oven  and thermometer should be of this requirement. " <<endl<<endl;

    }
    void printobs()
    {
        cout<<"----------------------"<<endl;
        cout<<"| OBSERVATION  TABLE |"<<endl;
        cout<<"----------------------"<<endl<<endl;
        cout<<"-----------------------------------------------------------------------------------"<<endl;
        cout<<"| S.no. | Temperature (* C) | Current (I) | Temperature (K) | 10^3 / T | Log10(I) |"<<endl;
        for(int j=0;j<5;j++)
        {
             cout<<"|   "<<j+1<<"   |"<<"        "<<temp[j]<<"         |"<<"      "<<current[j]<<"     |"<<"       "<<tempk[j]<<"        |"<<"    "<<tempexp[j]<<"    |"<<"    "<<currexp[j]<<"     |"<<endl;
        }
        cout<<"-----------------------------------------------------------------------------------"<<endl;
    }
};

void graph(double *x, double *y)
{
    ofstream fout;
    fout.open("transfer.txt", ios::out);
    fout.clear();
    for (int i = 0; i < 5 ; i++)
    {
        fout<<x[i]<<",";
    }
    fout<<"\n";
    for (int i = 0; i < 5; i++)
    {
        fout<<y[i]<<",";
    }
    fout.close();
    system("Python plot.py ok go");
    system("PAUSE");
}

int main(void)
{
    pn pn1;
    pn1.printtheory();
    pn1.gettemp();
    pn1.getcurrent();
    pn1.docalculations();
    pn1.printobs();
    graph(pn1.tempexp, pn1.currexp);
}