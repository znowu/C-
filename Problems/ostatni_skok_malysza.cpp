#include <bits/stdc++.h>
using namespace std;
const int bigN = 2*10000*10000+10;
map <int, bool> zlozona;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;

    if(n<=8)
    {
        cout<<4<<" "<<4;
        return 0;
    }

    for(int i=7; i<=n; i+=2)
    {
        if(i%3 != 0 && i%5 != 0 && !zlozona[i] )
        {
            int k=2;
            while(i*k <= n)
            {
                zlozona[k*i] = true;
                k++;
            }
        }
    }

    int n1=4, n2=4;
    int p1=3, p2=5;

    for(int i=7; i<=n; i+=2)
    {
        if(i%3 != 0 && i%5 != 0 && !zlozona[i])
        {
            if(i-p2 > 1+n2 - n1+1)
            {
                n1 = p2+1;
                n2 = i-1;
            }
            p1 = p2;
            p2 = i;
        }
    }

    if( n%2 == 0 || n%3 == 0 || n%5 == 0 || zlozona[n] )
    {
        //cout<<"Last number is non prime"<<endl;
        if(n+1 - p2 > n2 - n1)
        {
            n1 = p2+1;
            n2 = n;
        }
    }

    //cout<<p1<<" "<<p2<<endl;
    cout<<n1<<" "<<n2;
    return 0;


}
