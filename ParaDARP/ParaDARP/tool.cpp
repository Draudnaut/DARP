#include "pch.h"
#include "tool.h"

bool cmp(const Point a, const Point b)
{
	if (a.time_window_end != b.time_window_end)return a.time_window_end < b.time_window_end;
	else return a.time_window_start < b.time_window_start;
}
