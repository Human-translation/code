#include <iostream>
#include <utility>
using namespace std;

enum COLOR
{
	BLACK,
	RED
};

template <class K,class V>
struct RBNode
{
	RBNode<K, V>* _left;
	RBNode<K, V>* _right;
	RBNode<K, V>* _parent;
	pair<K, V> _value;
	COLOR _color;

	RBNode(const pair<K, V>& value = pair<K, V>())
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _value(value)
		, _color(RED)
	{}
};

template <class K,class V>
class RBTree
{
public:
	typedef RBNode<K, V> Node;
	typedef Node* pNode;

	RBTree()
	{
		_header = new Node();
		_header->_left = _header;
		_header->_right = _header;
	}

	pNode leftMost()
	{
		pNode cur = _header->_parent;
		while (cur && cur->_left != nullptr)
		{
			cur = cur->_left;
		}
		return cur;
	}

	pNode rightMost()
	{
		pNode cur = _header->_parent;
		while (cur && cur->_right != nullptr)
		{
			cur = cur->_right;
		}
		return cur;
	}


	void RotateR(pNode parent)
	{
		pNode subL = parent->_left;
		pNode subLR = subL->_right;

		subL->_right = parent;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		if (parent != _header->_parent)
		{
			pNode gParent = parent->_parent;
			if (gParent->_left == parent)
				gParent->_left = subL;
			else
				gParent->_right = subL;
			subL->_parent = gParent;
		}
		else
		{
			_header->_parent = subL;
			subL->_parent = _header;
		}
		parent->_parent = subL;
	}


	void RotateL(pNode parent)
	{
		pNode subR = parent->_right;
		pNode subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		if (parent != _header->_parent)
		{
			pNode gParent = parent->_parent;
			if (gParent->_left == parent)
				gParent->_left = subR;
			else
				gParent->_right = subR;
			subR->_parent = gParent;
		}
		else
		{
			_header->_parent = subR;
			subR->_parent = _header;
		}
		parent->_parent = subR;
	}

	bool Insert(const pair<K, V>& value)
	{
		if (_header->_parent == nullptr)
		{
			pNode root = new Node(value);
			root->_color = BLACK;
			root->_parent = _header;
			_header->_parent = root;

			_header->_left = root;
			_header->_right = root;
			return true;
		}
		pNode cur = _header->_parent;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_value.first == value.first)
			{
				return false;
			}
			else if (cur->_value.first > value.first)
			{
				cur = cur->_left;
			}
			else if (cur->_value.first < value.first)
			{
				cur = cur->_right;
			}
		}
		cur = new Node(value);
		if (parent->_value.first > cur->_value.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;


		while (cur != _header->_parent && cur->_parent->_color == RED)
		{
			parent = cur->_parent;
			pNode gfather = parent->_parent;
			if (gfather->_left == parent)
			{
				pNode uncle = gfather->_right;
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(parent);
						swap(cur, parent);
					}
					RotateR(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
			else
			{
				pNode uncle = gfather->_left;
				if (uncle && uncle->_color == RED)
				{
					parent->_color = uncle->_color = BLACK;
					gfather->_color = RED;
					cur = gfather;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(cur, parent);
					}
					RotateL(gfather);
					parent->_color = BLACK;
					gfather->_color = RED;
					break;
				}
			}
		}
		_header->_parent->_color = BLACK;

		_header->_left = leftMost();
		_header->_right = rightMost();
		return true;
	}

	bool isRBTree()
	{
		pNode root = _header->_parent;
		if (root == nullptr)
			return true;
		if (root->_color == RED)
		{
			cout << "根必须为红色" << endl;
			return false;
		}
		pNode cur = root;
		int blackCount = 0;
		while (cur)
		{
			if (cur->_color == BLACK)
			{
				++blackCount;
				cur = cur->_right;
			}
		}

		int k = 0;
		return _isRBTree(root, k, blackCount);

	}

	bool _isRBTree(pNode root, int curBlackCount, int totalBlackCount)
	{
		if (root == nullptr)
		{
			if (curBlackCount != totalBlackCount)
			{
				cout << "每条路径黑色节点个数不同" << endl;
				return false;
			}
			return true;
		}
		if (root->_color == BLACK)
			++curBlackCount;
		pNode parent = root->_parent;
		if (parent->_color == RED && root->_color == RED)
		{
			cout << "有红色连续的节点" << endl;
			return false;
		}
		return _isRBTree(root->_left, curBlackCount, totalBlackCount) && _isRBTree(root->_right, curBlackCount, totalBlackCount);
	}

private:
	pNode _header;
};