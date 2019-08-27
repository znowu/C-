#include <bits/stdc++.h>
using namespace std;

const int bigN = 5*100001;
long long pref[bigN];
long long suf[bigN];
int downto[bigN];
int a[bigN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;

    int mod3=0;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        mod3 = (mod3+a[i])%3;
        pref[i] = pref[i-1] + (long long)a[i];
    }

    long long sum = pref[n];
    if(mod3 != 0)
    {
        cout<<0;
        return 0;
    }

    long long s=sum/3;

    for(int i=n; i >= 1; i--)
    {
        suf[i] = suf[i+1]+(long long)a[i];
        downto[i] = downto[i+1] + (suf[i]==s);
    }

    long long res=0;
    for(int i=1; i<=n-2; i++)
    {
        if(pref[i] == s)
            res = res + (long long)downto[i+2];
    }
    cout<<res;
    return 0;
}
