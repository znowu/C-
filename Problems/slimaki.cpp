#include <bits/stdc++.h>
using namespace std;

const int bigN = 1001;
const int bigM = 1001;

char table[bigN][bigM];
int bombs[bigN][bigM];
int res[bigN][bigM];

int main()
{
    ios_base::sync_with_stdio(0);

    //Read data
    int N, M, C;
    cin>>N>>M>>C;
    int x, y;
    char field;

    for( int n=1; n<=N; n++)
        for( int m=1; m<=M; m++)
        {
            bombs[n][m] = 1;
        }

    for( int i=1; i<=C; i++)
    {
        cin>>x>>y;
        cin>>field;
        table[x][y] = field;

        if( y == 1 )
        {
            if( field == 'o')
                bombs[x][y] = 0;

            else
                bombs[x][y] = -1;
        }
    }

    cout<<"Displaying initial guesses for bombs \n";
    for( int m=M; m>=1; m--)
    {
        for( int n=1; n<=N; n++)
            cout<<bombs[n][m]<<" ";

        cout<<"\n";
    }

    //Compute bombs down

    for(int m=2; m<=M; m++)
    {
        for(int n = 1; n<=N; n++)
        {

            if(n == N)
            {
                if(bombs[n][m-1] == -1 || table[n][m] == 'x')
                    bombs[n][m] = -1;

                else
                    bombs[n][m] = bombs[n][m-1] + (table[n][m] == 0);
            }
            else
            {
                if( (bombs[n][m-1] == -1 && bombs[n+1][m-1] == -1) || table[n][m] == 'x')
                    bombs[n][m] = -1;

                else
                    bombs[n][m] = min( bombs[n][m-1], bombs[n+1][m-1]) + (table[n][m] == 0);
            }

        }
    }

    cout<<"Displaying bombs down \n";
    for( int m=M; m >= 1; m--)
    {
        for( int n=1; n<= N; n++)
            cout<<bombs[n][m]<<" ";

        cout<<"\n";

    }



    //Compute result
    for(int n=1; n<=N; n++)
    {
        res[n][1] = bombs[n][1];
    }


    for(int m = 2; m<=M; m++)
    {
        for(int n=1; n<=N; n++)
        {
            int best = 0;

            if(n == 1)
            {
                int others[] = {bombs[n][m]-1, bombs[n+1][m], bombs[n][m-1], bombs[n+1][m-1]};
                best = *min_element(others, others+4);
                if( best == -2)
                    res[n][m] = -1;
                else
                    res[n][m] = best + (table[n][m] == 0);


            }
            else if(n == N)
            {
                int others[] = {bombs[n][m]-1, bombs[n-1][m], bombs[n][m-1], bombs[n+1][m-1]};
                best = *min_element(others, others+4);
                if( best == -2)
                    res[n][m] = -1;
                else
                    res[n][m] = best + (table[n][m] == 0);
            }
            else
            {
                int others[] = {bombs[n][m]-1, bombs[n-1][m], bombs[n+1][m], bombs[n][m-1], bombs[n+1][m-1]};
                best = *min_element(others, others+5);
                if( best == -2)
                    res[n][m] = -1;
                else
                    res[n][m] = best + (table[n][m] == 0);
            }

        }

    }

    int minBombs = 1001*1001+1;
    int output = -1;

    for( int n=1; n<=N; n++)
    {
        //cout<<res[n][M]<<" ";

        if(res[n][M] < minBombs && res[n][M] != -1)
        {
            minBombs = res[n][M];
            output = minBombs;
        }
    }

    cout<<"\n";
    cout<<"The final answer is: "<<output;
    return 0;
}
