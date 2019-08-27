#include <bits/stdc++.h>
using namespace std;

const int bigN = 500*1000+10;

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

    cotan[0] = make_pair(double(-2000000), 0);
    cotan[R+1] = make_pair(double(2000000), R+1);


    for(int g=1; g<=G; g++)
    {
        //cout<<endl;
        //cout<<"Dragon "<<g<<endl;
        int right = R;
        int left=1;
        int m = (left+right)/2;
        double east = dragons[g].first;
        double west = dragons[g].second;
        int leftmost, rightmost;

        if(east < cotan[1].first)
            rightmost = 0;

        else
        {
            right = R; left = 1;
            m = (left+right)/2;
            int licznik=0;

            while( licznik<=R &&  (cotan[m].first > east || east >= cotan[m+1].first) )
            {
                licznik++;
                if(cotan[m].first > east)
                    right = m-1;

                else
                    left = m+1;

                m = (left+right)/2;
            }
            rightmost = m;

        }


        if(west > cotan[R].first)
            leftmost = R+1;

        else
        {
            right = R; left=1;
            m = (left+right)/2;

            int licznik = 0;
            while(  licznik <= R && ( cotan[m-1].first >= west || west > cotan[m].first ) )
            {
                licznik++;
                if(cotan[m-1].first >= west)
                    right = m-1;
                else
                    left = m+1;

                m = (left+right)/2;
            }
            leftmost = m;
        }

        //cout<<"For dragon "<<g<<" spreading from "<<east<<" to "<<west<<"\n"<<"leftmost is "<<leftmost<<" rightmost is "<<rightmost<<endl;

        for( int k=leftmost; k<=rightmost; k++)
        {
            int index = cotan[k].second;
            if( index >= 0)
                prices[index]++;
        }
    }

    for(int i=1; i<=R; i++)
        cout<<prices[i]<<" ";

    return 0;
}

