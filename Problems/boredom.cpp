#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
long long p[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin>>n;
    int a;
    for( int i=1; i<=n; i++)
    {
        cin>>a;
        p[a] = (long long)(p[a]+a);
    }

    long long old_score= 0;
    long long current_score = p[1];
    long long new_score=0;

    for( int i=2; i<=N;i++)
    {
        new_score = max( (long long)current_score, (long long)(old_score+p[i]) );
        old_score = current_score;
        current_score= new_score;
    }

    cout<<current_score;
    return 0;

}
