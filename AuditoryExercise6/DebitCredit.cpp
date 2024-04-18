#include <iostream>
#include <cstring>

using namespace std;

class DebitAccount
{
protected:
    string name;
    string accNumber;
    double balance;
public:
    DebitAccount(string name="",string accNumber="111111",double balance=0)
    {
        this->name=name;
        this->accNumber=accNumber;
        this->balance=balance;
    }
    DebitAccount(const DebitAccount &da)
    {
        this->name=da.name;
        this->accNumber=da.accNumber;
        this->balance=da.balance;
    }
    void printInfo()
    {
        cout<<"NAME: "<<name<<endl;
        cout<<"ACCOUNT NUMBER: "<<accNumber<<endl;
        cout<<"BALANCE: "<<balance<<endl;
    }
    void deposit(double amount)
    {
        balance+=amount;
    }
    void withdraw(double amount)
    {
        if(amount<=balance)
        {
            balance=balance-amount;
        }
        else
        {
            cout<<"You don't have enough money. Withdrawing: "<<balance<<endl;
            balance=0;
        }
    }
};

class CreditAccount:public DebitAccount
{
private:
    double limit;
    const double interest=0.05;
    double debt;
public:
    CreditAccount(string name="",string accNumber="111111",double balance=0,double limit=2000): DebitAccount(name,accNumber,balance)
    {
        this->limit=limit;
        this->debt=0;
    }
    CreditAccount(const DebitAccount &da, double limit): DebitAccount(da)
    {
        this->limit=limit;
        this->debt=0;
    }
    void printInfo()
    {
        DebitAccount::printInfo();
        cout<<"Debt: "<<debt<<endl;
        cout<<"LIMIT: "<<limit<<endl;
    }
    void deposit(double amount)
    {
        if(amount<=debt)
        {
            debt-=amount;
        }
        else
        {
            balance=amount-debt;
            debt=0;
        }
    }
    void withdraw(double amount)
    {
        if(amount<=balance)
        {
            DebitAccount::withdraw(amount);
        }
        else
        {
            double diff=amount-balance;
            if((diff+debt)<=limit)
            {
                balance=0;
                debt+=diff*(1+interest);
            }
            else
            {
                cout<<"LIMIT EXCEDED"<<endl;
            }
        }
    }
};
int main()
{
    CreditAccount ca("Zivko","12365842",5000);
    ca.printInfo();
    ca.withdraw(3000);
    ca.printInfo();
    ca.withdraw(2500);
    ca.printInfo();
    ca.deposit(800);
    ca.printInfo();
    ca.withdraw(3000);

    return 0;
}
