//arafat islam, 1507017, cse, KUET.
//aiproshar
///Solve of UVA-10130
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
int dp[1001][31];
int price[1001];
int weight[1001];
int cap;
int n;

int knapsack(int i , int w)
{
    if(i == n)
        return 0;
    int profit1 , profit2;
    if(w + weight[i] <= cap)
    {
        if(dp[i+1][w+weight[i]] == -1)
            dp[i+1][w+weight[i]] = knapsack(i+1 , w+weight[i]);
        profit1 = price[i] +  dp[i+1][w+weight[i]];
    }
    else
        profit1 = 0;
    if(dp[i+1][w] == -1)
        dp[i+1][w] = knapsack(i+1 , w);
    profit2 = dp[i+1][w];
    dp[i][w] = max(profit1 , profit2);
    return dp[i][w];
}

int main()
{
    //READ;
    //WRITE;
    int test;
    cin>>test;
    while(test--)
    {
        mset(price , 0);
        mset(weight , 0);
        mset(dp , -1);
        int ans = 0;
        cin>>n;
        for(int i = 0 ; i < n ; i++)
            cin>>price[i]>>weight[i];
        int people;
        cin>>people;
        while(people--)
        {
            cin>>cap;
            ans = ans + knapsack(0 , 0);
            mset(dp , -1); //this is where it took 5 hours for me to debug , i did not add this line
            //but this line must be added because the memory value must be recreated as depth of recursion is changing
            //following the values of upper nodes also changes. if we do not reset the memory , the previous values affects our
            //node value of new peoples
        }
        cout<<ans<<endl;
    }
    return 0;

}
