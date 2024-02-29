#include<iostream>
#include<cstring>
using namespace std;

typedef struct Date
{
    int day;
    int month;
    int year;
};

void readDate(Date &d)
{
    cin>>d.day>>d.month>>d.year;
}

void printDate(Date d)
{
    cout<<d.day<<"."<<d.month<<"."<<d.year<<endl;
}

int compare(Date d1, Date d2)
{
    if(d1.year>d2.year)
    {
        return 1;
    }else if(d1.year<d2.year)
    {
        return -1;
    }else
    {
        if(d1.month>d2.month)
        {
            return 1;
        }else if(d1.month<d2.month)
        {
            return -1;
        }
        else
        {
            if(d1.day>d2.day)
            {
                return 1;
            }else if(d1.day<d2.day)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }

}

int daysDifference(Date d1, Date d2)
{
    int days=d1.day-d2.day;
    days+=(d1.month-d2.month)*30;
    days+=(d1.year-d2.year)*365;
    return days;
}


int main() {

    Date d1;
    Date d2;
    readDate(d1);
    readDate(d2);
    printDate(d1);
    printDate(d2);

    if(compare(d1,d2)==1)
    {
        cout<<"Razlikata vo denovi e "<<daysDifference(d1,d2)<<endl;
    }
    else if(compare(d1,d2)==-1)
    {
        cout<<"Razlikata vo denovi e "<<daysDifference(d2,d1)<<endl;
    }
    else
    {
        cout<<"Datumite se ednakvi"<<endl;
    }

    return 0;
}
