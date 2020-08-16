#include <bits/stdc++.h>
#include "aiproshar_ds_heap.cpp"
using namespace std;

int main()
{
    cout << "Enter array size :";
    int n;
    cin >> n;
    MaxHeap A;
    for(int i = 0,temp; i < n ; i++)
    {
        cin >> temp;
        A.push(temp);
    }
    while(A.size())
        cout << A.pop() <<" ";

}
