#pragma once

void init();
void loop();
void commandExec(char command[]);
void cmdHelp();
void cmdAdd(const char*& string);
void cmdRem(const char*& name);
void cmdView(const char*& string);
void cmdIn(const char*& string);
void cmdOut();
void cmdCreate(const char*& string);