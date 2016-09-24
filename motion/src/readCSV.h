//11/9/16
//author:sakshi
//header file for readCSV.cpp
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string>


typedef std::vector<std::string>  vect;
class readCSV
{
public:
std::vector<std::string>  storeCSV2array(const char*const filename,int row,int col);	
};
