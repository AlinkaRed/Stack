#pragma once
#include <iostream>
using namespace std;
const int MAXS = 10000;
template <class T>
class TStack
{
	T* pMem;
	int MaxSize, Num;
public:
	TStack(int _MaxSize = 10); //êîíñòðóêòîð èíèöèàëèçàöèè
	~TStack(); //äåñòðóêòîð
	TStack(const TStack &s); //êîíñòðóêòîð êîïèðîâàíèÿ
	int GetMaxSize() { return MaxSize; } // ðàçìåð ñòåêà
	int GetNum() { return Num; } // èíäåêñ Num
	TStack& operator=(const TStack<T> s); //îïåðàòîð ïðèñâàèâàíèÿ
	bool operator==(const TStack& s) const; //ñðàâíåíèå ðàâíî
	bool operator!=(const TStack& s) const; //ñðàâíåíèå íå ðàâíî
	T Pop(); //èçâëå÷åíèå ýëåìåíòà èç ñòåêà
	void Push(T val); //äîáàâëåíèå ýëåìåíòà â ñòåê
	bool Empty() const; // ïðîâåðêà íà ïóñòîòó Num = -1
	bool Full() const; // ïðîâåðêà íà ïîëíîòó Nun = MaxSize-1
	T Top() const; //ïîñìîòðåòü íà âåðøèíêó ñòåêà
	void Clear(); //î÷èñòêà ñòåêà Clear
	friend istream& operator>>(istream& in, TStack& s) //ââîä ýëåìåíòà
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
template <class T>
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
	if (this->isEmpty())
		throw - 1;
	T tmp = pMem[Num];
	Num--;
	return tmp;
}
template <class T>
void TStack<T>::Push(T val)
{
	if (this->isFull())
		throw - 1;
	Num++;
	pMem[Num] = val;
}
template <class T>
T TStack<T>::Top() const
{
	if (this->isEmpty())
		throw - 1;
	return pMem[Num];
}
template <class T>
void TStack<T>::Clear() {
	Num = -1;
}
template <class T>
bool Check(string str)
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
