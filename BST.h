#pragma once

using namespace std;
template<typename T>
struct Node
{
	T data;
	Node* left;
	Node* right;
};

template<typename T>
class BST
{
public:
	BST(); //default constructor
	BST(const T& dat);// constructor
	~BST();//destructor
	void printPreOrder() const; //print preorder traversal
	void printPostOrder() const;//print postorder traversal
	void printInOrder() const;//print inorder traversal
	void insert(const T&);
	bool find(const T& data) const; 
	void remove(const T& data);
	void printLevelOrder() const;
	int countheightelem(size_t) const;
	Node<T>* findMin_rec() const;
	Node<T>* findMax_rec() const;
	void deletetree(Node<T>*);
	size_t height_rec() const;
	size_t height_iter() const;
	size_t max_width_iter() const;
	Node<T>* find_iter(const T&) const;
	void zigzag_iter() const;
	size_t leaf_count_iter() const;
	size_t leafcount_rec() const;
	size_t fullNodeCount_rec() const;
	size_t halfNodeCount_iter() const;
	bool strictBinaryTree_rec() const;
private:
	Node<T>* findMax_rec(Node<T>*)const;
	Node<T>* findMin_rec(Node<T>*) const;
	bool strictBinaryTree_rec(Node<T>*) const;
	size_t fullNodeCount_rec(Node<T>*) const;
	size_t leafcount_rec(Node<T>*) const;
	size_t height_rec(Node<T>*) const;
	Node<T>* findMin(Node<T>*) const;
	Node<T>* findMax(Node<T>*) const;
	Node<T>* find(Node<T>*, const T&) const;
	void printInOrder(Node<T>*) const;
	void printPostOrder(Node<T>*) const;
	void printPreOrder(Node<T>*) const;
	Node<T>* remove(const T& data, Node<T>*);
	void insert(Node<T>**, const T&);

	Node<T>* m_ptr;
};

template<typename T>
BST<T>::BST()
{
	m_ptr = nullptr;
}

template<typename T>
BST<T>::BST(const T& dat)
{
	m_ptr = new Node<T>;
	m_ptr->data = dat;
	m_ptr->left = m_ptr->right = nullptr;
}

template<typename T>
BST<T>::~BST()
{
	deletetree(m_ptr);
}

template<typename T>
void BST<T>::deletetree(Node<T>* ptr)
{

	if (ptr == nullptr)
		return;
	queue<Node<T>*> kk;
	kk.push(ptr);
	while (!kk.empty())
	{
		ptr = kk.front();
		kk.pop();
		if (ptr->left)
			kk.push(ptr->left);
		if (ptr->right)
			kk.push(ptr->right);
		delete (ptr);
		ptr = nullptr;

	}
	cout << "deleting tree is complete" << endl;
}


template<typename T>
void BST<T>::insert(const T& data)
{
	insert((&m_ptr), data);
}


template<typename T>
void BST<T>::insert(Node<T>** tt, const T& value)
{

	if (*tt == NULL) {
		Node<T>* tmp = new Node<T>;
		tmp->data = value;
		tmp->left = NULL;
		tmp->right = NULL;
		*tt = tmp;
		return;
	}
	else {
		if (value > (*tt)->data) {
			insert(&(*tt)->right, value);
		}
		else if (value < (*tt)->data) {
			insert(&(*tt)->left, value);
		}
	}
}

template<typename T>
bool BST<T>::strictBinaryTree_rec() const //All nodes have 2 childs,or 0 child
{
	return strictBinaryTree_rec(m_ptr);
}

template<typename T>
bool BST<T>::strictBinaryTree_rec(Node<T>* temp) const
{
	if (temp == nullptr)
		return true;
	if (temp->left && temp->right == nullptr || temp->right && temp->left == nullptr)
		return false;
	return strictBinaryTree_rec(temp->left) && strictBinaryTree_rec(temp->right);
}

template<typename T>
size_t BST<T>::halfNodeCount_iter() const
{
	queue<Node<T>*>qq;
	qq.push(m_ptr);
	size_t count = 0;
	while (!qq.empty())
	{
		Node<T>* temp = qq.front();
		qq.pop();
		if (temp->left)
			qq.push(temp->left);
		else if (temp->right)
			++count;
		if (temp->right)
			qq.push(temp->right);
		else if (temp->left)
			++count;
	}
	return count;
}

