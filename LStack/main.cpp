#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
	TStack<int> s(10);
	s.Push(3);
	s.Push(4);
	s.Push(2);
	//cout << s.Pop() << endl;
	TCalc c;
	c.SetInfix("3-6");
	c.ToPostfix();
	//cout << c.GetPostfix() << endl;
	cout << c.CalcPostfix() << endl;
	return 0;
}