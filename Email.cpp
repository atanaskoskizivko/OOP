#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class EmailMessage
{
private:
    char sender[50];
    char recipient[50];
    char subject[30];
    char body[300];
public:
    EmailMessage(char *_sender="someone@finki.ukim.mk",char *_recipient="someone@gmail.com",char *_subject="OOP Labs", char *_body="Slots..")
    {
        strcpy(sender,_sender);
        strcpy(recipient,_recipient);
        strcpy(subject,_subject);
        strcpy(body,_body);
    }

    ~EmailMessage(){}

    void show()
    {
        cout<<"SENDER: "<<sender<<endl;
        cout<<"RECIPIENT: "<<recipient<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"SUBJECT: "<<subject<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"BODY: "<<body<<endl;
        cout<<"-----------------------------"<<endl;
        cout<<"END"<<endl;
    }
};

bool isValid(char adress[50])
{
    int idx=-1;  //ako ni treba i pozicijata na @
    for(int i=0;i< strlen(adress);i++)
    {
        if(adress[i]=='@')
        {
            idx=i;
        }
    }
    if(idx==-1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    char sender[50];
    char recipient[50];
    char subject[30];
    char body[300];
    cin>>sender;
    cin>>recipient;
    cin>>subject;
    cin>>body;
    if(isValid(sender) && isValid(recipient))
    {
        EmailMessage e1(sender,recipient,subject,body);
        e1.show();
    }
    else
    {
        cout<<"INVALID"<<endl;
    }


    return 0;
}
