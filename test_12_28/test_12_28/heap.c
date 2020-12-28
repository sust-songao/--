//假设为小堆
void shiftDown(int *arr, int n, int curPos)
{
	//左孩子
	int child = 2 * curPos + 1;
	while (child < n)
	{
		//从左孩子中找到最小的一个位置
		if (child+1<n && arr[child + 1] < arr[child])
			++child;
	}
	//需要调整的数据和最小值进行比较
	if (arr[child] < arr[curPos])
	{
		int tmp = arr[child];
		arr[child] = arr[curPos];
		arr[curPos] = tmp;
		//更新位置
		curPos = child;
		child = 2 * curPos + 1;
	}
}
//假设为大堆
void shiftDown(int *arr, int n, int curPos)
{
	//左孩子
	int child = 2 * curPos + 1;
	while (child < n)		    
	{
		//从左孩子中找到最小的一个位置
		if (child + 1<n && arr[child + 1] >arr[child])
			++child;
	}
	//需要调整的数据和最小值进行比较
	if (arr[child] >arr[curPos])
	{
		int tmp = arr[child];
		arr[child] = arr[curPos];
		arr[curPos] = tmp;
		//更新位置
		curPos = child;
		child = 2 * curPos + 1;
	}
}