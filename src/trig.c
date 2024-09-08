#include "inc/lauxlib.h"
#include "inc/lua.h"

#include "math.h"

#include "complex.h"
#include "trig.h"
#include <math.h>

int cpx_sin(lua_State *L) {
  Complex *z = check_complex(L, 1);

  create_complex_userdata(L, (sin(z->r) * cosh(z->i)),
                          (cos(z->r) * sinh(z->i)));

  return 1;
}
int cpx_cos(lua_State *L) {
  Complex *z = check_complex(L, 1);

  create_complex_userdata(L, (cos(z->r) * cosh(z->i)),
                          (-1 * sin(z->r) * sinh(z->i)));

  return 1;
}
int cpx_tan(lua_State *L) {
  Complex *z = check_complex(L, 1);

  double tg_a = tan(z->r);
  double tgh_b = tanh(z->i);

  create_complex_userdata(
      L, FRACTION(tg_a - (tg_a * SQUARE(tgh_b)), 1 + SQUARE(tg_a * tgh_b)),
      FRACTION(tgh_b + SQUARE(tg_a) * tgh_b, 1 + SQUARE(tg_a * tgh_b)));
  return 1;
}
int cpx_cot(lua_State *L) {
  Complex *z = check_complex(L, 1);

  double ct_a = INVERSE(tan(z->r));
  double cth_b = INVERSE(tanh(z->i));

  create_complex_userdata(
      L,
      FRACTION(((ct_a * SQUARE(cth_b)) - ct_a), (SQUARE(ct_a) + SQUARE(cth_b))),
      FRACTION(((-1 * SQUARE(ct_a) * cth_b) - cth_b),
               (SQUARE(ct_a) + SQUARE(cth_b))));

  return 1;
}

int cpx_sec(lua_State *L);
int cpx_csc(lua_State *L);

int cpx_asin(lua_State *L) {
  Complex *z = check_complex(L, 1);

  // 1 - z^2 = (1 - a^2 - b^2) + 2abi
  Complex temp = {1 - (SQUARE(z->r) - SQUARE(z->i)), -2 * z->r * z->i};
  // sqrt(1 - z^2)
  double mod = sqrt(sqrt(SQUARE(temp.r) + SQUARE(temp.i)));
  double arg = atan2(temp.i, temp.r) / 2;
  temp = (Complex){mod * cos(arg), mod * sin(arg)};

  // ln(zi + sqrt(1 - z^2))
  temp = (Complex){(-1 * z->i) + temp.r, z->r + temp.i};

  mod = sqrt(SQUARE(temp.r) + SQUARE(temp.i));
  arg = atan2(temp.i, temp.r);

  create_complex_userdata(L, -1 * (log(mod)), arg);
  return 1;
}
int cpx_acos(lua_State *L) {
  Complex *z = check_complex(L, 1);

  // 1 - z^2 = (1 - a^2 - b^2) + 2abi
  Complex temp = {1 - (SQUARE(z->r) - SQUARE(z->i)), -2 * z->r * z->i};
  // sqrt(1 - z^2)
  double mod = sqrt(sqrt(SQUARE(temp.r) + SQUARE(temp.i)));
  double arg = atan2(temp.i, temp.r) / 2;
  temp = (Complex){mod * cos(arg), mod * sin(arg)};

  // ln(z+i * sqrt(1 - z^2))
  temp = (Complex){z->r + (-1 * temp.i), z->i + temp.r};

  mod = sqrt(SQUARE(temp.r) + SQUARE(temp.i));
  arg = atan2(temp.i, temp.r);

  create_complex_userdata(L, arg, -1 * log(mod));
  return 1;
}
int cpx_atan(lua_State *L) {
  Complex *z = check_complex(L, 1);

  Complex temp = {1 - z->i, z->r};    // 1 + iz
  Complex temp_2 = {1 + z->i, -z->r}; // 1 - iz

  // (1 + iz)/(1 - iz)
  temp = (Complex){(temp.r * temp_2.r + temp.i * temp_2.i) /
                       (SQUARE(temp_2.r) + SQUARE(temp_2.i)),
                   (temp.i * temp_2.r - temp.r * temp_2.i) /
                       (SQUARE(temp_2.r) + SQUARE(temp_2.i))};

  // ln((1 + iz)/(1 - iz))
  double mod = sqrt(SQUARE(temp.r) + SQUARE(temp.i));
  double arg = atan2(temp.i, temp.r);

  create_complex_userdata(L, arg / 2.0, log(mod) / -2.0);
  return 1;
}
int cpx_acot(lua_State *L);
int cpx_asec(lua_State *L);
int cpx_acsc(lua_State *L);

