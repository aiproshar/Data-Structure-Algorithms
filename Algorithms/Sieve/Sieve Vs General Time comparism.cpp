//arafat islam, 1507017, cse, KUET.
//aiproshar
//sieve of Eratosthenes VS Normal method
/*
   Compare between Time difference Between sieve and general method of finding prime
    for sieve memory complexity is O(N) and time complexity is O(log(logN))
    for normal method (little bit optimized) tome complexity is O(N^2) ans memory complexity is 1.
*/
#define LL                  long long
#define UL                  unsigned long long
#define PI                  acos(-1.0)
#define Di(x)               int x;scanf("%d",&x)
#define Si(x)               scanf("%d",&x);
#define So(x)               printf("%d",x)
#define pb                  push_back
#define mp                  make_pair
#define mset(name,value)    memset(name,value,sizeof(name))
#define IO                  ios_base::sync_with_stdio(0);cin.tie(0)
#define READ                freopen("C:/Users/arafat_islam/Desktop/in.txt","r",stdin)
#define WRITE               freopen("C:/Users/arafat_islam/Desktop/out.txt","w",stdout)
//----------------------------------------------------------------------------------------
#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
vector<int>v1; // We can also declare an static array here
//array must be declared globally so that sieve can access it
void sieve(void)
{
    v1[1] = 0;//1 is not prime
    for(int i = 2 ; i*i <= v1.size() ; i++)
    {
        if(v1[i])//if v1[i] == 1 that means prime
            for(int j = i ; j*i <= v1.size() ; j++)
                v1[j*i] = 0;
    }
}
bool isprime(LL x)
{
    if(x == 1)
        return false;
    if( x == 2)
        return true;
    if( x % 2 == 0)
        return false;
    for(int i = 3 ; i <=sqrt(x) ; i+=2)
    {
        if( x % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int size;
    cin>>size;
    v1.assign(size+1 , 1);
    int time = clock();
    sieve();
    //setting the memory to one. Indexing starts from 0 so size+1 is used
    //for static array use memset :)
    for(int i = 1 ; i <= v1.size() ; i++)
        if(v1[i]);
            //cout<<i<<endl;//if you wish you can comment out the this statement , it will print the primes
    cout<<"Time taken(ms) in sieve() : "<<clock() - time<<endl;//time taken after giving the input
    time = clock();
    for(int i = 1 ; i <= v1.size()-1 ; i++)
        if(isprime(i));
            //cout<<i<<endl;//if you wish you can comment out the this statement , it will print the primes
    cout<<"Time taken(ms) in isprime() : "<<clock() - time<<endl;

    return 0;
}
















