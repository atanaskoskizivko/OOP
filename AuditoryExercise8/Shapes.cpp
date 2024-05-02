#include <iostream>
#include <cstring>

using namespace std;

class Shapes
{
protected:
    double height;
public:
    Shapes(double height=0)
    {
        this->height=height;
    }
    virtual void print()=0;
    virtual double volume()=0;
    double getHeight()
    {
        return height;
    }
};
class Cylinder : public Shapes
{
private:
    double radius;
public:
    Cylinder(double height, double radius): Shapes(height)
    {
        this->radius=radius;
    }
    void print()
    {
        cout<<"Cilindar so radius "<<radius<<" i visina "<<Shapes::getHeight()<<endl;
    }
    double volume()
    {
        return radius*radius*3.14*getHeight();
    }
    double getRadius()
    {
        return radius;
    }


};

class Cone : public Shapes
{
private:
    double radius;
public:
    Cone(double height, double radius): Shapes(height)
    {
        this->radius=radius;
    }
    void print()
    {
        cout<<"Konus so radius "<<radius<<" i visina "<<Shapes::getHeight()<<endl;
    }
    double volume()
    {
        return radius*radius*3.14*getHeight()/3.0;
    }
    double getRadius()
    {
        return radius;
    }
};

class Cuboid : public Shapes
{
private:
    double a,b;
public:
    Cuboid(double height, double a,double b): Shapes(height)
    {
        this->a=a;
        this->b=b;
    }
    void print()
    {
        cout<<"Kvadar so osnovi "<<a<<" i "<<b<<" i visina "<<Shapes::getHeight()<<endl;
    }
    double volume()
    {
        return a*b*getHeight();
    }
};

void shapeWithMaxVolume(Shapes **shapes, int n)
{
    double maxVolume=0;
    int idx=0;
    for(int i=0;i<n;i++)
    {
        if(shapes[i]->volume()>maxVolume)
        {
            maxVolume=shapes[i]->volume();
            idx=i;
        }
    }
    cout<<"Shape with max volume is: "<<endl;
    shapes[idx]->print();
}

double getRadius(Shapes *s)
{
    Cylinder *c=dynamic_cast<Cylinder*>(s);
    if(c!= nullptr)
    {
        return c->getRadius();
    }

    Cone *k=dynamic_cast<Cone*>(s);
    if(k!=nullptr)
    {
        return k->getRadius();
    }
    return -1;

}

int main()
{
    int n;
    cin>>n;
    Shapes **shapes=new Shapes * [n];
    double r,h,a,b;
    int type;//1-cilindar 2 - konus 3-kvadar
    for(int i=0;i<n;i++)
    {
        cin>>type;
        if(type==1)
        {
            cin>>r>>h;
            shapes[i]=new Cylinder(h,r);
        }
        else if(type==2)
        {
            cin>>r>>h;
            shapes[i]=new Cone(h,r);
        }
        else
        {
            cin>>a>>b>>h;
            shapes[i]=new Cuboid(h,a,b);
        }
       // shapes[i]->print();
    }

    shapeWithMaxVolume(shapes,n);
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(getRadius(shapes[i])==-1)
        {
            count++;
        }
    }
    cout<<"Brojot na tela koi nemaat osnova krug e: "<<count<<endl;
    return 0;
}
