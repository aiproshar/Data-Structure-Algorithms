//Static implementation of Max Heap. Advantages over Dynamic: Constant element access time. Disadvantage: Max Capacity predefined
//author: aiproshar
//created : 4/29/2020 3:29AM GMT+6

#include<bits/stdc++.h>
using namespace std;

#define capacity 10000   //Maximum capacity of our HEAP, Static Data

class MinHeap
{
private:
    int size = 0; //current size of heap, initialized as zero
    int data[capacity]; //MAX CAP defined by macro
    void maxheapify_down()
    /*
    If we replace root, we need to bubble down. Used when root is poped,
    so we replace root with last element, decrease the size and bubble down
    our replaced value which may violate our heap property
    */
    {
        int index = 1; //root index
        while(2*index <= size) //iterate as long as bubble down is valid, in siaze
        {
            if(2*index+1 > size) //only left child, no right child :(
            {
                if(data[2*index] > data[index]) //child is bigger, so swap values and change index to child
                {
                    swap(data[2*index],data[index]);
                    index = 2*index;
                }
                else
                    break; //has only left child and its smaller, so terminate :)
            }
            else if (data[index] < data[2*index] && data[2*index] >= data[2*index+1]) //has two child and left is bigger
            {
                swap(data[index],data[2*index]);
                index = index*2; //index to left child, we will iterate to check if it violates HEAP property
            }
            else if (data[index] < data[2*index+1] && data[2*index+1] > data[2*index]) //has two childs and right is bigger
            {
                swap(data[index],data[2*index+1]);
                index = index*2 + 1; //index to right child, same we will iterate again
            }
            else
                break; //has two childs and none is bigger :) / :(

        }
    }
    void maxheapify_up()
    /*
    Used when new element is added in the bottom of static array
    So we bubble it up until it satisfy heap property
    just compare with parent and if bigger then swap and change index, simpler then maxheapify_down
    Remember : Parent is always floor of index. 1(parent)->2,3(child); so 3/2 = 1.5, floor(1.5) = 1
    */
    {
        int index = size;

        while(floor(index/2)) //check if our parent is valid, if index == 1 then no parent
        {
            int parent = floor(index/2);
            if(data[parent] < data[index])
            {
                swap(data[parent],data[index]);
                index = floor(index/2); //swap done, change index to parent
            }
            else
                break; //parent bigger, so abort
        }
    }
public:
    int pop() //remove MAX element and return it
    {
        assert(size); //assert our heap is not empty
        int temp = data[1];//ROOT, MAX element of MAX_HEAP
        data[1] = data[size];//replace root with last element (leaf node)
        size--; //decrease the size
        maxheapify_down(); //Root Modified, property violated. So bubble down
        return temp;
    }
    void push(int val)
    {
        size++;
        data[size] = val;
        maxheapify_up(); //bubble up newly added element , so heap property is not violated
    }
};



int main()
{

    MinHeap A;
    int size;
    cout << "Enter Heap Size : ";
    cin >> size;
    cout << "Enter Heap Elements, separated by Space : ";
    for(int i = 0 ; i  < size ; i++)
    {
        int temp;
        cin >> temp;
        A.push(temp);
    }
    cout << "Heap Elements : ";
    for(int i = 0 ; i < size ; i++)
    {
        cout << A.pop() << " ";
    }
    return 0;
}
