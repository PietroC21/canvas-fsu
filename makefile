run: student.o course.o commands.o menu.o 
	g++ student.o course.o commands.o menu.o -o menu.exe

menu.o: menu.cpp   student.h commands.h
	g++ -c menu.cpp

commands.o: commands.cpp commands.h 
	g++ -c commands.cpp

course.o: course.cpp  student.h
	g++ -c course.cpp

student.o: student.cpp student.h
	g++ -c student.cpp 

clean:
	rm *.o
	rm *.exe
