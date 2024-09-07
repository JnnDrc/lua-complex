# Lua-Complex

A simple complex number libray for Lua wrote in C

## How to download

1. Ensure dependencies

   1. you need the Lua c API installed, you can move the lib to the
      lib/{YOUR-PLATFORM} directory inside src or change the makefile to use your global installed,
      for windows users the lua54.dll is already in the lib/Windows directory
   2. GCC and GNU Make, (other compilers may work, but you need to change it in the Makefile)

2. git clone this repo
3. type `make install OS={YOUR-PLATFORM}`

   1. Platforms:

   - Windows (dependencies included)
   - Linux (dependencies need to be downloaded apart)
   - MacOS (dependencies need to be downloaded apart)
   - BSD (dependencies need to be downloaded apart)

   2. If your system isn't availble, you can compile the program
      using your compilers CLI

4. copy the dynamic library to your lua project or to your lua path/cpath
5. require it and use :3

## Documentation and Examples

The entire documentation can be found in the docs directory.  
Examples of all functions can be found on the tst directory.

```lua
local cpx = require("complex")

local z = cpx.new(2,3)
local w = cpx.new(3,2)

print(cpx.to_string(z) .. " + " .. cpx.to_string(w) .. " = " .. cpx.to_string(cpx.add(z,w)))
-- > 2.0000000000 + 3.0000000000i + 3.0000000000 + 2.0000000000i = 5.0000000000 + 5.0000000000i

```
