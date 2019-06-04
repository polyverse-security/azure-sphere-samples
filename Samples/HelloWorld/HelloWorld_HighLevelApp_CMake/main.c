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

	init();

	Log_Debug("show: %p\n", (void *)&show);
	for (int i = 3; i >= 0; i--) {
		show(((unsigned long)&show >> (4 * i)) & 0x0F);
	}

	Log_Debug("init: %p\n", (void *)&init);
	for (int i = 3; i >= 0; i--) {
		show(((unsigned long)&init >> (4 * i)) & 0x0F);
	}

	Log_Debug("foo3: %p\n", (void *)&foo3);
	for (int i = 3; i >= 0; i--) {
		show(((unsigned long)&foo3 >> (4 * i)) & 0x0F);
	}
}