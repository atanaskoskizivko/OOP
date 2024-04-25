#include <iostream>
#include <cstring>
using namespace std;


class Book
{
protected:
    string name;
public:
    Book(string name)
    {
        this->name=name;
    }

    virtual void printType()
    {
        cout<<name<<" is a something"<<endl;
    }
};

class Roman:public Book
{
public:
    Roman(string name): Book(name)
    {

    }
    void printType()
    {
        cout<<name<<" is a roman"<<endl;
    }
};

class Academic:public Book
{
public:
    Academic(string name): Book(name)
    {

    }
    void printType()
    {
        cout<<name<<" is an academic"<<endl;
    }
};


int main()
{
   /* Book *b=new Roman("Ana Karenina");
    b->printType();

    Book *r=new Roman("War and peace");
    r->printType();

    Book *a=new Academic("OOP");
    a->printType();*/

   int n;
   cin>>n;

   Book **books=new Book * [n];
   string name;
   int type;
   for(int i=0;i<n;i++)
   {
       cin>>name;
       cin>>type;//roman 0  academic 1
       if(type==0)
       {
           books[i]=new Roman(name);
       }
       else
       {
           books[i]=new Academic(name);
       }
   }

   for(int i=0;i<n;i++)
   {
       books[i]->printType();
   }

    return 0;
}