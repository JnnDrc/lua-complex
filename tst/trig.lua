-- Test of trigonometric funtions
local cpx = require("complex")
local z = cpx.new(2, 3)
local c
-- common
c = cpx.sin(z)
print("sin(z) = " .. cpx.to_string(c))

c = cpx.cos(z)
print("cos(z) = " .. cpx.to_string(c))

c = cpx.tan(z)
print("tan(z) = " .. cpx.to_string(c))

-- c = cpx.cot(z)
-- print("cot(z) = " .. cpx.to_string(c))

c = cpx.asin(z)
print("asin(z) = " .. cpx.to_string(c))

c = cpx.acos(z)
print("acos(z) = " .. cpx.to_string(c))

c = cpx.atan(z)
print("atan(z) = " .. cpx.to_string(c))
-- hyperbolic

c = cpx.sinh(z)
print("sinh(z) = " .. cpx.to_string(c))

c = cpx.cosh(z)
print("cosh(z) = " .. cpx.to_string(c))

c = cpx.tanh(z)
print("tanh(z) = " .. cpx.to_string(c))

c = cpx.asinh(z)
print("asinh(z) = " .. cpx.to_string(c))

c = cpx.acosh(z)
print("acosh(z) = " .. cpx.to_string(c))

c = cpx.atanh(z)
print("atanh(z) = " .. cpx.to_string(c))
