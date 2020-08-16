//aiproshar
//code is based on the pseudo code from CLRS
//Time complexity : O(n^2)

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
#define READ                freopen("in.txt","r",stdin)
#define WRITE               freopen("out.txt","w",stdout)
//----------------------------------------------------------------------------------------
#include<bits/stdc++.h>
using namespace std;
int main()
{
   cout << "Enter Array Size : " << endl;
   int N;
   cin >> N;
   int arr[N];
   cout << "Enter Elements : " << endl;
   for(int i = 0 ; i < N ; i++)
    cin >> arr[i];


   for(int  i,j = 0; i < N; i++)
   {
       int key = arr[i];
       j = i - 1;
       while(j >= 0)
       {
           if(arr[j] > key)
           {
               arr[j+1] = arr[j];
               j--;
           }
           if(arr[j] <= key || j < 0)
           {
               arr[j+1] = key;
               break;
           }
       }

   }

   for(int i = 0 ; i < N ; i++)
   {
       cout << arr[i] <<" ";
   }
   return 0;
}
