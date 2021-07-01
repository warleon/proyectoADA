flags= -std=c++11 -g -Wall -o FFT 
src = src/main.cpp 
lib = -Ilib 

FFT:
	g++ ${flags} ${src} ${lib}

.PHONY: FFT