#include<iostream>
using namespace std;

template <class T, int MAX = 10>
class stack
{
	T item[MAX];
	int top;
public:
	stack() : top(-1){}
	void push(const T& i){ if (top < MAX - 1) item[++top] = i; }
	T pop(){ if (MAX != -1) return item[top--]; }
	void print()
	{
		for (int i = 0; i <= top; i++)
			cout << item[i] << "  ";
		cout << "\n";
	}
	void addItem(stack<T, MAX> &s1, stack<T, MAX> &s2);
};

template <class T, int MAX>
void stack<T,MAX> :: addItem(stack<T,MAX> &s2, stack<T,MAX> &s3)
{
	if (top >= s2.top)
	{
		for (int i = 0; i <= s2.top; i++)
		{
			s3.item[i] = item[i] + s2.item[i];		
		}
		for (int i = s2.top+1; i<=top ; i++)
		{
			s3.item[i] = item[i];	
		}
		s3.top = top;
	}
	else
	{
		for (int i = 0; i <= top; i++)
		{
			s3.item[i] = item[i] + s2.item[i];
		}
		for (int i = top+1; i <= s2.top; i++)
		{
			s3.item[i] = s2.item[i];
		}
		s3.top = s2.top;
	}
}

int main()
{
	//----Stack : additem ----
	cout << "----addItem----\n";
	stack<int, 10>s1, s2, s3, s4; // stack type int has capacity 10
	for (int i = 0; i < 5; i++)
		s1.push(i);
	cout << "s1: "; s1.print();
	for (int i = 0; i < 7; i++)
		s2.push(i);
	cout << "s1: "; s2.print();
	cout << "s2: "; s3.print();
	cout << "s3: "; s4.print();
	s1.addItem(s2, s3); cout << "s1.addItem(s2,s3); s3: "; s3.print();
	s4.addItem(s1, s3); cout << "s4.addItem(s1,s3); s3: "; s3.print();
	s4.addItem(s4, s3); cout << "s4.addItem(s4,s3); s3: "; s3.print();
	s2.addItem(s2, s3); cout << "s2.addItem(s2,s3); s3: "; s3.print();
	return 0;
}