// Global functions and macros
#ifndef _CPX_H
#define _CPX_H

#include "inc/lua.h"

typedef struct cpxr_t {
  double r;
  double i;
} Complex;

Complex *create_complex_userdata(lua_State *L, double r, double i);
Complex *check_complex(lua_State *L, int ud);

#define SQUARE(_x) ((_x) * (_x))
#define INVERSE(_x) ((1) / (_x))
#define FRACTION(_x, _y) ((_x) / (_y))
#define MOD(_r, _i) (sqrt(SQUARE((_r)) + SQUARE(_i)))
#define ARG(_r, _i) (atan2((_i), (_r)))

#define TAU 6.283185307179586
#define PI 3.141592653589793
#define PI_2 1.570796326794896
#define E 2.718281828459045

#endif /* _CPX_H */
