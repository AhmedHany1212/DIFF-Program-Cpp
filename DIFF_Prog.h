#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include<bits/stdc++.h>
using namespace std;



typedef struct file
{
    int     line_num;
    string  Line;
    int     word_num;
    string  word;
    int     num_spaces;

} file;


//============================= FUNCTIONS ============================================

void compare_lines(file File_1,file File_2,int mode,int line_num,int pass_flag);
