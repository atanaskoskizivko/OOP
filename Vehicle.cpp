#include <iostream>

using namespace std;

class Vehicle
{
protected:
    int acc;
public:
    Vehicle()
    {
        cout<<"Vehicle constructor called"<<endl;
        acc=0;
    }
    virtual ~Vehicle()
    {
        cout<<"Vehicle destructor called"<<endl;
    }
    virtual void accelerate()
    {
        acc++;
    }
    int getAcc()
    {
        return acc;
    }
};
class Car:virtual public Vehicle
{
public:
    Car()
    {
        cout<<"Car constructor called"<<endl;
    }
    virtual void accelerate()
    {
        cout<<"Car acceleration called"<<endl;
        Vehicle::accelerate();
        Vehicle::accelerate();
    }
    virtual void drive()
    {
        cout<<"Car is driving"<<endl;
    }
    virtual ~Car(){
        cout<<"Car destructor called"<<endl;
    }
};

class Jet:virtual public Vehicle {
public:
    Jet()
    {
        cout<<"Jet constructor called"<<endl;
    }
   /* void accelerate()
    {
        cout<<"Jet acceleration called"<<endl;
        acc+=50;
    }*/
    virtual void fly()
    {
        cout<<"Jet is flying"<<endl;
    }
    virtual ~Jet()
    {
        cout<<"Jet destructor called"<<endl;
    }
};

class JetCar:public Car,public Jet
{
public:
    JetCar()
    {
        cout<<"JetCar constructor called"<<endl;
    }
    ~JetCar()
    {
        cout<<"JetCar destructor called"<<endl;
    }
    void drive()
    {
        cout<<"JetCar is driving"<<endl;
    }
    void fly()
    {
        cout<<"JetCar is flying"<<endl;
    }
};
int main()
{
   /* Car c;
    c.drive();
    c.accelerate();
    cout<<c.getAcc()<<endl;

    Jet j;
    j.fly();
    j.accelerate();
    cout<<j.getAcc()<<endl;*/

   JetCar jc;
   jc.fly();
   jc.drive();

   return 0;
}
