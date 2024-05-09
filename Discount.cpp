#include <iostream>

using namespace std;

class Product
{
protected:
    string name;
    float price;
public:
    Product(string name="",float price=0)
    {
        this->name=name;
        this->price=price;
    }
    float getPrice()
    {
        return price;
    }
};
class Discountable
{
public:
    virtual float getPrice()=0;
    virtual float getDiscountPrice()=0;
    virtual void print()=0;
};

class FoodProduct:public Product,public Discountable
{
private:
    float callories;
public:
    FoodProduct(string name="",float price=0, float callories=0): Product(name,price)
    {
        this->callories=callories;
    }
    float getPrice()
    {
        return Product::getPrice();
    }
    float getDiscountPrice()
    {
        return 0.8*getPrice();
    }
    void print()
    {
        cout<<"NAME: "<<name<<" PRICE: "<<price<<" DISCOUNT PRICE: "<<getDiscountPrice()<<" CALLORIES: "<<callories<<endl;
    }
};

class DigitalProduct:public Product,public Discountable
{
private:
    float size;
public:
    DigitalProduct(string name="",float price=0,float size=0): Product(name,price)
    {
        this->size=size;
    }
    float getPrice()
    {
        return Product::getPrice();
    }
    float getDiscountPrice()
    {
        return 0.9*getPrice();
    }
    void print()
    {
        cout<<"NAME: "<<name<<" PRICE: "<<price<<" DISCOUNT PRICE: "<<getDiscountPrice()<<" MB: "<<size<<endl;
    }
};

float total_discount(Discountable **d,int n)
{
    float price=0,discount=0;
    for(int i=0;i<n;i++)
    {
        price+=d[i]->getPrice();
        discount+=d[i]->getDiscountPrice();
    }
    return price-discount;
}

int main()
{
    int n;
    cin>>n;
    Discountable **d=new Discountable * [n];
    for(int i=0;i<n;i++)
    {
        int type;
        string name;
        float price;
        float cal,size;
        cin>>type; // 1 - FOOD 2 - DIGITAL
        if(type==1)
        {
            cin>>name>>price>>cal;
            d[i]=new FoodProduct(name,price,cal);
        }
        else
        {
            cin>>name>>price>>size;
            d[i]=new DigitalProduct(name,price,size);
        }
    }

    for(int i=0;i<n;i++)
    {
        d[i]->print();
    }

    cout<<"TOTAL DISCOUNT: "<<total_discount(d,n)<<endl;
    for (int i = 0; i < n; i++)
    {
        delete d[i];
    }
    delete[] d;
    return 0;
}