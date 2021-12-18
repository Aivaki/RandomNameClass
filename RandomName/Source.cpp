#include "Header.h"

int main()
{
	RandomNameClass Name;

	std::cout << Name.Name_LPCWSTR() << std::endl;
	std::cout << Name.Name_string() << std::endl;

	return NULL;
}