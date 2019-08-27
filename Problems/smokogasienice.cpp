#include <bits/stdc++.h>
using namespace std;

const int bigN = 500*1000+10;
const int bigX = 1000*1000*1000+10;

float knights[bigN];
pair<double, double >dragons[bigN];
priority_queue< pair<double, int> >q;
pair<double, int> cosines[bigN];

int prices[bigN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int G, R;
    cin>>G>>R;

    for( int i=1; i<=G; i++)
    {
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        double r1 = sqrt(x1*x1+y1*y1);
        double cos1 = (double)(x1/r1);
        double r2 = sqrt(x2*x2 + y2*y2);
        double cos2 = (double)(x2/r2);
        dragons[i] = make_pair( max(cos1, cos2), min(cos1, cos2) );
        //cout<<"Dragon "<<i<<" "<<dragons[i].first<<" "<<dragons[i].second<<endl;
    }

    for( int i=1; i<=R; i++)
    {
        int x, y;
        cin>>x>>y;

        double r = sqrt(x*x+y*y);
        double cos = (double)(x/r);
        q.push( make_pair(cos, i) );
    }

    for( int i=R; i>=1; i--)
    {
        cosines[i] = q.top();
        //cout<<"Knight "<<i<<" "<<cosines[i].first<<endl;
        q.pop();
    }

    for(int g=1; g<=G; g++)
    {
        int right = R, left=1;
        int m = (left+right)/2;
        double east = dragons[g].first;
        double west = dragons[g].second;

        while( right > 0 && east < cosines[right].first )
            right--;
        int rightmost = right;

        while( left < R+1 && west > cosines[left].first)
            left++;
        int leftmost = left;


        /*

        while( !(m==R || m==1 || cosines[m].first <= east <= cosines[m+1].first) )
        {
            if( east < cosines[m].first )
                right = m;
            else if(cosines[m+1].first < east)
                left = m+1;

            m = (left+right)/2;
        }
        /*/

        //int rightmost = m;


        /*/
        right = R; left=1;
        m = (left+right)/2;

        while( !(m==R || m==1 || cosines[m-1].first <= west <= cosines[m].first) )
        {
            if( west < cosines[m-1].first )
                right = m-1;
            else if(cosines[m].first < west)
                left = m;

            m = (left+right)/2;
        }
        /*/


        //int leftmost = m+1;

        //cout<<"For dragon "<<g<<" spreading from "<<east<<" to "<<west<<" leftmost is "<<leftmost<<" rightmost is "<<rightmost<<endl;

        for( int k=leftmost; k<=rightmost; k++)
        {
            int index = cosines[k].second;
            prices[index]++;
        }
    }

    for(int i=1; i<=R; i++)
        cout<<prices[i]<<" ";

    return 0;
}
