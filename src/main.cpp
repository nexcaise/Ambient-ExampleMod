#include <Macro.h>
#include <configAPI.h>
#include <android/log.h>
#include <main.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "ExampleMod", __VA_ARGS__)

Config cfg("ExampleMod");

__attribute__((constructor))
void onLoad() {
    LOGI("Loading...");

    cfg.load();

    auto config = cfg.open("config.json");

    config.set("player.name", std::string("Zed"));
    config.set("player.level", 10);

    int level = config.get<int>("player.level", 0);
    std::string name = config.get<std::string>("player.name", "unknown");

    LOGI("Player Level: %d", level);
    LOGI("Player Name: %s", name.c_str());

    config.save();

    LOGI("Loading Done");
}