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
