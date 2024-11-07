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
	c.SetInfix("2+4");
	c.ToPostfix();
	double a = c.CalcPostfix();
	cout << c.CalcPostfix() << endl;
	c.SetInfix("2-9");
	c.ToPostfix();
	a = c.CalcPostfix();
	cout << c.CalcPostfix() << endl;
	c.SetInfix("8+7-1-8");
	c.ToPostfix();
	a = c.CalcPostfix();
	cout << c.CalcPostfix() << endl;
	c.SetInfix("-2-1");
	c.ToPostfix();
	a = c.CalcPostfix();
	cout << c.CalcPostfix() << endl;
	c.SetInfix("(9+8)*3-4");
	c.ToPostfix();
	a = c.CalcPostfix();
	cout << c.CalcPostfix() << endl;
	c.SetInfix("6^2*7+2-1");
	c.ToPostfix();
	a = c.CalcPostfix();
	cout << c.CalcPostfix() << endl;
	c.SetInfix("(8-1)*2-7^3");
	c.ToPostfix();
	a = c.CalcPostfix();
	cout << c.CalcPostfix() << endl;
	return 0;
}