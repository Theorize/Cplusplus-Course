#include <iostream>
#include "OutOfRangeException.hpp"


//Constructor
OutOfRangeException::OutOfRangeException(std::string prob) : Exception(prob, "Out of Range")
{
}
