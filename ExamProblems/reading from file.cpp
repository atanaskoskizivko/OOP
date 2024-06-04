#include <iostream>
#include <string>
#include <fstream>

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
    friend istream &operator>>(istream &in, Person & p){
        return in >> p.name >> p.surname >> p.year;
    }
    friend ostream &operator<<(ostream &out, Person &p)
    {
        out<<p.name<<" "<<p.surname<<" "<<p.year<<endl;
        return out;
    }
};

int main()
{

    ifstream fin("input1.txt"); //opening input file
    if (!fin) {
        cout << "Error opening file!" << endl;
        return 1;
    }
    Person people[3];
    for(int i = 0; i < 3; ++i) {
        fin >> people[i];  //reading data from file and initializing object
    }
    fin.close(); //closing the file

    for(int i = 0; i < 3; ++i) // Print the information read from the file
    {
        people[i].print();
    }

    ofstream fout("out.txt"); //opening output file
    if (!fout) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    for(int i = 0; i < 3; ++i) //writing to file 
    {
        fout<<people[i];
    }

    fout.close();




    return 0;
}
