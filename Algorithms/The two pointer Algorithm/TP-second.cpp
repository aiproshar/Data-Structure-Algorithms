//The two pointer algorithm
//Second Demonstration - making two sorted arrays into one
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
Making two sorted array into one shorted array using two pointer
there are three pointers , two for the given shorted arrays and one for the answer array.
every pointer starts from head . The input pointers compare each other ans the less is assigned in
the answer array.The pointer value of both the answer and the array from where assigned from is increased.
There is a special case , if we go the the end of one array then we cant compare anymore , doing so will crash
the program or create unified behavior so a condition is given to handle the case before start comparing.
After handling , all we have to do is to assigning the value of left over array continuously.
And the loop will run in O(size of answer array). Remember the size of answer array is equal to the
summation of input arrays.
*/
#include<bits/stdc++.h>
using namespace std;
#define size1 10000
#define size2 10000
int arr1[size1];
int arr2[size2];
int ans[size1 + size2];
int main()
{
    for(int i = 0 ; i < size1 ; i++)arr1[i] = i*33; //assigning in first array
    for(int i = 0 ; i < size2 ; i++)arr2[i] = i*27; //assigning in second array
    int time = clock();
    int p3 = 0; //ans pointer
    int p1 = 0; //first pointer
    int p2 = 0; //second pointer
    while( p1 < size1 || p2 < size2)
    {
        if( p1 < size1 && p2 < size2) //special case handling
        {
            if(arr1[p1] > arr2[p2])
                ans[p3++] = arr2[p2++];
            else
                ans[p3++] = arr1[p1++];
        }
        else if( p1 < size1) //Special case , checking if this array has remaining values
            ans[p3++] = arr1[p1++];
        else //same as above
            ans[p3++] = arr1[p2++];
    }
    for(int i = 0 ; i < size1+size2 ; i++)
        cout<<ans[i]<<endl;
    cout<<"Time taken (ms) : "<<clock() - time;
    return 0;
}
















