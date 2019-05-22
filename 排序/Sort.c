#include"Sort.h"
void InsertSort(int* a, int n)
{
	int end=0;
	int tmp;
	int set;
	while (end<n-1)
	{
		tmp = a[end+1];
		set = end;
		while (set>=0)
		{
			if (a[set]>tmp)
			{
				a[set + 1] = a[set];
				--set;
			}
			else
			{
				break;
			}
		}
		a[set + 1] = tmp;
		end++;
	}
}
void InsertSort2(int* a, int n)
{
	int i = 0; 
	for (i = 0; i < n - 1; ++i)
	{
		int end;
		int tmp;
		end = i;
		tmp = a[i + 1];
		while (end >= 0)
		{
			if (a[end]>tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}

}
void ShellSort(int* a, int n)
{
	int grap=3;
	while (grap)
	{
		int end = 0;
		int tmp;
		int set;
		while (end<n - grap)
		{
			tmp = a[end + grap];
			set = end;
			while (set >= 0)
			{
				if (a[set]>tmp)
				{
					a[set + grap] = a[set];
					set-=grap;
				}
				else
					break;
			}
			a[set + grap] = tmp;

			end+=grap;
		}
		--grap;
	}
}
void ShellSort2(int* a, int n)
{
	int grap;
	grap = n;
	while (grap>1)
	{
		grap = grap / 3 + 1;
		int i;
		for (i = 0; i < n - grap; ++i)
		{
			int end;
			int tmp;
			end = i;
			tmp = a[i + grap];
			while (end >= 0)
			{
				if (a[end]>tmp)
				{
					a[end + grap] = a[end];
					end-=grap;
				}
				else
					break;
			}
			a[end + grap] = tmp;
		}
	}
	
}
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int max;
	int min;
	int tmp;
	int i;
	while (begin < end)
	{
		max = begin;
		min = begin;
		for (i = begin; i <= end; ++i)
		{
			if (a[max] < a[i])
			{
				max = i;
			}
			if (a[min] > a[i])
			{
				min = i;
			}
		}
		tmp = a[begin];
		a[begin] = a[min];
		a[min] = tmp;
		if (max == begin)
		{
			max = min;
		}
		tmp = a[end];
		a[end] = a[max];
		a[max] = tmp;
		begin++;
		end--;
	}
}
void ADjustdown(int* a, int n, int parent)
{
	int child;
	child = parent * 2 + 1;
	int tmp;
	while (child < n)
	{
		if (child + 1<n&&a[child] < a[child + 1])
			child++;
		if (a[parent] < a[child])
		{
			tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapSort(int* a, int n)
{
	int tmp;
	int i = n - 1;
	i = (i - 1) / 2;
	while (i >= 0)
	{
		ADjustdown(a, n, i);
		--i;
	}
	i = n - 1;
	while (i > 0)
	{
		tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		--i;
		ADjustdown(a, i, 0);
	}
}
void BubbleSort(int* a, int n)
{
	int i;
	int j=0;
	int tmp;
	for (i = n - 1; i > 0; --i)
	{
		for (j = 0; j < i; ++j)
		{
			if (a[j]>a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
}
void Swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;

}
int Qsort1(int* a, int begin, int end)
{
	int cur;
	cur = begin;
	while (begin < end)
	{
		while (begin < end)
		{
			if (a[end] < a[cur])
				break;
			--end;
		}
		while (begin < end)
		{
			if (a[begin] > a[cur])
				break;
			++begin;
		}
		if (begin<end)
			Swap(&a[begin], &a[end]);
	}
	Swap(&a[cur], &a[end]);
	return end;
}
int Qsort2(int* a, int begin, int end)
{
	int tmp;
	tmp = a[begin];
	while (begin < end)
	{
		while (begin < end)
		{
			if (a[end] < tmp)
			{
				a[begin] = a[end];
				break;
			}
			end--;
		}
		while (begin < end)
		{
			if (a[begin]>tmp)
			{
				a[end] = a[begin];
				break;
			}
			begin++;
		}
	}
	a[begin] = tmp;
	return begin;
}
int Qsort3(int* a, int begin, int end)
{
	int tmp=a[begin];
	int prev = begin;
	int cur = begin + 1;
	while (cur <= end)
	{
		if (a[cur]<tmp&&cur>(++prev))
			Swap(&a[cur], &a[prev]);
		cur++;
	}
	Swap(&a[begin], &a[prev]);
	return prev;
}
void FastSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int div;
	div = Qsort3(a, begin, end);

	FastSort(a, begin, div - 1);
	FastSort(a, div + 1, end);

}
void Msort(int* a,int* b,int begin,int end)
{
	if (end-begin < 1)
		return;
	int mid = begin + (end - begin) / 2;
	int left = begin;
	int right = mid + 1;
	int set=begin;
	Msort(a, b, begin, mid);
	Msort(a, b, mid+1, end);
	while (left <= mid && right <= end)
	{
		if (a[left] < a[right])
			b[set++] = a[left++];
		else
			b[set++] = a[right++];
	}
	while (left <= mid)
	{
		b[set++] = a[left++];
	}
	while (right <= end)
	{
		b[set++] = a[right++];
	}
	set = begin;
	while (set <= end)
	{
		a[set] = b[set];
		++set;
	}
}
void MergeSort(int* a, int n)
{
	int* b = (int*)malloc(sizeof(int)*n);
	Msort(a,b,0,n-1);
}
void CountSort(int* a, int n)
{
	int i = 0;
	int j;
	int set;
	int max;
	int min;
	int* count;
	max = a[0];
	min = a[0];
	while (i < n)
	{
		if (max < a[i])
			max = a[i];
		if (min>a[i])
			min = a[i];
		i++;
	}
	set = max - min + 1;
	count = (int*)malloc(sizeof(int)*set);
	memset(count, 0, sizeof(int)*set);
	i = 0;
	while (i < n)
	{
		count[(a[i] - min)]++;
		i++;
	}
	i = 0;
	j = 0;
	while (i < set)
	{
		while (count[i])
		{
			a[j++] = i + min;
			count[i]--;
		}
		i++;
	}

}
void Printf(int* a,int n)
{
	while (n--)
	{
		printf("%d ", *a);
		a++;
	}
	printf("\n");
}

void Test()
{
	int a1[10] = { 4, 3, 5, 1, 8, 1, 6, 3, 2, 7 };
	int a2[10] = { 4, 3, 5, 1, 8, 1, 6, 3, 2, 7 };
	int a3[10] = { 4, 3, 5, 1, 8, 1, 6, 3, 2, 7 };
	int a4[10] = { 4, 3, 5, 1, 8, 1, 6, 3, 2, 7 };
	int a5[10] = { 4, 3, 5, 1, 8, 1, 6, 3, 2, 7 };
	int a6[10] = { 4, 3, 5, 1, 8, 1, 6, 3, 2, 7 };
	int a7[10] = { 4, 3, 5, 1, 8, 1, 6, 3, 2, 7 };
	int a8[10] = { 4, 3, 5, 1, 8, 1, 6, 3, 2, 7 };
	InsertSort2(a1, 10);
	Printf(a1, 10);
	ShellSort2(a2, 10);
	Printf(a2, 10);
	SelectSort(a3, 10);
	Printf(a3, 10);
	HeapSort(a4, 10);
	Printf(a4, 10);
	BubbleSort(a5, 10);
	Printf(a5, 10);
	FastSort(a6, 0, 10-1);
	Printf(a6, 10);
	MergeSort(a7, 10);
	Printf(a7, 10);
	CountSort(a8, 10);
	Printf(a8, 10);
}