#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

class String
{

public:
	typedef char* iterator;
	typedef const char* const_iterator;

	String(const char *str = "")
	{
		_size = strlen(str);
		_str = new char[_size + 1];
		_capacity = _size;
		strcpy(_str, str);
	}

	String(const String& s)
		:_str(nullptr)
		, _size(0)
		, _capacity(0)
	{
		String Tmp(s);
		this->Swap(Tmp);
	}

	String& operator=(String s)
	{
		this->Swap(s);
		return *this;
	}

	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}

	void clear()
	{
		_size = 0;
		_str[_size] = '\0';
	}

	void PushBack(char c)
	{
		if (_size = _capacity)
		{
			Reserve(_capacity * 2);
		}
		_str[_size++] = c;
		_str[_size] = '\0';
	}

	void Append(const char* str)
	{
		Reserve(_size + strlen(str) + 1);
		strcpy(_str + _size, str);
		_size += strlen(str);
	}

	String& Insert(size_t pos, char c)
	{
		if (_size + 1 > _capacity)
		{
			Reserve(_size + 1);
		}
		_str[_size + 1] = '\0';
		for (int i = _size; i > pos; i--)
		{
			_str[i] = _str[i - 1];
		}
		_str[pos] = c;
		++_size;
		return *this;
	}

	String& Insert(size_t pos, const char* str)
	{
		if (_size + strlen(str) + 1 > _capacity)
		{
			Reserve(_size + strlen(str) + 1);
		}

		_str[_size + strlen(str)] = '\0';
		for (int i = _size + strlen(str) - 1; i > pos; i--)
		{
			_str[i] = _str[i - strlen(str)];
		}


		while (*str != '\0')
		{
			_str[pos++] = *str++;
		}

		_size = strlen(_str);
		return *this;
	}

	String& Erase(size_t pos, size_t len)
	{
		if (pos + len < _size)
		{
			while (_str[pos + len] != '\0')
			{
				_str[pos] = _str[pos + len];
				pos++;
			}
			_str[pos] = _str[pos + len];
		}
		else
		{
			_str[pos] = _str[_size];
		}
		_size = strlen(_str);
		return *this;
	}

	String& operator+=(char c)
	{
		PushBack(c);
		return *this;
	}

	String& operator+=(const char* str)
	{
		Append(str);
		return *this;
	}

	const char* C_Str()const
	{
		return _str;
	}

	size_t Size()const
	{
		return _size;
	}

	size_t Capacity()const
	{
		return _capacity;
	}

	bool Empty()const
	{
		return _size == 0;
	}

	void Resize(size_t newSize, char c = '\0')
	{
		if (newSize > _size)
		{
			if (newSize > _capacity)
			{
				Reserve(newSize);
			}
			memset(_str + _size, c, newSize - _size);
		}
		_size = newSize;
		_str[_size] = '\0';
	}

	void Reserve(size_t newCapacity)
	{
		if (newCapacity > _capacity)
		{
			char* str = new char[newCapacity + 1];
			strcpy(str, _str);
			delete[] _str;
			_str = str;
			_capacity = newCapacity;
		}
	}

	char& operator[](size_t index)
	{
		assert(index < _size);
		return _str[index];
	}

	const char& operator[](size_t index)const
	{
		assert(index < _size);
		return _str[index];
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

	iterator begin()
	{
		return _str;
	}

	iterator end()
	{
		return _str + _size;
	}

	const_iterator begin()const
	{
		return _str;
	}

	const_iterator end()const
	{
		return _str + _size;
	}


	friend ostream& operator<<(ostream& _cout, const String& s);

private:
	char* _str;
	size_t _capacity;
	size_t _size;
};

ostream& operator<<(ostream& _cout, const String& s)
{
	_cout << s.C_Str();
	return _cout;
}

void test()
{
	String a("i like money");
	String b("heo world");
	a += 'c';
	b.Insert(5, "niha");
	//for (const auto& ch : b)
	//{
	//	cout << ch;
	//}
	cout << b << endl;
	b.Erase(5, 3);
}

int main()
{
	test();
	system("pause");
	return 0;
}