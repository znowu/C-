#include <bits/stdc++.h>
using namespace std;

const int big = 1000*1000+10;
const long long INF = 1000000000000+10;

long long tree[4*big];
int baza; //2^something -1

vector <pair< int, long long> > ending_with[big];

void update(int place, long long val)
{
    place += baza;
    tree[place] = val;

    while( place > 1)
    {
        place /= 2;
        tree[place] = min(tree[2*place], tree[2*place+1]);
    }
}

long long best(int a, int b)
{
    a += baza; b += baza;
    long long result = min(tree[a], tree[b]);

    while( b-a > 1)
    {
        if(b%2 == 1)
            result = min(result, tree[b-1]);

        if(a%2 == 0)
            result = min(result, tree[a+1]);

        a /= 2; b /= 2;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    int p, k;
    long long c;

    for(int i=1; i<=m; i++)
    {
        cin>>p>>k>>c;
        ending_with[k].push_back( make_pair(p, c) );
    }

    baza = 1;
    while(baza < n)
        baza *=2;
    //baza--;

    for( int i=1; i<=n; i++)
    {
        update(i, INF);
    }

    for( int i=1; i<=n; i++)
    {
        int s = ending_with[i].size();
        for( int j=0; j<s; j++)
        {
            pair< int, long long> segment = ending_with[i][j];
            int start = segment.first;
            long long price = segment.second;

            long long optimal = best(start, i-1);
            if(optimal+price < tree[baza+i])
                update(i, optimal+price);
        }
    }

    cout<<tree[baza+n];
    return 0;
}

