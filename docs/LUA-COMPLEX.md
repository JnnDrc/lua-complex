# Lua-complex library documentation

## Table of contents

### Functions

- [new](#new)
- [Re](#Re)
- [Im](#Im)

## Functions

### new(r,i)

#### Synopsis

Creates a new complex number

#### Parameters

r : number, the real part
i : number, the imaginary part

#### Example

```lua
local cpx = require("complex")

local z = cpx.new(2,3)

print("z is " .. cpx.to_string(z))

```

### Re(z)

#### Synopsis

Gets the real part of a complex number

#### Parameters

z : complex, the complex number

#### Example

```lua
local cpx = require("complex")

local z = cpx.new(2,3)

print("z's real part is " .. cpx.Re(z))

```

### Im(z)

#### SYNOPISI

Gets the imaginary part of a complex number

#### Parameters

z : complex, the complex number

#### Example

```lua
local cpx = require("complex")

local z = cpx.new(2,3)

print("z's imaginary part is " .. cpx.Im(z))

```
