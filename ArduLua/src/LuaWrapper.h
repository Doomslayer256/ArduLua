#ifndef LUAWRAPPER_H
#define LUAWRAPPER_H

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

class LuaWrapper {
public:
    LuaWrapper();
    ~LuaWrapper();

    void begin();
    void run(const char* code);

    // Easy way to expose C functions to Lua by name
    void expose(const char* name, lua_CFunction func);

private:
    lua_State* lua;
};

#endif // LUAWRAPPER_H
