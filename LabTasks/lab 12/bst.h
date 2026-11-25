#pragma once
template <typename t>
class bst {
	template <typename u>
	struct node {
		u val;
		node<u>* left, *right, *parent;
	};
	node<t>* head;
	int n;
public:
	bst()
	{
		head = new node<t>;
		head->parent = head->left = head->right = head;
	}
	void insert(const t& val) {
		node<t>* temp;
		temp = new node<t>;
		temp->val = val;
		temp->left = head;
		temp->right = head;
		if (head->parent == head)
		{
			head->parent = temp;
			temp->parent = head;
			head->left = temp;
			head->right = temp;
			++n;
		}
		else {
			node<t>* ptr;
			ptr = head->parent;
			while (1)
			{
				if (temp->val < ptr->val)
				{
					if (ptr->left != head)
					{
						ptr = ptr->left;
					}
					else
					{
						ptr->left = temp;
						temp->parent = ptr;
						++n;
						if (temp->val < head->left->val)
							head->left = temp;
						return;
					}
				}
				else
				{
					if (ptr->right != head)
					{
						ptr = ptr->right;
					}
					else
					{
						ptr->right = temp;
						temp->parent = ptr;
						++n;
						if (temp->val > head->right->val)
							head->right = temp;
						return;
					}
				}
			}
		}
	}
	bool contains(const t& val)const
	{
		node<t>* ptr;
		ptr = head->parent;
		while (ptr != head)
		{
			if (val == ptr->val)
			{
				return true;
			}
			else if (ptr->val < val)
			{
				ptr = ptr->right;
			}
			else {
				ptr = ptr->left;
			}
		}
		return false;
	}
	bool empty() const
	{
		if (head->parent == head)
			return 1;
		else
			return false;
	}
	int size()const
	{
		return n;
	}


};
