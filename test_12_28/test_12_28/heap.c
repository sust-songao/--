//����ΪС��
void shiftDown(int *arr, int n, int curPos)
{
	//����
	int child = 2 * curPos + 1;
	while (child < n)
	{
		//���������ҵ���С��һ��λ��
		if (child+1<n && arr[child + 1] < arr[child])
			++child;
	}
	//��Ҫ���������ݺ���Сֵ���бȽ�
	if (arr[child] < arr[curPos])
	{
		int tmp = arr[child];
		arr[child] = arr[curPos];
		arr[curPos] = tmp;
		//����λ��
		curPos = child;
		child = 2 * curPos + 1;
	}
}
//����Ϊ���
void shiftDown(int *arr, int n, int curPos)
{
	//����
	int child = 2 * curPos + 1;
	while (child < n)		    
	{
		//���������ҵ���С��һ��λ��
		if (child + 1<n && arr[child + 1] >arr[child])
			++child;
	}
	//��Ҫ���������ݺ���Сֵ���бȽ�
	if (arr[child] >arr[curPos])
	{
		int tmp = arr[child];
		arr[child] = arr[curPos];
		arr[curPos] = tmp;
		//����λ��
		curPos = child;
		child = 2 * curPos + 1;
	}
}