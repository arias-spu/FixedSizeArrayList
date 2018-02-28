list:	main person personlist
	g++ -std=c++11 main.o person.o personlist.o -o list

person:	person.cpp person.h
	g++ -std=c++11 -c person.cpp

personlist:	person.h personlist.h personlist.cpp
	g++ -std=c++11 -c personlist.cpp

main:	main.cpp person.h personlist.h
	g++ -std=c++11 -c main.cpp

clean:
	rm *.o list
