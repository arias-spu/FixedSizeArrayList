#include "person.h"
#include "personlist.h"
#include <string>
using std::string;

	Person** _persons;
	size_t _size;
	size_t _capacity;

PersonList::PersonList(size_t capacity): _size(0), _capacity(capacity){
	_persons = new Person*[_capacity];
	for (size_t i=0; i<_capacity; i++)
		_persons[i] = nullptr;
}
PersonList::PersonList(const PersonList& other): _size(other._size), _capacity(other._capacity){
	_persons = new Person*[_capacity];
	for (size_t i=0; i<_capacity; i++)
		_persons[i] = other._persons[i];
}
PersonList::~PersonList(){
	if (_persons){
		for (size_t i=0; i<_size; i++)
			if (_persons[i])
				delete _persons[i];
		delete[] _persons;
	}
}
PersonList& PersonList::operator=(const PersonList& rhs){
	if (this == &rhs)
		return *this;
	
	for (size_t i=0; i<_size; i++){
		delete _persons[i];
		_persons[i] = nullptr;
	}
	_size = rhs._size;
	
	if (_capacity != rhs._capacity){
		delete[] _persons;
		_capacity = rhs._capacity;
		_persons = new Person*[_capacity];
		for (size_t i=0; i<_capacity; i++)
			_persons[i] = nullptr;
	}
	for (size_t i=0; i<rhs._size; i++)
		_persons[i] = new Person(*rhs._persons[i]);
	return *this;
}
bool PersonList::Insert(Person* person, size_t position){
	if (_size == _capacity)
		return false;
	if (position > _size)
		return false;
	for (size_t i = _size; i > position; i--)
		_persons[i] = _persons[i-1];
	_persons[position] = person;
	_size++;
	return true;
}
bool PersonList::Insert(const string& name, size_t age, size_t position){
	if (_size == _capacity)
		return false;
	if (position > _size)
		return false;
	return Insert(new Person(name, age), position);
}
Person* PersonList::Get(size_t position)const{
	if (position >= _size)
		return nullptr;
	return _persons[position];
}
int PersonList::IndexOf(const Person& person)const{
	for (size_t i=0; i<_size; i++)
		if (_persons[i]->ToString() == person.ToString())
			return i;
	return -1;
}
bool PersonList::Remove(size_t position){
	if (position >= _size)
		return false;
	Person* toErase = _persons[position];
	for (size_t i=position; i<_size-1; i++)
		_persons[i] = _persons[i+1];
	_size--;
	_persons[_size] = nullptr;
	delete toErase;
	return true;
}
bool PersonList::IsEmpty()const{
	return _size == 0;
}
size_t PersonList::Size()const{
	return _size;
}
