// lua headers
#include "inc/lauxlib.h"
#include "inc/lua.h"
// other headers
#include <math.h>
#include <stdlib.h>
#include <string.h>

// project headers
#include "arith.h"
#include "complex.h"
#include "other.h"
#include "trig.h"

Complex *create_complex_userdata(lua_State *L, double r, double i) {
  Complex *cpx = (Complex *)lua_newuserdata(L, sizeof(Complex));
  cpx->r = r;
  cpx->i = i;
  luaL_setmetatable(L, "Complex");

  return cpx;
}
Complex *check_complex(lua_State *L, int ud) {
  return (Complex *)luaL_checkudata(L, ud, "Complex");
}

int cpx_new(lua_State *L);
int cpx_real(lua_State *L);
int cpx_imag(lua_State *L);

int luaopen_complex(lua_State *L) {
  const luaL_Reg complex_funcs[] = {{"new", cpx_new},
                                    {"Re", cpx_real},
                                    {"Im", cpx_imag},
                                    {"add", cpx_add},
                                    {"sub", cpx_sub},
                                    {"mult", cpx_mlt},
                                    {"div", cpx_div},
                                    {"pow", cpx_pow},
                                    {"root", cpx_root},
                                    {"exp", cpx_exp},
                                    {"log", cpx_log},
                                    {"sin", cpx_sin},
                                    {"cos", cpx_cos},
                                    {"tan", cpx_tan},
                                    //{"cot", cpx_cot},
                                    //{"sec",cpx_sec},
                                    //{"csc",cpx_csc},
                                    {"asin", cpx_asin},
                                    {"acos", cpx_acos},
                                    {"atan", cpx_atan},
                                    //{"acot", cpx_acot},
                                    //{"asec",cpx_asec},
                                    //{"acsc",cpx_acsc},
                                    {"sinh", cpx_sinh},
                                    {"cosh", cpx_cosh},
                                    {"tanh", cpx_tanh},
                                    //{"coth", cpx_coth},
                                    //{"sech",cpx_sech},
                                    //{"csch",cpx_csch},
                                    {"asinh", cpx_asinh},
                                    {"acosh", cpx_acosh},
                                    {"atanh", cpx_atanh},
                                    //{"acoth", cpx_acoth},
                                    //{"asech",cpx_asech},
                                    //{"acsch",cpx_acsch},
                                    {"mod", cpx_mod},
                                    {"arg", cpx_arg},
                                    {"conj", cpx_conj},
                                    {"equals", cpx_equals},
                                    {"to_string", cpx_to_string},
                                    {NULL, NULL}};

  luaL_newmetatable(L, "Complex");

  luaL_newlib(L, complex_funcs);

  return 1;
}

int cpx_new(lua_State *L) {
  create_complex_userdata(L, luaL_checknumber(L, 1), luaL_checknumber(L, 2));
  return 1;
}
int cpx_real(lua_State *L) {
  lua_pushnumber(L, ((Complex *)check_complex(L, 1))->r);
  return 1;
}
int cpx_imag(lua_State *L) {
  lua_pushnumber(L, ((Complex *)check_complex(L, 1))->i);
  return 1;
}
