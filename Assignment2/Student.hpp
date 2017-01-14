#ifndef SUBMISSION_STUDENT_HPP_
#define SUBMISSION_STUDENT_HPP_

#include <string>
#include <iostream>

class Student {
public:
	Student();
	Student(std::string name, double fines, double fees);

	std::string name;
	double tuition_fees;
	virtual double MoneyOwed() const;

	void SetLibraryFines(double amount);
	double GetLibraryFines() const;

private:
	double library_fines;
};



#endif /* SUBMISSION_STUDENT_HPP_ */
