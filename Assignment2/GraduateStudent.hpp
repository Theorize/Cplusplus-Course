#ifndef SUBMISSION_GRADUATESTUDENT_HPP_
#define SUBMISSION_GRADUATESTUDENT_HPP_

#include "Student.hpp"

class GraduateStudent : public Student {
private:

public:
	GraduateStudent();
	GraduateStudent(std::string name, double fines, double fees, bool fullTime);
	bool fullTime;
	virtual double MoneyOwed() const;

};



#endif /* SUBMISSION_GRADUATESTUDENT_HPP_ */
