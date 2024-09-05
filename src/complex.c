#include "inc/lauxlib.h"
#include "inc/lua.h"

#include <math.h>

#define SQUARE(_x) ((_x) * (_x))

// Rectangular number struct

typedef struct cpxr_t {
  double r;
  double i;
} Rectangular;
typedef struct cpxp_t {
  double mod;
  double phase;
} Polar;

// Internal functions

Rectangular *create_complex_userdata(lua_State *L, double r, double i) {
  Rectangular *cpx = (Rectangular *)lua_newuserdata(L, sizeof(Rectangular));
  cpx->r = r;
  cpx->i = i;
  luaL_setmetatable(L, "Rectangular");

  return cpx;
}

// lib functions

// number functions

int cpx_new(lua_State *L) {
  create_complex_userdata(L, luaL_checknumber(L, 1), luaL_checknumber(L, 2));
  return 1;
}
int cpx_real(lua_State *L) {
  lua_pushnumber(L, ((Rectangular *)luaL_checkudata(L, 1, "Rectangular"))->r);
  return 1;
}
int cpx_imag(lua_State *L) {
  lua_pushnumber(L, ((Rectangular *)luaL_checkudata(L, 1, "Rectangular"))->i);
  return 1;
}

// Simple arithmetic functions

int cpx_add(lua_State *L) {
  Rectangular *z = (Rectangular *)luaL_checkudata(L, 1, "Rectangular");
  Rectangular *w = (Rectangular *)luaL_checkudata(L, 2, "Rectangular");

  create_complex_userdata(L, (z->r + w->r), (z->i + w->i));

  return 1;
}

int cpx_sub(lua_State *L) {
  Rectangular *z = (Rectangular *)luaL_checkudata(L, 1, "Rectangular");
  Rectangular *w = (Rectangular *)luaL_checkudata(L, 2, "Rectangular");

  create_complex_userdata(L, (z->r - w->r), (z->i - w->i));

  return 1;
}
int cpx_mlt(lua_State *L) {
  Rectangular *z = (Rectangular *)luaL_checkudata(L, 1, "Rectangular");
  Rectangular *w = (Rectangular *)luaL_checkudata(L, 2, "Rectangular");

  create_complex_userdata(L, ((z->r * w->r) - (z->i * w->i)),
                          (z->r * w->i) + (z->i * w->r));

  return 1;
}
int cpx_div(lua_State *L) {
  Rectangular *z = (Rectangular *)luaL_checkudata(L, 1, "Rectangular");
  Rectangular *w = (Rectangular *)luaL_checkudata(L, 2, "Rectangular");

  double _r = (((z->r * w->r) + (z->i * w->i)) / (SQUARE(w->r) + SQUARE(w->i)));
  double _i = (((z->i * w->r) - (z->r * w->i)) / (SQUARE(w->r) + SQUARE(w->i)));

  create_complex_userdata(L, _r, _i);

  return 1;
}

int cpx_pow(lua_State *L) {
  Rectangular *z = (Rectangular *)luaL_checkudata(L, 1, "Rectangular");
  double n = luaL_checknumber(L, 2);

  double t = (atan2(z->i, z->r));
  double m = (sqrt(SQUARE(z->r) + SQUARE(z->i)));

  create_complex_userdata(L, (pow(m, n) * cos(n * t)),
                          (pow(m, n) * sin(n * t)));

  return 1;
}
int cpx_root(lua_State *L);
int cpx_log(lua_State *L);
int cpx_log10(lua_State *L);

// trigonometic functions

int cpx_sin(lua_State *L) {
  Rectangular *z = (Rectangular *)luaL_checkudata(L, 1, "Rectangular");

  create_complex_userdata(L, (sin(z->r) * cosh(z->i)),
                          (cos(z->r) * sinh(z->i)));

  return 1;
}
int cpx_cos(lua_State *L) {
  Rectangular *z = (Rectangular *)luaL_checkudata(L, 1, "Rectangular");

  create_complex_userdata(L, (cos(z->r) * cosh(z->i)),
                          (-1 * sin(z->r) * sinh(z->i)));

  return 1;
}

int luaopen_complex(lua_State *L) {
  const luaL_Reg complex_funcs[] = {
      {"new", cpx_new}, {"Re", cpx_real},  {"Im", cpx_imag}, {"add", cpx_add},
      {"sub", cpx_sub}, {"mult", cpx_mlt}, {"div", cpx_div}, {"pow", cpx_pow},
      {"sin", cpx_sin}, {"cos", cpx_cos},  {NULL, NULL}};

  luaL_newmetatable(L, "Rectangular");

  luaL_newlib(L, complex_funcs);

  return 1;
}
