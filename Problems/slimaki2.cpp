#include <bits/stdc++.h>
using namespace std;

const int bigN = 1000+5;
const int bigM = 1000+5;

//char field[bigN][bigM];
short ingrid[bigN][bigM];
int d[bigN][bigM];
bool vis[bigN][bigM];

vector < pair< int, int > > v[bigN][bigM];
priority_queue< pair<int, pair<int, int> > >q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, M, C;
    cin>>N>>M>>C;

    for( int n=1; n<=N; n++)
    {
        for( int m=1; m<=M; m++)
            ingrid[n][m] = 1;
    }

    int x, y;
    char type;

    for( int c = 1; c <= C; c++)
    {
        cin>>x>>y;
        cin>>type;

        if(type == 'x')
            ingrid[x][y] = 0;

        else if(type == 'o')
            ingrid[x][y] = 2;
    }

    //If a field is normal in the grid, then it has value 1. If it is radio-active, it has value 2. Otherwise, it has value 0.

    //ingrid[0][0] = 2;
    //The invisible root is of no weight.

    for( int n=1; n<=N; n++)
    {
        for( int m=1; m <= M; m++)
        {
            if(ingrid[n-1][m] > 0)
                v[n][m].push_back( make_pair(n-1, m) );

            if(ingrid[n-1][m+1] > 0)
                v[n][m].push_back( make_pair(n-1, m+1) );

            if(ingrid[n][m+1] > 0)
                v[n][m].push_back( make_pair(n, m+1) );

            if(ingrid[n+1][m] > 0)
                v[n][m].push_back( make_pair(n+1, m) );

            if(ingrid[n+1][m-1] > 0)
                v[n][m].push_back( make_pair(n+1, m-1) );

            if(ingrid[n][m-1] > 0)
                v[n][m].push_back( make_pair(n, m-1) );
        }

        if(ingrid[n][1] > 0)
            v[0][0].push_back( make_pair(n, 1) );

        if(ingrid[n][M] > 0)
            v[n][M].push_back( make_pair(0, M+1) );
    }

    /*/
    cout<<"I will show the vector of interest \n";
    int s = v[3][2].size();
    for( int i =0 ; i<s; i++)
        cout<<v[3][2][i].first<<" "<<v[3][2][i].second<<"\n";
    /*/

    //cout<<"I will try "<<n<<", "<<M<<"\n";
    int INF = 2* bigN*bigM;
    int best = INF;

    for( int i=1; i<=N; i++)
    {
        for( int j=1; j<=M; j++)
        {
            d[i][j] = INF;
            vis[i][j] = false;
        }
    }

    d[0][M+1] = INF;
    vis[0][M+1] = false;

    //cout<<"I think it is "<<d[n][M]<<"\n";

    for( int i=1; i<=N; i++)
    {
        for( int j=1; j<=M; j++)
            q.push( make_pair( -d[i][j], make_pair(i, j) ) );
    }

    q.push( make_pair(-d[0][M+1], make_pair(0, M+1) ) );
    q.push( make_pair(-d[0][0], make_pair(0, 0) ) );

    while( !q.empty() )
    {
        pair< int, pair<int, int> > top_ = q.top();
        q.pop();
        pair<int, int> xy = top_.second;
        int x = xy.first;
        int y = xy.second;
        vis[x][y] = true;

        int s = v[x][y].size();

        for( int i=0; i<s; i++)
        {
            pair< int, int> uk = v[x][y][i];
            int u = uk.first;
            int k = uk.second;

            if(!vis[u][k])
            {
                if(d[x][y] + (ingrid[u][k]==1) < d[u][k] )
                {
                    //cout<<"I am changing "<<u<<","<<k<<" from "<<d[u][k]<<" to "<<d[x][y]+(field[u][k]==0)<<"\n";
                    d[u][k] = d[x][y] + (ingrid[u][k]==1);
                    q.push( make_pair(-d[u][k], make_pair(u, k) ) );

                }
            }
        }

    }

    if( d[0][M+1] == INF)
        cout<<-1;
    else
        cout<<d[0][M+1];

    return 0;
}
