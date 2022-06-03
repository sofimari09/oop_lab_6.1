#include "Array.h"
#include <iostream>
#include <stdexcept>
#include <exception>
#include <cmath>
using namespace std;

Array::Array(const size_t& n) throw(bad_alloc, invalid_argument)
{
    First = 0;
    Count = Size = n;
    elems = new int[Size];
    for (unsigned int i = 0; i < Size; i++)
        elems[i] = 0;
}

Array::Array(const double* first, const double* last) throw(bad_alloc, invalid_argument)
{
    First = 0;
    if (first <= last) {
        Count = Size = (last - first) + 1;
        elems = new int[Size];
        for (unsigned int i = 0; i < Size; ++i)
            elems[i] = 0;
    }
    else
        throw invalid_argument("!!!");
}

Array::Array(const size_t first, const size_t last)
throw(bad_alloc, invalid_argument)
{
    if (first <= last) {
        First = first;
        Count = Size = (last - first) + 1;
        elems = new int[Size];
        for (unsigned int i = 0; i < Size; ++i)
            elems[i] = 0;
    }
    else
        throw invalid_argument("!!!");
}

Array::Array(const Array& t) throw(bad_alloc)
    : Size(t.Size), Count(t.Count), First(t.First), elems(new int[Size])
{
    for (unsigned int i = 0; i < Size; ++i)
        elems[i] = t.elems[i];
}

Array& Array::operator =(const Array& t) {
    Array tmp(t);
    swap(tmp);
    return *this;
}

Array::~Array()
{
    delete[]elems;
    elems = 0;
}

void Array::push_back(const int& v)
{
    if (Count == Size)
        resize(Size + 1);
    elems[Count++] = v;
}

int& Array::operator [](size_t index) throw(out_of_range)
{
    if ((First <= index) && (index < First + Size))
        return elems[index - First];
    else
        throw out_of_range("Index out of range!");
}

const int& Array::operator [](size_t index) const
throw(out_of_range)
{
    if ((First <= index) && (index < First + Size))
        return elems[index - First];
    else
        throw out_of_range("Index out of range!");
}

void Array::resize(size_t newsize) throw(bad_alloc)
{
    if (newsize > capacity())
    {
        int* data = new int[newsize];
        for (size_t i = 0; i < Count; ++i)
            data[i] = elems[i];
        delete[] elems;
        elems = data;
        Size = newsize;
    }
}

void Array::swap(Array& other)
{
    std::swap(elems, other.elems);
    std::swap(Size, other.Size);
}

size_t Array::capacity() const
{
    return Size;
}

size_t Array::size() const
{
    return Count;
}

bool Array::empty() const
{
    return Count == 0;
}

ostream& operator <<(ostream& out, const Array& tmp)
{
    for (size_t j = 0; j < tmp.Count; j++)
        cout << tmp[j] << " ";
    cout << endl;
    return out;
}

istream& operator >>(istream& in, const Array& tmp)
{
    for (int i = 0; i < tmp.size(); i++)
    {
        cout << "arr[" << i << "] = ";
        in >> tmp[i];
    }
    return in;
}

void Array::pop_back() throw(bad_alloc)
{
    if (size() > 0)
    {
        int* tmp = new int[size() - 1];
        for (size_t i = 0; i < size() - 1; ++i)
            tmp[i] = elems[i];
        delete[] elems;
        elems = tmp;
        Size = size() - 1;
    }
}

void Array::Print()
{
    for (int i = 0; i < size(); i++)
        cout << elems[i] << " ";
    cout << "\n\n";
}

double Array::Sum() const
{
    int sum = 0;

    for (int i = 0; i < size(); i++)
        sum += elems[i];

    return sum;
}

double Array::ArithmeticMeanAbs() const
{
    return abs(Sum() / capacity());
}

void Array::GeneralTask() throw(bad_alloc)
{
    push_back(Sum());
    push_back(ArithmeticMeanAbs());
}

int Array::MaxNumber() const
{
    double MaxNumber = elems[0];

    for (int i = 0; i < size(); i++)
        if (elems[i] > MaxNumber)
        {
            MaxNumber = elems[i];
        }

    return MaxNumber;

}

int Array::MinNumber() const
{
    double MinNumber = elems[0];

    for (int i = 0; i < size(); i++)
        if (elems[i] < MinNumber)
        {
            MinNumber = elems[i];
        }
    return MinNumber;
}

void Array::MyTask()
{
    double MaxNumber = this->MaxNumber();
    double MinNumber = this->MinNumber();
    int tmp = 0;

    for (int i = 0; i < size(); i++)
    {
            tmp++;
            elems[i] = 1.*elems[i] /MinNumber;
            elems[i] += MaxNumber;
    }
}
