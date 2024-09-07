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

int cpx_equals(lua_State *L);
int cpx_to_string(lua_State *L);

int cpx_conj(lua_State *L);
int cpx_mod(lua_State *L);
int cpx_phase(lua_State *L);

int luaopen_complex(lua_State *L) {
  const luaL_Reg complex_funcs[] = {
      {"new", cpx_new},   {"Re", cpx_real},       {"Im", cpx_imag},
      {"add", cpx_add},   {"sub", cpx_sub},       {"mult", cpx_mlt},
      {"div", cpx_div},   {"pow", cpx_pow},       {"root", cpx_root},
      {"sin", cpx_sin},   {"cos", cpx_cos},       {"tan", cpx_tan},
      {"cot", cpx_cot},   {"mod", cpx_mod},       {"phase", cpx_phase},
      {"conj", cpx_conj}, {"equals", cpx_equals}, {"to_string", cpx_to_string},
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
  lua_pushnumber(L, ((Complex *)luaL_checkudata(L, 1, "Complex"))->r);
  return 1;
}
int cpx_imag(lua_State *L) {
  lua_pushnumber(L, ((Complex *)luaL_checkudata(L, 1, "Complex"))->i);
  return 1;
}

int cpx_equals(lua_State *L) {
  Complex *z = (Complex *)luaL_checkudata(L, 1, "Complex");
  Complex *w = (Complex *)luaL_checkudata(L, 2, "Complex");

  lua_pushboolean(L, ((z->r == w->r) && (z->i == w->i)));

  return 1;
}
int cpx_to_string(lua_State *L) {
  Complex *z = (Complex *)luaL_checkudata(L, 1, "Complex");

  char *buf = malloc(512);
  if (z->i >= 0) {
    snprintf(buf, 512, "%.10lf + %.10lfi", z->r, z->i);
  } else {
    snprintf(buf, 512, "%.10lf - %.10lfi", z->r, -1 * z->i);
  }
  buf = realloc(buf, strlen(buf));
  lua_pushstring(L, buf);
  free(buf);
  return 1;
}

int cpx_conj(lua_State *L) {
  Complex *z = (Complex *)luaL_checkudata(L, 1, "Complex");

  create_complex_userdata(L, z->r, -1 * z->i);

  return 1;
}
int cpx_mod(lua_State *L) {
  Complex *z = (Complex *)luaL_checkudata(L, 1, "Complex");

  lua_pushnumber(L, sqrt((SQUARE(z->r) + SQUARE(z->i))));

  return 1;
}
int cpx_phase(lua_State *L) {
  Complex *z = (Complex *)luaL_checkudata(L, 1, "Complex");

  lua_pushnumber(L, atan2(z->i, z->r));

  return 1;
}
