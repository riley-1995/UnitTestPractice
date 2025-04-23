# UnitTestPractice

## Getting Started

Prerequisites:
* Docker (\*nix) or Docker Desktop (Windows/Mac)
* \*nix-based Command Line Environment (i.e. WSL2 on Windows)

With Docker running, execute the following commands in order.

This will generate the container image. It needs to be run each time the
container configuration changes.

`docker build -t cpp-container .`

This will use the current code, attempt to build it, and run its tests
within the container. If you change the code (and not the container
configuration), you only need to repeat this command.

`docker run -v "$(pwd)":/usr/src -it cpp-container`


Docker Broken, Use this instead:

make mac-all
./a.put


Notes for testing:
docker run -v "$(pwd)":/usr/src -it cpp-container sh
make clean
make
./PasswordTest
gcov -r Password.cpp # or gcov -rbc Password.cpp # -r is relative, bc is for branch coverage