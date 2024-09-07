#include "inc/lauxlib.h"
#include "inc/lua.h"

#include <math.h>

#include "complex.h"

int cpx_add(lua_State *L) {
  Complex *z = check_complex(L, 1);
  Complex *w = check_complex(L, 2);

  create_complex_userdata(L, (z->r + w->r), (z->i + w->i));

  return 1;
}

int cpx_sub(lua_State *L) {
  Complex *z = check_complex(L, 1);
  Complex *w = check_complex(L, 2);

  create_complex_userdata(L, (z->r - w->r), (z->i - w->i));

  return 1;
}
int cpx_mlt(lua_State *L) {
  Complex *z = check_complex(L, 1);
  Complex *w = check_complex(L, 2);

  create_complex_userdata(L, ((z->r * w->r) - (z->i * w->i)),
                          (z->r * w->i) + (z->i * w->r));

  return 1;
}
int cpx_div(lua_State *L) {
  Complex *z = check_complex(L, 1);
  Complex *w = check_complex(L, 2);

  create_complex_userdata(
      L, (((z->r * w->r) + (z->i * w->i)) / (SQUARE(w->r) + SQUARE(w->i))),
      (((z->i * w->r) - (z->r * w->i)) / (SQUARE(w->r) + SQUARE(w->i))));

  return 1;
}

int cpx_pow(lua_State *L) {
  Complex *z = check_complex(L, 1);
  double n = luaL_checknumber(L, 2);

  double t = (atan2(z->i, z->r));
  double m = (sqrt(SQUARE(z->r) + SQUARE(z->i)));

  create_complex_userdata(L, (pow(m, n) * cos(n * t)),
                          (pow(m, n) * sin(n * t)));

  return 1;
}
int cpx_root(lua_State *L) {
  Complex *z = check_complex(L, 1);
  double n = luaL_checknumber(L, 2);

  double t = (atan2(z->i, z->r));
  double m = (sqrt(SQUARE(z->r) + SQUARE(z->i)));

  create_complex_userdata(L, (pow(m, 1 / n) * cos(t / n)),
                          (pow(m, 1 / n) * sin(t / n)));

  return 1;
}

int cpx_exp(lua_State *L);
int cpx_log(lua_State *L);
