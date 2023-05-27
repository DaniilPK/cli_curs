#pragma once
#include<iostream>
#include<conio.h>
#include<string>
#include<ctime>


using namespace std;
class w_time {

public:
	void get_times()
	{

		time_t result = time(NULL);
		char str[26];
		ctime_s(str, sizeof str, &result);
		cout<< str;
	}
};
