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

void conflict_table(Point a[], int conflict[][2007],int length)
{
	/*
		calculate whether i and j are conflict.
		conflict[i][j] = 1 means i and j are conflict.
		conflict[i][j] = 0 means i and j are not conflicted.
	*/
	int count = 0;
	for (int i=1;i<=length;i++)
	{
		for (int j = 1; j <= length; j++) 
		{
			if (i == j) continue;
			/*i j both pickup*/
			if (i <= length / 2) {
				if (j <= length / 2) {
					double distance1 = distance(a, i, j);
					double distance2 = distance(a, j, j + length / 2);
					if (distance1 + distance2 > (double)(a[j + length / 2].time_window_end)) { printf("time : %.4lf , end : %.4lf\n", distance1 + distance2, (double)(a[j + length / 2].time_window_end)); count++; conflict[i][j] = 1; }
				}
			}
			/*i pickup j not corresponding delivery*/
			if (i <= length/2){
				if (j > length / 2 and j != i + length / 2) {
					double distance1 = distance(a, i, j);
					double distance2 = distance(a, j, i + length / 2);
					if (distance1 + distance2 > (double)(a[i + length / 2].time_window_end)) { printf("time : %.4lf , end : %.4lf\n", distance1 + distance2, (double)(a[j + length / 2].time_window_end)); count++; conflict[i][j] = 1; }
				}
			}
			if (i > length / 2 and j > length / 2) continue;
		}
	}
}
