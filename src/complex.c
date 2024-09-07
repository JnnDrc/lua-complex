#include "inc/lauxlib.h"
#include "inc/lua.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SQUARE(_x) ((_x) * (_x))
#define INVERSE(_x) ((1) / (_x))
#define FRACTION(_x, _y) ((_x) / (_y))

// Complex number struct

typedef struct cpxr_t {
  double r;
  double i;
} Complex;

// Internal functions

Complex *create_complex_userdata(lua_State *L, double r, double i) {
  Complex *cpx = (Complex *)lua_newuserdata(L, sizeof(Complex));
  cpx->r = r;
  cpx->i = i;
  luaL_setmetatable(L, "Complex");

  return cpx;
}

// lib functions

// number functions

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

// Simple arithmetic functions

int cpx_add(lua_State *L) {
  Complex *z = (Complex *)luaL_checkudata(L, 1, "Complex");
  Complex *w = (Complex *)luaL_checkudata(L, 2, "Complex");

  create_complex_userdata(L, (z->r + w->r), (z->i + w->i));

  return 1;
}

int cpx_sub(lua_State *L) {
  Complex *z = (Complex *)luaL_checkudata(L, 1, "Complex");
  Complex *w = (Complex *)luaL_checkudata(L, 2, "Complex");

  create_complex_userdata(L, (z->r - w->r), (z->i - w->i));

  return 1;
}
int cpx_mlt(lua_State *L) {
  Complex *z = (Complex *)luaL_checkudata(L, 1, "Complex");
  Complex *w = (Complex *)luaL_checkudata(L, 2, "Complex");

  create_complex_userdata(L, ((z->r * w->r) - (z->i * w->i)),
                          (z->r * w->i) + (z->i * w->r));

  return 1;
}
int cpx_div(lua_State *L) {
  Complex *z = (Complex *)luaL_checkudata(L, 1, "Complex");
  Complex *w = (Complex *)luaL_checkudata(L, 2, "Complex");

  create_complex_userdata(
      L, (((z->r * w->r) + (z->i * w->i)) / (SQUARE(w->r) + SQUARE(w->i))),
      (((z->i * w->r) - (z->r * w->i)) / (SQUARE(w->r) + SQUARE(w->i))));

  return 1;
}

int cpx_pow(lua_State *L) {
  Complex *z = (Complex *)luaL_checkudata(L, 1, "Complex");
  double n = luaL_checknumber(L, 2);

  double t = (atan2(z->i, z->r));
  double m = (sqrt(SQUARE(z->r) + SQUARE(z->i)));

  create_complex_userdata(L, (pow(m, n) * cos(n * t)),
                          (pow(m, n) * sin(n * t)));

  return 1;
}
int cpx_root(lua_State *L) {
  Complex *z = (Complex *)luaL_checkudata(L, 1, "Complex");
  double n = luaL_checknumber(L, 2);

  double t = (atan2(z->i, z->r));
  double m = (sqrt(SQUARE(z->r) + SQUARE(z->i)));

  create_complex_userdata(L, (pow(m, 1 / n) * cos(t / n)),
                          (pow(m, 1 / n) * sin(t / n)));

  return 1;
}
int cpx_log(lua_State *L);
int cpx_log10(lua_State *L);

// trigonometic functions

int cpx_sin(lua_State *L) {
  Complex *z = (Complex *)luaL_checkudata(L, 1, "Complex");

  create_complex_userdata(L, (sin(z->r) * cosh(z->i)),
                          (cos(z->r) * sinh(z->i)));

  return 1;
}
int cpx_cos(lua_State *L) {
  Complex *z = (Complex *)luaL_checkudata(L, 1, "Complex");

  create_complex_userdata(L, (cos(z->r) * cosh(z->i)),
                          (-1 * sin(z->r) * sinh(z->i)));

  return 1;
}
int cpx_tan(lua_State *L) {
  Complex *z = (Complex *)luaL_checkudata(L, 1, "Complex");

  double tg_a = tan(z->r);
  double tgh_b = tanh(z->i);

  create_complex_userdata(
      L, FRACTION(tg_a - (tg_a * SQUARE(tgh_b)), 1 + SQUARE(tg_a * tgh_b)),
      FRACTION(tgh_b + SQUARE(tg_a) * tgh_b, 1 + SQUARE(tg_a * tgh_b)));
  return 1;
}
int cpx_cot(lua_State *L) {
  Complex *z = (Complex *)luaL_checkudata(L, 1, "Complex");

  double ct_a = INVERSE(tan(z->r));
  double cth_b = INVERSE(tanh(z->i));

  create_complex_userdata(
      L,
      FRACTION(((ct_a * SQUARE(cth_b)) - ct_a), (SQUARE(ct_a) + SQUARE(cth_b))),
      FRACTION(((-1 * SQUARE(ct_a) * cth_b) - cth_b),
               (SQUARE(ct_a) + SQUARE(cth_b))));

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
