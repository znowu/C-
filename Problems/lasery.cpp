#include <bits/stdc++.h>
using namespace std;

const int bigN = 5*10000+10;
const int bigM = 1000*1000+10;

pair<int, int> tower[bigM];
vector<int> tow_in_col[bigN];
vector<int> tow_in_row[bigN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, M, row, col;
    cin>>N>>M;

    for( int i=1; i<=M; i++)
    {
        cin>>row>>col;
        tow_in_col[col].push_back(row);
        tow_in_row[row].push_back(col);

        tower[i] = make_pair(row, col);
    }

    int good=0;

    for( int i=1; i<=M; i++)
    {
        pair< int, int> tow = tower[i];
        row = tow.first; col = tow.second;

        if( tow_in_col[col].size() == 1 && tow_in_row[row].size() == 1)
            good++;
    }

    cout<<good;
    return 0;
}
