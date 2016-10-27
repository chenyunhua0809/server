#include <stdio.h>
#include <stdlib.h>

#define UINT8 	unsigned char 
#define UINT16 	unsigned short 
#define UINT32 	unsigned int 

#define INT8  	signed char 
#define INT16 	signed short 
#define INT32 	signed int 


void swap(INT32 *a, INT32 *b)
{
	INT32 tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
 * 如果碰见一个和插入元素相等的，那么插入元素把想插入的元素放在相等元素的后面。
 * 所以，相等元素的前后顺序没有改变，从原无序序列出去的顺序就是排好序后的顺序，
 * 所以插入排序是稳定的。
 */
void myInsert(INT32 *src, INT32 len)
{
	int i, j;
	INT32 tmp = 0;
	for (i = 1; i < len; ++i)
	{
		if (src[i] < src[i-1])
		{
			tmp = src[i];
			j = i - 1;
			do{
				src[j+1] = src[j];
				j--;
			}while(tmp < src[j]);
			src[j+1] = tmp;
		}
	}
}

/**
 * [shellInsert description]
 * @param src   [description]
 * @param len   [description]
 * @param start [description]
 */
void shellInsert(INT32 *src, INT32 len, INT32 start)
{
	int i, j;
	INT32 tmp = 0;
	for (i = start; i < len; ++i)
	{
		if (src[i] < src[i-1])
		{
			tmp = src[i];
			j = i - 1;
			do{
				src[j+1] = src[j];
				j--;
			}while(tmp < src[j]);
			src[j+1] = tmp;
		}
	}
}
/**
 * 希尔排序时效分析很难，关键码的比较次数与记录移动次数依赖于增量因子序列d的选取，
 * 特定情况下可以准确估算出关键码的比较次数和记录的移动次数。目前还没有人给出选取
 * 最好的增量因子序列的方法。增量因子序列可以有各种取法，有取奇数的，也有取质数的，
 * 但需要注意：增量因子中除1 外没有公因子，且最后一个增量因子必须为1。
 * 希尔排序方法是一个不稳定的排序方法。
 */
void shellSort(INT32 *src, INT32 len)
{
	INT32 start = len / 2;
	while(start >= 1)
	{
		shellInsert(src,len,start);
		start /= 2;
	}
}
/**
 * 在要排序的一组数中，选出最小（或者最大）的一个数与第1个位置的数交换；
 * 然后在剩下的数当中再找最小（或者最大）的与第2个位置的数交换，依次类推，
 * 直到第n-1个元素（倒数第二个数）和第n个元素（最后一个数）比较为止。
 */
void singleSelectSort(INT32 *src, INT32 len)
{
	INT32 i, j;
	INT32 minIndex = 0;
	INT32 tmp = 0;
	for (i = 0; i < len - 1; ++i)
	{
		minIndex = i+1;
		for ( j = minIndex; j < len; j++)
		{
			if (src[j] < src[minIndex])
				minIndex = j;
		}
		if (src[i] > src[minIndex])
		{
			tmp = src[i];
			src[i] = src[minIndex];
			src[minIndex] = tmp;
		}
		// printf("i = %d, minIndex = %d\n", i,minIndex);
	}
}
/**
 * 简单选择排序的改进——二元选择排序
 * 简单选择排序，每趟循环只能确定一个元素排序后的定位。我们可以考虑改进为每趟循环确定两个元素
 * （当前趟最大和最小记录）的位置,从而减少排序所需的循环次数。改进后对n个数据进行排序，
 * 最多只需进行[n/2]趟循环即可。
 */
void doubleSelectSort(INT32 *src, INT32 len)
{
	INT32 i, j;
	INT32 minIndex = 0;
	INT32 maxIndex = 0;
	INT32 tmp = 0;
	for (i = 0; i < len / 2; ++i)
	{
		minIndex = i+1;
		maxIndex = i+1;
		for ( j = minIndex; j < len - i; j++)
		{
			if (src[j] < src[minIndex])
				minIndex = j;
			if (src[j] > src[maxIndex])
				maxIndex = j;
		}
		if (src[i] > src[minIndex])
		{
			tmp = src[i];
			src[i] = src[minIndex];
			src[minIndex] = tmp;
		}
		if (src[len - i - 1] < src[maxIndex])
		{
			tmp = src[len - i - 1];
			src[len - i - 1] = src[maxIndex];
			src[maxIndex] = tmp;
		}
		// printf("i = %d, minIndex = %d, maxIndex = %d\n", i,minIndex,maxIndex);
	}
}

void heapSort(INT32 *src, INT32 len)
{
	
}
/**
 * 在要排序的一组数中，对当前还未排好序的范围内的全部数，自上而下对相邻的两个数依次进行比较和调整，
 * 让较大的数往下沉，较小的往上冒。
 * 即：每当两相邻的数比较后发现它们的排序与排序要求相反时，就将它们互换。
 */
void bubbleSort(INT32 *src, INT32 len)
{
	int i, j;
	INT32 tmp = 0;
	for (i = 0; i < len; ++i)
	{
		for (j = i; j < len; ++j)
		{
			if (src[i] > src[j])
			{
				swap(&src[i],&src[j]);
			}
		}
	}
}
/**
 * 传统冒泡排序中每一趟排序操作只能找到一个最大值或最小值,我们考虑利用在每趟排序中进行
 * 正向和反向两遍冒泡的方法一次可以得到两个最终值(最大者和最小者) , 
 * 从而使排序趟数几乎减少了一半。
 */
void doubleBubbleSort(INT32 *src, INT32 len)
{
	INT32 low = 0, high = len - 1;
	INT32 i = 0;
	while (low < high)
	{
		for (i = low; i < high; i++)
		{
			if (src[i] > src[i+1])
			{
				swap(&src[i],&src[i+1]);
			}
		}
		high--;
		for (i = high; i > low; i--)
		{
			if (src[i] < src[i - 1])
			{
				swap(&src[i],&src[i-1]);
			}
		}
		low++;

		printf("high = %d,low = %d\n", high,low);
	}
}

INT32 partition(INT32 *src, INT32 low, INT32 high)
{
	INT32 key = src[low];
	while(low < high)
	{
		while(low < high && src[high] >= key) high--;
		swap(&src[low], &src[high]);

		while(low < high && src[low] <= key) low++;
		swap(&src[low], &src[high]);
	}
	return low;
}
void quickSort(INT32 *src, INT32 low, INT32 high)
{
	if (low < high)
	{
		INT32 position = partition(src,low,high);

		quickSort(src, low, position);
		quickSort(src, position+1, high);
	}
}


void print(INT32 *input, INT32 len)
{
	int i = 0;
	for (i = 0; i < len; ++i)
	{
		printf("%d ", input[i]);
	}
	printf("\n");
}



int main(int argc, char const *argv[])
{
	// srandom(time(NULL));
	INT32 len = 0;
	INT32 testArray[10];
	len = sizeof(testArray) / sizeof(testArray[0]);

	int i = 0;
	for (i = 0; i < len; ++i)
	{
		testArray[i] = random()%100;
	}

	print(testArray, len);
	// myInsert(testArray, len);
	// doubleSelectSort(testArray, len);
	doubleBubbleSort(testArray, len);
	quickSort(testArray, 0, len -1);

	// printf("len = %d\n", len);
	print(testArray, len);

	return 0;
}