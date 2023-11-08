/*
  AxEEPROM.h - EEPROM interface for PayTestHub devices Frontend processor
  (c) Abrantix AG
*/

#ifndef __AXEEPROM_H
#define __AXEEPROM_H

#include <Arduino.h>
#include <EEPROM.h>
#include "Trace.h"
#include "CoreDefinitions.h"
#include "IpConfig.h"

/* EEPROM defines */
typedef struct _EEPROM_DATA {
  byte Magic[4];
  IPCONFIG IPConfiguration;
  uint16_t WebIfPort;
} EEPROM_DATA, *PEEPROM_DATA;

extern EEPROM_DATA EEPROMData;

class AxEEPROM
{
public:
	AxEEPROM();
	void Init();
	void LoadEEPROM(bool loadDefaults);
	void SaveEEPROM();

private:
};

extern AxEEPROM AxEEPROMInstance;

#endif