template<typename T>
size_t BST<T>::fullNodeCount_rec() const
{
	return fullNodeCount_rec(m_ptr);
}

template<typename T>
size_t BST<T>::fullNodeCount_rec(Node<T>* temp) const
{
	if (temp == nullptr)
		return 0;
	size_t count = 0;
	if (temp->left && temp->right)
		++count;

	count += fullNodeCount_rec(temp->left) + fullNodeCount_rec(temp->right);
	return count;
}

template<typename T>
size_t BST<T>::leafcount_rec() const
{
	return leafcount_rec(m_ptr);
}

template<typename T>
size_t BST<T>::leafcount_rec(Node<T>* temp) const
{
	if (temp == nullptr)
		return 0;
	if (temp->left == nullptr && temp->right == nullptr)
		return 1;
	return  leafcount_rec(temp->left) + leafcount_rec(temp->right);
}


template<typename T>
size_t BST<T>::leaf_count_iter() const
{
	if (m_ptr == nullptr)
		return 0;
	queue<Node<T>*> qq;
	qq.push(m_ptr);
	size_t count_leaf = 0;
	while (!qq.empty())
	{
		Node<T>* temp = qq.front();
		qq.pop();
		if (temp->left)
			qq.push(temp->left);
		if (temp->right)
			qq.push(temp->right);
		else if (temp->left == nullptr)
			++count_leaf;
	}
	return count_leaf;
}


template<typename T>
void BST<T>::zigzag_iter() const //zigzag traversal of the tree with 2 stacks
{
	if (m_ptr == nullptr)
		return;
	stack<Node<T>*> prev;
	stack<Node<T>*> next;
	bool leftright = true;
	prev.push(m_ptr);
	while (!prev.empty())
	{
		while (!prev.empty())
		{
			Node<T>* temp = prev.top();
			prev.pop();
			cout << temp->data << ' ';
			if (leftright)
			{
				if (temp->left)
					next.push(temp->left);
				if (temp->right)
					next.push(temp->right);
			}
			else {
				if (temp->right)
					next.push(temp->right);
				if (temp->left)
					next.push(temp->left);
			}
		}
		leftright = !leftright;
		swap(prev, next);
	}
	cout << endl;
}

template<typename T>
size_t BST<T>::max_width_iter() const
{
	if (m_ptr == nullptr)
		return 0;
	queue<Node<T>*> qq;
	qq.push(m_ptr);
	size_t lenght = 1, max_ = 1;
	while (!qq.empty())
	{
		max_ = max(max_, lenght);
		while (lenght--)
		{
			Node<T>* temp = qq.front();
			qq.pop();
			if (temp->left)
				qq.push(temp->left);
			if (temp->right)
				qq.push(temp->right);
		}
		lenght = qq.size();
	}
	return max_;
}


template<typename T>
size_t BST<T>::height_iter() const
{
	if (m_ptr == nullptr)
		return 0;
	queue<Node<T>*> zz;
	int height = -1;
	zz.push(m_ptr);
	int level = 1;
	while (!zz.empty())
	{
		++height;
		while (level--)
		{
			Node<T>* temp = zz.front();
			zz.pop();

			if (temp->left)
				zz.push(temp->left);
			if (temp->right)
				zz.push(temp->right);
		}
		level = zz.size();
	}
	return height;
}

template<typename T>
size_t BST<T>::height_rec() const
{
	return height_rec(m_ptr);
}

template<typename T>
size_t BST<T>::height_rec(Node<T>* m_ptr) const
{

	if (m_ptr == nullptr)
		return 0;
	if (m_ptr->left == nullptr && m_ptr->right == nullptr)
		return 0;

	return 1 + max(height_rec(m_ptr->left), height_rec(m_ptr->right));

}

template<typename T>
int BST<T>::countheightelem(size_t h) const
{
	if (m_ptr == nullptr)
		return 0;
	queue<Node<T>*> q;
	q.push(m_ptr);
	while (!q.empty())
	{
		if (h == 0)
			break;
		size_t l = q.size();
		while (l--)
		{
			Node<T>* zz = q.front();
			q.pop();
			if (zz->left)
				q.push(zz->left);
			if (zz->right)
				q.push(zz->right);
		}
		--h;
	}
	int i = 0;
	while (!q.empty())
	{
		i += q.front()->data;
		q.pop();
	}
	return i;
}

