#pragma once
#include "common.h"


#ifdef ENABLE_GROVE_LOG
    #define GLInitialize(callback)  GroveLog::Initialize(callback)
    #define GLPrintln(msg)          GroveLog::Println(msg)
    #define GLPrintf(format, ...)   GroveLog::Printf(format, __VA_ARGS__)
    #define GLWrite(buffer, size)   GroveLog::Write(buffer, size)
#else
    #define GLInitialize(callback)  NULL
    #define GLPrintln(msg)          NULL
    #define GLPrintf(format, ...)   NULL
    #define GLWrite(buffer, size)   NULL
#endif


// Definizione del tipo di callback per il logging
typedef void (*LogCallbackFunc)(const char* message);

#ifdef ENABLE_GROVE_LOG
///
class GroveLog
{
public:
    ///
    static void Initialize(LogCallbackFunc callback);

    ///
    static void Println(const char* msg);

    ///
    static void Printf(const char* format, ...);

    ///
    static void Write(const uint8_t* buffer, size_t size);

private:
    ///
    static LogCallbackFunc _logCallback;
};


#endif // ENABLE_GROVE_LOG





