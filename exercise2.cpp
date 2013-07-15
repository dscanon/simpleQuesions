#include<iostream>
using namespace std;

template <class T>
class Node
{
public:
	Node();
	~Node();
	void addList(T value);
	void addListFormArray(T *a, int size);
	void print();
	void merge(Node<T> &h2);
private:
	struct Cell
	{
		T data;
		Cell *link;
	};
	Cell *start;
	Cell *cursor;
};

template <class T>
Node<T> ::Node()
{
	start = cursor = new Cell;
	start->link = NULL;
}

template <class T>
Node<T> :: ~Node()
{
	Cell *cp = start;
	while (cp != NULL)
	{
		Cell *next = cp->link;
		cout << "Destroy " << cp->data << endl;
		delete cp;
		cp = next;
	}
}

template <class T>
void Node<T> ::addList(T value)
{
	Cell *cp = new Cell();
	cp->data = value;
	cp->link = NULL;
	cursor->link = cp;
	cursor = cp;
}

template <class T>
void Node<T> ::addListFormArray(T *a, int size)
{
	int i = 0;
	while (i != size)
	{
		Cell *cp = new Cell();
		cp->data = a[i];
		cp->link = NULL;
		cursor->link = cp;
		cursor = cp;
		i++;
	}
}

template<class T>
void Node<T> ::print()
{
	Cell *cp = start->link;
	while (cp != NULL)
	{
		cout << cp->data << " ";
		cp = cp->link;
	}
	cout << endl;
}

template <class T>
void Node<T> :: merge(Node<T> &h2)
{
	if (start->link < h2.start->link)
	{
		Cell *cp1 = start->link;
		Cell *cp2 = h2.start->link;
		Cell *temp1 = cp1->link;
		Cell *temp2 = cp2->link;
		while (temp1 != NULL && temp2 != NULL)
		{
			if (cp1->data < cp2->data)
			{
				if (cp2->data < temp1->data)
				{
					cp1->link = cp2;
					cp1 = temp1;
					temp1 = temp1->link;
				}
				else
				{
					cp1 = temp1;
					temp1 = temp1->link;
				}
			}
			else if (cp2->data < cp1->data)
			{
				if (cp1->data < temp2->data)
				{
					cp2->link = cp1;
					cp2 = temp2;
					temp2 = temp2->link;
				}
				else
				{
					cp2 = temp2;
					temp2 = temp2->link;
				}
			}

		}
		if (temp1 == NULL && temp2 != NULL)
		{
			cp1->link = cp2;
		}
		if (temp2 == NULL && temp1 != NULL)
		{
			cp2->link = cp1;
		}
	}
	else
	{
		Cell *cp1 = h2.start->link;
		Cell *cp2 = start->link;
		Cell *temp1 = cp1->link;
		Cell *temp2 = cp2->link;
		while (temp1->link != NULL && temp2->link != NULL)
		{
			if (cp1->data < cp2->data)
			{
				if (cp2->data < temp1->data)
				{
					cp1->link = cp2;
					cp1 = temp1;
					temp1 = temp1->link;
				}
				else
				{
					cp1 = temp1;
					temp1 = temp1->link;
				}
			}
			else if (cp2->data < cp1->data)
			{
				if (cp1->data < temp2->data)
				{
					cp2->link = cp1;
					cp2 = temp2;
					temp2 = temp2->link;
				}
				else
				{
						cp2 = temp2;
						temp2 = temp2->link;
				}
			}
		}
		
		if (temp1 == NULL && temp2 != NULL)
		{
			cp1->link = cp2;
		}
		if (temp2 == NULL && temp1 != NULL)
		{
			cp2->link = cp1;
		}
	}
}

int main()
{
	cout << "--- create & print list ------\n";
	int a1 [] = { 1, 3, 5, 6, 9, 10 }; int a2 [] = { 2, 4, 7, 8 };
	Node<int> h1, h2;
	//--student part ให้นศ.สร้างลิสต์ h1 h2 จากข้อมูลใน a1 และ a2 นศ.อาจสร้างตัวแปรอื่นๆ เพิ่มได้----
	h1.addListFormArray(a1, sizeof(a1) / sizeof(a1[0]));
	h2.addListFormArray(a2, sizeof(a2) / sizeof(a2[0]));
	h1.print();
	h2.print();
	cout << "--- merge list ------\n";
	Node<int> h3;
	cout << "h1 = "; h1.print();
	cout << "h2 = "; h2.print();
	h1.merge(h2);
	h3 = h1;
	cout << "merging:h1+h2=h3\n";
	cout << "h3 = "; h3.print();
	cout << "h1 = "; h1.print();
	cout << "h2 = "; h2.print();
	return 0;
}