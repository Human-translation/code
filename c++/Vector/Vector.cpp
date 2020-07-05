#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

template <class T>
class Vector
{
public:
	typedef T* iterator;
	typedef const T* const_iterator;

	Vector()
		:_start(nullptr)
		, _finish(nullptr)
		, _eos(nullptr)
	{}

	void PushBack(const T& val)
	{
		//if (_finish == _eos)
		//{
		//	size_t newC = _start == nullptr ? 1 : 2 * Capacity();
		//	Reserve(newC);
		//}
		//*_finish = val;
		//++_finish;
		Insert(end(), val);
	}

	size_t Capacity()const
	{
		return _eos - _start;
	}

	void Reserve(size_t n)
	{
		int sz = Size();
		if (n > Capacity())
		{
			T* tmp = new T[n];

			//memcpy(tmp, _start, sizeof(T)*Size());

			for (int i = 0; i < sz; i++)
			{
				tmp[i] = _start[i];
			}

			delete[] _start;

			_start = tmp;
			_finish = _start + sz;
			_eos = _start + n;
		}
	}

	size_t Size()const
	{
		return _finish - _start;
	}

	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}

	const T& operator[](size_t pos)const
	{
		assert(pos < Size());
		return _start[pos];
	}

	iterator begin()
	{
		return _start;
	}

	iterator end()
	{
		return _finish;
	}

	const iterator begin()const
	{
		return _start;
	}

	const iterator end()const
	{
		return _finish;
	}

	void Insert(iterator pos, const T& val)
	{
		int len = pos - _start;
		assert(pos >= begin() && pos <= end());
		if (_finish == _eos)
		{
			size_t newC = _start == nullptr ? 1 : 2 * Capacity();
			Reserve(newC);
		}
		pos = _start + len;
		iterator end = _finish;
		while (end > pos)
		{
			*end = *(end - 1);
			--end;
		}
		*pos = val;
		++_finish;
	}

	iterator Erase(iterator pos)
	{
		assert(pos >= begin() && pos < end());
		iterator begin = pos + 1;

		while (begin < _finish)
		{
			*(begin - 1) = *begin;
			++begin;
		}
		--_finish;
		return pos;
	}

	void Resize(size_t n, const T& val = T())
	{
		if (n <= Size())
		{
			_finish = _start + n;
		}
		else
		{
			if (n > Capacity())
			{
				Reserve(n);
			}
			while (_finish != _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
	}

	void PopBack()
	{
		Erase(end() - 1);
	}

	template <class InputIterator>
	Vector(InputIterator first, InputIterator last)
	{
		while (first != last)
		{
			PushBack(*first);
			++first;
		}
	}

	Vector(const Vector<T>& vec)
		:_start(new T[vec.Size()])
		, _finish(_start + vec.Size())
		, _eos(_start + vec.Capacity())
	{
		/*for (const auto& e : vec)
		PushBack(e);*/
		for (int i = 0; i < vec.Size(); ++i)
		{
			_start[i] = vec[i];
		}
	}

	Vector<T>& operator=(const Vector<T>& vec)
	{
		Swap(vec);
		return *this;
	}

	void Swap(Vector<T>& vec)
	{
		swap(_start, vec._start);
		swap(_finish, vec._finish);
		swap(_eos, vec._eos);
	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _eos = nullptr;
		}
	}

private:
	iterator _start;
	iterator _finish;
	iterator _eos;
};

template <class T>
void PrintVec(const Vector<T>& vec)
{
	for (size_t i = 0; i < vec.Size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

template <class T>
void PrintVecIterator(const Vector<T>& vec)
{
	Vector<T>::const_iterator vit = vec.begin();
	while (vit != vec.end())
	{
		cout << *vit << " ";
		++vit;
	}
	cout << endl;
}

void TestVec1()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	v.PushBack(5);
	PrintVec(v);
}

void TestVec2()
{
	Vector<string> v;
	v.PushBack("1");
	v.PushBack("2");
	v.PushBack("3");
	v.PushBack("4");
	v.PushBack("5");
	PrintVecIterator(v);
}

void TestVec3()
{
	Vector<int> v;
	v.PushBack(1);
	v.PushBack(2);
	v.PushBack(3);
	v.PushBack(4);
	Vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		if (*it % 2 == 0)
		{
			it = v.Erase(it);
		}
		else
		{
			++it;
		}
	}
}

void TestVec4()
{
	//Vector<Vector<int>> v;
	//v.PushBack(Vector<int>());
	//v.PushBack(Vector<int>());

	Vector<int> v;
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(1);
	v.PushBack(1);
	v.Resize(6);
	v.Resize(10, 10);
	v.Resize(2);

}

int main()
{
	TestVec4();
	system("pause");
	return 0;
}