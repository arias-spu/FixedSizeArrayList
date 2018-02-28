#include "person.h"
#include "personlist.h"

#include <iostream>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setw;

void PrintList(const PersonList&);

int main(int argc, char* argv[]){
	PersonList list(5);
	PrintList(list);
	cout << "IsEmpty       = " << list.IsEmpty() << endl;
	cout << "Size          = " << list.Size() << endl;
	cout << "Remove(0)     = " << list.Remove(0) << endl;
	cout << "Insert(E, 1)  = " << list.Insert("JOHN", 15, 1) << endl;
	cout << "Insert(E, 0)  = " << list.Insert("PETER", 15, 0) << endl;
	PrintList(list);
	cout << "Insert(E, 0)  = " << list.Insert("ANNE", 23, 0) << endl;
	PrintList(list);
	cout << "Insert(E, 1)  = " << list.Insert("PATRICK", 18, 1) << endl;
	cout << "Insert(E, 3)  = " << list.Insert("KATHY", 19, 3) << endl;
	PrintList(list);
	cout << "Remove(0)     = " << list.Remove(0) << endl;
	PrintList(list);



	return 0;
}
void PrintList(const PersonList& list){
	cout << "-------------------------------------" << endl;
	cout << "Printing List of Size = " << list.Size() << endl;
	for (size_t i=0; i<list.Size(); i++)
		cout << setw(5) << i << list.Get(i)->ToString() << endl;
	cout << "-------------------------------------" << endl;
}
