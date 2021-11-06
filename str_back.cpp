#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::string str ("Sanfoundry.");
	str.back() = '!';
	std::cout << str << endl;			// Sanfoundry!
  
	return 0;
}

/*
back() function modifies the last character of the string with the character provided.
*/
