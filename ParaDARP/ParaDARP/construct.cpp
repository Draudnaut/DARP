#include "pch.h"
#include "construct.h"
#include "tool.h"
void construct_new(Point a[],Tour s[],int length,int conflict[][2007])
{
	std::vector<int> list_point;
	for (int i = 0; i < length; i++)
	{
		int tour_len = s[i].get_length();
		for (int i = 0; i < tour_len; i++)
		{
			list_point.push_back(s[i].get_item(i));
		}
	}
}
