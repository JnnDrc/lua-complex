// Global functions and macros

#include "inc/lauxlib.h"
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
