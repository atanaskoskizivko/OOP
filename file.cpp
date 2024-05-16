#include <iostream>
#include <fstream>
#include <ctype.h>
using namespace std;

int e_samoglaska(char c){
    c = tolower(c);
    return (c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u');
}
int main()
{
    ifstream fin("Primer.txt");
    if(!fin.is_open()){
        cout<<"Ne mozham da ja otvoram datotekata!"<<endl;
        return -1;
    }
    char c;
    int red = 0, vkupno = 0, samoglaski = 0;
    while(fin.get(c))
    {
        if(e_samoglaska(c)){
            ++samoglaski;
            ++vkupno;
        }
        if(c == '\n') {
            if(samoglaski > 10){
                red++;
            }
            samoglaski = 0;
        }
    }
    if(samoglaski > 10){
        red++;
    }
    cout<<"Vkupno "<<red<<" reda imaat povekje od 10 samoglaski"<<endl;
    cout<<"Vo datotekata ima vkupno "<<vkupno<<" samoglaski."<<endl;
    return 0;
}