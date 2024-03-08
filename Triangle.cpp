#include <iostream>
#include <cmath>
using namespace std;

class Triangle
{
private:
    float a,b,c;
public:
    Triangle(){}
    Triangle(int x,int y, int z)
    {
        a=x;
        b=y;
        c=z;
    }

    float Perimeter()
    {
        return a+c+c;
    }

    float Area()
    {
        float s=(a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    void setA(float x)
    {
        a=x;
    }
    void setB(float y)
    {
        b=y;
    }
    void setC(float z)
    {
        c=z;
    }

    float getA()
    {
        return a;
    }
    float getB()
    {
        return b;
    }
    float getC()
    {
        return c;
    }

    ~Triangle(){
        cout<<"Object is destroyed"<<endl;
    }

};

int main()
{
    float x,y,z;
    cin>>x>>y>>z;
    Triangle t1(x,y,z);
    cout<<"Area: "<<t1.Area()<<endl;
    cout<<"Perimeter: "<<t1.Perimeter()<<endl;
    Triangle t2;
    cin>>x>>y>>z;
    t2.setA(x);
    t2.setB(y);
    t2.setC(z);
    cout<<"Sides: "<<t2.getA()<<" "<<t2.getB()<<" "<<t2.getC()<<endl;

    return 0;
}
