#pragma once

#include "person.h"
#include <string>
using std::string;

class PersonList{
	Person** _persons;
	size_t _size;
	size_t _capacity;
public:
	PersonList(size_t);
	PersonList(const PersonList&);
	~PersonList();
	PersonList& operator=(const PersonList&);
	bool Insert(Person*, size_t);
	bool Insert(const string&, size_t, size_t);
	Person* Get(size_t)const;
	int IndexOf(const Person&)const;
	bool Remove(size_t);
	bool IsEmpty()const;
	size_t Size()const;
};
