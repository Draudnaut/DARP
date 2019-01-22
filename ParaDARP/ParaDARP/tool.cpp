#include "pch.h"
#include "tool.h"
#include <random>

bool cmp(const Point a, const Point b)
{
	if (a.time_window_end != b.time_window_end)return a.time_window_end < b.time_window_end;
	else return a.time_window_start < b.time_window_start;
}

void divide(int belong[], int length,int k)
{
	for (int i = 1; i <= length; i++)
		belong[i] = rand()%k;
}

double distance(Point ref[],int a, int b)
{
	return sqrt((ref[a].x - ref[b].x)*(ref[a].x - ref[b].x)+(ref[a].y - ref[b].y)*(ref[a].y - ref[b].y));
}
