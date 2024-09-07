#include "inc/lauxlib.h"
#include "inc/lua.h"

#include "math.h"

#include "complex.h"
#include "trig.h"

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

int cpx_asin(lua_State *L);
int cpx_acos(lua_State *L);
int cpx_atan(lua_State *L);
int cpx_acot(lua_State *L);
int cpx_asec(lua_State *L);
int cpx_acsc(lua_State *L);

int cpx_sinh(lua_State *L);
int cpx_cosh(lua_State *L);
int cpx_tanh(lua_State *L);
int cpx_coth(lua_State *L);
int cpx_sech(lua_State *L);
int cpx_csch(lua_State *L);

int cpx_asinh(lua_State *L);
int cpx_acosh(lua_State *L);
int cpx_atanh(lua_State *L);
int cpx_acoth(lua_State *L);
int cpx_asech(lua_State *L);
int cpx_acsch(lua_State *L);
