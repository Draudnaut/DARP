#include "pch.h"
#include "Solution.h"

Solution::Solution()
{
	length = 0;
}

Solution::Solution(Solution & s)
{
	length = s.length;
	for (int i = 0; i < length; i++)
	{
		tourlist[i] = s.tourlist[i];
	}
}

Solution::Solution(Tour listtour[], int len)
{
	length = len;
	for (int i = 0; i < len; i++)
		tourlist[i] = listtour[i];
}

Solution::Solution(Point list_point[], int len,int vertex_number)
{
	length = 0;
	for (int i = 0; i < len; i++) 
	{
		Tour t;
		t.add_point(list_point[i].id, t.get_length());
		t.add_point(list_point[i].id + vertex_number / 2, t.get_length());
		tourlist[length++] = t;
	}
}

Tour Solution::getitem(int index)
{
	if (index >= length) {
		printf("segmentation error,index out of range.\n");
		exit(-1);
	}
	return tourlist[index];
}

void Solution::update()
{
}
