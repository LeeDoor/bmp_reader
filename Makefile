all:
	g++ main.cpp bmp.cpp bmp_reader.cpp bmp_drawer.cpp bmp_writer.cpp -o bmp_reader -std=c++20 -g -Wall -Wextra -Werror
