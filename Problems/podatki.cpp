#include <bits/stdc++.h>
using namespace std;
const int bigN = 500;
const int bigM = 500;

int tab[bigN+10][bigM+10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N, M;
    cin>>N>>M;
    int row = 0;
    int tradeof = 0;

    for( int n=1; n<=N; n++)
    {
        row=0;
        for( int m=1; m<=M; m++)
        {
            cin>>tradeof;
            row+=tradeof;
            tab[n][m] = tab[n-1][m]+row;
            //cout<<"At n="<<n<<" and m="<<m<<" tab is "<<tab[n][m]<<endl;

        }
    }

    int best = -1000000;
    for(int n1= 0; n1<=N; n1++)
    {
        for(int n2=n1+1; n2<=N; n2++)
        {
            int current = 0;
            for( int m=1; m<=M; m++)
            {
                int rec = tab[n2][m] - tab[n2][m-1] - tab[n1][m] + tab[n1][m-1];
                //cout<<n1<<" "<<n2<<" "<<m<<": "<<rec<<endl;
                if(current + rec < 0)
                {
                    if(current > best)
                        best = current;
                    current = 0;
                }
                else
                {
                    if(current > best)
                        best = current;
                    current += rec;
                    if( current>best)
                        best = current;
                }
            }
        }
    }

    cout<<best;
    return 0;
}
