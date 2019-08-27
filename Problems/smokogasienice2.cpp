#include <bits/stdc++.h>
using namespace std;

int big = 1000*1000;
pair<int, int> knights[big];
pair<int, int> kopiec[2*big];
pair< pair<int, int>, pair<int, int> >dragons[big];

pair< pair< int, int>, int> pop(int heap_size)
{
    int n = heap_size;
    pair< pair<int, int>, int> peak = kopiec[1];
    kopiec[1] = kopiec[n];
    heap_size = n-1;

    int vertex = 1;
    pair< pair<int, int>, int> node = kopiec[1];
    int x = node.first.first;
    int y = node.first.second;

    while(2*v < x*kopiec[2*v].first.second < kopiec[2*v].first.first*y || x*kopiec[2*v+1].first.second < kopiec[2*v+1].first.first*y)
    {

    }
}
