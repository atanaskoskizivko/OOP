#include <iostream>
#include <cstring>

using namespace std;

class Datum
{
private:
    int d;
    int m;
    int god;
public:
    Datum(int _d=0,int _m=0,int _god=0)
    {
        d=_d;
        m=_m;
        god=_god;
    }
    ~Datum(){}
    int getD()
    {
        return d;
    }
    int getM()
    {
        return m;
    }
    int getG()
    {
        return god;
    }
};

class Vraboten
{
private:
    char ime[20];
    int plata;
    Datum d1;
public:
    Vraboten(){}
    Vraboten(char *_ime,int _plata,Datum _d1)
    {
        strcpy(ime,_ime);
        plata=_plata;
        d1=_d1;
    }
    ~Vraboten(){}

    void pecati()
    {
        cout<<ime<<" "<<plata<<" ";
        cout<<d1.getD()<<"."<<d1.getM()<<"."<<d1.getG()<<endl;
    }
    int getPlata()
    {
        return plata;
    }
    Datum getData()
    {
        return d1;
    }
};

int sporedba(Datum d1, Datum d2) {
    if (d1.getG() > d2.getG()) return 1;
    else if (d1.getG() < d2.getG()) return 2;
    else if (d1.getM() > d2.getM()) return 1;
    else if (d1.getM() < d2.getM()) return 2;
    else if (d1.getD() > d2.getD()) return 1;
    else if (d1.getD() < d2.getD()) return 2;
    else return 0;
}
//go vrakja najmladiot vraboten od nizata v
Vraboten najmlad(Vraboten v[], int n) {
    Datum data(v[0].getData());
    int ind = 0;
    for (int i = 1; i < n; i++) {
        if (sporedba(v[i].getData(), data) == 1) {
            data = v[i].getData();
            ind = i;
        }
    }
    return v[ind];
}

Vraboten najbogat(Vraboten *v,int n)
{
    int plata=v[0].getPlata();
    int idx=0;
    for (int i = 0; i <n ; i++)
    {
        if(v[i].getPlata()>plata)
        {
            plata=v[i].getPlata();
            idx=i;
        }
    }
    return v[idx];
}

int main()
{
    int n;
    cin>>n;
    Vraboten vraboteni[20];
    char ime[20];
    int plata;
    int d,m,g;
    for(int i=0;i<n;i++)
    {
        cin>>ime>>plata;
        cin>>d>>m>>g;
        Datum data=Datum(d,m,g);
        vraboteni[i]=Vraboten(ime,plata,data);
    }

    for(int i=0;i<n;i++)
    {
        vraboteni[i].pecati();
    }

    najbogat(vraboteni,n).pecati();
    najmlad(vraboteni,n).pecati();
    return 0;
}
