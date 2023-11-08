/*
  AxNetworkInstance.h - Networking interface for Card Cloud Multiplexer
  (c) Abrantix AG
*/

#ifndef __AXNETWORK_H
#define __AXNETWORK_H

#include <ETH.h>
#include <ESPmDNS.h>
#include "Pinout.h"
#include "AxEEPROM.h"
#include "IpConfig.h"
#include "AxDisplay.h"

typedef enum {
  NETWORK_UNDEFINED = -1,
  WIRED_NETWORK_STATIC_IP = 1,
	WIRELESS_STA = 2,
	WIRELESS_AP = 3,
	USB = 4,
	WIRED_DHCP = 0
} wifi_network_t;

typedef
void
(*CONNECTION_CHANGED_FCT)(
  void
  );

class AxNetwork 
{
public:
  AxNetwork();
  void Setup(PIPCONFIG ipCfg);
  void Process();
  bool IsEthConnected();
  IPAddress GetLocalIP();
  const char* GetBaseMacAddress();
  const char* GetNetworkTypeString();
  wifi_network_t GetNetworkMode();
  const PIPCONFIG GetIpConfig();
  void PeristNewIpConfig(PIPCONFIG ipCfg);
  CONNECTION_CHANGED_FCT ConnectionChanged;

private:
  static void WiFiEvent(WiFiEvent_t event);
  static void StopWifi();
  static void SetupNetwork(char mode);
  static IPAddress ArrayToIPAddress(char *bytes);
  bool isBound:1;
};

extern AxNetwork AxNetworkInstance;

#endif
