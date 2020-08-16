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
int price[1001];
int weight[1001];
int cap;
int n;

int knapsack(int i , int w)
{
    if(i == n)//base case ( 0 based i indexing so equals means all objects are used :) )
        return 0;
    int profit1 , profit2;
    if(w + weight[i] <= cap)//we want to go to next state so want to check that overflow of capacity does not happen
        profit1 = price[i] + knapsack(i+1 , w+weight[i]);//we are taking the i-th object and going to next state
    else
        profit1 = 0;
    profit2 = knapsack(i+1 , w);//we are not taking i-th object and going to next state
    return max(profit1,profit2);
}

int main()
{
    int test;
    cout<<"Enter number of objects"<<endl;
    cin>>n;//no of objects
    cout<<"Enter maximum capacity"<<endl;
    cin>>cap;//maximum capacity
    cout<<"Enter price and weight of n objects"<<endl;
    for(int i = 0 ; i < n ; i++)
        cin>>weight[i]>>price[i];//price and weight input of n objects
    int ans = knapsack(0 , 0);//returns maximum possible value
    cout<<ans<<endl;
    return 0;
}
