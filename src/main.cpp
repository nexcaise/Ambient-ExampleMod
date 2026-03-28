#include <Macro.h>
#include <nise/stub.h>
#include <pl/Logger.h>

//this is constructor func (__attribute((constructor)))__);
LoadAPI void onLoad() {
    auto &logger = pl::log::Logger::getOrCreate("ExampleMod");
    logger.info("Loading...");
    logger.info("Loading Done");
}