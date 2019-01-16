#pragma once
#include <string>
struct Point {
	int id;
	double x;
	double y;
	int service_time;
	int quality;
	int time_window_start;
	int time_window_end;
};
struct request{
	Point pickup;
	Point delivery;
};
struct parameter {
	int k;
	std::string path;
};