local cpx = require("complex")

local z = cpx.new(2, 3)
local w = cpx.new(3, 2)

-- simple arithmetic

local r = cpx.add(z, w)

print("Simple arithmetic: ")
print("z + w = " .. cpx.Re(r) .. " + " .. cpx.Im(r) .. "i")
r = cpx.sub(z, w)
print("z - w = " .. cpx.Re(r) .. " + " .. cpx.Im(r) .. "i")
r = cpx.mult(z, w)
print("z * w = " .. cpx.Re(r) .. " + " .. cpx.Im(r) .. "i")
r = cpx.div(z, w)
print("z / w = " .. cpx.Re(r) .. " + " .. cpx.Im(r) .. "i")
r = cpx.pow(z, 3)
print("z ^ 3 = " .. cpx.Re(r) .. " + " .. cpx.Im(r) .. "i")

--trigonometric
local t = cpx.sin(z)

print("Trigonometric: ")
print("sin(z) = " .. cpx.Re(t) .. " + " .. cpx.Im(t) .. "i")
t = cpx.cos(z)
print("cos(z) = " .. cpx.Re(t) .. " + " .. cpx.Im(t) .. "i")

-- other

local o = cpx.equals(z, w)

print("is " .. cpx.to_string(z) .. " equals to " .. cpx.to_string(w) .. " ? : " .. tostring(o))
