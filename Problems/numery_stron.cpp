#include <bits/stdc++.h>
using namespace std;

bool is_holy(int x)
{
    while( x> 0 && x%4 != 3)
    {
        if(x%4 ==2)
            x/=2;
        else if(x%4 == 0)
            x/= 4;
        else
            x/= 4;
    }
    if(x==0)
        return true;

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    cin>>N;
    int x;

    for(int i=1; i<=N; i++)
    {
        cin>>x;
        int power = 0;
        while( !is_holy(x+1) )
        {
            x/=2;
            power++;
        }
        int res = x+1;
        for( int i=1; i<= power; i++)
            res *= 2;

        cout<<res<<"\n";
    }

    return 0;
}
