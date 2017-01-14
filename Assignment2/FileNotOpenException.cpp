#include <iostream>
#include "Exception.hpp"
#include "FileNotOpenException.hpp"



//Constructor
FileNotOpenException::FileNotOpenException(std::string prob) : Exception(prob,"File Not Open")
{
}
