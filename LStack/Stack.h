#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;
const int MAXS = 10000;
template <class T>
class TStack
{
	T* pMem;
	int MaxSize, Num;
public:
	TStack(int _MaxSize = 10); //конструктор инициализации
	~TStack(); //деструктор
	TStack(const TStack &s); //конструктор копирования
	int GetSize() { return MaxSize; } // размер стека
	int GetStartIndex() { return Num; } // индекс Num
	TStack& operator=(const TStack<T> s); //оператор присваивания
	bool operator==(const TStack& s) const; //сравнение равно
	bool operator!=(const TStack& s) const; //сравнение не равно
	T Pop(); //извлечение элемента из стека
	void Push(T val); //добавление элемента в стек
	bool Empty() const; // проверка на пустоту Num = -1
	bool Full() const; // проверка на полноту Nun = MaxSize-1
	T Top() const; //посмотреть на вершинку стека
	void Clear(); //очистка стека Clear
	bool Check(string str);
	friend istream& operator>>(istream& in, TStack& s) //ввод элемента
	{
		if (this->isFull())
			throw -1;
		Num++;
		in >> s.pMem[Num];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TStack& s) //âûâîä ýëåìåíòà
	{
		if (this->isEmpty())
			throw - 1;
		out << s.pMem[Num];
		return out;
	}
};
template <class T>
TStack<T>::TStack(int _MaxSize)
{
	if (_MaxSize < 0 || _MaxSize > MAXS)
		throw - 1;
	MaxSize = _MaxSize;
	Num = -1;
	pMem = new T[MaxSize];
}
template <class T> 
TStack<T>::TStack(const TStack<T>& s)
{
	if (s.MaxSize < 0 || s.MaxSize > MAXS || s.Num < -1 || s.Num >= s.MaxSize)
		throw - 1;
	MaxSize = s.MaxSize;
	Num = s.Num;
	pMem = new T[MaxSize];
	for (int i = 0; i <= Num; i++)
		pMem[i] = s.pMem[i];
}
template <class T>
TStack<T>::~TStack()
{
	delete[] pMem;
}
template <class T>
TStack<T>& TStack<T>::operator=(const TStack<T> s)
{
	if (this == &s)
		return *this;
	if (MaxSize != s.MaxSize)
	{
		MaxSize = s.MaxSize;
		delete[] pMem;
		pMem = new T[MaxSize];
	}
	Num = s.Num;
	for (int i = 0; i <= Num; i++)
		pMem[i] = s.pMem[i];
	return *this;
}
template <class T>
bool TStack<T>::operator==(const TStack& s) const
{
	if (this == &s)
		return true;
	if (MaxSize != s.MaxSize)
		return false;
	if (Num != s.Num)
		return false;
	for (int i = 0; i <= Num; i++) {
		if (pMem[i] != s.pMem[i])
			return false;
	}
	return true;
}
template <class T> // сравнение
bool TStack<T>::operator!=(const TStack& s) const
{
	return !(*this == s);
}
template <class T>
bool TStack<T>::Empty() const
{
	if (Num == -1)
		return true;
	return false;
}
template <class T>
bool TStack<T>::Full() const
{
	if (Num == MaxSize - 1)
		return true;
	return false;
}
template <class T>
T TStack<T>::Pop()
{
	if (this->Empty())
		throw - 1;
	T tmp = pMem[Num];
	Num--;
	return tmp;
}
template <class T>
void TStack<T>::Push(T val)
{
	if (this->Full())
		throw - 1;
	Num++;
	pMem[Num] = val;
}
template <class T>
T TStack<T>::Top() const
{
	if (this->Empty())
		throw - 1;
	return pMem[Num];
}
template <class T>
void TStack<T>::Clear() {
	Num = -1;
}
template <class T>
bool TStack<T>::Check(string str)
{
	TStack<char> s;
	bool res = true;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
			s.Push('(');
		if (str[i] == ')')
		{
			if (s.Empty())
				return false;
			s.Pop();
		}
	}
	if (!s.Empty())
		return false;
	return true;
}
class TCalc
{
	string infix;
	string postfix;
	TStack<double> StNum;
	TStack<char> StClon;
public:
	//конструктор может быть пустым
	//set get infix, postfix
	void ToPostfix();//преобразовать из infix в postfix
	double CalcPostfix();
	double Calc();
};
double TCalc::CalcPostfix() {
	StNum.Clear();
	StClon.Clear();
	for (int i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] >= '0' && postfix[i] <= '9')
			StNum.Push(postfix[i] - '0');
		if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
		{
			double Num2 = StNum.Pop();
			double Num1 = StNum.Pop();
			if (postfix[i] == '+')
				StNum.Push(Num1 + Num2);
			if (postfix[i] == '-')
				StNum.Push(Num1 - Num2);
			if (postfix[i] == '*')
				StNum.Push(Num1 * Num2);
			if (postfix[i] == '/')
			{
				if (Num2 == 0)
					throw - 1;
				StNum.Push(Num1 / Num2);
			}
		}
		//извлечь элемент, проверка стека на пустоту - если пуст - хорошо, иначе исключение
		return StNum.Pop();
	}
}