#include <Macro.h>
#include <configAPI.h>
#include <android/log.h>
#include <main.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "ExampleMod", __VA_ARGS__)

ConfigManager cfg("ExampleMod");

__attribute__((constructor))
void onLoad() {
    LOGI("Loading...");
//    LOGI("Package: %s", getAppPackage().c_str());

    auto config = cfg.open("config.json");

    config.write("player.name", std::string("Zed"));
    config.write("player.level", 10);

    int level = config.read<int>("player.level", 0);
    std::string name = config.read<std::string>("player.name", "unknown");

    LOGI("Player Level: %d", level);
    LOGI("Player Name: %s", name.c_str());

    config.save();

    LOGI("Loading Done");
}