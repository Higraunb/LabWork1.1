#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double make_random_number(double min_ch, double max_ch, int sid_variable)
{
    double zero_one = 0, random_number = 0, zero_max_ch = 0;
    int randomization = 0;
    srand(clock() + sid_variable * 3452);
    randomization = rand();
    zero_one = (double)randomization / RAND_MAX;
    zero_max_ch = zero_one * (max_ch - min_ch);
    random_number = zero_max_ch + min_ch;
    return random_number;
}



int make_dec_remain(double double_variable)
{
    double remain = 0;
    int int_remain = 1;
    if (double_variable >= 0)
    {
        remain = double_variable - floor(double_variable);
    }
    else
        remain = (-double_variable) + ceil(double_variable);
    remain *= 1000000;
    int_remain = (int)round(remain);
    return int_remain;
}