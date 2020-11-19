SRCS = main.cpp console.cpp page.cpp perform.cpp user.cpp
HEADER = console.hpp page.hpp perform.hpp user.hpp
OBJF = $(SRCS:.c=.o)

main.out : $(OBJF)
	g++ $^ -o $@
	rm -f *.o

.c.o : $(HEADER)
	g++ -c $(SRCS)

clean :
	rm -f *.out *.o
