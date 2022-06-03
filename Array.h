#pragma once
#include <iostream>
using namespace std;

class Array
{
public:
	// типи
	typedef unsigned int UINT;
	typedef int  value_type;
	typedef double* iterator;
	typedef const double* const_iterator;
	typedef double& reference;
	typedef const double& const_reference;
	typedef std::size_t size_type;
private:
	static const size_type minsize = 10; // мінімальний розмір масиву
	size_type Size; // виділено пам’яті для елементів
	size_type Count; // кількість елементів в масиві
	size_type First; // значення індексу першого елемента в масиві
	value_type* elems; // вказівник на дані
public:
	Array(const size_t& n = minsize) throw(bad_alloc, invalid_argument);
	Array(const Array&) throw(bad_alloc);
	Array(const double* first, const double* last) throw(bad_alloc, invalid_argument);
	Array(const size_t first, const size_t last) throw(bad_alloc, invalid_argument);
	~Array();
	Array& operator=(const Array&);


	int* begin() { return elems; }
	const int* begin() const { return elems; }
	int* end() { return elems + Count; }
	const int* end() const { return elems + Count; }


	size_t size() const;
	bool empty() const;
	size_t capacity() const;
	void resize(size_t newsize) throw(bad_alloc);


	int& operator [](size_t) throw(out_of_range);
	const int& operator [](size_t) const throw(out_of_range);
	int& front() { return elems[0]; }
	const int& front() const { return elems[0]; }
	int& back() { return elems[size() - 1]; }
	const int& back() const { return elems[size() - 1]; }


	void push_back(const int& v);
	void pop_back();
	void clear() { Count = 0; }
	void swap(Array& other);


	friend ostream& operator <<(ostream& out, const Array& a);
	friend istream& operator >>(istream& in, Array& a);


	void GeneralTask() throw(bad_alloc);
	double Sum() const;
	double ArithmeticMeanAbs() const;
	void Print();
	void MyTask();
	int MaxNumber() const;
	int MinNumber() const;
};
