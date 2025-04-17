#include "GroveLog.h"
#ifdef ENABLE_GROVE_LOG

// Inizializza la variabile statica
LogCallbackFunc GroveLog::_logCallback = nullptr;

///
void GroveLog::Initialize(LogCallbackFunc callback)
{
    _logCallback = callback;
}

///
void GroveLog::Println(const char* msg)
{
    if (_logCallback) {
        _logCallback(msg);
    }
}

///
#define _BUFFER_SIZE 1024
static char _buffer[_BUFFER_SIZE];
void GroveLog::Printf(const char* format, ...)
{
    if (_logCallback) {
        va_list list;
        va_start(list, format);
        vsnprintf(_buffer, _BUFFER_SIZE, format, list);
        _logCallback(_buffer);
        va_end(list);
    }
}

///
void GroveLog::Write(const uint8_t* buffer, size_t size)
{
    // Questa è una funzionalità più complessa, converte il buffer binario in testo esadecimale
    if (_logCallback && size > 0) {
        static char hexBuffer[_BUFFER_SIZE * 3]; // *3 per lasciare spazio ai byte esadecimali
        int hexPos = 0;
        
        // Converte fino a _BUFFER_SIZE/3 byte per evitare overflow
        int maxBytes = (_BUFFER_SIZE / 3) < size ? (_BUFFER_SIZE / 3) : size;
        
        for (int i = 0; i < maxBytes; i++) {
            hexPos += sprintf(hexBuffer + hexPos, "%02X ", buffer[i]);
        }
        
        _logCallback(hexBuffer);
    }
}

#endif // ENABLE_GROVE_LOG
