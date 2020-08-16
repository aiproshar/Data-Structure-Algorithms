//Static implementation of Max Heap. Advantages over Dynamic: Constant element access time. Disadvantage: Max Capacity predefined
//author: aiproshar
//created : 4/29/2020 3:29AM GMT+6


#ifndef aiproshar_ds_heap
#define aiproshar_ds_heap
#endif // aiproshar_ds_heap
#define capacity 10000   //Maximum capacity of our HEAP, Static Data

class MinHeap
{
private:
    int size = 0;
    int data[capacity];
    void maxheapify_down();
    void maxheapify_up();

public:
    int pop();
    void push(int val);

};
#endif
