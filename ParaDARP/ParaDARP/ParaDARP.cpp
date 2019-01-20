// ParaDARP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Read.h"
#include "config.h"
#include "tool.h"
#include "Solution.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <thread>
#include <vector>
int thread_belong[102][2005];
//thread_belong[i][j] means the j-th point in thread i.
//please set setting.
int main(int argc,char* argv[])
{
	parameter para;
	int vehicle_number, vehicle_distance, vehicle_capacity, ridetime,vertex_number;
	Point vertex_list[maxn];
	int belong[maxn];
	para = analyse_input_para(argc, argv);
	/*read the data*/
	read_data(para.path, vertex_list,vehicle_number,vehicle_distance,vehicle_capacity,ridetime,vertex_number);
	/*sort the point*/
	time_t start, end;
	start = clock();
	end = clock();
	Solution s(vertex_list+1, vertex_number / 2, vertex_number);
	while ((double)(end - start) / CLOCKS_PER_SEC <= 60.0) 
	{
		divide(belong, s.get_length(), para.k);
		memset(thread_belong, 0, sizeof(thread_belong));
		for (int i = 1; i <= vertex_number / 2; i++) 
		{
			thread_belong[belong[i]][0]+=2;
			thread_belong[belong[i]][thread_belong[belong[i]][0]-1] = i;
			thread_belong[belong[i]][thread_belong[belong[i]][0] ] = i+vertex_number/2;
		}
		end = clock();
		s.update();
	}
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
