#include <iostream>

using namespace std;

class HotelReservation
{
protected:
    int days;
    int guests;
    string contact;

public:
    HotelReservation(int days, int guests, string contact)
    {
        this->days=days;
        this->guests=guests;
        this->contact=contact;
    }
    virtual double price()
    {
        return days*guests*25;
    }
   virtual double price(double amount)
    {
        if(amount>=price())
        {
            return amount-price();
        }
        else
        {
            cout<<"You have to pay: "<<price();
            return -1;
        }
    }
};

class HalfBoardHotelReservation:public HotelReservation
{
public:
    HalfBoardHotelReservation(int days, int guests, string contact): HotelReservation(days,guests,contact)
    {}
    double price(double amount)
    {
        double p1=HotelReservation::price()+days*guests*5;
        if(amount>=p1)
        {
            return amount-p1;
        }
        else
        {
            cout<<"You have to pay: "<<p1;
            return -1;
        }
    }
};

class Hotel
{
private:
    string name;
    double balance;
public:
    Hotel(string name)
    {
        this->name=name;
        balance=0;
    }

    double pay(HotelReservation &hr, double amount)
    {
        double change=hr.price(amount);
        if(change!=-1)
        {
            balance+=amount-change;
        }
        return change;
    }

    friend ostream &operator<<(ostream &out,const Hotel &h)
    {
        out<<h.name<<" BALANCE: "<<h.balance<<endl;
        return out;
    }
};

int main()
{
    Hotel h("HOLIDAY INN");
    cout<<h;

    HotelReservation *hr=new HotelReservation(3,5,"Zivko");
    double c=h.pay(*hr,5000);
    if(c!=-1)
    {
        cout<<"KUSUR: "<<c<<endl;
    }
    cout<<h;

    HotelReservation *hr1=new HalfBoardHotelReservation(3,5,"Zivko");
    double c1=h.pay(*hr1,1000);
    if(c1!=-1)
    {
        cout<<"KUSUR: "<<c1<<endl;
    }
    cout<<h;

    return 0;
}
