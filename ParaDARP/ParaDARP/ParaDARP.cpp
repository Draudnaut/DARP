// ParaDARP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Read.h"
#include "config.h"
#include <iostream>
#include <algorithm>
Point vertex_list[maxn];
int cmp(Point a, Point b) {
	if (a.time_window_end < b.time_window_end) return 1;
	else if (a.time_window_start < b.time_window_start) return 1;
	else return 0;
}
int main(int argc,char* argv[])
{
	parameter para;
	int vehicle_number, vehicle_distance, vehicle_capacity, ridetime,vertex_number;
	para = analyse_input_para(argc, argv);
	read_data(para.path, vertex_list,vehicle_number,vehicle_distance,vehicle_capacity,ridetime,vertex_number);
	std::sort(vertex_list + 1, vertex_list + vertex_number + 1, cmp);

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
