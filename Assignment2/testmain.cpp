#include "Exception.hpp"
#include "FileNotOpenException.hpp"
#include "OutOfRangeException.hpp"




int main(int argc, char* argv[]) {
	Exception test("Problem","Info");
	test.PrintDebug();

	FileNotOpenException filetest("Nextprob");
	filetest.PrintDebug();	

	OutOfRangeException rangetest("Lastprob");
	rangetest.PrintDebug();	

return 0;}