#pragma once
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include "basic_datastructure.h"
parameter analyse_input_para(int c, char**argv);
void read_data(std::string path, Point point_list[], int &vehicle_number, int &vehicle_distance, int &vehicle_capacity, int &ridetime,int &vertex_number);