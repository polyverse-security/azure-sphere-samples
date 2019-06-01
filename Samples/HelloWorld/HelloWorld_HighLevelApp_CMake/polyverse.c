#include <time.h>

#include <applibs/gpio.h>
#include <applibs/log.h>

#include <hw/sample_hardware.h>

enum HexLight {
	Hex0 = MT3620_RDB_LED1_RED,
	Hex1 = MT3620_RDB_LED1_GREEN,
	Hex2 = MT3620_RDB_LED1_BLUE,
	//Hex3 = MT3620_RDB_LED1_WHITE,
	Hex4 = MT3620_RDB_LED2_RED,
	Hex5 = MT3620_RDB_LED2_GREEN,
	Hex6 = MT3620_RDB_LED2_BLUE,
	//Hex7 = MT3620_RDB_LED2_WHITE,
	Hex8 = MT3620_RDB_LED3_RED,
	Hex9 = MT3620_RDB_LED3_GREEN,
	HexA = MT3620_RDB_LED3_BLUE,
	//HexB = MT3620_RDB_LED3_WHITE,
	HexC = MT3620_RDB_LED4_RED,
	HexD = MT3620_RDB_LED4_GREEN,
	HexE = MT3620_RDB_LED4_BLUE
	//HexF = MT3620_RDB_LED4_WHITE
};

int g_fd[16];

int init(void) {

	g_fd[0] = GPIO_OpenAsOutput(MT3620_RDB_LED1_RED, GPIO_OutputMode_PushPull, GPIO_Value_High);

	g_fd[1] = GPIO_OpenAsOutput(MT3620_RDB_LED1_GREEN, GPIO_OutputMode_PushPull, GPIO_Value_High);

	g_fd[2] = GPIO_OpenAsOutput(MT3620_RDB_LED1_BLUE, GPIO_OutputMode_PushPull, GPIO_Value_High);

	g_fd[3] = 0;

	g_fd[4] = GPIO_OpenAsOutput(MT3620_RDB_LED2_RED, GPIO_OutputMode_PushPull, GPIO_Value_High);

	g_fd[5] = GPIO_OpenAsOutput(MT3620_RDB_LED2_GREEN, GPIO_OutputMode_PushPull, GPIO_Value_High);

	g_fd[6] = GPIO_OpenAsOutput(MT3620_RDB_LED2_BLUE, GPIO_OutputMode_PushPull, GPIO_Value_High);

	g_fd[7] = 0;
	g_fd[8] = GPIO_OpenAsOutput(MT3620_RDB_LED3_RED, GPIO_OutputMode_PushPull, GPIO_Value_High);

	g_fd[9] = GPIO_OpenAsOutput(MT3620_RDB_LED3_GREEN, GPIO_OutputMode_PushPull, GPIO_Value_High);

	g_fd[10] = GPIO_OpenAsOutput(MT3620_RDB_LED3_BLUE, GPIO_OutputMode_PushPull, GPIO_Value_High);

	g_fd[11] = 0;

	g_fd[12] = GPIO_OpenAsOutput(MT3620_RDB_LED4_RED, GPIO_OutputMode_PushPull, GPIO_Value_High);

	g_fd[13] = GPIO_OpenAsOutput(MT3620_RDB_LED4_GREEN, GPIO_OutputMode_PushPull, GPIO_Value_High);

	// LED4_BLUE
	g_fd[14] = GPIO_OpenAsOutput(MT3620_GPIO23, GPIO_OutputMode_PushPull, GPIO_Value_High);
	g_fd[15] = 0;

	return 0;
}

void show(int val) {
	const struct timespec sleepTime = { 1, 0 };

	//Log_Debug("val: %i, g_gpio_ids[%i]: %i\n", val, val, g_gpio_ids[val]);

	if (g_fd[val] == 0) {
		//Log_Debug("This is white and need to turn on %i, %i and %i.\n", g_gpio_ids[val - 1], g_gpio_ids[val - 2], g_gpio_ids[val - 3]);
		GPIO_SetValue(g_fd[val - 1], GPIO_Value_Low);
		GPIO_SetValue(g_fd[val - 2], GPIO_Value_Low);
		GPIO_SetValue(g_fd[val - 3], GPIO_Value_Low);
		nanosleep(&sleepTime, NULL);
		GPIO_SetValue(g_fd[val - 1], GPIO_Value_High);
		GPIO_SetValue(g_fd[val - 2], GPIO_Value_High);
		GPIO_SetValue(g_fd[val - 3], GPIO_Value_High);
		nanosleep(&sleepTime, NULL);
	}
	else
	{
		//Log_Debug("Just turn on %i.\n", g_gpio_ids[val]);
		GPIO_SetValue(g_fd[val], GPIO_Value_Low);
		nanosleep(&sleepTime, NULL);
		GPIO_SetValue(g_fd[val], GPIO_Value_High);
		nanosleep(&sleepTime, NULL);
	}
}

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