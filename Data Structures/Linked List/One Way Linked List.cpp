//One-Way linked list.
//Dynamic Data Structure
//O(1) FIFO

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node(int x)
    {
        data = x;
    }
    int data;
    Node *ptr = nullptr;
};
class LinkedList
{
public:
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;
    void append(int x)
    {
        size++;
        Node *temp = new Node(x);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->ptr = temp;
            tail = temp;
        }
    }
    int at(int index)
    {
        assert(index < size);
        int current = 0;
        for(Node* traverse = head; traverse != nullptr; traverse = traverse->ptr,current++)
        {
            if (current == index)
            {
                return traverse->data;
            }
        }
    }
    int pop(void)
    {
        assert(size > 0);
        size--;
        int data = head->data;
        Node* temp = head;
        head = head->ptr;
        delete temp;
        return data;
        
    }
};

int main()
{
    LinkedList lst;
    lst.append(10);
    lst.append(11);
    lst.append(17);
    lst.pop();
    for(int i = 0; i < lst.size; i++)
    {
        cout << lst.at(i) <<" ";
    }
    return 0;
}