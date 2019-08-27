#include <bits/stdc++.h>
using namespace std;
const int N = 1000*1000+10; //tyle moge miec kubkow
const int P = 1000*1000*1000+9;
int tab[N]; //wartosc permutacji od liczby
bool wyjebana[N]; //czy liczba zostala juz wliczona w jakis cykl
int c=0;
vector<int> primes;//vector liczb pierwszych
int decomp[N]; //jaki jest exponent wyniku dla ktej liczby pierwszej
bool zlozona[N]; //czy dana liczba jest zlozona

long long my_pow(int a, int b)
{
    if(b==0)
        return 1;

    else if(b==1)
        return (long long)a;

    else if(b%2 == 0)
        return (my_pow(a, b/2) * my_pow(a, b/2) )%P;

    else return ( ( (long long)a*my_pow(a, b/2)%P)*my_pow(a, b/2))%P;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin>>n;
    int wyjebane= 0;

    bool already_set = true;
    for( int i=1; i<=n; i++)
    {
        cin>>tab[i];
        if( tab[i] != i)
            already_set = false;
    }

    if(already_set)
    {
        cout<<0;
        return 0;
    }

    for(int i=2; i<=n; i++)
    {
        if( !zlozona[i] )
        {
            int k=2;
            while(k*i <= n)
            {
                zlozona[k*i] = true;
                k++;
            }
            primes.push_back(i);
        }

    }
    //cout<<"I found all the primes"<<endl;

    int all_primes = primes.size();

    for( int i=1; i<=n; i++)
    {
        if( !wyjebana[i] )
        {
            int cycle_start=i; //start a new cycle
            int cycle_length=1; //it has currently length 1
            int j= tab[i]; //we go to its processor
            wyjebana[i] = true; //we have found a cycle for it

            while( j != cycle_start)
            {
                wyjebana[j] = true; //we mark that the new node has its cycle
                cycle_length++; //we therefore increase its length
                j = tab[j]; //and jump to a new element
            }
            //cout<<"Cycle length: "<<cycle_length<<endl;

            int temp= cycle_length;
            int u= 0; //we will decompose cycle_length
            while(temp > 1 && u < all_primes) //we search through all primes
            {
                int prime = primes[u];
                //cout<<"I am checking its divisibility by: "<<prime<<endl;
                int exponent= 0; //we compute the exponent of prime in cycle length

                while(temp%prime == 0)
                {
                    temp /= prime;
                    exponent ++;
                }

                //cout<<"It has exponent: "<<exponent<<endl;

                decomp[u] = max(exponent, decomp[u]); //we exchange the exponent of hcf to max
                u++;
                //cout<<"I corrected the decomposition"<<endl;
            }

        }
    }

    long long resultat=1;
    for(int u=0; u<all_primes; u++)
        resultat = (resultat * my_pow(primes[u], decomp[u]) )%P;

    cout<<resultat;
    return 0;

}
