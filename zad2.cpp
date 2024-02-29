#include<iostream>
#include<cstring>
using namespace std;

struct Vector
{
    int x;
    int y;
    int z;
};

void read(Vector &v)
{
    cin>>v.x>>v.y>>v.z;
}

void print(Vector v)
{
    cout<<"["<<v.x<<","<<v.y<<","<<v.z<<"]"<<endl;
}

int scalar_product(Vector v1,Vector v2)
{
    return v1.x*v2.x+v1.y*v2.y+v1.z*v2.z;
}

int main()
{
    struct Vector v1,v2;
    read(v1);
    read(v2);

    print(v1);
    print(v2);

    cout<<"a*b="<<scalar_product(v1,v2);
    return 0;
}

