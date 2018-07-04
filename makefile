cc	=	gcc
OBJ=	main.o	List.o	Map.o	status.o
astar	:	$(OBJ)
cc	-o	astar	$(OBJ)
main.o	:	List.h	Map.h
List.o	:	status.h	List.h
Map.o	:	List.h	Map.h
status.o	:	status.h
.phony	:	clean
clean	:
rm	astar	$(OBJ)
