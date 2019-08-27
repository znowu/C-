#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
string name[N];
int score[N];
bool wyjebany[N];
vector<int> winner_history;
vector<int> challenger_history;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;

    for( int i=1; i<=n; i++)
        cin>>name[i]>>score[i];

    int i=0;
    string Name="";
    int Last=0;
    int Score=0;
    int wyjebani=0;
    int Beating=0;
    pair< string, int > winner= make_pair("", -1);

    while(wyjebani < n)
    {
        i=1;
        while(wyjebany[i])
            i++;
        Name = name[i];
        Last = 0;
        Score = 0;
        Beating= 0;
        challenger_history.clear();

        for(int k=i; k<=n; k++)
        {
            if(name[k] == Name)
            {
                challenger_history.push_back(k);
                wyjebany[k] = true;
                wyjebani++;
                Score += score[k];
                if(Score >= winner.second && Beating==0)
                    Beating= k;

            }
        }
        //cout<<"Winner name: "<<winner.first<<endl;
        //cout<<"Winner score: "<<winner.second<<endl;
        //cout<<"Challenger name: "<<Name<<endl;
        //cout<<"He has beaten the score at: "<<Beating<<endl;

        int champBeating=0;
        int chempRes = 0;
        int s = winner_history.size();
        for(int x=0; x<s; x++)
        {
            chempRes +=  score[ winner_history[x] ];
            if(chempRes >= winner.second)
            {
                champBeating = winner_history[x];
                break;
            }
        }

        //cout<<"Current winner has beaten his score at: "<<champBeating<<endl;

        if(Score > winner.second || (Score == winner.second && champBeating>Beating) )
        {
            winner = make_pair(Name,Score);
            winner_history = challenger_history;
        }

    }


    cout<<winner.first;
    return 0;
}
