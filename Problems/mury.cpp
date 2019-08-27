#include <bits/stdc++.h>
using namespace std;
const int bigN = 2*100005;
const int bigH = 5*100001;
int standing[bigH];
int hanging[bigH];

int upto[bigH];
int downto[bigH];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, H;
    cin>>N>>H;
    int length;
    int hang=0;
    int stand=0;

    for(int i=1; i<=N; i++)
    {
        cin>>length;
        if(i%2 == 1)
        {
            standing[length]+=1;
            stand += 1;
        }

        else
        {
            hang += 1;
            hanging[length]+=1;
        }
    }

    for(int h=1; h<=H; h++)
    {
        upto[h] = upto[h-1]+standing[h];
        downto[H-h+1] = downto[H-h+2] + hanging[h];
    }

    int minMurow= bigN+1;
    int places= 0;
    for( int h=1; h<=H; h++)
    {
        if( (stand - upto[h-1]) + (hang - downto[h+1]) < minMurow)
        {
            minMurow = (stand - upto[h-1]) + (hang - downto[h+1]);
            places= 1;
        }
        else if((stand - upto[h-1]) + (hang - downto[h+1]) == minMurow)
            places += 1;
    }

    cout<<minMurow<<" "<<places;
    return 0;

}
