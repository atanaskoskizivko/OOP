#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctype.h>
#include <vector>

using namespace std;

class Person
{
private:
    string name;
    string surname;
    int year;

public:
    Person(string name=" ", string surname=" ", int year=0)
    {
        this->name=name;
        this->surname=surname;
        this->year=year;
    }
    void print()
    {
        cout<<"Name: "<<name<<" Surname: "<<surname<<" Year: "<<year<<endl;
    }
    string getName()
    {
        return name;
    }
    int getYear()
    {
        return year;
    }
};

int main()
{
    ifstream fin("data.txt");
    ofstream fout("output.txt");
    if(!fin.is_open()){
        cout<<"Ne mozham da ja otvoram datotekata vlezna.txt!"<<endl;
        return -1;
    }
    if(!fout.is_open()){
        cout<<"Ne mozham da ja otvoram datotekata izlezna.txt!"<<endl;
        return -1;
    }
    string line;
    Person people[3];
    int idx=0;
    while(getline(fin,line))
    {
        istringstream iss(line);
        string name,surname;
        int year;
        iss>>name>>surname>>year;
        people[idx++]=Person(name,surname,year);
    }
    for (int i = 0; i < 3; i++) {
        fout<<people[i].getName() + " " + to_string(2024-people[i].getYear())+ '\n';
    }
    fin.close();
    fout.close();


    return 0;
}