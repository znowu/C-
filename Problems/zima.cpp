#include <bits/stdc++.h>
using namespace std;
const int bigN = 1000*1000+10;
int T[bigN];
int best[bigN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N;
    cin>>N;

    for(int i=1; i<=N; i++)
        cin>>T[i];

    best[N] = 1;
    for(int i=N-1; i>=1; i--)
    {
        int lost = T[i];
        if(i + lost + 1 > N)
            best[i] = best[i+1];

        else
            best[i] = max( best[i+1] , best[i+lost+1]+1);
    }
    cout<<best[1];
    return 0;
}
