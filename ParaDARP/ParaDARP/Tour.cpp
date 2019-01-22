#include "pch.h"
#include "Tour.h"

void Tour::remove_point(int index)
{
	for (int i=nodelist_len-1;i>index;i--)
	{
		nodelist[i - 1] = nodelist[i];
	}
	nodelist_len--;
}

Tour::Tour()
{
	nodelist_len = 0;
}

void Tour::delete_request(int req1,int req2)
{
	int index1, index2;
	for (int i = 0; i < nodelist_len; i++)
	{
		if (nodelist[i] == req1) index1 = i;
	}
	remove_point(index1);
	for (int i = 0; i < nodelist_len; i++) 
	{
		if (nodelist[i] == req2) index1 = i;
	}
	remove_point(index1);
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

void Tour::add_point(int point, int index)
{
	for (int i = nodelist_len; i > index; i--) {
		nodelist[i] = nodelist[i - 1];
	}
	nodelist[index] = point;
	nodelist_len++;
}

void Tour::copy_nodelist(int new_nodelist[])
{
	for (int i = 0; i < nodelist_len; i++)
	{
		new_nodelist[i] = nodelist[i];
	}
}
