CC	=	gcc
OBJ =	main.o	List.o	Map.o	status.o
CFLAGS = -c -g 
astar:	$(OBJ)
	$(CC)	-o	astar	$(OBJ)
main.o:	main.c 
	$(CC) $(CFLAGS) $^ -o $@
List.o: List.c
	$(CC) $(CFLAGS) $^ -o $@
Map.o:	Map.c
	$(CC) $(CFLAGS) $^ -o $@
status.o:	status.c 
	$(CC) $(CFLAGS) $^ -o $@
.PHONY:	clean
clean:
	rm	astar	$(OBJ)
