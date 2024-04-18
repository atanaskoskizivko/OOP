#include <iostream>
#include <cstring>
using namespace std;

class TennisPlayer
{
protected:
    string name;
    bool playsInLeague;
public:
    TennisPlayer(string name="",bool playsInLeague= false)
    {
       // cout<<"TP constructor"<<endl;
        this->name=name;
        this->playsInLeague=playsInLeague;
    }
    TennisPlayer(const TennisPlayer &tp)
    {
        this->name=tp.name;
        this->playsInLeague=tp.playsInLeague;
    }
    friend ostream &operator<<(ostream &out,const TennisPlayer &tp) {
        out << "TennisPlayer " + tp.name;
        if (tp.playsInLeague)
            out << " plays in league ";
        else
            out << " doesn't play in league";
        return out;
    }
    ~TennisPlayer()
    {
       // cout<<"TennisPlayer Destructor"<<endl;
    }
};

class RankedTennisPlayer:public TennisPlayer
{
private:
    int rank;
public:
    RankedTennisPlayer(string name=" ",bool playsInLeague= false,int rank=100): TennisPlayer(name,playsInLeague)
    {
      //  cout<<"RTP constructor"<<endl;
        this->rank=rank;
    }
    RankedTennisPlayer(const TennisPlayer &tp,int rank): TennisPlayer(tp)
    {
        this->rank=rank;
    }
    RankedTennisPlayer(const RankedTennisPlayer &other): TennisPlayer(other)
    {
        this->rank=other.rank;
    }
    friend ostream &operator<<(ostream &out,const RankedTennisPlayer &rtp)
    {
       out<<"Ranked";
       TennisPlayer tmp(rtp);
       out<<tmp<<", is ranked "<<rtp.rank<<endl;
       return out;
    }
    ~RankedTennisPlayer()
    {
        //cout<<"RankedTennisPlayer Destructor"<<endl;
    }
};


int main() {

    TennisPlayer tp("Roger Federer",true);
    cout<<tp<<endl;
    TennisPlayer tp1("Rafael Nadal",true);
    RankedTennisPlayer rtp1(tp1,50);
    cout<<rtp1;
    RankedTennisPlayer rtp("Novak Djokovic",true,10);
    cout<<rtp;
    return 0;
}
