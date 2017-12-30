// Chapter9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

class StudentGrade
{
	std::string m_name;
	char m_grade;
	friend class GradeMap;

public:
	
	StudentGrade(std::string name, char grade='C') :m_name(name), m_grade(grade)
	{
	}
};

class GradeMap
{
	std::vector<StudentGrade> m_map;

public:
	GradeMap()
	{
	}

	char& operator[](const std::string &name)
	{
		for (auto &ref : m_map)
		{
			if (ref.m_name == name)
				return ref.m_grade;
		}
		m_map.push_back(StudentGrade(name));
		return m_map.back().m_grade;
	}

};

int main()
{
	GradeMap grades;
	grades["Joe"] = 'A';
	grades["Frank"] = 'B';
	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	

    return 0;
}

