#include <iostream>
#include <cstring>
using namespace std;

class Discount
{
public:
    static float EUR_TO_MKD;
    static float USD_TO_MKD;
    virtual float discount_price()=0;
    virtual float getPrice()=0;
    virtual void print_rule()=0;
};
float Discount::EUR_TO_MKD=61.5;
float Discount::USD_TO_MKD=58.4;

class NegativeValueExeption
{
private:
    char name[50];
public:
    NegativeValueExeption(char *name)
    {
        strcpy(this->name,name);
    }
    void showMessage()
    {
        cout<<"The product "<<name<<" can't have negative value for the price"<<endl;
    }
};
class Product
{
protected:
    char name[50];
    float price;
public:
    Product(char *name="",float price=0.0)
    {
        strcpy(this->name,name);
        this->price=price;
    }

    void changePrice(float c)
    {
        if(c < 0)
        {
            throw NegativeValueExeption(this->name);
        }
        this->price=c;
    }
};

class FoodProduct : public Product, public Discount {
public:
    FoodProduct(char *name = "", float price = 0.0) : Product(name, price) {

    }

    float discount_price() {
        return getPrice();
    }

    float getPrice()
    {
        return price*Discount::EUR_TO_MKD;
    }
    void print_rule()
    {
        cout<<"No discount for food products"<<endl;
    }

};

class Drinks : public Product, public Discount
{
private:
    bool isAlcoholic;
public:
    Drinks(char *name="",float price=0.0, bool isAlcoholic=false): Product(name,price)
    {
        this->isAlcoholic=isAlcoholic;
    }
    float discount_price() {
        if(isAlcoholic && price>20.0)
        {
            return getPrice()*0.95;
        }
        if(!isAlcoholic && strcmp(name,"coca-cola")==0)
        {
            return getPrice()*0.9;
        }
        return getPrice();
    }

    float getPrice()
    {
        return price*Discount::EUR_TO_MKD;
    }
    void print_rule()
    {
        cout<<"Alcohol products with price > 20 eur. 5%, Coca-cola 10%"<<endl;
    }
};

class Cosmetics : public Product, public Discount
{
public:
    Cosmetics(char *name="",float price=0.0): Product(name,price)
    {

    }
    float discount_price() {
        float priceUSD=price*Discount::EUR_TO_MKD/Discount::USD_TO_MKD;

        if(priceUSD>20.0)
        {
            return getPrice()*0.86;
        }
        if(price > 5.0)
        {
            return getPrice()*0.88;
        }
        return getPrice();
    }

    float getPrice()
    {
        return price*Discount::EUR_TO_MKD;
    }
    void print_rule()
    {
        cout<<"Price in USD > 14$ - 14%; price in EUR > 5eur - 12%"<<endl;
    }
};

int main()
{/*
    Product *p = new FoodProduct("bread",0.5);
    try {
        p->changePrice(-5);
    }catch(NegativeValueExeption e)
    {
        e.showMessage();
    }*/
    int n = 0;
    float newPrice;
    Discount **d = new Discount*[10];
    d[n++] = new FoodProduct("leb", 0.5);
    d[n++] = new Drinks("viski", 50, true);
    d[n++] = new FoodProduct("sirenje", 10);
    d[n++] = new Drinks("votka", 10, true);
    d[n++] = new Cosmetics("krema", 35);
    d[n++] = new Drinks("coca-cola",3, false);
    d[n++] = new Cosmetics("parfem", 60);

    for(int i=0;i<n;i++)
    {
        cout<<i+1<<endl;
        cout<<d[i]->getPrice()<<endl;
        cout<<d[i]->discount_price()<<endl;
        d[i]->print_rule();
    }

    for(int i=0;i<n;i++)
    {
        Cosmetics *cosmeticsTrial=dynamic_cast<Cosmetics *>(d[i]);
        if(cosmeticsTrial!= nullptr)
        {
            int newPrice;
            cin>>newPrice;
            try {
                cosmeticsTrial->changePrice(newPrice);
            }
            catch (NegativeValueExeption e)
            {
                e.showMessage();
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<i+1<<endl;
        cout<<d[i]->getPrice()<<endl;
        cout<<d[i]->discount_price()<<endl;
        d[i]->print_rule();
    }

    for (int i = 0; i < n; ++i) {
        delete d[i];
    }
    delete[] d;

    return 0;

}
