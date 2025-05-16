#include <Arduino.h>
#include <LuaWrapper.h>

LuaWrapper lua;

void setup() {
  Serial.begin(115200);
  while(!Serial);
  Serial.println("Lua Interpreter Starting...");
  if (!lua.begin()) {
    Serial.println("Failed to start Lua");
    while (1);
  }

  const char* script = "print('Hello from Lua on RP2040!')";
  if (!lua.doString(script)) {
    Serial.println("Lua script failed");
  }
}

void loop() {
  // your code here
}
