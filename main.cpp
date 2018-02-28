#include "person.h"
#include "personlist.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[]){
	PersonList list(5);
	cout << list.IsEmpty() << endl;
	cout << list.Size() << endl;
	cout << list.Remove(0) << endl;

	return 0;
}
