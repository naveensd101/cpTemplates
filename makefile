all:
	g++ soln.cpp -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector -I .
fast:
	g++ soln.cpp -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -I .
slow:
	g++ soln.cpp -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -I .
r:
	./a.out < in.txt
clean:
	rm a.out makefile in.txt
