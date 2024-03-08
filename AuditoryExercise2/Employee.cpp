#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

enum Type{
    employee,
    menager,
    owner
};
class Employee
{
private:
    char name[50];
    int salary;
    Type position;

public:
    Employee(char *_name="NAME", int _salary=20000, Type _position=employee)
    {
        strcpy(name,_name);
        salary=_salary;
        position=_position;
    }
    ~Employee(){}
    void print()
    {
        cout<<name<<" "<<salary<<" ";
        switch (position) {
            case employee:
                cout<<"Vraboten"<<endl;
                break;
            case menager:
                cout<<"Menadzer"<<endl;
                break;
            case owner:
                cout<<"Sopstvenik"<<endl;
                break;
        }
    }
    void setName(char *_name)
    {
        strcpy(name,_name);
    }
    void setSalary(int _salary)
    {
        salary=_salary;
    }
    void setPosition(Type pos)
    {
        position=pos;
    }

    char getName()
    {
        return *name;
    }
    int getSalary()
    {
        return salary;
    }
    Type getPosition()
    {
        return position;
    }

};

void sort(Employee *employees, int n)
{
    Employee tmp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(employees[j].getSalary()<employees[j+1].getSalary())
            {
                tmp=employees[j];
                employees[j]=employees[j+1];
                employees[j+1]=tmp;
            }
        }
    }
}

int main()
{
    int N;
    cin>>N;
    Employee employees[100];
    char name[50];
    int salary;
    int position;
    for(int i=0;i<N;i++)
    {
        cin>>name;
        cin>>salary;
        cin>>position;
        employees[i].setName(name);
        employees[i].setSalary(salary);
        employees[i].setPosition(Type(position));
    }

    sort(employees,N);

    for(int i=0;i<N;i++)
    {
        employees[i].print();
    }

    return 0;
}
