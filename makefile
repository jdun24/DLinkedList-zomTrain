OBJS = zombie.o
CPPS = main.cpp dlist.cpp zombie.cpp

#_______________ROAD SEGMENT FILES_____________
DLISTFILES = dlist.h 
ZOMBIEFILES = zombie.h zombie.cpp

DEBUG = -g
CFLAGS = -Wall -c 
LFLAGS = -Wall $(DEBUG)
WALL = -Wall


exe: $(OBJS) $(DLISTFILES)
	g++ $(WALL) $(CPPS) -o exe
	
zombie.o: $(ZOMBIEFILES)
	g++ $(CFLAGS) zombie.cpp
	
clean:
	\rm *.o *~ exe