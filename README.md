### Setup
1. Install readline library and some extra dependencies
	`sudo apt-get install lib32readline8 lib32readline-dev make git gcc`
2. Clone the repository
	 `git clone https://github.com/fortytwobytes/minibash && cd minibash`
3. Compile and run the program
    - with Cmake
     `mkdir -p build && (cd build && cmake .. && make && ./minibash)`
    - with Makefile
     `make && ./minibash`

