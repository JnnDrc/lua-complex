# Lua-Complex

A simple complex number libray for Lua wrote in C

## How to use

there a two methods:

1. Pre-built binaries
   1. download/copy the binarie for your platform(if it's availble)
2. Manual install
   1. Ensure dependencies
      1. you need the Lua c API installed, you can move the lib to the
         lib directory insed src or change the makefile, for windows users the lua54.dll is already there
      2. GCC and GNU Make, (other compilers may work, but you need to change it in the Makefile)
   2. git clone this repo
   3. type `make install OS={YOUR-PLATFORM-HERE}`
      1. Platforms:
         - Windows (dependencies included)
         - Linux (dependencies need to be downloaded apart)
         - MacOS (dependencies need to be downloaded apart)
         - BSD (dependencies need to be downloaded apart)
      2. If your system isn't availble, you can compile the program
         using your compilers CLI

## Debug build

You can make debug build also, just type `make build OS={YOUR-PLATFORM-HERE}`,
the dependecies are equal to the install

## Documentation and Examples

todo
