#include <iostream>
#include "Exception.hpp"


//Constructor
Exception::Exception(std::string tagString, std::string probString)
{
	mProblem = probString;
    mTag = tagString;
}

void Exception::PrintDebug() const {
   std::cerr << "** Error ("<<mTag<<") **\n";
   std::cerr << "Problem: " << mProblem << "\n\n";
}