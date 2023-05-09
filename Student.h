#pragma once
#ifndef STUDENT
#define STUDENT 0x0001
#include <string>

class Student {
public:	Student() {
	id = -1;
	uid = "";
	name = "";
	address = "";
}
public:	Student(int _id, std::string _uid, std::string _name, std::string _address) :
	id(_id), uid(_uid), name(_name), address(_address) {}
public: Student(int _id) :id(_id) {}
public:
	int id;
	std::string uid;
	std::string name;
	std::string address;
};

#endif
