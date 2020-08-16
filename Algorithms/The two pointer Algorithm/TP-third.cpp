//The two pointer algorithm
//third - implementation in problem solving
//http://www.spoj.com/problems/HOTELS/
//

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
/*
starting two pointers in the head and then shifting the right pointer to the right to increase
the summation until it increase. when summation increases in the condition checking (not increasing actually , we are just
checking in the condition ) , we compare it with the current maximum and decreases by one array. If the summation still
remains bigger in the condition checking , we just decrease it again and this goes on.When increasing does not breaks
the condition , we enter the while loop and increase the value of summation until it breaks .
And we goes through until the left pointer(honestly second , both of them starts from the right) reaches the end.

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int SIZE , x , answer = 0;
    cin>>SIZE>>x;
    int arr[SIZE];
    mset(arr,0);
    int sum = 0;
    for(int i = 0 ; i < SIZE ; i++)
    {
        int temp;
        cin>>temp;
        arr[i] = temp;
    }
    int l = 0 , r = 0;
    while(l < SIZE) // Until second pointer reaches he end
    {
        while( r < SIZE && arr[r] + sum <= x ) //while increasing value does not exceed the given limit
        {
            sum = sum + arr[r];
            r++;
        }
        answer = max(answer , sum);
        sum = sum - arr[l]; // Now increasing will exceed the limit , so we are decreasing it first
        l++;                //so that we can check it in the while loop again. If if fails , we will decrease it again :)
    }
    cout<<answer<<endl;
    return 0;
}
