/*
  AxEEPROM.h - EEPROM interface for PayTestHub devices Frontend processor
  (c) Abrantix AG
*/


#include "AxEEPROM.h"
#include "Ports.h"

AxEEPROM AxEEPROMInstance;
EEPROM_DATA EEPROMData;

AxEEPROM::AxEEPROM()
{
}

void AxEEPROM::Init()
{
  EEPROM.begin(512);
  LoadEEPROM(false);
}

void AxEEPROM::LoadEEPROM(bool loadDefaults)
{
  EEPROM.readBytes(0, &EEPROMData, sizeof(EEPROMData));
  TRACE("EEPROM ");
  TRACEHEXDUMP((unsigned char*)&EEPROMData, sizeof(EEPROMData));
  TRACELN();
  if(loadDefaults || 0 != memcmp(EEPROMData.Magic, EEPROM_MAGIC, 4))
  {
    TRACELN("Load EEPROM defaults");
    memcpy(EEPROMData.Magic, EEPROM_MAGIC, 4);

    /* Overwrite existing values with 0 */
    memset(&EEPROMData.IPConfiguration, 0, sizeof(IPCONFIG));

    //Default to SoftAP Mode
    EEPROMData.IPConfiguration.Mode = 3;

    EEPROMData.WebIfPort = TCP_PORT_WEBIF_DEFAULT;

    //Default to Wired DHCP mode
    //EEPROMData.IPConfiguration.Mode = 0;

    
    /*
    // Test with static IP 192.168.1.222
    EEPROMData.IPConfiguration.Mode = 1;
    memcpy(EEPROMData.IPConfiguration.IP,     "\300\250\1\336", 4);
    memcpy(EEPROMData.IPConfiguration.Subnet, "\300\250\1\1", 4);
    memcpy(EEPROMData.IPConfiguration.Gateway,"\300\250\1\1", 4);
    memcpy(EEPROMData.IPConfiguration.DNS,    "\300\250\1\1", 4);
    */

    
    // Test with AP Client Mode (STA)
    //WIFI STA mode (DHCP)
    //EEPROMData.IPConfiguration.Mode = 2;
    //strcpy(EEPROMData.IPConfiguration.SSID,   "<WIFI SSID goes here>");
    //strcpy(EEPROMData.IPConfiguration.WifiPassword, "<WIFI Password goes here>");
    
        
    SaveEEPROM();
  }
}

void AxEEPROM::SaveEEPROM()
{
  EEPROM.writeBytes(0, &EEPROMData, sizeof(EEPROMData));
  EEPROM.commit();
}
