#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
const int N = 3*100000+10;
int many_a[N];
int many_b[N];
long long factorial[N];
pair< int, int> pairs[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin>>n;

    factorial[0] = 1;
    factorial[1] = 1;
    for(int i=2; i<=n; i++)
        factorial[i] = (factorial[i-1]*i)%P;

    int a, b;
    for( int i=1; i<=n; i++)
    {
        cin>>a;
        cin>>b;
        many_a[a]++;
        many_b[b]++;
        pairs[i] = make_pair(a, b);
    }

    long long bad_a=1, bad_b=1;

    for(int i=1; i<=n; i++)
    {
        if(many_a[i]>1)
            bad_a = (bad_a * factorial[ many_a[i] ])%P;

        if(many_b[i]>1)
            bad_b = (bad_b * factorial[ many_b[i] ])%P;
    }

    //cout<<"Bad a and b "<<bad_a<<" "<<bad_b<<endl;
    sort(pairs+1, pairs+n+1);
    long long doubled=1;
    int counter=0;

    pair<int, int> last_pair = make_pair(0, 0);
    for( int i=1; i<=n; i++)
    {
        if(pairs[i].second < last_pair.second)
        {
            doubled= 0;
            break;
        }
        if( pairs[i] == last_pair )
            counter+=1;

        else
        {
            doubled = (doubled*factorial[counter+1])%P;
            last_pair = pairs[i];
            counter= 0;
        }

    }

    //cout<<"Doubled "<<doubled<<endl;
    long long bad = (P + P + bad_a + bad_b - doubled)%P;
    cout<<factorial[n]-bad;
    return 0;

}
