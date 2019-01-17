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

Tour::Tour(const Tour &a)
{
	nodelist_len = a.nodelist_len;
	for (int i = 0; i < nodelist_len; i++)
		nodelist[i] = a.nodelist[i];
}

int Tour::get_item(int index)
{
	return nodelist[index];
}
