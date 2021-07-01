flags= -g -Wall -o FFT  -Ilib
src = src/main.cpp src/FFT.cpp

FFT:
	g++ ${flags} ${src}

.PHONY: FFT