template<typename T>
void BST<T>::printInOrder() const
{
	cout << "Inorder traversal -";
	printInOrder(m_ptr);
	cout << endl;
}

template<typename T>
void BST<T>::printInOrder(Node<T>* tt) const
{
	if (tt == NULL)
		return;
	printInOrder(tt->left);
	cout << tt->data << ' ';
	printInOrder(tt->right);
}

template<typename T>
void BST<T>::printPreOrder() const
{
	cout << "Preorder traversal -";
	printPreOrder(m_ptr);
	cout << endl;
}

template<typename T>
void BST<T>::printPreOrder(Node<T>* tt) const
{
	if (tt == NULL)
		return;
	cout << tt->data << ' ';
	printPreOrder(tt->left);
	printPreOrder(tt->right);
}

template<typename T>
void BST<T>::printPostOrder() const
{
	cout << "Postorder traversal -";
	printPostOrder(m_ptr);
	cout << endl;
}

template<typename T>
void BST<T>::printPostOrder(Node<T>* tt) const
{
	if (tt == NULL)
		return;
	printPostOrder(tt->left);
	printPostOrder(tt->right);
	cout << tt->data << ' ';
}

template<typename T>
void BST<T>::printLevelOrder() const
{
	cout << "LevelOrder Traversal- ";
	if (this->m_ptr == NULL)
		return;
	queue<Node<T>*> kk;
	kk.push(this->m_ptr);
	while (!kk.empty())
	{
		Node<T>* temp;
		temp = kk.front();
		cout << temp->data << ' ';
		kk.pop();
		if (temp->left)
			kk.push(temp->left);
		if (temp->right)
			kk.push(temp->right);
	}
	cout << endl;
}

template<typename T>
Node<T>* BST<T>::findMin_rec() const
{
	return FindMin_rec(m_ptr);
}

template<typename T>
Node<T>* BST<T>::findMin_rec(Node<T>* temp) const
{
	if (temp == nullptr)
		return nullptr;
	if (temp->left)
		findMin_rec(temp->left);
	else return temp;
}

template<typename T>
Node<T>* BST<T>::findMax_rec() const
{
	return findMax_rec(m_ptr);
}

template<typename T>
Node<T>* BST<T>::findMax_rec(Node<T>* temp) const
{
	if (temp == nullptr)
		return nullptr;
	if (temp->right)
		findMax_rec(temp->right);
	else return temp;
}

template<typename T>
Node<T>* BST<T>::findMin(Node<T>* zz) const
{
	if (zz == nullptr)
		return nullptr;
	while (zz->left != nullptr)
		zz = zz->left;
	return zz;
}

template<typename T>
Node<T>* BST<T>::find_iter(const T& data) const
{
	Node<T>* temp = m_ptr;
	while (temp)
	{
		if (data < temp->data)
			temp = temp->left;
		else if (data > temp->data)
			temp = temp->right;
		else return temp;
	}
	return nullptr;
}

template<typename T>
Node<T>* BST<T>::findMax(Node<T>* zz) const
{
	if (zz == nullptr)
		return *zz;
	while (zz->right != nullptr)
		zz = zz->right;
	return zz;
}


template<typename T>
bool BST<T>::find(const T& data) const
{
	return find(m_ptr, data);
}

template<typename T>
Node<T>* BST<T>::find(Node<T>* cur, const T& data) const
{
	if (cur == nullptr)
		return nullptr;
	if (cur->data < data)
		return find(cur->right, data);
	else if (cur->data > data)
		return find(cur->left, data);
	else {
		return cur;
	}
}

template<typename T>
void BST<T>::remove(const T& data)
{
	m_ptr = remove(data, m_ptr);
}

template<typename T>
Node<T>* BST<T>::remove(const T& x, Node<T>* t) {
	Node<T>* temp;
	if (t == nullptr)
		return nullptr;
	else if (x < t->data)
		t->left = remove(x, t->left);
	else if (x > t->data)
		t->right = remove(x, t->right);
	else if (t->left && t->right)
	{
		temp = findMin(t->right);
		t->data = temp->data;
		t->right = remove(t->data, t->right);
	}
	else
	{
		temp = t;
		if (t->left == NULL)
			t = t->right;
		else if (t->right == NULL)
			t = t->left;
		delete temp;
	}

	return t;
}

