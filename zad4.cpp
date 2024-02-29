#include <iostream>

using namespace std;

typedef struct City
{
    char name[50];
    int population;
};

typedef struct President
{
    char name[50];
    char surname[50];
    char party[20];
};

typedef struct Country
{
    char name[50];
    President p;
    City c;
    int population;
};

void readCity(City &c)
{
    cin>>c.name>>c.population;
}
void readPresident(President &p)
{
    cin>>p.name>>p.surname>>p.party;
}
void readCountry(Country &country)
{
    cin>>country.name>>country.population;
    readPresident(country.p);
    readCity(country.c);
}

void printCountry(Country country)
{
    cout<<country.name<<" "<<country.population<<" President: "<<country.p.name<<" "<<country.p.surname<<" "<<country.p.party<<" ";
    cout<<"Capital: "<<country.c.name<<" "<<country.c.population<<endl;
}
void maxCapitalpopulation(Country countries[], int n)
{
    Country max=countries[0];
    for(int i=1;i<n;i++)
    {
        if(countries[i].c.population>max.c.population){
            max=countries[i];
        }
    }
    cout<<"PRESIDENT: "<<max.p.name<<" "<<max.p.surname<<endl;
}

int main()
{
    Country countries[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        readCountry(countries[i]);
    }
    for(int i=0;i<n;i++)
    {
        printCountry(countries[i]);
    }

    maxCapitalpopulation(countries,n);

    return 0;
}

