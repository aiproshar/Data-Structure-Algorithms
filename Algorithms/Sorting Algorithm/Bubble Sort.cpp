//aiproshar
//code is based on the pseudo code from CLRS
//Time complexity : Depends on the array. In best case its n and worst case n^2

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
int main()
{
    int n;
    cout<<"Input array size : ";
    cin>>n;
    cout<<"Enter the elements : ";
    int arr[n];
    for(int i= 0 ;  i < n ; i++)
        cin>>arr[i];
    for(int i = 0 ; i < n-1 ; i++)
    {
        for(int j = 0 ; j < n-1; j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[j] , arr[j+1]);
        }
    }
    for(int i = 0 ; i < n ; i++)
        cout<<arr[i]<<" ";
    return 0;

}





