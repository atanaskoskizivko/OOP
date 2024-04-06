#include<iostream>
#include<cstring>
using namespace std;

class Speaker
{
private:
    char name[30];
    char title[50];
    int duration;

public:
    Speaker(char *name = "",char *title = "",int duration=0)
    {
        strcpy(this->name,name);
        strcpy(this->title,title);
        this->duration=duration;
    }
    Speaker(const Speaker &s)
    {
        strcpy(this->name,s.name);
        strcpy(this->title,s.title);
        this->duration=s.duration;
    }
    ~Speaker(){}
    friend ostream & operator<<(ostream &out, Speaker &s)
    {
        out<<s.name<<" - "<<s.title<<", "<<s.duration;
        return out;
    }

    int getDuration() {
        return duration;
    }
};

class Conference
{
private:
    char code[9];
    char date[11];
    Speaker *speakers;
    int number;
    static int maxDuration;
public:
    Conference(char *code="",char *date="")
    {
        strcpy(this->code,code);
        strcpy(this->date,date);
        speakers=0;
        number=0;
    }
    Conference(const Conference &c)
    {
        strcpy(this->code,c.code);
        strcpy(this->date,c.date);
        number=c.number;
        speakers=new Speaker[number];
        for(int i=0;i<number;i++)
        {
            speakers[i]=c.speakers[i];
        }
    }
    ~Conference()
    {
        delete []speakers;
    }
    static void setMaxDuration(int number)
    {
        maxDuration=number;
    }
    friend ostream &operator<<(ostream &out,Conference &c)
    {
        out<<c.code<<" - "<<c.date<<", "<<c.number;
        return out;
    }
    bool operator>(const Conference &c)
    {
        return number>c.number;
    }
    bool operator==(const Conference &c)
    {
        return strcmp(date,c.date)==0;
    }
    Conference& operator=(const Conference& dr)
    {
        if(this!=&dr){
            strcpy(this->code, dr.code);
            strcpy(this->date, dr.date);
            number = dr.number;
            delete [] speakers;
            speakers = new Speaker[number];
            for(int i=0;i<number;i++)
            {
                speakers[i] = dr.speakers[i];
            }
        }
        return *this;
    }
    Conference& operator+=(Speaker& s)
    {
        int total=0;
        for(int i=0;i<number;i++)
        {
            total+=speakers[i].getDuration();
        }
        if(s.getDuration()+total>360) {
            cout << "CANT ADD SPEAKER" << endl;
            return *this;
        }
        else {

            Speaker *tmp = new Speaker[number + 1];
            for (int i = 0; i < number; i++) {
                tmp[i] = speakers[i];
            }
            tmp[number++] = s;
            delete[] speakers;
            speakers = tmp;
            return *this;
        }
    }
    void longestPresentation() {
        int maxDuration = 0;
        int maxIndex = -1;

        for (int i = 0; i < number; i++) {
            if (speakers[i].getDuration() > maxDuration) {
                maxDuration = speakers[i].getDuration();
                maxIndex = i;
            }
        }

        if (maxIndex != -1) {
            cout << "Longest Presentation: " << speakers[maxIndex] << endl;
        }
    }
};
int Conference::maxDuration=360;
int main()
{
    int testCase;
    cin >> testCase;

    if (testCase == 0) {
        cout << "Speaker constructor" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);
        cout << "TEST PASSED" << endl;
    } else if (testCase == 1) {
        cout << "Speaker copy-constructor and operator=" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);

        Speaker c1 = speaker2;
        Speaker c3;
        c3 = speaker2;
        cout<<c3<<endl;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 2) {
        cout << "Speaker operator print" << endl;
        Speaker speaker1("Aleksandar Stojmenski", "Introduction to C++", 60);
        Speaker speaker2("Stefan Andonov", "Object-Oriented Programming", 120);
        Speaker speaker3("Boban Joksimoski", "Computer Animation", 180);
        cout<<speaker1<<endl;
        cout<<speaker2<<endl;
        cout<<speaker3<<endl;
        cout << "TEST PASSED" << endl;
    } else if (testCase == 3) {
        cout << "Conference class" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);

        Conference conference("CONF001", "2023-07-01");
        conference+=speaker1;
        conference+=speaker2;
        conference+=speaker3;

        cout << conference << endl;
    } else if (testCase == 4) {
        cout << "Conference constructors" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);

        Conference c("CONF001", "2023-07-01");
        c+=speaker1;
        c+=speaker2;
        Conference c1,c2 = c;
        c1 = c;
        c2+=speaker3;
        cout << c1 << endl;
        cout << c2 << endl;
    } else if (testCase == 5) {
        cout << "Conference operator> constructors" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);

        Conference c("CONF001", "2023-07-01");
        c+=speaker1;
        c+=speaker2;
        Conference c1,c2 = c;
        c2+=speaker3;
        if(c2>c)
        {
            cout<<"PASSED"<<endl;
        }
    } else if (testCase == 6) {
        cout << "longestPresentation and comparison" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);
        Conference conference("CONF001", "2023-07-01");

        conference+=speaker1;
        conference+=speaker2;
        conference+=speaker3;

        cout << "Conference: " << conference << endl;

        conference.longestPresentation();

        // Test case for comparison operators
        Conference conference2("CONF002", "2023-07-01");
        conference2+=speaker1;
        conference2+=speaker2;

        if (conference > conference2) {
            cout << "CONF001 has more speakers than CONF002." << endl;
        }
        else {
            cout << "CONF001 has fewer speakers than CONF002." << endl;
        }

        // Test case for exceeding duration limit
        Speaker speaker4("Sarah Adams", "Advanced C++ Programming", 240);

    } else if (testCase == 7) {
        cout << "Exception handling" << endl; //not for the first partial exam
        cout << "longestPresentation and comparison" << endl;
        Speaker speaker1("John Doe", "Introduction to C++", 60);
        Speaker speaker2("Jane Smith", "Object-Oriented Programming", 120);
        Speaker speaker3("David Johnson", "Data Structures and Algorithms", 180);
        Conference conference("CONF001", "2023-07-01");
        conference+=speaker1;
        conference+=speaker2;
        conference+=speaker3;
        Conference conference2("CONF002", "2023-07-01");
        conference2+=speaker1;
        conference2+=speaker2;
        if (conference > conference2) {
            cout << "CONF001 has more speakers than CONF002." << endl;
        }
        else {
            cout << "CONF001 has fewer speakers than CONF002." << endl;
        }
        Speaker speaker4("Sarah Adams", "Advanced C++ Programming", 240);
        conference+=speaker4;

    } else if (testCase == 8) {
        Conference conference4("CONF004", "2023-07-01");
        Conference conference5("CONF005", "2023-07-01");

        Speaker speaker9("Alex Turner", "Network Security", 120);
        Speaker speaker10("Olivia Parker", "Artificial Intelligence", 180);

        conference4+=speaker9;
        conference5+=speaker10;

        cout << "Conference 4: " << conference4 << endl;
        cout << "Conference 5: " << conference5 << endl;

        if (conference4 == conference5) {
            cout << "Conference 4 and Conference 5 have the same date." << endl;
        } else {
            cout << "Conference 4 and Conference 5 have different dates." << endl;
        }
    }else if (testCase == 9) {
        Conference conference3("CONF003", "2023-07-01");
        Conference::setMaxDuration(1000);
        Speaker speaker5("Michael Brown", "Web Development", 180);
        Speaker speaker6("Emily Davis", "Machine Learning", 240);
        Speaker speaker7("Robert Wilson", "Software Engineering", 120);

        conference3+=speaker5;
        conference3+=speaker6;
        conference3+=speaker7;

        cout << "Conference 3: " << conference3 << endl;

        Speaker speaker8("Jessica Lee", "Database Management", 180);


        conference3+=speaker8;
        cout<<conference3;
    }
    return 0;
}







