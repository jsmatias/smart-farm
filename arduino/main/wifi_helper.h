#pragma once
#include <WiFiS3.h>


void connectToWifi(const char* ssid, const char* pass);

extern WiFiServer server;