#ifndef _CPX_TRIG_H
#define _CPX_TRIG_H

#include "inc/lua.h"

int cpx_sin(lua_State *L);
int cpx_cos(lua_State *L);
int cpx_tan(lua_State *L);
int cpx_cot(lua_State *L);
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

#endif /* _CPX_TRIG_H */
