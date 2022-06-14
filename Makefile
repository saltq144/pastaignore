default:
	make pastaignore --ignore-errors
pastaignore:
	rm pastaignore
	g++ pastaignore.cpp -o pastaignore -Wall -Wextra -std=c++20 -O2

