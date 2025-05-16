#include "LuaWrapper.h"
#include <Arduino.h>

LuaWrapper::LuaWrapper() : lua(nullptr) {}

LuaWrapper::~LuaWrapper() {
    if (lua) {
        lua_close(lua);
    }
}

void LuaWrapper::begin() {
    lua = luaL_newstate();
    luaL_openlibs(lua);
}

void LuaWrapper::run(const char* code) {
    if (!lua) return;

    int result = luaL_dostring(lua, code);
    if (result != LUA_OK) {
        const char* err = lua_tostring(lua, -1);
        Serial.print("Lua error: ");
        Serial.println(err);
        lua_pop(lua, 1);
    }
}

void LuaWrapper::expose(const char* name, lua_CFunction func) {
    if (!lua) return;

    lua_register(lua, name, func);
}
