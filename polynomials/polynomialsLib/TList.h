#pragma once
#include <iostream>

template <class T>
struct Link
{
	T value;
	Link* next;

	Link<T>(T _value = 0, Link* _next = nullptr) : value(_value), next(_next) {}
};

template <class T>
class List {
	Link<T>* first;
	Link<T>* last;
public:
	List() : first(nullptr), last(nullptr) { }

	List(const List<T>& p) {
		first = last = nullptr;
		if (p.first != nullptr)
		{
			first = new Link<T>(p.first->value);
			Link<T>* l1, * l2;
			l1 = p.first->next;
			l2 = first;
			while (l1 != nullptr) {
				l2->next = new Link<T>(l1->value);
				l2 = l2->next;
				l1 = l1->next;
			}
			last = l2;
		}
	}

	~List() { clean(); }

	void clean() {
		while (first != nullptr) 
			pop_front();
	}

	void push_front(T value) {
		Link<T>* p = new Link<T>(value, first);
		first = p;
		if (first->next == nullptr)
			last = first;
	}

	void push_back(T value) {
		if (first == nullptr) push_front(value);
		else {
			Link<T>* p = new Link<T>(value);
			last->next = p;
			last = last->next;
		}
	}

	void pop_front() {
		if (first == nullptr) throw - 1;
		Link<T>* p;
		p = first;
		first = first->next;
		delete p;
	}

	void pop_back() {
		if (last == nullptr) throw - 1;
		Link<T>* p, * p1;
		p = first;
		while (p->next->next != nullptr)
			p = p->next;
		p1 = p->next;
		p->next = NULL;
		last = p;
		delete p1;
	}

	bool empty()
	{
		return first == nullptr;
	}

	Link<T>* front() {
		return first;
	}

	bool operator==(const List& l) {
		Link<T>* p1, * p2;
		p1 = first;
		p2 = l.first;
		while (p1 != nullptr && p2 != nullptr) {
			if (p1->value != p2->value) return false;
			p1 = p1->next;
			p2 = p2->next;
		}
		return !((p1 == nullptr && p2 != nullptr) || (p1 != nullptr && p2 == nullptr));
	}

	List& operator=(const List& p) {
		if (this == &p) return *this;

		if (first != nullptr) clean();
		if (p.first == nullptr) throw - 1;
		first = new Link<T>(p.first->value);
		Link<T>* t1, * t2;
		t1 = p.first->next;
		t2 = first;
		while (t1 != nullptr) {
			t2->next = new Link<T>(t1->value);
			t2 = t2->next;
			t1 = t1->next;
		}
		last = t2;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& o, List<T>& p) {
		Link<T>* t = p.first;
		while (t != nullptr) {
			o << t->value;
			t = t->next;
		}
		o << std::endl;
		return o;
	}
};


