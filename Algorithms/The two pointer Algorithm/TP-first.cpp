//The two pointer algorithm
//First Demonstration - Finding the pair
//https://tp-iiita.quora.com/The-Two-Pointer-Algorithm
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
demonstration of a two pointer algorithm
this algorithm is applicable to a sorted array only. using two pointers (or indexing) simultaneously
we can compare and do calculation by setting one pointer to the head ans another to the tail.
in this example our task was to find out the index of two arrays whose summation will be equal to the given
input X. we can run a linear search (O(N^2)) or a binary search to find the element (x - arr[i]) as the given array is sorted.
but binary search will take O(N * log(N)) complexity. But using this two pointer algorithm we can find our result in O(N).
here N denotes size of array.
*/
/*WARNING : if there is multiple same value in the sorted array , all possible combination
not occur as you can see if we are able to find a pair we are increasing or decreasing our head index ans tail index
respectively,thus we are not using it again to check if he condition becomes true for that head or tail index and the values
of the opposite increased index.
This algorithm is better suited just for finding if there exist or not , not for finding all true
combinations.
1,2,2,3,4,5,6,7,8,9,10,11 and x = 11 ; in this case in tail pointer decreasing we will miss
the combination of third position and 9 as we will jump from 9 to the value 8 after the condition becomes true.
if we used head increasing in the upper test case , this code would work just fine but similar case can be
made ( 1,2,3,4,5,6,7,8,8,9,10 ans x = 9) so head increasing will fail.
THINK THINK THINK..........THINK MORE CODE LESS !!!!
*/

#include<bits/stdc++.h>
using namespace std;
int arr[100000000];
int main()
{
    int x ;
    cin>>x;
    int time = clock();
    for(int i = 0 ; i < 100000 ; i++)arr[i] = i; //sorted array
    int l = 0; //head
    int r = 100000 - 1; //tail
    while( l < r) // O(l+r) complexity :)
    {
        if(arr[l] + arr[r] == x)
        {
            cout<<"POSITIONS :"<<l<<" "<<r<<endl; //condition is true , prints out the positions :)
            r--; //tail decreasing
        }
        else if( arr[r] + arr[l] > x) //if greater then shift the right pointer to left
            r--; //tail decreasing
        else
            l++; //if smaller shift the right pointer to right
    }
    cout<<clock() - time; //prints the time taken to calculate after giving user input
    return 0;
}
















