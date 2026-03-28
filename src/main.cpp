#include <Macro.h>
#include <api.h>

//this is constructor func (__attribute((constructor)))__);
LoadAPI void onLoad() {
    ClientLog("ExampleMod", "onLoad", "Loading...");
    ClientLog("ExampleMod", "onLoad", "Loading Done");
}