#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
class Momche
{
private:
    char ime[10];
    char prezime[10];
    int godini;
public:
    Momche(char *_ime="Toni",char *_prezime="Markovski", int _godini=18)
    {
        strcpy(ime,_ime);
        strcpy(prezime,_prezime);
        godini=_godini;
    }
    ~Momche(){
        cout<<"Destroy momce"<<endl;
    }
    void pecati()
    {
        cout<<"Momche: "<<ime<<" "<<prezime<<" "<<godini<<" ";
    }
    int getGodini()
    {
        return godini;
    }
};

class Devojce
{
private:
    char ime[10];
    char prezime[10];
    int godini;
public:
    Devojce(char *_ime="Tanja",char *_prezime="Pavlovska", int _godini=20)
    {
        strcpy(ime,_ime);
        strcpy(prezime,_prezime);
        godini=_godini;
    }
    ~Devojce(){
        cout<<"Destroy devojce"<<endl;
    }
    void pecati()
    {
        cout<<"Devojche: "<<ime<<" "<<prezime<<" "<<godini<<" ";
    }
    int getGodini()
    {
        return godini;
    }
};

class Sredba
{
private:
    Momche m1;
    Devojce d1;
public:
    Sredba(Momche m, Devojce d)
    {
        m1=m;
        d1=d;
    }
    ~Sredba(){
        cout<<"Destroy sredba"<<endl;
    }

    void print()
    {
        cout<<"Sredba: ";
        m1.pecati();
        d1.pecati();
    }
    void daliSiOdgovaraat()
    {
        if(abs(m1.getGodini()-d1.getGodini())<=5)
        {
            cout<<"Si odgovaraat"<<endl;
        }
        else
        {
            cout<<"Ne si odgovaraat"<<endl;
        }
    }
};

int main()
{
    Momche m;
    Devojce d;
    char ime[10],prezime[10];
    int godini;
    cout<<"Vnesi za momche"<<endl;
    cin>>ime>>prezime>>godini;
    m=Momche(ime,prezime,godini);

    cout<<"Vnesi za devojce"<<endl;
    cin>>ime>>prezime>>godini;
    d=Devojce(ime,prezime,godini);

    Sredba s(m,d);
    s.print();
    s.daliSiOdgovaraat();


    return 0;
}