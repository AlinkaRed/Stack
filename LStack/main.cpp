#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
	system("color 0B");
	TStack<int> s(10);
	s.Push(3);
	s.Push(4);
	s.Push(2);
	//cout << s.Pop() << endl;
	TCalc c;
	c.SetInfix("4-8+(9-6)^5+7/8+3*6");
	c.ToPostfix();
	cout << c.CalcPostfix() << endl;
	c.SetInfix("6/4");
	cout << c.Calc() << endl;
	return 0;
}