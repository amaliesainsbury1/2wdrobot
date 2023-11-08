/*
  AxWebServer.h - Web Updater interface for PayTestHub devices Frontend processor
  (c) Abrantix AG
*/

#ifndef __AXOTAWEBSERVER_H
#define __AXOTAWEBSERVER_H

#include <Arduino.h>
#include <WiFi.h>
//#include <WebServer.h>
//https://github.com/me-no-dev/AsyncTCP
#include <AsyncTCP.h>
//https://github.com/me-no-dev/ESPAsyncWebServer
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include "Trace.h"
#include "Ports.h"
#include "AxNetwork.h"

#define FILE_UPLOAD_CHUNK_TIMEOUT_MILLIS 20000

class AxWebServer 
{
public:
  AxWebServer();
  void Init();
  void Process();
  void OnNetworkChanged();

private:
  bool isBound;
  bool wifiScanRunning;
  unsigned long lastWifiScan;
  String GetMainPage();
};

#endif
