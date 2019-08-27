#include <bits/stdc++.h>
using namespace std;
const int bigN = 1010;
char letter[bigN][bigN];
int inSacred[bigN][bigN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            cin>>letter[i][j];
    }

    int k;
    cin>>k;
    string sacred;
    cin>>sacred;
    string current;
    int point, current_length=0, res=0;

    for( int i=1; i<=n; i++)
    {
        current = "";
        current_length= 0;
        point = 1;
        while(  point <= m)
        {

            if( letter[i][point] == sacred[current_length] )
            {
                current = current + letter[i][point];
                current_length++;
                //cout<<"At i and point: "<<i<<" "<<point<<" current is "<<current<<endl;
                if(current == sacred)
                {
                    for(int u = point - k +1; u <= point; u++)
                    {
                        inSacred[i][u]+=1;
                        if(inSacred[i][u]==2)
                            res++;
                    }
                    current = "";
                    current_length= 0;
                }
                else
                    point+=1;

            }
            else
            {
                current = "";
                current_length=0;
                point+=1;
            }
        }
    }
    //cout<<endl;
    //////////////////////
    for( int i=1; i<=m; i++)
    {
        current = "";
        point = 1;
        current_length= 0;
        while( point <= n )
        {
            if( letter[point][i] == sacred[current_length] )
            {
                current = current + letter[point][i];
                current_length++;
                //cout<<"At i and point: "<<i<<" "<<point<<" current is "<<current<<" with length "<<current_length<<endl;
                if(current == sacred)
                {
                    for(int u = point - k +1; u <= point; u++)
                    {
                        inSacred[u][i]+=1;
                        //cout<<"u, i "<<u<<" "<<i<<" "<<inSacred[u][i]<<endl;
                        if(inSacred[u][i] == 2)
                            res++;
                    }
                    current = "";
                    current_length= 0;
                }
                else
                    point+=1;
            }
            else
            {
                current = "";
                current_length= 0;
                point+=1;
            }
        }
    }
    /////////////////////////////////////////////////
    for( int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cout<<inSacred[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<res;
    return 0;
}
