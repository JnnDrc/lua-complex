# Lua-complex library documentation

!THIS IS NOT DONE YET!

## Table of contents

### Types

- [complex](#complex)

### Functions

#### Common

- [new](#newri)
- [Re](#Rez)
- [Im](#Imz)
- [conj](#conjz)
- [mod](#modz)
- [arg](#argz)
- [equals](#equalszw)
- [to_string](<#to_string(z)>)

#### Math

##### Arithmetic

- [add](#addzw)
- [sub](#subzw)
- [mult](#multzw)
- [div](#divzw)
- [pow](#powzn)
- [root](#rootzn)
- [exp](#expz)
- [log](#logz)

##### Trigonometrics

###### Normal

- [sin](#sinz)
- [cos](#cosz)
- [tan](#tanz)
- [asin](#asinz)
- [acos](#acosz)
- [atan](#atanz)

###### Hyperbolic

- [sinh](#sinhz)
- [cosh](#coshz)
- [tanh](#tanhz)
- [asinh](#asinhz)
- [acosh](#acoshz)
- [atanh](#atanhz)

## Types

### complex

[back to table of contents](#table-of-contents)

#### Synopsis

Complex number

#### Fields

- r : number, the real part
- i : number, the imaginary part

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

### mod(z)

#### Synopsis

Returns the modulus of z

#### Parameters

- z : complex, the complex number

#### Example

```lua
local cpx = require("complex")

local z = cpx.new(2,3)

local mod = cpx.mod(z)

print("z modulus is " .. cpx.to_string(cj))

```

### arg(z)

#### Synopsis

Returns the argument(phase,angle) of z

#### Parameters

- z : complex, the complex number

#### Example

```lua
local cpx = require("complex")

local z = cpx.new(2,3)

local arg = cpx.arg(z)

print("z argument is "..tostring(arg))

```

### equals(z,w)

#### Synopsis

Compare two complex numbers, return true if they a equals, zero if not

#### Parameters

- z : complex, a complex number
- w : complex, another complex number

#### Example

```lua
local cpx = require("complex")

local z = cpx.new(2,3)
local w = cpx.new(24,69)

print("is z == w ?: " .. tostring(cpx.equals(z,w)))

```

### to_string(z)

#### Synopsis

Returns a string representing the complex number z

#### Parameters

- z : complex, the complex number

#### Example

```lua
local cpx = require("complex")

local z = cpx.new(2,3)

print(cpx.to_string(cj))

```
