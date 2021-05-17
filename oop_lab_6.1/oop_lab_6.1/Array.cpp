#include "Array.h"

#include <iostream>
#include <stdexcept>
#include <exception>
#include <iomanip>

using namespace std;

// ������������/���������/����������

Array::Array(const Array::size_type& n)
throw(bad_alloc, invalid_argument)
{
	First = 0;
	Count = Size = n;
	elems = new value_type[Size];
	for (UINT i = 0; i < Size; i++)
		elems[i] = 0;
}

Array::Array(const iterator first, const iterator last)
throw(bad_alloc, invalid_argument)
{
	First = 0;
	if (first <= last) {
		Count = Size = (last - first) + 1;
		elems = new value_type[Size];
		for (UINT i = 0; i < Size; ++i)
			elems[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}

Array::Array(const size_type first, const size_type last)
throw(bad_alloc, invalid_argument)
{
	if (first <= last) {
		First = first;
		Count = Size = (last - first) + 1;
		elems = new value_type[Size];
		for (UINT i = 0; i < Size; ++i)
			elems[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}

Array::Array(const Array& t) throw(bad_alloc)
	: Size(t.Size), Count(t.Count), First(t.First), elems(new value_type[Size])
{
	for (UINT i = 0; i < Size; ++i)
		elems[i] = t.elems[i];
}

Array::~Array()
{
	delete[]elems;
	elems = 0;
}

Array& Array::operator =(const Array& t)
{
	Array tmp(t);
	swap(tmp);
	return *this;
}

// ������

Array::size_type Array::size() const
{
	return Count;
}

bool Array::empty() const
{
	return Count == 0;
}

Array::size_type Array::capacity() const
{
	return Size;
}

void Array::resize(size_type newsize) throw(bad_alloc)
{
	if (newsize > capacity())
	{
		value_type* data = new value_type[newsize];
		for (size_type i = 0; i < Count; ++i)
			data[i] = elems[i];
		delete[] elems;
		elems = data;
		Size = newsize;
	}
}

// ������ �� ��������

Array::reference Array::operator [](size_type index) throw(out_of_range)
{
	if ((First <= index) && (index < First + Size))
		return elems[index - First];
	else
		throw out_of_range("Index out of range!");
}

Array::const_reference Array::operator [](size_type index) const
throw(out_of_range)
{
	if ((First <= index) && (index < First + Size))
		return elems[index - First];
	else
		throw out_of_range("Index out of range!");
}

// ������-������������

void Array::push_back(const value_type& v)
{
	if (Count == Size) // ���� ����
		resize(Size * 2); // �������� "�������"
	elems[Count++] = v; // ��������
}

void Array::pop_back()
{
	if (size() > 0)
	{
		double* tmp = new double[size() - 1];
		for (size_t i = 0; i < size() - 1; ++i)
			tmp[i] = elems[i];
		delete[] elems;
		elems = tmp;
		Size = size() - 1;
	}
}

void Array::swap(Array& other)
{
	std::swap(elems, other.elems); // ���������� ������� �����
	std::swap(Size, other.Size);
}

void Array::assign(const value_type& v)
{
	push_back(v);
}

// ����� ������� �����/������

ostream& operator <<(ostream& out, const Array& tmp)
{
	for (size_t j = 0; j < tmp.Count; j++)
		cout << fixed << showpoint << setprecision(2) << tmp[j] << " ";
	//out << endl;
	return out;
}

istream& operator >>(istream& in, Array& tmp)
{
	// �������� �������� ������
	for (int i = 0; i < tmp.size(); i++)
	{
		cout << "arr[" << i << "] = ";
		in >> tmp[i];
	}

	return in;
}

// ��������

double Array::Sum() const
{
	double sum = 0;

	for (int i = 0; i < size(); i++)
		sum += elems[i];

	return sum;
}

double Array::arithmeticMeanAbs() const
{
	return abs(Sum() / capacity());
}

void Array::commonPart()
{
	push_back(Sum());
	push_back(arithmeticMeanAbs());
}

double Array::arithmetic() const
{
	double sum = 0;

	for (int i = 0; i < size(); i++)
		sum += abs(elems[i]);

	return sum / capacity();
}

void Array::individualPart()
{
	for (int i = 0; i < size(); i++)
	{

		if (!(int(elems[i]) % 2 == 0))
			//if (!(i % 2 == 0))
		{
			elems[i] /= arithmetic();
		}
	}

}
