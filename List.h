#pragma once
#pragma once
#include <iostream> 

using namespace std;

template<class T>
struct ForwardList
{
private:

	struct Node {
		Node(T data, Node* ptr) : data(data), ptr(ptr) {}
		Node* ptr;
		T data;
	};

	Node* Head;
	Node* End;
	static Node ForwardListEnd;
	int Size;
public:

	 ForwardList() noexcept : Head(&ForwardListEnd), End(&ForwardListEnd), Size(0) {}

	 ~ForwardList()
	{
		clear();
	}

	constexpr void pushFront(T data)
	{
		if (!Size)
		{
			Head = End = new Node(data, &ForwardListEnd);
		}
		else
		{
			Head = new Node(data, Head);
		}
		++Size;
	}

	constexpr void pushBack(T data)
	{
		if (!Size)
		{
			Head = End = new Node(data, &ForwardListEnd);
		}
		else
		{
			End->ptr = new Node(data, &ForwardListEnd);
			End = End->ptr;
		}
		++Size;
	}

	constexpr void popFront() {
		if (!Size) return;

		Node* tempNode = Head->ptr;
		delete Head;
		if (tempNode == &ForwardListEnd) {
			Head = End = &ForwardListEnd;
		}
		else
			Head = tempNode;
		--Size;
	}

	constexpr void printNode() const {
		const Node* current = Head;
		int i = 1;
		while (current != &ForwardListEnd) {
			cout << "Номер: " << i << endl;
			cout << "Адрес:\t" << current << "\tЗначение:\t" << current->data << endl;
			++i;
			current = current->ptr;
		}
		cout << "\nСписок окончен.\t" << "Элементов\t" << Size << endl;
		cout << "------------------------------------------------------" << endl;
	}

	constexpr void clear() {
		if (Head) {
			Node* current = Head;
			while (current != &ForwardListEnd) {
				Node* nextptr = current->ptr;
				delete current;
				current = nextptr;
			}
			Head = End = &ForwardListEnd;
			Size = 0;
		}
	}

	constexpr bool insert(T data, int index)
	{
		if (index < 0 || index > Size)
			return false;

		if (index == 0)
		{
			pushFront(data);
			return true;
		}
		if (index == Size)
		{
			pushBack(data);
			return true;
		}

		Node* current = Head;
		for (int i{ 0 }; i < index - 1; ++i)
			current = current->ptr;

		current->ptr = new Node(data, current->ptr);
		++Size;

		return true;
	}

	constexpr bool remove(int index) {
		if (index >= Size || index < 0)
			return false;

		if (index == 0) {
			popFront();
			return true;
		}

		Node* current = Head;
		for (int i{ 0 }; i < index - 1; ++i)
			current = current->ptr;
		Node* toDelete = current->ptr;
		current->ptr = toDelete->ptr; // Перелинковка

		if (toDelete == End) { // Исправлено: обновление End
			End = current;
		}
		delete toDelete;
		--Size;
		return true;
	}

	//T& operator [](int index) {
	//	if(index > Size || index < 0)
	//	Node* current = Head;
	//	int counter = 0;
	//	while (current) {
	//		if (counter == index)
	//			return current->data;
	//		current = current->ptr;
	//		counter++;
	//	}
	//	return *current;
	//}

	struct Iterator1
	{
		Iterator1(Node* start) : current(start) {}

		T& operator*() {
			return current->data;
		}

		const T& operator*() const
		{
			return current->data;
		}

		bool operator == (const Iterator1& other) const {
			return current == other.current;
		}

		bool operator!=(const Iterator1& other) const {
			return !(*this == other);
		}

		Iterator1& operator++() {
			if (current != nullptr && current != &ForwardListEnd)
				current = current->ptr;
			return *this;
		}

		Iterator1 operator++(T) {
			Iterator1 temp = *this;
			++(*this);
			return temp;
		}
	private:
		Node* current;
	};

	Iterator1 begin() {
		return Iterator1(Head);
	}

	Iterator1 end() {
		return Iterator1(&ForwardListEnd);
	}

	using const_Iterator1 = const Iterator1;

	constexpr bool remove(Iterator1 Iter) {
		if (Iter == Head) {
			popFront();
			return true;
		}
		if (Iter)
			return false;

		if (Iter == End) {
			Node* current = Head;
			for (; current->ptr == Iter; current = current->ptr) {
				delete End;
				current->ptr = nullptr;
				End = current;
				--Size;
				return true;
			}
		}
		Node* current = Head;
		for (current; current->ptr != Iter; current = current->ptr) {
			if (current->ptr == Iter) {
				Node* nextptr = current->ptr->ptr;
				delete current->ptr;
				current->ptr = nextptr;
				--Size;
				return true;
			}
		}
	}

	constexpr bool insert(T data, Iterator1 Iter)
	{

		if (Iter == Head)
		{
			pushFront(data);
			return true;
		}
		if (Iter == End) {
			pushBack(data);
			return true;
		}
		if (!Iter)
			return false;

		Node* current = Head;
		for (current; current == Iter; current = current->ptr) {
			Node* nextptr = current->ptr;
			current->ptr = new Node(data);
			current->ptr->ptr = nextptr;
			++Size;
			return true;

		}
	}

};

template<class T>
typename ForwardList<T>::Node ForwardList<T>::ForwardListEnd = typename ForwardList<T>::Node(T(), nullptr);


