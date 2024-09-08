# Lua-complex library documentation

## Table of contents

### Pattern

all documentation follows this pattern

### Thing(arg1,arg2...)

[back to table of contents](#table-of-contents)

#### Synopsis

thing description

#### Parameters

- list
- of
- arguments

#### Example

```lua
local cpx = require("complex")

local t = cpx.thing(a,b)

-- doing things to thing...

```

### Functions

- [new](#newri)
- [Re](#Rez)
- [Im](#Imz)

## Functions

### new(r,i)

[back to table of contents](#table-of-contents)

#### Synopsis

Creates a new complex number

#### Parameters

- r : number, the real part
- i : number, the imaginary part

#### Example

```lua
local cpx = require("complex")

local z = cpx.new(2,3)

print("z is " .. cpx.to_string(z))

```

### Re(z)

[back to table of contents](#table-of-contents)

#### Synopsis

Gets the real part of a complex number

#### Parameters

- z : complex, the complex number

#### Example

```lua
local cpx = require("complex")

local z = cpx.new(2,3)

print("z's real part is " .. cpx.Re(z))

```

### Im(z)

[back to table of contents](#table-of-contents)

#### Synopsis

Gets the imaginary part of a complex number

#### Parameters

- z : complex, the complex number

#### Example

```lua
local cpx = require("complex")

local z = cpx.new(2,3)

print("z's imaginary part is " .. cpx.Im(z))

```

### conj(z)

#### Synopsis

Returns the conjugate of z

#### Parameters

- z : complex, the complex number

#### Example

```lua
local cpx = require("complex")

local z = cpx.new(2,3)

local cj = cpx.conj(z)

print(cpx.to_string(cj))

```
