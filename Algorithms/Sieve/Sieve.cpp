//arafat islam, 1507017, cse, KUET.
//aiproshar
//sieve of Eratosthenes :)
/*
    The idea is simple , we will first memset the array into 1 then we will continuously set the non primes
    as  0. First we will loop through the multiples of 2. It is to be noted that we ran only to
    sqrt() of the given numbers , because if a number is not prime , its one factor of each factor pair ( a * b = number
    so in here one of number a) will be equal (if the number is square) or less than the sqrt() of the
    total number. so we just need to find out the multiples from 2 to sqrt() of total.
    To optimize the solution , we did not enter the loop for multiples of 4 , 6 , 8... as they were already
    marked zero by 2.And after finding a number which is not marked zero yet (means it is prime) , we start the loop
    from number*number or square of that number ( if we find five, we will start from 25 till sqrt()).We should
    have started from 2*that number but its not needed because the multiples of numbers smaller than square of that
    number was marked zero by the smaller prime numbers :)) . Like (10 , 15, 20 were marked zero by 2, 3 ,2 respectively)
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
            for(int j = i ; j*i <= v1.size() ; j++)//factor of all the primes until end, starts from i*i
                v1[j*i] = 0;
    }
}
int main()
{
    int size;
    cin>>size;
    int time = clock();
    v1.assign(size+1 , 1);//setting the memory to one. Indexing starts from 0 so size+1 is used
    //for static array use memset :)
    sieve();
    for(int i = 1 ; i <= v1.size() ; i++)
        if(v1[i])
            cout<<i<<endl;
    cout<<"Time taken(ms) : "<<clock() - time;//time taken after giving the input
    return 0;
}
















