#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

class BitMap
{
public:
	BitMap(size_t range)
	{
		_array.resize((range >> 5) + 1);
	}

	void set(int data)
	{
		int idx = data >> 5;
		int bitIdx = data % 32;
		_array[idx] |= (1 << bitIdx);
	}

	bool test(int data)
	{
		int idx = data >> 5;
		int bitIdx = data % 32;
		return (_array[idx] >> bitIdx) & 1;
	}

	void reset(int data)
	{
		int idx = data >> 5;
		int bitIdx = data % 32;
		_array[idx] &= ~(1 << bitIdx);
	}


private:
	vector<int> _array;
};

int main()
{
	BitMap m(100);
	m.set(3);
	m.set(55);
	m.set(4);
	m.set(88);
	bool ret = m.test(1);
	ret = m.test(3);
	m.reset(3);
	ret = m.test(3);
	return 0;
}