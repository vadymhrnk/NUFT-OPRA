#include <iostream>

using namespace std;

struct p
{
	int e;
	p* prev;
	p* next;
};

void print(p* list) {
	while (list) {
		cout << list->e << " ";
		list = list->next;
	}
}

bool isSubset(p* set1, p* set2) {
	p* current = set1;
	while (current) {
		p* temp = set2;
		bool found = false;
		while (temp) {
			if (temp->e == current->e) {
				found = true;
				break;
			}
			temp = temp->next;
		}
		if (!found) {
			return false;
		}
		current = current->next;
	}
	return true;
}

int main()
{
	const int na = 5;
	const int nb = 6;
	int a[na] = { 5, 15, 4, 6 ,2 };
	int b[nb] = { 1, 4, 5, 2, 15, 6 }; 
	int i;
	p* begin1 = NULL;
	p* begin2 = NULL;
	p* last1 = NULL;
	p* list1 = NULL;

	i = 0;
	while (i < na)
	{
		last1 = new p;
		last1->e = a[i];
		if (begin1 == NULL)
		{
			last1->prev = NULL;
			last1->next = NULL;
			begin1 = last1;
		}
		else
		{
			list1->next = last1;
			last1->prev = list1;
			last1->next = NULL;
			list1 = last1;
		}
		list1 = last1;
		i++;
	}

	i = 0;
	while (i < nb)
	{
		last1 = new p;
		last1->e = b[i];
		if (begin2 == NULL) {
			last1->prev = NULL;
			last1->next = NULL;
			begin2 = last1;
		}
		else
		{
			list1->next = last1;
			last1->prev = list1;
			last1->next = NULL;
			list1 = last1;
		}
		list1 = last1;
		i++;
	}

	cout << "Set 1 = ";
	print(begin1);
	cout << "\nSet 2 = ";
	print(begin2);

	bool subset1 = isSubset(begin1, begin2);
	bool subset2 = isSubset(begin2, begin1);

	if (subset1)
		cout << "\nSet 1 is a subset of Set 2.";
	else
		cout << "\nSet 1 is not a subset of Set 2.";

	if (subset2)
		cout << "\nSet 2 is a subset of Set 1.";
	else
		cout << "\nSet 2 is not a subset of Set 1.";

	while (begin1) {
		list1 = begin1;
		begin1 = list1->next;
		delete list1;
	}

	while (begin2) {
		list1 = begin2;
		begin2 = list1->next;
		delete list1;
	}

	return 0;
}
