#pragma once

#include "smarterpointer.h"
#include <mutex>

#ifdef _MSC_VER
#define MODULE_EXPORT __declspec(dllexport)
#else
#define MODULE_EXPORT __attribute__((visibility("default")))
#endif


#define DECLARE_MODULE_CREATE(Class)                         \
    extern "C" MODULE_EXPORT Class *query_module_instance(); \
    extern "C" MODULE_EXPORT const char *query_module_metadata();


#define DECLARE_MODULE_CREATE_IMP(Class)                         \
    Class *g_##Class = nullptr;                                  \
    extern "C" MODULE_EXPORT Class *query_module_instance()      \
    {                                                            \
        static std::once_flag flag;                              \
        std::call_once(flag, []() { g_##Class = new Class(); }); \
        return g_##Class;                                        \
    }                                                            \
    extern "C" MODULE_EXPORT const char *query_module_metadata() \
    {                                                            \
        return reinterpret_cast<const char *>(_module_metadata); \
    }


class ModuleLoader
{
public:
    static RefObject *load(const char *path);

    template<class T>
    static SmarterPtr<T> load(const char *path)
    {
        RefObject *module = load(path);
        if (module) { return new SmarterPtr<T>(static_cast<T *>(module)); }
        return nullptr;
    }
};