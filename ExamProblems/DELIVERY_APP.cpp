#include<iostream>
#include<cstring>

using namespace std;

class DeliveryPerson
{
private:
    char id[6];
    char *name;
    int location;
    int numberOfDeliveries;

public:
    DeliveryPerson(char *id = "",char *name= "" ,int location=0,int numberOfDeliveries=0)
    {
        this->location=location;
        this->numberOfDeliveries=numberOfDeliveries;
        strcpy(this->id,id);
        this->name=new char[strlen(name)+1];
        strcpy(this->name,name);
    }

    DeliveryPerson(const DeliveryPerson &p)
    {
        this->location=p.location;
        this->numberOfDeliveries=p.numberOfDeliveries;
        strcpy(this->id,p.id);
        this->name=new char[strlen(p.name)+1];
        strcpy(this->name,p.name);
    }
    DeliveryPerson &operator=(const DeliveryPerson &p)
    {
        if(this!=&p)
        {
            delete [] name;
            this->location=p.location;
            this->numberOfDeliveries=p.numberOfDeliveries;
            strcpy(this->id,p.id);
            this->name=new char[strlen(p.name)+1];
            strcpy(this->name,p.name);
        }
        return *this;
    }
    ~DeliveryPerson()
    {
        delete [] name;
    }

    void print()
    {
        cout << "ID: " << id << " Name: " << name << " Current location: " << location << " # of deliveries: "
             << numberOfDeliveries << endl;
    }
    bool isSame(const DeliveryPerson &p)
    {
        return strcmp(this->id,p.id)==0;
    }

    int distance(int area)
    {
        return abs(location-area);
    }

    bool compare(DeliveryPerson &dp,int area)
    {
        if(this->distance(area)<dp.distance(area))
            return true;
        else if(this->distance(area)==dp.distance(area))
            return this->numberOfDeliveries<dp.numberOfDeliveries;
        else
            return false;
    }

    void increaseDeliveries() {
        ++numberOfDeliveries;

    }

    void setLocation(int a)
    {
        location=a;
    }
};

class DeliveryApp
{
private:
    char name[20];
    DeliveryPerson *people;
    int number;

public:
    DeliveryApp(char *name="")
    {
        strcpy(this->name,name);
        people=new DeliveryPerson[0];
        number=0;
    }
    ~DeliveryApp()
    {
        delete [] people;
    }
    void print()
    {
        cout<<name<<endl;
        if(number==0)
        {
            cout<<"EMPTY"<<endl;
        }
        for(int i=0;i<number;i++)
        {
            people[i].print();
        }
    }
    void addDeliveryPerson(const DeliveryPerson &p)
    {
        for(int i=0;i<number;i++)
        {
            if(people[i].isSame(p))
                return;
        }

        DeliveryPerson *tmp=new DeliveryPerson[number+1];
        for(int i=0;i<number;i++)
        {
            tmp[i]=people[i];
        }
        tmp[number++]=p;
        delete [] people;
        people=tmp;
    }

    void assignDelivery(int restaurantArea,int customerArea)
    {
        int idx=0;
        for(int i=0;i<number;i++)
        {
            if(people[i].compare(people[idx],restaurantArea))
                idx=i;
        }
        people[idx].increaseDeliveries();
        people[idx].setLocation(customerArea);
    }

};

int main() {

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "CONSTRUCTOR DeliveryPerson" << endl;
        DeliveryPerson person("12345", "Stefan", 5);
        person.print();
        cout << "CONSTRUCTOR DeliveryPerson OK" << endl;
    } else if (testCase == 2) {
        cout << "COPY-CONSTRUCTOR DeliveryPerson" << endl;
        DeliveryPerson person = DeliveryPerson("12345", "Stefan", 5);
        person.print();
        cout << "COPY-CONSTRUCTOR DeliveryPerson OK" << endl;
    } else if (testCase == 3) {
        cout << "DEFAULT CONSTRUCTOR AND OPERATOR = DeliveryPerson" << endl;
        DeliveryPerson person;
        DeliveryPerson person2("12345", "Stefan", 5);
        person = person2;
        person.print();
        cout << "DEFAULT CONSTRUCTOR AND OPERATOR = DeliveryPerson OK" << endl;
    } else if (testCase == 4) {
        cout << "CONSTRUCTOR DeliveryApp" << endl;
        char appName[50];
        cin >> appName;
        DeliveryApp app(appName);
        app.print();
        cout << "CONSTRUCTOR DeliveryApp OK" << endl;
    } else if (testCase == 5) {
        cout << "DeliveryApp addDeliveryPerson test" << endl;
        char appName[50];
        cin >> appName;
        DeliveryApp app(appName);
        int n;
        cin >> n;
        char ID[6];
        char name[20];
        int location;
        for (int i = 0; i < n; i++) {
            cin >> ID >> name >> location;
            app.addDeliveryPerson(DeliveryPerson(ID, name, location));
        }
        app.print();
    } else if (testCase == 6) {
        cout << "DeliveryApp addDeliveryPerson test" << endl;
        char appName[50];
        cin >> appName;
        DeliveryApp app(appName);
        int n;
        cin >> n;
        char ID[6];
        char name[20];
        int location;
        for (int i = 0; i < n; i++) {
            cin >> ID >> name >> location;
            app.addDeliveryPerson(DeliveryPerson(ID, name, location));
        }
        cin >> n; //read assign deliveries
        for (int i = 0; i < n; i++) {
            int restaurantArea, customerArea;
            cin >> restaurantArea >> customerArea;
            app.assignDelivery(restaurantArea, customerArea);
        }
        app.print();
    }
    return 0;
}