int cpx_sinh(lua_State *L) {
  Complex *z = check_complex(L, 1);

  create_complex_userdata(L, sinh(z->r) * cos(z->i), cosh(z->r) * sin(z->i));

  return 1;
}
int cpx_cosh(lua_State *L) {
  Complex *z = check_complex(L, 1);

  create_complex_userdata(L, cosh(z->r) * cos(z->i), sinh(z->r) * sin(z->i));

  return 1;
}
int cpx_tanh(lua_State *L) {
  Complex *z = check_complex(L, 1);

  create_complex_userdata(
      L,
      FRACTION(
          ((sinh(z->r) * cosh(z->r) * SQUARE(cos(z->i))) +
           (sinh(z->r) * cosh(z->r) * SQUARE(sin(z->i)))),
          (SQUARE(cosh(z->r) * cos(z->i)) + SQUARE(sinh(z->r) * sin(z->i)))),
      FRACTION(
          ((SQUARE(cosh(z->r)) * sin(z->i) * cos(z->i)) -
           (SQUARE(sinh(z->r)) * sin(z->i) * cos(z->i))),
          (SQUARE(cosh(z->r) * cos(z->i)) + SQUARE(sinh(z->r) * sin(z->i)))));

  return 1;
}
int cpx_coth(lua_State *L);
int cpx_sech(lua_State *L);
int cpx_csch(lua_State *L);

int cpx_asinh(lua_State *L) {
  Complex *z = check_complex(L, 1);

  Complex temp = {(SQUARE(z->r) - SQUARE(z->i)) + 1, 2 * z->r * z->i};

  double mod = sqrt(sqrt(SQUARE(temp.r) + SQUARE(temp.i)));
  double arg = atan2(temp.i, temp.r) / 2;
  temp = (Complex){mod * cos(arg), mod * sin(arg)};

  temp = (Complex){z->r + temp.r, z->i + temp.i};

  mod = sqrt(SQUARE(temp.r) + SQUARE(temp.i));
  arg = atan2(temp.i, temp.r);

  create_complex_userdata(L, log(mod), arg);

  return 1;
}
int cpx_acosh(lua_State *L) {
  Complex *z = check_complex(L, 1);

  Complex temp = {(SQUARE(z->r) - SQUARE(z->i)) - 1, 2 * z->r * z->i};

  double mod = sqrt(sqrt(SQUARE(temp.r) + SQUARE(temp.i)));
  double arg = atan2(temp.i, temp.r) / 2;
  temp = (Complex){mod * cos(arg), mod * sin(arg)};

  temp = (Complex){z->r + temp.r, z->i + temp.i};

  mod = sqrt(SQUARE(temp.r) + SQUARE(temp.i));
  arg = atan2(temp.i, temp.r);

  create_complex_userdata(L, log(mod), arg);

  return 1;
}
int cpx_atanh(lua_State *L) {
  Complex *z = check_complex(L, 1);

  Complex temp = {1 + z->r, z->i}; // 1 + z

  Complex temp_2 = {1 - z->r, -z->i}; // 1 - z

  temp = (Complex){(temp.r * temp_2.r + temp.i * temp_2.i) /
                       (SQUARE(temp_2.r) + SQUARE(temp_2.i)),
                   (temp.i * temp_2.r - temp.r * temp_2.i) /
                       (SQUARE(temp_2.r) + SQUARE(temp_2.i))};

  double mod = sqrt(SQUARE(temp.r) + SQUARE(temp.i));
  double arg = atan2(temp.i, temp.r);

  create_complex_userdata(L, log(mod) / 2.0, arg / 2.0);

  return 1;
}
int cpx_acoth(lua_State *L);
int cpx_asech(lua_State *L);
int cpx_acsch(lua_State *L);
