#include<iostream>
#include<cstring>

using namespace std;

class Sneakers {
private:
    char model[50];
    int size;
    float price;

public:
    Sneakers(const char *model = "", int size = 38, float price = 1000) : size(size), price(price) {
        strncpy(this->model, model, 49);
        this -> model[49] = 0;
    }

    friend istream &operator>>(istream &in, Sneakers &s) {
        return in >> s.model >> s.size >> s.price;
    }

    friend ostream &operator<<(ostream &out, const Sneakers &s) {
        return out << "Model: " << s.model << " Size: " << s.size << " Price: " << s.price;
    }

    Sneakers &operator+=(float increment) {
        price += increment;
        return *this;
    }

    Sneakers &operator*=(float coefficient) {
        price *= coefficient;
        return *this;
    }

    bool operator==(Sneakers &s) {
        return strcmp(this->model, s.model) == 0 && this->size == s.size;
    }

    char *getModel() {
        return model;
    }

    int getSize() const {
        return size;
    }

    void setSize(int size) {
        this->size = size;
    }

    float getPrice() const {
        return price;
    }

    void setPrice(float price) {
        this->price = price;
    }
};

class SneakersShop
{
protected:
    char name[50];
    Sneakers *sneakers;
    int total;
    static int INCREMENT;
public:
    SneakersShop(char *name)
    {
        strcpy(this->name,name);
        sneakers = new Sneakers[0];
        total=0;
    }
    ~SneakersShop()
    {
        delete [] sneakers;
    }
    friend ostream &operator<<(ostream &out, SneakersShop &s)
    {
        out<<"Sneakers shop: "<<s.name<<endl;
        out<<"List of sneakers:"<<endl;
        if(s.total==0)
        {
            out<<"EMPTY"<<endl;
        }
        else
        {
            for(int i=0;i<s.total;i++)
            {
                out<<i+1<<". "<<s.sneakers[i]<<endl;
            }
        }
        return out;
    }
    SneakersShop &operator+=(Sneakers s)
    {
        Sneakers *tmp=new Sneakers[total+1];
        for(int i=0;i<total;i++)
        {
            tmp[i]=sneakers[i];
        }
        tmp[total++]=s;
        delete [] sneakers;
        sneakers=tmp;
        return *this;
    }
    virtual float checkItemAvailability(char* model, int size)
    {
        Sneakers tmp(model,size);
        for(int i=0;i<total;i++)
        {
            if(tmp==sneakers[i])
            {
                return sneakers[i].getPrice();
            }
        }
        return 0;
    }

    SneakersShop &operator++()
    {
        for(int i=0;i<total;i++)
        {
            sneakers[i]*=(1.0+((float)INCREMENT/100));
        }
    }
    static void setIncreasePercentage(int p)
    {
        INCREMENT=p;
    }

};
int SneakersShop::INCREMENT=5;
class OnlineSneakersShop:public SneakersShop
{
private:
    char url[100];
    const static int DISCOUNT;
public:
    OnlineSneakersShop(char *name, char *url): SneakersShop(name)
    {
        strcpy(this->url,url);
    }
    float checkItemAvailability(char* model, int size)
    {
        return SneakersShop::checkItemAvailability(model,size)*(1-(float )DISCOUNT/100);
    }
    friend ostream &operator<<(ostream &out, OnlineSneakersShop &s)
    {
        out<<"OnlineSneakers shop: "<<s.name<<" URL: "<<s.url<<endl;
        out<<"List of sneakers:"<<endl;
        if(s.total==0)
        {
            out<<"EMPTY"<<endl;
        }
        else
        {
            for(int i=0;i<s.total;i++)
            {
                out<<i+1<<". "<<s.sneakers[i]<<endl;
            }
        }
        return out;
    }
};
const int OnlineSneakersShop::DISCOUNT=10;




void printShop(SneakersShop *shop) {
    OnlineSneakersShop *casted = dynamic_cast<OnlineSneakersShop *>(shop);
    if (casted) {
        cout << (*casted);
    } else {
        cout << (*shop);
    }
}

int main() {
    int testCase;
    cin >> testCase;
    char name[100];
    char url[100];

    if (testCase == 1) {
        cout << "TESTING CLASS SneakersShop: CONSTRUCTOR AND OPERATOR <<" << endl;
        cin >> name;
        SneakersShop shop(name);
        cout << shop;
    } else if (testCase == 2) {
        cout << "TESTING CLASS OnlineSneakersShop: CONSTRUCTOR AND OPERATOR <<" << endl;
        cin >> name >> url;
        OnlineSneakersShop shop(name, url);
        cout << shop;
    } else if (testCase == 3) {
        cout << "TESTING CLASS SneakersShop, CONSTRUCTOR, += and <<" << endl;
        cin >> name;
        SneakersShop shop(name);
        cout << shop;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            shop += s;
        }
        cout << shop;
    } else if (testCase == 4) {
        cout << "TESTING CLASS OnlineSneakersShop, CONSTRUCTOR, += and <<" << endl;
        cin >> name >> url;
        OnlineSneakersShop shop(name, url);
        cout << shop;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            shop += s;
        }
        cout << shop;
    } else if (testCase == 5) {
        cout << "TESTING METHOD checkItemAvailability" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0) {
            shop = new SneakersShop(name);
        } else {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }
        char model[100];
        int size;
        cin >> model >> size;
        cout << "Price for model " << model << " with size: " << size << " is: "
             << shop->checkItemAvailability(model, size) << endl;
    } else if (testCase == 6) {
        cout << "TESTING OPERATOR ++" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0) {
            shop = new SneakersShop(name);
        } else {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }
        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);
    } else if (testCase == 7) {
        cout << "TESTING OPERATOR ++ AND CHANGE OF STATIC MEMBER" << endl;
        int typeOfShop;
        cin >> typeOfShop >> name; //0 = regular, 1 = online
        SneakersShop *shop;
        if (typeOfShop == 0) {
            shop = new SneakersShop(name);
        } else {
            cin >> url;
            shop = new OnlineSneakersShop(name, url);
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            Sneakers s;
            cin >> s;
            (*shop) += s;
        }

        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);

        cout <<"CHANGING INCREASE PERCENTAGE IN SneakersShop" << endl;
        SneakersShop::setIncreasePercentage(17);

        cout << "BEFORE ++ IS CALLED" << endl;
        printShop(shop);
        ++(*shop);
        cout << "AFTER ++ IS CALLED" << endl;
        printShop(shop);

    }


}