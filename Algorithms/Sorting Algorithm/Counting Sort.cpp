#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 10000

int arr[MAX_SIZE];



int main()
{

    int n;
    cout << "Enter Array Size: ";
    cin >> n;
    cout << "Enter Elements : ";
    int data;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> data;
        arr[data]++;
    }
    for(int j = 0 ; j < MAX_SIZE ; j++)
    {
        while(arr[j])
        {
            arr[j]--;
            cout << j <<" ";
        }
    }
}


