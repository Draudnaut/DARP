#pragma once
#include "Tour.h"
#include "basic_datastructure.h"
const int tour_len = 1003;
class Solution
{
private:
	Tour tourlist[tour_len];
	int length;
public:
	Solution();
	Solution(Tour listtour[], int len);
	Solution(Point list_point[], int len,int vertex_number);
	int get_length() { return length; };
	Tour getitem(int index);
};