#include <stdio.h>
#include <stdlib.h>

#define  INT8	signed char
#define  INT16	signed short
#define  INT32	signed int
#define  INT64	signed long

#define  UINT8	unsigned char
#define  UINT16	unsigned short
#define  UINT32	unsigned int
#define  UINT64	unsigned long

void swap(INT32 *a, INT32 *b)
{
	INT32 tmp = *a;
	*a = *b;
	*b = tmp;
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

void doubleBubbleSort(INT32 *src, INT32 len)
{
	INT32 low = 0, high = len - 1;
	INT32 i = 0;
	while (low < high)
	{
		for (i = low; i < high; i++)
		{
			if (src[i] > src[i + 1])
			{
				swap(&src[i], &src[i + 1]);
			}
		}
		high--;
		for (i = high; i > low; i--)
		{
			if (src[i] < src[i - 1])
			{
				swap(&src[i], &src[i - 1]);
			}
		}
		low++;
		// printf("high = %d,low = %d\n", high, low);
	}
}

INT32 binarySearch(INT32 *src, INT32 len, INT32 searchKey)
{
	INT32 low = 0, high = len - 1;
	INT32 mid = 0;

	while (low <= high)
	{
		mid = (high + low) >> 1;
		printf("1low:%d,mid:%d,high:%d,midValue:%d\n", low, mid, high,src[mid]);

		if (src[mid] == searchKey)
		{
			return mid;
		}
		else
		{
			if (src[mid] > searchKey)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}

		printf("2low:%d,mid:%d,high:%d,midValue:%d\n", low, mid, high, src[mid]);
	}

	return -1;
}


INT32 binarySearch2(INT32 *src, INT32 low, INT32 high, INT32 searchKey)
{
	INT32 mid = 0;
	mid = (high + low) >> 1;

	if (src[mid] == searchKey)
	{
		return mid;
	}

	if (low <= high)
	{
		if (src[mid] > searchKey)
		{
			return binarySearch2(src, low, mid - 1, searchKey);
		}
		else
		{
			return binarySearch2(src, mid + 1, high, searchKey);
		}
	}
	return -1;
}

int main(int argc, char **argv)
{

	if (argc < 2)
	{
		printf("need a search key\n");
		exit(1);
	}

	INT32 len = 0;
	INT32 testArray[50];
	len = sizeof(testArray) / sizeof(testArray[0]);

	int i = 0;
	for (i = 0; i < len; ++i)
	{
		testArray[i] = random() % 100;
	}

	print(testArray, len);
	doubleBubbleSort(testArray, len);
	print(testArray, len);

	// printf("search key: %d,index: %d\n", atoi(argv[1]), binarySearch(testArray, len, atoi(argv[1])));
	printf("search key: %d,index: %d\n", atoi(argv[1]), binarySearch2(testArray, 0,len - 1, atoi(argv[1])));

	return 0;
}