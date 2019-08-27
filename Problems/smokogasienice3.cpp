#include <bits/stdc++.h>
using namespace std;

const int bigN = 500*1000+10;
const int bigX = 1000*1000*1000+10;

float knights[bigN];
pair<double, double >dragons[bigN];
priority_queue< pair<double, int> >q;
pair<double, int> cotan[bigN];

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
        double cot1 = double(x1)/double(y1);
        double cot2 = double(x2)/double(y2);
        dragons[i] = make_pair( max(cot1, cot2), min(cot1, cot2) );
        //cout<<"Dragon "<<i<<" "<<dragons[i].first<<" "<<dragons[i].second<<endl;
    }

    for( int i=1; i<=R; i++)
    {
        int x, y;
        cin>>x>>y;

        double cot = double(x)/double(y);
        q.push( make_pair(cot, i) );
    }

    for( int i=R; i>=1; i--)
    {
        cotan[i] = q.top();
        //cout<<"ith cotan "<<cotan[i].first<<" "<<cotan[i].second<<endl;
        //cout<<"Knight "<<i<<" "<<cosines[i].first<<endl;
        q.pop();
    }

    for(int g=1; g<=G; g++)
    {
        //cout<<endl;
        //cout<<"Dragon "<<g<<endl;
        int right = R;
        int left=1;
        int m = (left+right)/2;
        double east = dragons[g].first;
        double west = dragons[g].second;

        //cout<<"East: "<<east<<" init right "<<cotan[right].first<<endl;
        while( right > 0 && east < cotan[right].first )
        {
            //cout<<east<<" and "<<cotan[right].first<<" so move left "<<endl;
            right--;
        }
        int rightmost = right;

        //cout<<"West: "<<west<<" init right "<<cotan[left].first<<endl;
        while( left < R+1 && west > cotan[left].first)
        {
            //cout<<west<<" and "<<cotan[left].first<<" so move right "<<endl;
            left++;
        }
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

        //cout<<"For dragon "<<g<<" spreading from "<<east<<" to "<<west<<"\n"<<"leftmost is "<<leftmost<<" rightmost is "<<rightmost<<endl;

        for( int k=leftmost; k<=rightmost; k++)
        {
            int index = cotan[k].second;
            prices[index]++;
        }
    }

    for(int i=1; i<=R; i++)
        cout<<prices[i]<<" ";

    return 0;
}
