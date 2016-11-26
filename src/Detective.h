#ifndef COLLECT_H
#define COLLECT_H
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <cstdbool>
#include <fstream>
#include <cstddef>       
#include "Tokenizer.h"

using namespace std; 

struct sink {
	string value;
 	string line;
 	int line_number;
 	bool taint;
	bool inloop;
};

struct startpoint {
 	string var_name;
 	string line;
 	int line_number;
 	vector<sink> sinks;
};


class Detective
{
public:

// This is array of functions names that use HEAP
// brk(), sbrk() ? at the future
	vector<string> heap_in = {"malloc","xmalloc","realloc","xrealloc","calloc","xcalloc","new "}; 
	vector<string> heap_out = {"free","xfree","FREE","XFREE","delete "};
	vector<string> loop_in = {"for","while","do"};
	vector<string> cond = {"if","else","elseif","switch"};

	vector<startpoint> array;
	vector<sink> sinks;

	void get_sinks(string FileName);                                     
	void view_sinks();                                     
};

#endif 
