#include "Student.hpp"
#include "GraduateStudent.hpp"
//#include "PhdStudent.hpp"
#include <iostream>


int main(int argc, char* argv[]) {
	Student test;
	Student undergrad("me",3,4);
	std::cout << "total owed:" << undergrad.MoneyOwed() << "\n";
	GraduateStudent grad("you",3,4, 0);
	std::cout << "total owed:" << grad.MoneyOwed() << "\n";
return 0;}