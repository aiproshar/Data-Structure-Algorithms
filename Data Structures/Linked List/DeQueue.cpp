//Double Ended Quequ
//Contant push front/back
//constant pop front/back
//other than front/back element access,update all operations are O(n) :( 
//Dynamic +  Grabage Collection :) 

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
    Node *post = nullptr;
    Node *pre = nullptr;
};
class Deque
{
public:
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;
    void append_front(int x)
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
            head->pre = temp;
            temp->post = head;
            head = temp;
        }
    }
    void append_back(int x)
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
            tail->post = temp;
            temp->pre = tail;
            tail = temp;
        }
    }
    int at(int index)
    {
        assert(index < size);
        int current = 0;
        for (Node *traverse = head; traverse != nullptr; traverse = traverse->post, current++)
        {
            if (current == index)
            {
                return traverse->data;
            }
        }
    }
    int pop_front(void)
    {
        assert(size > 0);
        size--;
        int data = head->data;
        Node *temp = head;
        head = head->post;
        delete temp;
        return data;
    }
    int pop_back(void)
    {
        assert(size > 0);
        size--;
        int data = tail->data;
        Node *temp = tail;
        tail = tail->pre;
        delete temp;
        return data;
    }
};

int main()
{
    Deque Q;
    Q.append_back(10);
    Q.append_back(11);
    Q.append_front(9);
    Q.append_back(12);
    Q.append_front(8);
    Q.pop_back();
    Q.pop_front();
    Q.pop_front();
    for(int i = 0; i < Q.size; i++)
    {
        cout << Q.at(i) << " ";
    }
}