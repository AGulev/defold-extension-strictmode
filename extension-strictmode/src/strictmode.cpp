#define LIB_NAME "StrictMode"
#define MODULE_NAME "strictmode"

#if defined(DM_PLATFORM_ANDROID)

#include <dmsdk/sdk.h>
#include "strictmode_jni.h"

dmExtension::Result AppInitializeStrictMode(dmExtension::AppParams* params)
{
    dmStrictMode::ThreadAttacher attacher;
    JNIEnv *env = attacher.env;
    dmStrictMode::ClassLoader class_loader = dmStrictMode::ClassLoader(env);
    jclass cls = class_loader.load("com/agulev/strictmode/ApplyStrictMode");

    bool policy_active = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.thread_policy_active", 0) == 1;
    if (policy_active) {
        bool detect_all = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.thread_detect_all", 0) == 1;
        bool detect_disk_reads = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.thread_detect_disk_reads", 0) == 1;
        bool detect_disk_write = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.thread_detect_disk_writes", 0) == 1;
        bool detect_network = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.thread_detect_network", 0) == 1;
        bool detect_slow_calls = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.thread_detect_slow_calls", 0) == 1;
        bool detect_resource_mismatches = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.thread_detect_resource_mismatches", 0) == 1;
        bool detect_unbuffered_io = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.thread_detect_unbuffered_io", 0) == 1;
        
        bool penalty_log = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.thread_penalty_log", 0) == 1;
        bool penalty_death = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.thread_penalty_death", 0) == 1;
        bool penalty_dialog = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.thread_penalty_dialog", 0) == 1;
        bool penalty_death_on_network = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.thread_penalty_death_on_network", 0) == 1;
        bool penalty_drop_box = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.thread_penalty_drop_box", 0) == 1;
        bool penalty_flash_screen = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.thread_penalty_flash_screen", 0) == 1;
        
        jmethodID methodThread = env->GetStaticMethodID(cls, "ApplyThreadStrictMode", "(ZZZZZZZZZZZZZ)V");
        env->CallStaticVoidMethod(cls, methodThread, detect_all, detect_disk_reads, detect_disk_write, detect_network, detect_slow_calls,
            detect_resource_mismatches, detect_unbuffered_io, penalty_log, penalty_death, penalty_dialog, penalty_death_on_network,
            penalty_drop_box, penalty_flash_screen);
    }


    bool vm_policy_active = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.vm_policy_active", 0) == 1;
    if (vm_policy_active) {
        bool vm_detect_all = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.vm_detect_all", 0) == 1;
        bool vm_detect_sqllite_leaks = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.vm_detect_sqllite_leaks", 0) == 1;
        bool vm_detect_leaked_closable_objects = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.vm_detect_leaked_closable_objects", 0) == 1;
        bool vm_penalty_log = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.vm_penalty_log", 0) == 1;
        bool vm_penalty_death = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.vm_penalty_death", 0) == 1;
        bool vm_penalty_death_on_file_uri_exposure = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.vm_penalty_death_on_file_uri_exposure", 0) == 1;
        bool vm_penalty_death_on_network = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.vm_penalty_death_on_network", 0) == 1;
        bool vm_penalty_drop_box = dmConfigFile::GetInt(params->m_ConfigFile, "strictmode.vm_penalty_drop_box", 0) == 1;
        
        jmethodID methodVm = env->GetStaticMethodID(cls, "ApplyVMStrictMode", "(ZZZZZZZZ)V");
        env->CallStaticVoidMethod(cls, methodVm, vm_detect_sqllite_leaks, vm_detect_leaked_closable_objects, vm_detect_all, vm_penalty_log,
            vm_penalty_death, vm_penalty_death_on_file_uri_exposure, vm_penalty_death_on_network, vm_penalty_drop_box);
        }
    
    return dmExtension::RESULT_OK;
}

dmExtension::Result InitializeStrictMode(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeStrictMode(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

DM_DECLARE_EXTENSION(StrictMode, LIB_NAME, AppInitializeStrictMode, 0, InitializeStrictMode, 0, 0, FinalizeStrictMode)

#else

extern "C" void StrictMode()
{

}

#endif //DM_PLATFORM_ANDROID
