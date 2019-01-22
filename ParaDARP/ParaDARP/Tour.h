#pragma once
#include "basic_datastructure.h"
#include <cstdio>
const int const_node_length = 50;
class Tour 
{
private:
	int nodelist[const_node_length];
	int nodelist_len;
	void remove_point(int index);
public:
	Tour();
	void delete_request(int req1,int req2);
	Tour(int node[], int len);
	Tour(const Tour &);
	int get_item(int index);
	void add_point(int point,int index);
	int get_length() { return nodelist_len; };
	void copy_nodelist(int new_nodelist[]);
};