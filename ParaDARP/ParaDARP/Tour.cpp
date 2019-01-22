#include "pch.h"
#include "Tour.h"
#include "tool.h"
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

double Tour::Evaluation(Point a[],int vehicle_capacity)
{
	/*check feasibilty*/
	double time = distance(a,0,nodelist[0])+a[nodelist[0]].service_time;
	for (int i = 1; i < nodelist_len; i++) 
	{
		time += distance(a,nodelist[i - 1], nodelist[i]);
		if (time > a[nodelist[i]].time_window_end) return -1;
		time += a[nodelist[i]].service_time;
	}
	int total_weight = 0;
	for (int i = 0; i < nodelist_len; i++)
	{
		total_weight += a[nodelist[i]].quality;
	}
	if (total_weight > vehicle_capacity) return -1;
	/*return cost*/
	double cost = distance(a, 0, nodelist[0]);
	for (int i = 1; i < nodelist_len; i++)
	{
		cost += distance(a, nodelist[i - 1], nodelist[i]);
	}
	return cost;
}
