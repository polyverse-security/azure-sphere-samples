echo "Copying %1..."

copy %1 "C:\Users\Chris Hanaoka\source\repos\azure-sphere-samples\Samples\HelloWorld\HelloWorld_HighLevelApp_CMake\out\ARM-Release-2\approotHelloWorld_HighLevelApp_CMake\bin\app"

echo "Stripping..."
"C:\Program Files (x86)\Microsoft Azure Sphere SDK\Sysroots\2\tools\gcc\strip.exe" --strip-unneeded "C:\Users\Chris Hanaoka\source\repos\azure-sphere-samples\Samples\HelloWorld\HelloWorld_HighLevelApp_CMake\out\ARM-Release-2\approotHelloWorld_HighLevelApp_CMake\bin\app"

echo "Creating imagepackage..."
copy /Y "C:\Users\Chris Hanaoka\source\repos\azure-sphere-samples\Samples\HelloWorld\HelloWorld_HighLevelApp_CMake\app_manifest.json" "C:\Users\Chris Hanaoka\source\repos\azure-sphere-samples\Samples\HelloWorld\HelloWorld_HighLevelApp_CMake\out\ARM-Release-2\approotHelloWorld_HighLevelApp_CMake\app_manifest.json"

dir "C:\Users\Chris Hanaoka\source\repos\azure-sphere-samples\Samples\HelloWorld\HelloWorld_HighLevelApp_CMake\out\ARM-Release-2"

cmd.exe /C "cd /D "C:\Users\Chris Hanaoka\source\repos\azure-sphere-samples\Samples\HelloWorld\HelloWorld_HighLevelApp_CMake\out\ARM-Release-2" && "C:\Program Files (x86)\Microsoft Azure Sphere SDK\Tools\azsphere.exe" image package-application  -v -i "C:\Users\Chris Hanaoka\source\repos\azure-sphere-samples\Samples\HelloWorld\HelloWorld_HighLevelApp_CMake\out\ARM-Release-2\approotHelloWorld_HighLevelApp_CMake" -o "C:\Users\Chris Hanaoka\source\repos\azure-sphere-samples\Samples\HelloWorld\HelloWorld_HighLevelApp_CMake\out\ARM-Release-2\HelloWorld_HighLevelApp_CMake.imagepackage" -s "2" -h "C:/Users/Chris Hanaoka/source/repos/azure-sphere-samples/Samples/HelloWorld/HelloWorld_HighLevelApp_CMake/../../../Hardware/mt3620_rdb/sample_hardware.json""

dir "C:\Users\Chris Hanaoka\source\repos\azure-sphere-samples\Samples\HelloWorld\HelloWorld_HighLevelApp_CMake\out\ARM-Release-2"

echo "Sideload delete..."
azsphere device sideload delete

echo "Sideload deploy..."
azsphere device sideload deploy --imagepackage "C:\Users\Chris Hanaoka\source\repos\azure-sphere-samples\Samples\HelloWorld\HelloWorld_HighLevelApp_CMake\out\ARM-Release-2\HelloWorld_HighLevelApp_CMake.imagepackage" -m

echo "Starting..."
azsphere device sideload start
