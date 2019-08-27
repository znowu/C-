#include <bits/stdc++.h>
using namespace std;
const int P = 1000*1000*1000+7;

int paths[110][110];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, k, d;
    cin>>n>>k>>d;

    for( int i=0; i<=n;i++)
        paths[i][i] = 1;

    for( int i=2; i<=n; i++)
    {
        for( int j=1; j < i; j++)
        {
            int suma1=0, suma2=0;
            for( int u=1; u<j; u++)
                    suma1 = (suma1+paths[i-u][j])%P;

            for(int v=j; v<=min(k, i); v++)
            {
                    suma2 = (suma2+paths[i-v][1])%P;
                    suma2 = (suma2+paths[i-v][0])%P;
            }
            paths[i][j] = (suma1+suma2)%P;

            //cout<<i<<" "<<j<<" "<<paths[i][j]<<endl;
        }
    }

    cout<<paths[n][d];
    return 0;
}
