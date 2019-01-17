#include "pch.h"
#include "Tour.h"

Tour::Tour()
{
	nodelist_len = 0;
}

Tour::Tour(int node[], int len)
{
	nodelist_len = len;
	for (int i = 0; i < len; i++) 
	{
		nodelist[i] = node[i];
	}
}

int Tour::get_item(int index)
{
	return nodelist[index];
}
