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

void read_data(std::string path)
{
}
