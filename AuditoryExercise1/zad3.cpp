#include <iostream>
#include <cstring>
using namespace std;

struct Student {
    char name[50];
    char surname[50];
    char index[10];
    int totalPoints;
};

void normalize(char *name)
{
    name[0]= toupper(name[0]);
    for(int i=1;i< strlen(name);i++)
    {
        name[i]= tolower(name[i]);
    }

}
void read(Student &s)
{
    cin>>s.name>>s.surname>>s.index;
    normalize(s.name);
    normalize(s.surname);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    s.totalPoints=a+b+c+d;
}
void print(Student s)
{
    cout << s.name << "\t";
    cout << s.surname << "\t";
    cout << s.index << "\t";
    cout << s.totalPoints << endl;
}
void sort(Student s[], int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n - 1; ++j) {
            if(s[j].totalPoints < s[j + 1].totalPoints) {
                Student tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
        }
    }
}

int main() {
    Student s[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        read(s[i]);
    }
    sort(s, n);
    cout << "======== SPISOK: ========" << endl;
    for(int i = 0; i < n; ++i) {
        print(s[i]);
    }
    return 0;
}
