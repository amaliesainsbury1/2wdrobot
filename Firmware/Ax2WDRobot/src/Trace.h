/*
  Trace.h - Debug / Serial Tracing
  (c) Abrantix AG
*/

#ifndef __TRACE_H
#define __TRACE_H

#include <Arduino.h>

//(un)comment the following line to enable/disable serial traces
#define SERIAL_TRACE

#ifdef SERIAL_TRACE
	#define SERIAL_TRACE_BAUDRATE	115200
	#define  TRACELN(x)         Serial.println(x)
	#define  TRACE(x)           Serial.print(x)
    #define  TRACEBYTE(x)       Serial.write(x)
	#define  TRACELNF(x, y)     Serial.println(x, y)
	#define  TRACEF(x, y)       Serial.print(x, y)
    #define  TRACEPRINTF(x, ...) Serial.printf(x, __VA_ARGS__)
	#define  TRACEHEX(x)        if(0x10 > x)Serial.print("0");Serial.print(x, HEX)
	#define  TRACEHEXDUMP(x, y)  TraceHexDump(x, y)
	#define  TRACEWRITE(x, y)   if(Serial) Serial.write((uint8_t*)x, y)
#else
	#define TRACELN(x)
	#define TRACE(x)
    #define  TRACEBYTE(x)
	#define TRACELNF(x, y)
	#define TRACEF(x, y)
	#define  TRACEHEX(x)
    #define  TRACEPRINTF(x, ...)
    #define  TRACEHEXDUMP(x, y)
	#define  TRACEWRITE(x, y) 
#endif

void TraceHexDump(uint8_t *data, uint16_t length);

#endif
