#include "person.h"
#include "personlist.h"

#include <iostream>
#include <cassert>
using std::cout;
using std::endl;
    0      ANNE    23

int main(int argc, char* argv[]){
	PersonList list(5);
	assert(list.Size() == 0);
	assert(list.Empty() == true);
	assert(list.Remove(0) == false);
	assert(list.Insert("JOHN", 18, 1) == false);
	assert(list.Insert("JENNY", 19, 0) == true);
	assert(list.Get(0)->ToString() == Person("JENNY", 19).ToString());
	assert(list.Size() == 1);
	assert(list.IsEmpty() == false);
	assert(list.Insert("JULES", 21, 0) == true);
	assert(list.Get(0)->ToString() == Person("JULES", 21).ToString());
	assert(list.Get(1)->ToString() == Person("JENNY", 19).ToString());
	assert(list.Size() == 2);
	assert(list.IndexOf(Person("JULES", 21)) == 0);
	assert(list.IndexOf(Person("ANNE", 23)) == -1);
	assert(list.Insert("CLAUDE", 25, 2) == true);
	assert(list.Remove(3) == false);
	assert(list.Remove(1) == true);
	assert(list.Size() == 2);
	assert(list.Get(1)->ToString() == Person("CLAUDE", 25).ToString());
	assert(list.Insert("FELIX", 17, 0) == true);
	assert(list.Insert("CLARA", 16, list.Size()) == true);
	assert(list.Insert("CHRIS", 27, 2) == true);
	assert(list.Insert("FULL", 90, 2) == false);
	assert(list.Size() == 5);

	cout << "Program passed all unit tests!" << endl << endl;


	return 0;
}
