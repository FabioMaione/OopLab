
objectfile=build/objectfile.cmd
tests=./build/methods

all: main

detectsystem:
	echo "\n\nInizio test: `date +%H:%M:%S`"
	echo "build/*lin.o" >$(objectfile)

clean:
	rm -f *~ *.o *.tar.gz compile compile.exe main main.exe signature build/*.cmd build/*.h build/*.cpp
	killall -q -v compile; echo ""

compile: detectsystem *.cpp *.h
	echo "Compilazione per test..."
	cp *.h *.cpp build
	rm build/main.cpp
	g++ --std=c++11 build/*.cpp `cat $(objectfile)` -o compile
	echo "fatto."

test: compile
	$(tests)
	echo "FINITO: `date +%H:%M:%S`\n\n"
