void bTreeLevelOrder(Node*root)
{
	Queue q;
	initQueue(&q);
	if (root)
		queuePush(&q, root);
	while (!queueEmpty(&q))
	{
		Node*front = queueFront(&q);
		queuePop(&q);
		printf("%d", front->data);
		if (front->_left)
			queuePush(&q,front->_left)
		if (front->_right)
			queuePush(&q, front->_right)
	}
	printf("\n");
	��ȫ�����������Ҳ�������м��޿սڵ㣬

struct TreeNode* invertTree(struct TreeNode*root)
	{
		if (root == NULL)
			return NULL;
		//������������
		struct TreeNode*tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL&&q == NULL)
		return true;
	if (p == NULL || q = NULL)
		return false;
	return p->val == q->val
		&&isSameTree(p->left, q->left)
		&& isSameTree(p->right, q->right);
}

 //�ж�һ�����Ƿ�Ϊ��һ���������� ��
bool isSubtree(struct TreeNode* s, struct treeNode* t)
{
	if (t == NULL)
		return ture;
	if (s == NULL)
		return false;
	return isSameTree(s,t)
		|| isSubtree(s->left,t)
		|| isSubtree(s->right,t)
}

  //�Գƶ�����
bool _isSym(struct TreeNode* left, struct TreeNode* right)
{
	if (left == NULL&&right == NULL)
		return ture;
	if (left == NULL || right == NULL)
		return false;
	return left->val == right->val
		&&_isSym(left->left, right->right)
		&& _isSym(left->right, right->left);
}
boolisSymmetric(struc TreeNode*root)
{
	if (root == NULL)
		return true;
	return _isSym(root->left, root->right);
}
//ƽ�������
int getHeight(struct TreeNode* root)
{
	if (root)
	{
		int left = getHeight(root->left);
		int right = getHeight(root->right);
		return left > right ? left + 1;

	}
}
bool isBanlance(struct TreeNode* root)
{
	if (root == NULL)
		return ture;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	//��ǰ�������߶Ȳ�С��2
	return abs(left - right) < 2
		&& isBalabce(root->left)
		&& isBanlance(root->right);
}












































































































































































}
