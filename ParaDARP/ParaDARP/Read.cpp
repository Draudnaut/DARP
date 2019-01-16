#include "pch.h"
#include "Read.h"

parameter analyse_input_para(int c, char ** argv)
{
	int k;
	std::string path;
	k = atoi(argv[2]);
	path = std::string(argv[4]);
	parameter re;
	re.k = k;
	re.path = path;
	return re;
}

void read_data(std::string path,Point point_list[],int &vehicle_number,int &vehicle_distance,int &vehicle_capacity,int &ridetime,int &vertex_number)
{
	char path_operate[200];
	strcpy(path_operate, path.c_str());
	FILE* input=fopen(path_operate,"r");
	if (input == NULL) {
		printf("input file doesn't exsit.\n");
		exit(-1);
	}
	char dataset_name[100];
	char name[100];
	fscanf(input, "%s", dataset_name);
	int index = 8;
	while (dataset_name[index]) {
		name[index - 8] = dataset_name[index];
		index++;
	}
	name[index - 8] = '\0';
	if (strcmp(name, "Cordeau2003")==0) 
	{
		fscanf(input, "%d%d%d%d%d", &vehicle_number, &vertex_number, &vehicle_distance, &vehicle_capacity, &ridetime);
		for (int i = 0; i <= vertex_number; i++) 
		{
			fscanf(input, "%d%lf%lf%d%d%d%d", &point_list[i].id, &point_list[i].x, &point_list[i].y, &point_list[i].service_time, &point_list[i].quality, &point_list[i].time_window_start, &point_list[i].time_window_end);
		}
	}
	else 
	{

	}
	fclose(input);
}
