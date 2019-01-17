#include "pch.h"
#include "Solution.h"

Solution::Solution()
{
	length = 0;
}

Solution::Solution(Tour listtour[], int len)
{
	length = len;
	for (int i = 0; i < len; i++)
		tourlist[i] = listtour[i];
}

Tour Solution::getitem(int index)
{
	if (index >= length) {
		printf("segmentation error,index out of range.\n");
		exit(-1);
	}
	return tourlist[index];
}
