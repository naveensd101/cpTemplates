all:
	g++ __soln.cpp -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result
fast:
	g++ __soln.cpp -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result
slow:
	g++ __soln.cpp -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
r:
	./a.out < in.txt
clean:
	rm a.out makefile in.txt
