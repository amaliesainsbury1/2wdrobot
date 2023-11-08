/*
  AxButton.h - IPConfig definition for PayTestHub devices Frontend processor
  (c) Abrantix AG
*/

#ifndef __IPCONFIG_H
#define __IPCONFIG_H

typedef struct _IPCONFIG
{
  /* 0: DHCP, 1:Static IP, 2:WLAN AP Client mode, 3:SoftAP mode */
  char      Mode;
  char      IP[4];
  char      Subnet[4];
  char      Gateway[4];
  char      DNS[4];
  char      SSID[64];
  char      WifiPassword[64];
} IPCONFIG, *PIPCONFIG;

#endif
