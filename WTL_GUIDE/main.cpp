#include <iostream>

template<class T>
class B1
{
public:
	void SayHi()
	{
		T *pT = static_cast<T*>(this);
		pT->PrintClassName();
	}

	void PrintClassName() { std::cout << "This is B1" << std::endl; }
};

class D1 : public B1<D1>
{
};

class D2 : public B1<D2>
{
public:
	void PrintClassName() { std::cout << "This is D2" << std::endl; }
};

int main()
{
	D1 d1;
	D2 d2;
	d1.SayHi();
	d2.SayHi();
}