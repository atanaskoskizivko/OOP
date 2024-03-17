#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
typedef struct UmetnickoDelo
{
    char avtor[50];
    float cena;
    int tip; // 1 slika 2 skluptura

    void pecati()
    {
        cout<<avtor<<" "<<cena<<" "<<tip<<endl;
    }
};

typedef struct Galerija
{
    char ime[50];
    UmetnickoDelo dela[30];
    int brDela;
};

void print(Galerija g)
{
    cout<<g.ime<<endl;
    for(int i=0;i<g.brDela;i++)
    {
        g.dela[i].pecati();
    }
}

void najdobra_ponuda(Galerija *g,int n,int t)
{
    char best[50];
    float minCena=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<g[i].brDela;j++)
        {
            if(g[i].dela[j].tip==t)
            {
                if(minCena==-1 || g[i].dela[j].cena<minCena)
                {
                    strcpy(best,g[i].ime);
                    minCena=g[i].dela[j].cena;
                }
            }
        }
    }
    if(minCena!=-1)
    {
        cout<<"Najevtino umetnicko delo tip ";
        if(t==1)
        {
            cout<<"slika ";
        }
        else
        {
            cout<<"skluptura ";
        }
        cout<<" go nudi galerijata: "<<best<<" so cena: "<<minCena<<endl;
    }
    else
    {
        cout<<"Ne e pronajdeno umetnicko delo od tip ";
        if(t==1)
        {
            cout<<"slika ";
        }
        else
        {
            cout<<"skluptura ";
        }
    }

}

int main()
{
    int n;
    cin>>n; //broj na Galerii
    Galerija galerii[n];
    //vnesuvanje na galeriite, zaedno so raspolozlivite podatoci
    for(int i=0;i<n;i++)
    {
        cin>>galerii[i].ime>>galerii[i].brDela;
        for(int j=0;j<galerii[i].brDela;j++)
        {
            cin>>galerii[i].dela[j].avtor>>galerii[i].dela[j].cena>>galerii[i].dela[j].tip;
        }
    }
    //pecatenje na prodazni saloni
    for(int i=0;i<n;i++)
    {
        print(galerii[i]);
    }

    //povik na glavnata metoda
    int tipNaDelo;
    cin>>tipNaDelo;
    najdobra_ponuda(galerii, n, tipNaDelo);
    return 0;
}
