#include <applibs/log.h>

void say(char *words)
{
	Log_Debug("%s\n", words);
}

void chat(int argc, char *argv[])
{
	int arg;
	for (arg = 0; arg < argc; arg++)
		say(argv[arg]);
}

void foo1(void) {
	for (int arg = 1; arg < 10; arg++) {
	}
	return;
}

void foo2(void) {
	for (int arg = 1; arg < 10; arg++) {
	}
	return;
}

void foo3(void) {
	for (int arg = 1; arg < 10; arg++) {
	}
	return;
}