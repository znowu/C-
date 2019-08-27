#include <bits/stdc++.h>
using namespace std;
const int bigN = 1001;
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
    string current = "";
    int point = 1, result=0;
    int col, row, col_, row_, point0;
    int current_length= 0;
    while(  point <= n*m)
    {
        col = (point + n-1)/n ;
        row = point - (col-1)*n;
        if( letter[row][col] == sacred[current_length] )
        {
            current = current + letter[row][col];
            current_length++;
            cout<<row<<" "<<col<<" "<<current<<endl;
            if(current == sacred)
            {
                for(int point0 = point; point0 >= point - current_length+1;  point0--)
                {
                    col_ = (point0+n-1)/n;
                    row_ = point0 - (col_-1)*n;
                    inSacred[row_][col_]+=1;
                    if(inSacred[row_][col_] == 2)
                        result++;
                }
                current = "";
                current_length=0;
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

    cout<<result;
    return 0;
}
