-- Test of basic arithmetic functions
local cpx = require("complex")
local z = cpx.new(2, 3)
local w = cpx.new(3, 2)
local c
-- basic four

c = cpx.add(z, w)
print(cpx.to_string(z) .. " + " .. cpx.to_string(w) .. " = " .. cpx.to_string(c))

c = cpx.sub(z, w)
print(cpx.to_string(z) .. " - " .. cpx.to_string(w) .. " = " .. cpx.to_string(c))

c = cpx.mult(z, w)
print(cpx.to_string(z) .. " * " .. cpx.to_string(w) .. " = " .. cpx.to_string(c))

c = cpx.div(z, w)
print(cpx.to_string(z) .. " / " .. cpx.to_string(w) .. " = " .. cpx.to_string(c))

-- powers 'n logs

c = cpx.pow(z, 4)
print(cpx.to_string(z) .. " ^ 4 = " .. cpx.to_string(c))

local oldc = c
c = cpx.root(oldc, 4)
print("4./ " .. cpx.to_string(oldc) .. " = " .. cpx.to_string(c))

c = cpx.exp(z)
print("e ^ " .. cpx.to_string(z) .. " = " .. cpx.to_string(c))

c = cpx.log(z)
print("ln(" .. cpx.to_string(z) .. ") = " .. cpx.to_string(c))
