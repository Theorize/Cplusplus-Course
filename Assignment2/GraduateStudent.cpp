#include "GraduateStudent.hpp"
#include <string>
#include <iostream>
#include <cassert>

GraduateStudent::GraduateStudent(std::string name, double fines, double fees, bool fullTime) : Student()
{
	this->name = name;
	tuition_fees = fees;
	SetLibraryFines(fines);
	this->fullTime = fullTime;
}

double GraduateStudent::MoneyOwed() const{
	return GetLibraryFines();
}