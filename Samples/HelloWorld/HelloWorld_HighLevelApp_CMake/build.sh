#!/bin/bash

echo "Compiling main.c..."
#[1/6] C:\PROGRA~2\MI3C21~1\Sysroots\2\tools\gcc\ARFCD8~1.EXE -D_POSIX_C_SOURCE -I"C:\Program Files (x86)\Microsoft Azure Sphere SDK\Sysroots\2\usr\include" -I..\..\..\..\..\Hardware\mt3620_rdb\inc -B "C:/Program Files (x86)/Microsoft Azure Sphere SDK/Sysroots/2/tools/gcc" -march=armv7ve -mthumb -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a7 --sysroot="C:/Program Files (x86)/Microsoft Azure Sphere SDK/Sysroots/2"   -std=c11 -g1 -O2 -fPIC -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-omit-frame-pointer -fno-exceptions -Wall -Wstrict-prototypes -Wswitch -Wempty-body -Wconversion -Wreturn-type -Wparentheses -Wno-pointer-sign -Wno-format -Wuninitialized -Wunreachable-code -Wunused-function -Wunused-value -Wunused-variable -Werror=implicit-function-declaration -fstack-protector-strong -o CMakeFiles\HelloWorld_HighLevelApp_CMake.dir\main.c.obj   -c ..\..\main.c
gcc -D_POSIX_C_SOURCE -I/opt/azurespheresdk/Sysroots/2/usr/include/ -I/opt/pv/Hardware/mt3620_rdb/inc -march=armv7ve -mthumb -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a7 --sysroot=/opt/azurespheresdk/Sysroots/2 -std=c11 -g1 -Os -fPIC -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-omit-frame-pointer -fno-exceptions -Wall -Wstrict-prototypes -Wswitch -Wempty-body -Wconversion -Wreturn-type -Wparentheses -Wno-pointer-sign -Wno-format -Wuninitialized -Wunreachable-code -Wunused-function -Wunused-value -Wunused-variable -Werror=implicit-function-declaration -fstack-protector-strong -o main.c.obj -c main.c

echo "Compiling polyverse.c..."
# C:\PROGRA~2\MI3C21~1\Sysroots\2\tools\gcc\ARFCD8~1.EXE -D_POSIX_C_SOURCE -I"C:\Program Files (x86)\Microsoft Azure Sphere SDK\Sysroots\2\usr\include" -I..\..\..\..\..\Hardware\mt3620_rdb\inc -B "C:/Program Files (x86)/Microsoft Azure Sphere SDK/Sysroots/2/tools/gcc" -march=armv7ve -mthumb -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a7 --sysroot="C:/Program Files (x86)/Microsoft Azure Sphere SDK/Sysroots/2"   -std=c11 -g1 -Os -fPIC -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-omit-frame-pointer -fno-exceptions -Wall -Wstrict-prototypes -Wswitch -Wempty-body -Wconversion -Wreturn-type -Wparentheses -Wno-pointer-sign -Wno-format -Wuninitialized -Wunreachable-code -Wunused-function -Wunused-value -Wunused-variable -Werror=implicit-function-declaration -fstack-protector-strong -o CMakeFiles\HelloWorld_HighLevelApp_CMake.dir\polyverse.c.obj   -c ..\..\polyverse.c
gcc -D_POSIX_C_SOURCE -I/opt/azurespheresdk/Sysroots/2/usr/include/ -I/opt/pv/Hardware/mt3620_rdb/inc -march=armv7ve -mthumb -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a7 --sysroot=/opt/azurespheresdk/Sysroots/2 -std=c11 -g1 -Os -fPIC -ffunction-sections -fdata-sections -fno-strict-aliasing -fno-omit-frame-pointer -fno-exceptions -Wall -Wstrict-prototypes -Wswitch -Wempty-body -Wconversion -Wreturn-type -Wparentheses -Wno-pointer-sign -Wno-format -Wuninitialized -Wunreachable-code -Wunused-function -Wunused-value -Wunused-variable -Werror=implicit-function-declaration -fstack-protector-strong -o polyverse.c.obj -c polyverse.c

echo "Linking main.c.obj and polyverse.c.obj and creating HelloWorld_HighLevelApp_CMake.out..."
# [3/6] cmd.exe /C "cd . && C:\PROGRA~2\MI3C21~1\Sysroots\2\tools\gcc\ARFCD8~1.EXE -B "C:/Program Files (x86)/Microsoft Azure Sphere SDK/Sysroots/2/tools/gcc" -march=armv7ve -mthumb -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a7 --sysroot="C:/Program Files (x86)/Microsoft Azure Sphere SDK/Sysroots/2"  -nodefaultlibs -pie -Wl,--no-undefined -Wl,--gc-sections CMakeFiles\HelloWorld_HighLevelApp_CMake.dir\main.c.obj CMakeFiles\HelloWorld_HighLevelApp_CMake.dir\polyverse.c.obj  -o HelloWorld_HighLevelApp_CMake.out  -lapplibs -lpthread -lgcc_s -lc && cd ."
gcc -march=armv7ve -mthumb -mfpu=neon -mfloat-abi=hard -mcpu=cortex-a7 --sysroot=/opt/azurespheresdk/Sysroots/2 -nodefaultlibs -pie -Wl,--no-undefined -Wl,--gc-sections main.c.obj polyverse.c.obj -o HelloWorld_HighLevelApp_CMake.out -Wl,-rpath,/opt/azurespheresdk/Sysroots/2/usr/lib/ -lapplibs -lpthread -lgcc_s -lc

nm -C -g ./HelloWorld_HighLevelApp_CMake.out | grep 'T init\|T show\|T foo3' | sort -k3 | awk '{print $1}' | xargs

strip --strip-unneeded HelloWorld_HighLevelApp_CMake.out
