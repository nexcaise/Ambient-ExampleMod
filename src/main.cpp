#include <android/log.h>

#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, "ExampleMod", __VA_ARGS__)

__attribute__((constructor))
void onLoad() {
    LOGI("Loading...");
}