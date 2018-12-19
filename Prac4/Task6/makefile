fraction.out: ArrayOperations.o ArrayOperations.cpp
	g++ ArrayOperations.o ArrayViewer.cpp -o ArrayViewer.out
	
test.out: reduce.o test.cpp
	g++ reduce.o test.cpp -o test.out

test: test.out
	./test.out
	
run: fraction.out
	./fraction.out
	
ArrayOperations.o: ArrayOperations.h ArrayOperations.cpp
	g++ -c ArrayOperations.cpp