tic-tac-toe.out: input_validation.o main.o setting_up.o tic-tac-toe.o win.o
	gcc -g -Wall -Werror -o tic-tac-toe.out input_validation.o main.o setting_up.o tic-tac-toe.o win.o
input_validation.o: input_validation.c input_validation.h
	gcc -g -Wall -Werror -c input_validation.c

main.o: main.c setting_up.h tic-tac-toe.h
	gcc -g -Wall -Werror -c main.c
setting_up.o: setting_up.c setting_up.h
	gcc -g -Wall -Werror -c setting_up.c 
tic-tac-toe.o: tic-tac-toe.c tic-tac-toe.h input_validation.h
	gcc -g -Wall -Werror -c tic-tac-toe.c
win.o: win.c win.h
	gcc -g -Wall -Werror -c win.c

clean:
	rm -f *.o *.out 

dimensions ?= 3
run: tic-tac-toe.out
	./tic-tac-toe.out $(dimensions)