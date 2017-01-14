#ifndef SUBMISSION_FILENOTOPENEXCEPTION_HPP_
#define SUBMISSION_FILENOTOPENEXCEPTION_HPP_

#include "Exception.hpp"

class FileNotOpenException : public Exception {
	public:
		FileNotOpenException(std::string prob);
};


#endif /* SUBMISSION_FILENOTOPENEXCEPTION_HPP_ */
