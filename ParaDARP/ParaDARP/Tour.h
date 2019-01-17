#pragma once
#include "basic_datastructure.h"
#include <cstdio>
const int const_node_length = 50;
class Tour 
{
private:
	int nodelist[const_node_length];
	int nodelist_len;
public:
	Tour();
	Tour(int node[], int len);
	Tour(const Tour &);
	int get_item(int index);
	void add_point(int point,int index);
	int get_length() { return nodelist_len; };
};