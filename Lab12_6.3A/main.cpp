#include <iostream>
using namespace std;

struct Elem
{
	Elem* next,
		* prev;
	int info;
};

void enqueue(Elem*& first, Elem*& last, int info)
{
	Elem* tmp = new Elem;
	tmp->info = info;
	tmp->next = nullptr;
	if (last != nullptr)
		last->next = tmp;
	tmp->prev = last;
	last = tmp;
	if (first == nullptr)
		first = tmp;
}

int dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->next;
	int info = first->info;
	delete first;
	first = tmp;
	if (first == nullptr)
		last = nullptr;
	else
		first->prev = nullptr;
	return info;
}

void print(const Elem* first)
{
	int i = 0;
	while (first != nullptr)
	{
		cout << first->info << " ";
		i++;
		first = first->next;
	}
	cout << endl;
}

int count(Elem* first, int info)
{
	int k = 0;
	while (first != nullptr)
	{
		if (first->info == info) k++;
		first = first->next;
	}
	return k;
}

int main()
{
	Elem* first = nullptr, * last = nullptr;
	for (int i = 0; i < 10; i++)
		enqueue(first, last, rand() % 11);

	print(first);
	int info;
	cout << "search: "; cin >> info;
	cout << count(first, info) << endl;
	print(first);

	for (size_t i = 0; i < 10; i++)
		dequeue(first, last);
	
	return 0;
}