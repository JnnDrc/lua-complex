#include "inc/lua.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "complex.h"

int cpx_conj(lua_State *L) {
  Complex *z = (Complex *)check_complex(L, 1);

  create_complex_userdata(L, z->r, -1 * z->i);

  return 1;
}
int cpx_mod(lua_State *L) {
  Complex *z = (Complex *)check_complex(L, 1);

  lua_pushnumber(L, sqrt((SQUARE(z->r) + SQUARE(z->i))));

  return 1;
}
int cpx_arg(lua_State *L) {
  Complex *z = (Complex *)check_complex(L, 1);

  lua_pushnumber(L, atan2(z->i, z->r));

  return 1;
}
//-------------------------------------------------------------
int cpx_equals(lua_State *L) {
  Complex *z = (Complex *)check_complex(L, 1);
  Complex *w = (Complex *)check_complex(L, 2);

  lua_pushboolean(L, ((z->r == w->r) && (z->i == w->i)));

  return 1;
}
int cpx_to_string(lua_State *L) {
  Complex *z = (Complex *)check_complex(L, 1);

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
