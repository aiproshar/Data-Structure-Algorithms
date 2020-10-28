#include <stdexcept>
template<typename T>
class Node
{
public:
	T data;
	Node* pre;
	Node* post;
	Node() {};
	Node(T data, Node* pre, Node* post)
		:data(data), pre(pre), post(post) {}

};
template<typename T>
class LinkedList: private Node<typename T>
{
	
private:
	unsigned long long int size_val;
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList()
		:size_val(0), head(nullptr), tail(nullptr)
	{
		head = nullptr;
		tail = nullptr;
	}
	~LinkedList()
	{
		for (register Node<T>* ptr = head; ptr != nullptr;)
		{
			Node<T>* temp = ptr;
			ptr = ptr->post;
			delete temp;	
		}
	}
	void push_front(T& data)
	{
		Node<T>* node = new Node<T>(data, nullptr, head);
		head->pre = node;
		if (tail == nullptr)
			tail = node;
		else
			head->pre = node;
		head = node;
		if (size_val == 1)
		{
			tail->pre = head;
			head->post = tail;
		}
		++size_val;
	}
	void push_back(T& data)
	{
		Node<T>* node = new Node<T>(data, tail, nullptr);
		if (head == nullptr)
			head = node;
		else
			tail->post = node;
		tail = node;

		if (size_val == 1)
		{
			head->post = tail;
			tail->pre = head;
		}
		++size_val;
	}
	T pop_front()
	{
		if (size_val == 0)
		{
			throw std::out_of_range("List Empty");
		}
		T val =  head->data;
		Node<T>* temp = head;
		head = head->post;
		if (head == nullptr)
			tail = nullptr;
		else
			head->pre = nullptr;
		delete temp;
		--size_val;
		return val;
	}
	T pop_back()
	{
		if (size_val == 0)
		{
			throw std::out_of_range("List Empty");
		}
		T val = tail->data;
		Node<T>* temp = tail;
		tail = tail->pre;
		if (tail == nullptr)
			head = nullptr;
		else
			tail->post = nullptr;
		delete temp;
		--size_val;
		return val;
	}
	T peek_front() const
	{
		return head->data;
	}
	T peek_back() const
	{
		return tail->data;
	}
	unsigned long long size() const
	{
		return size_val;
	}
};