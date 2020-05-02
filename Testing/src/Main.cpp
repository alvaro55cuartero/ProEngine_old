#include <iostream>
#include <string.h>
#include <vector>
#include "Tree.h"
#include "List.h"
#include "Main.h"

#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

int exitPro = 1;
const int commandLength = 100;
const int cmdCount = 9;
const char* cmd[cmdCount] = { "exit", "help", "add", "view", "in", "out", "create", "rem", "tool"};

Tree obj("root");
List type;
const char* tools[1] = {""};

/*int main(void) {
	init();
	loop();
	return 0;
}*/

void init() {
	//primitive.
	const char* a = "int";
	type.addObj(a);
	
}

void loop() {
	char command[commandLength];

	printf("EnginePro!\n");
	while (exitPro) {
		printf(">");
		fgets(command, commandLength - 1, stdin);
		command[strlen(command) - 1] = '\0';
		commandExec(command);
		command[0] = '\0';
	}
}

void commandExec(char command[]) {
	const char* nextToken = 0;
	const char* token = 0;
	token = strtok_s(command, " ", (char**) &nextToken);
	
	if (strcmp(token, cmd[0]) == 0) {
		exitPro = 0;
	} else if (strcmp(token, cmd[1]) == 0) {
		cmdHelp();
	} else if (strcmp(token, cmd[2]) == 0) {
		cmdAdd(nextToken);
	} else if (strcmp(token, cmd[3]) == 0) {
		cmdView(nextToken);
	} else if (strcmp(token, cmd[4]) == 0) {
		cmdIn(nextToken);
	} else if (strcmp(token, cmd[5]) == 0) {
		cmdOut();
	} else if (strcmp(token, cmd[6]) == 0) {
		cmdCreate(nextToken);
	} else if (strcmp(token, cmd[7]) == 0) {
		cmdRem(nextToken);
	} else {
		printf("Este commando: %s | no exite\n", command);
	}
}

void cmdHelp() {
	for (int i = 0; i < NELEMS(cmd); i++) {
		printf("%s\n", cmd[i]);
	}
}

void cmdAdd(const char* &token) {
	char** temp =(char**) &token;
	const char* nextToken = strtok_s(NULL, " ", temp);
	obj.addBranch(nextToken);
}

void cmdRem(const char* &token) {
	const char* nextToken = strtok_s(NULL, " ", (char**) &token);
	obj.remBranch(nextToken);
}

void cmdView(const char* &string) {
	if (strcmp(string, "obj") == 0) {
		obj.view(0, 0, false);
	} else if (strcmp(string, "type") == 0) {
		type.view();
	}
}

void cmdIn(const char* &string) {
	obj.moveIn(string);
}

void cmdOut() {
	obj.moveOut();
}

void cmdCreate(const char* &string) {
	type.addObj(string);
}
