COMPILER = g++
FLAGS = -std=c++14
COMPILE = $(COMPILER)  $(FLAGS)

out: main.o CancerData.o
	$(COMPILE) main.o CancerData.o -o mainexe

main.o: main.cpp
	$(COMPILE) -c main.cpp

CancerData.o: CancerData.cpp
	$(COMPILE) -c CancerData.cpp
	
clean:
	rm main.o; rm CancerData.o; rm mainexe