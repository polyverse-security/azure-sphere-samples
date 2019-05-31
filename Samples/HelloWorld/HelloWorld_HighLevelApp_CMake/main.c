/* Copyright (c) Microsoft Corporation. All rights reserved.
   Licensed under the MIT License. */

// This minimal Azure Sphere app repeatedly toggles GPIO 8, which is the red channel of RGB
// LED 1 on the MT3620 RDB. Use this app to test that device and SDK installation succeeded
// that you can build, deploy, and debug a CMake app with Visual Studio.
//
// It uses the API for the following Azure Sphere application libraries:
// - gpio (digital input for button)
// - log (messages shown in Visual Studio's Device Output window during debugging)

#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#include <applibs/log.h>
#include <applibs/gpio.h>

// By default, this sample is targeted at the MT3620 Reference Development Board (RDB).
// This can be changed using the CMakeSettings.json property "Target Hardware Definition Directory".
// This #include imports the sample_hardware abstraction from that hardware definition.
#include <hw/sample_hardware.h>

#include "polyverse.h"

int main(void)
{
    Log_Debug("Starting CMake Hello World application...\n");

//	say((char *) "Hello world!");
	//char s[256];
	//char t[256];

	Log_Debug("s: %p", (void *)&foo1);
	Log_Debug("t: %p", (void *)&foo2);
	//char * argv[] = { s, t, "hey ho" };
	//chat(sizeof(argv)/sizeof(argv[0]), argv);

    //int fd = GPIO_OpenAsOutput(SAMPLE_LED, GPIO_OutputMode_PushPull, GPIO_Value_High);
    //if (fd < 0) {
     //   Log_Debug(
    //        "Error opening GPIO: %s (%d). Check that app_manifest.json includes the GPIO used.\n",
    //        strerror(errno), errno);
    //    return -1;
    //}

    const struct timespec sleepTime = {1, 0};
	int fd;
	int fd_red = GPIO_OpenAsOutput(SAMPLE_RGBLED_RED, GPIO_OutputMode_PushPull, GPIO_Value_High);
	if (fd < 0) {
		Log_Debug("Error opening GPIO: %s (%d). Check that app_manifest.json includes the GPIO used.\n", strerror(errno), errno);
		return -1;
	}

	int fd_green = GPIO_OpenAsOutput(SAMPLE_RGBLED_GREEN, GPIO_OutputMode_PushPull, GPIO_Value_High);
	if (fd < 0) {
		Log_Debug("Error opening GPIO: %s (%d). Check that app_manifest.json includes the GPIO used.\n", strerror(errno), errno);
		return -1;
	}

	int fd_blue = GPIO_OpenAsOutput(SAMPLE_RGBLED_BLUE, GPIO_OutputMode_PushPull, GPIO_Value_High);
	if (fd < 0) {
		Log_Debug("Error opening GPIO: %s (%d). Check that app_manifest.json includes the GPIO used.\n", strerror(errno), errno);
		return -1;
	}

	int fd_led1_blue = GPIO_OpenAsOutput(MT3620_RDB_LED1_BLUE, GPIO_OutputMode_PushPull, GPIO_Value_High);
	//int fd_led1_blue = GPIO_OpenAsOutput(SAMPLE_LED, GPIO_OutputMode_PushPull, GPIO_Value_High);
	if (fd < 0) {
		Log_Debug("Error opening GPIO: %s (%d). Check that app_manifest.json includes the GPIO used.\n", strerror(errno), errno);
		return -1;
	}

    while (true) {
		Log_Debug("red\n");
        GPIO_SetValue(fd_red, GPIO_Value_Low);
        nanosleep(&sleepTime, NULL);
        GPIO_SetValue(fd_red, GPIO_Value_High);
        nanosleep(&sleepTime, NULL);

		Log_Debug("green\n");
		GPIO_SetValue(fd_green, GPIO_Value_Low);
		nanosleep(&sleepTime, NULL);
		GPIO_SetValue(fd_green, GPIO_Value_High);
		nanosleep(&sleepTime, NULL);

		Log_Debug("blue\n");
		GPIO_SetValue(fd_blue, GPIO_Value_Low);
		nanosleep(&sleepTime, NULL);
		GPIO_SetValue(fd_blue, GPIO_Value_High);
		nanosleep(&sleepTime, NULL);

		Log_Debug("led 1 blue\n");
		GPIO_SetValue(fd_led1_blue, GPIO_Value_Low);
		nanosleep(&sleepTime, NULL);
		GPIO_SetValue(fd_led1_blue, GPIO_Value_High);
		nanosleep(&sleepTime, NULL);

    }
}