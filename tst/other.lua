-- Other functions test
local cpx = require("complex")
local z = cpx.new(2, 3)
----------------------------------

print("z is " .. cpx.to_string(z))

print("z conjugate is " .. cpx.to_string(cpx.conj(z)))

print("z in polar is " .. tostring(cpx.mod(z)) .. "/_" .. tostring(cpx.arg(z)))

print("is z equals to it's conjugate ? : " .. tostring(cpx.equals(z, cpx.conj(z))))
