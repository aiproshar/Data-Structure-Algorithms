//arafat islam, 1507017, cse, KUET.
//aiproshar
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
using namespace std;
UL dp[1000];

UL fibdynamic(int x)
{
    if( x == 1 || x == 2)
        return 1;
    else if(dp[x] != -1)
        return dp[x];
    else
    {
        dp[x]= fibdynamic(x-1)+ fibdynamic(x-2);
        return dp[x];
    }
}
UL fib(int x)
{
    if( x == 1 || x == 2)
        return 1;
    else
        return fib(x-1)+ fib(x-2);
}

int main()
{
    mset(dp , -1);
    int n;
    cin>>n;
    int time = clock();
    for(int i = 1 ; i <= n ; i++)
        cout<<i<<" : "<<fib(i)<<endl;
    cout<<"Time taken(ms): "<<clock() - time<<endl;

    time = clock();
    for(int i = 1 ; i <= n ; i++)
        cout<<i<<" : "<<fibdynamic(i)<<endl;
    cout<<"Time taken in dynamic(ms): "<<clock() - time<<endl;
}
