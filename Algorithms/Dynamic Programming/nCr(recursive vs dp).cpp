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
int dp[1000][1000];
UL call;
UL memory_use;
UL dp_nCr(int n , int r)
{
    call++;
    if(r == 1)
        return n;
    if(r == n)
        return 1;
    if( dp[n][r] != -1) {
        memory_use++;
        return dp[n][r];
    }
    dp[n][r] =  dp_nCr(n-1,r) + dp_nCr(n-1,r-1);
    return dp[n][r];
}



UL nCr(int n , int r)
{
    call++;
    if(r == 1)
        return n;
    if(r == n)
        return 1;
    return nCr(n-1,r) + nCr(n-1,r-1);
}



int main()
{
    mset(dp,-1);
    int x,y;
    cin>>x>>y;
    int time = clock();
    cout<<"Ans : "<<dp_nCr(x,y)<<endl;
    cout<<"Total function Call : "<<call<<" "<<"Memory_access : "<<memory_use<<endl;
    cout<<"Time taken in dp : "<<clock()-time<<endl<<endl<<endl;
    time = clock();
    call = 0 ; memory_use = 0;
    cout<<"ANs : "<<nCr(x,y)<<endl;
    cout<<"Total function Call : "<<call<<" "<<"Memory_access : "<<memory_use<<endl;
    cout<<"Time taken in recursion : "<<clock()-time<<endl;
    return 0;
}
