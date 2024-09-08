#ifndef _CPX_OTHER_H
#define _CPX_OTHER_H

#include "inc/lua.h"

int cpx_conj(lua_State *L);
int cpx_mod(lua_State *L);
int cpx_arg(lua_State *L);

int cpx_equals(lua_State *L);
int cpx_to_string(lua_State *L);

#endif /* _CPX_OTHER_H */
