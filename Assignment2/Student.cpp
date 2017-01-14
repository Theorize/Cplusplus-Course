#include "Student.hpp"
#include <string>
#include <iostream>
#include <cassert>


//overwrite default constructor
Student::Student() {
	name = "unspecified";
}

Student::Student(std::string name, double fines, double fees){
	this->name = name;
	tuition_fees = fees;
	SetLibraryFines(fines);
}

void Student::SetLibraryFines(double amount){
	if(amount >= 0.0){
		library_fines = amount;
	}
}

double Student::GetLibraryFines() const{
	return library_fines;
}

double Student::MoneyOwed() const{
	double owed = library_fines + tuition_fees;
	return owed;
}