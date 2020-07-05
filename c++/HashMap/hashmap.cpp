#include <iostream>
#include <vector>
using namespace std;

enum State
{
	EXIST,
	DELETE,
	EMPTY
};

template <class K,class V>
struct Node
{
	pair<K, V> _value;
	State _state;
};

template <class K,class V>
class HashTable
{
	typedef Node<K, V> Node;
public:
	HashTable(size_t N = 10)
	{
		_table.resize(N);
		for (size_t i = 0; i < N; i++)
		{
			_table[i]._state = EMPTY;
		}
		_size = 0;
	}

	bool Insert(const pair<K, V>& value)
	{
		CheckCapcity();

		int idx = value.first % _table.size();
		while (_table[idx]._state == EXIST)
		{
			if (_table[idx]._value.first == value.first)
			{
				return false;
			}
			++idx;
			if (idx == _table.size())
				idx = 0;
		}
		_table[idx]._value = value;
		_table[idx]._state = EXIST;
		++_size;
		return true;
	}

	void CheckCapcity()
	{
		if (_size * 10 / _table.size() >= 7)
		{
			int newC = _table.size() * 2;

			//_table.resize(newC);
			HashTable<K, V> newHT(newC);
			for (size_t i = 0; i < _table.size(); i++)
			{
				if (_table[i]._state == EXIST)
				{
					newHT.Insert(_table[i]._value);
				}
			}
			_table.swap(newHT._table);
		}
	}

	Node* find(const K& key)
	{
		int idx = key % _table.size();
		while (_table[idx]._state != EMPTY)
		{
			if (_table[idx]._state == EXIST && _table[idx]._value.first == key)
			{
				return &_table[idx];
			}
			++idx;
			if (idx == _table.size())
				idx = 0;
		}
		return nullptr;
	}

	bool erase(const K& key)
	{
		Node* node = find(key);
		if (node)
		{
			node->_state == DELETE;
			--_size;
			return true;
		}
		return false;
	}

private:
	vector<Node> _table;
	size_t _size;
};

//int main()
//{
//	HashTable<int, int> ht;
//	ht.Insert(make_pair(1, 1));
//	ht.Insert(make_pair(2, 2));
//	ht.Insert(make_pair(3, 3));
//	ht.Insert(make_pair(4, 4));
//	return 0;
//}