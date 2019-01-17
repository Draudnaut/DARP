#pragma once
#include "Tour.h"
const int tour_len = 80;
class Solution
{
private:
	Tour tourlist[tour_len];
	int length;
public:
	Solution();
	Solution(Tour listtour[], int len);
	Tour getitem(int index);
};