// Chapter9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Mystring
{
	std::string m_string;

public:
	Mystring(std::string string) :m_string(string)
	{
	}

	std::string operator()(int index, int length)
	{
		std::string tempString;
		for (int i = index; i < index+length; ++i)
		{
			tempString += m_string[i];
		}
		return tempString;
	}
};



int main()
{
	Mystring string("Hello, world!");
	std::cout << string(7, 5); // start at index 7 and return 5 characters

    return 0;
}

