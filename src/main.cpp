#include <Macro.h>
#include <configAPI.h>
#include <android/log.h>
#include <pl/Logger.h>

ConfigManager cfg("ExampleMod");

auto &logger = pl::log::getOrCreate("ExampleMod");

//this is constructor func (__attribute__((constructor)));
__attribute__((constructor))
 void onLoad() {
    logger.info("Loading...");
    auto config = cfg.open("config.json");
    config.write("player.name", std::string("Zed"));
    config.write("player.level", 10);
    int level = config.read<int>("player.level", 0);
    std::string name = config.read<std::string>("player.name", "unknown");
    logger.info("Player Level: %s", level);
    logger.info("Player Name: %s", name);
    logger.info("Loading Done");
}