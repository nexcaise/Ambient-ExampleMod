#include <Macro.h>
#include <android/log.h>

#define LOG_TAG "ExampleMod"

#define LOGI(fmt, ...) \
__android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, ##__VA_ARGS__)

//this is constructor func (__attribute((constructor)))__);
LoadAPI void onLoad() {
    LOGI("Loading...");
    LOGI("Loading Done");
}