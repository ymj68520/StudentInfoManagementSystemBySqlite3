#define _CRT_SECURE_NO_WARNINGS 1

#include "Student.cpp"
#include <vector>

class StudentInfo {
public:
	int count;
	std::vector<Student> stu;

private:
	StudentInfo() {
		count = 0;
		stu.clear();
	}
};