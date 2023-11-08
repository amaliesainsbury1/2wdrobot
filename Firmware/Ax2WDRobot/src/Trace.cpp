/*
  Trace.cpp - Debug / Serial Tracing
  (c) Abrantix AG
*/

#include <Arduino.h>
#include "Trace.h"

#ifdef SERIAL_TRACE

#define HEXUMP_CHUNK_SIZE 32

inline void SetHexChar(uint8_t srcNibble, char *targetchar) __attribute__((always_inline));
void SetHexChar(uint8_t srcNibble, char *targetchar)
{
  if(srcNibble < 0x0A)
  {
    *targetchar = '0' + srcNibble;
  }
  else
  {
    *targetchar = 'A' + (srcNibble - 0x0A);
  }
}

//Prints up to HEXUMP_CHUNK_SIZE bytes
void TraceHexDumpInternal(uint8_t *data, unsigned int length) // prints 8-bit data in hex with leading zeroes
{
       //one input byte results in two output bytes
      char buffer[HEXUMP_CHUNK_SIZE * 2];
      char *P = buffer;
       for (int i=0; i<length; i++) 
       { 
          if(P - buffer >= sizeof(buffer))
          {
            break;
          }
          SetHexChar(data[i] >> 4, P);
          P++;
          SetHexChar(data[i] & 0x0F, P);
          P++;
       }
       TRACEWRITE(buffer, length * 2);
}

void TraceHexDump(uint8_t *data, uint16_t length) // prints 8-bit data in hex with leading zeroes
{
  //print in chunks of HEXUMP_CHUNK_SIZE bytes
  for(int i=0; i<length; i+=HEXUMP_CHUNK_SIZE)
  {
    int16_t currentBlockLength = i + HEXUMP_CHUNK_SIZE <= length ? HEXUMP_CHUNK_SIZE : length % HEXUMP_CHUNK_SIZE;
    TraceHexDumpInternal(data + i, currentBlockLength);
  }
}



#endif
