#include <iostream>
#include "Stack.h"
using namespace std;
int main()
{
	system("color 0B");
	TStack<int> s(8);
	s.Push(9);
	s.Push(4);
	s.Push(2);
	//cout << s.Pop() << endl;
	TCalc c;
	c.SetInfix("2+7-5");
	c.ToPostfix();
	cout << c.GetPostfix() << endl;
	c.SetInfix("7.3+1");
	c.ToPostfix();
	cout << c.CalcPostfix() << endl;
	c.SetInfix("4-8+(9-6)^5+7/8+3*6");
	cout << c.Calc() << endl;
	return 0;
}