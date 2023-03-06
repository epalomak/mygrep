#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<string>
#include<string.h>
#include<fstream>

using namespace std;


struct options
{
	int l = 0;
	int o = 0;
	int r = 0;
	int i = 0;
};


int		findstr(string, string);
string	to_lower(string);
void	grep_with_options(char **argv, options chosen_options);

#endif