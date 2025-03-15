#ifndef OWM_EPD47_MAIN_H
#define OWM_EPD47_MAIN_H

#include <Arduino.h>            // In-built
#include <WiFi.h>               // In-built
#include <HTTPClient.h>         // In-built
#include <ArduinoJson.h>        // https://github.com/bblanchon/ArduinoJson
#include "epd_driver.h"         // https://github.com/Xinyuan-LilyGO/LilyGo-EPD47

#include "forecast_record.h"

// Screen Dimensions
#define SCREEN_WIDTH   EPD_WIDTH
#define SCREEN_HEIGHT  EPD_HEIGHT

// Alignment Enum
enum alignment {LEFT, RIGHT, CENTER};

// Color Definitions
#define White         0xFF
#define LightGrey     0xBB
#define Grey          0x88
#define DarkGrey      0x44
#define Black         0x00

//Icon size settings
#define Large  20           // For icon drawing
#define Small  10           // For icon drawing

#define max_readings 24 // Limited to 3-days here, but could go to 5-days = 40 as the data is issued

void InitialiseSystem();
uint8_t StartWiFi();
void StopWiFi();
void BeginSleep();
boolean SetupTime();
boolean UpdateLocalTime();

String ConvertUnixTime(int unix_time);
int JulianDate(int d, int m, int y);
String TitleCase(String text);

float mm_to_inches(float value_mm);
float hPa_to_inHg(float value_hPa);
float SumOfPrecip(float DataArray[], int readings);
String WindDegToOrdinalDirection(float winddirection);
double NormalizedMoonPhase(int d, int m, int y);

bool obtainWeatherData(WiFiClient & client, const String & RequestType);
bool DecodeWeather(WiFiClient& json, String Type);
void Convert_Readings_to_Imperial();

void DisplayWeather();
void DisplayGeneralInfoSection();
void DisplayWeatherIcon(int x, int y);
void DisplayMainWeatherSection(int x, int y);
void DisplayDisplayWindSection(int x, int y, float angle, float windspeed, int Cradius);
void DisplayTempHumiPressSection(int x, int y);
void DisplayForecastTextSection(int x, int y);
void DisplayVisiCCoverSection(int x, int y);
void DisplayForecastWeather(int x, int y, int index, int fwidth);
void DisplayAstronomySection(int x, int y);
void DrawMoon(int x, int y, int diameter, int dd, int mm, int yy, String hemisphere);
String MoonPhase(int d, int m, int y, String hemisphere);
void DisplayForecastSection(int x, int y);
void DisplayGraphSection(int x, int y);
void DisplayConditionsSection(int x, int y, String IconName, bool IconSize);
void DrawSegment(int x, int y, int o1, int o2, int o3, int o4, int o11, int o12, int o13, int o14);
void DrawPressureAndTrend(int x, int y, float pressure, String slope);
void DisplayStatusSection(int x, int y, int rssi);
void DrawRSSI(int x, int y, int rssi);
void DrawBattery(int x, int y);

void addcloud(int x, int y, int scale, int linesize);
void addrain(int x, int y, int scale, bool IconSize);
void addsnow(int x, int y, int scale, bool IconSize);
void addtstorm(int x, int y, int scale);
void addsun(int x, int y, int scale, bool IconSize);
void addfog(int x, int y, int scale, int linesize, bool IconSize);
void ClearSky(int x, int y, bool IconSize, String IconName);
void BrokenClouds(int x, int y, bool IconSize, String IconName);
void FewClouds(int x, int y, bool IconSize, String IconName);
void ScatteredClouds(int x, int y, bool IconSize, String IconName);
void Rain(int x, int y, bool IconSize, String IconName);
void ChanceRain(int x, int y, bool IconSize, String IconName);
void Thunderstorms(int x, int y, bool IconSize, String IconName);
void Snow(int x, int y, bool IconSize, String IconName);
void Mist(int x, int y, bool IconSize, String IconName);
void CloudCover(int x, int y, int CloudCover);
void addmoon(int x, int y, bool IconSize);
void Nodata(int x, int y, bool IconSize, String IconName);

void Visibility(int x, int y, String Visibility);
void DrawMoonImage(int x, int y);
void DrawSunriseImage(int x, int y);
void DrawSunsetImage(int x, int y);
void DrawGraph(int x_pos, int y_pos, int gwidth, int gheight, float Y1Min, float Y1Max, String title, float DataArray[], int readings, boolean auto_scale, boolean barchart_mode);

void drawString(int x, int y, String text, alignment align);
void fillCircle(int x, int y, int r, uint8_t color);
void drawFastHLine(int16_t x0, int16_t y0, int length, uint16_t color);
void drawFastVLine(int16_t x0, int16_t y0, int length, uint16_t color);
void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
void drawCircle(int x0, int y0, int r, uint8_t color);
void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
void drawPixel(int x, int y, uint8_t color);
void arrow(int x, int y, int asize, float aangle, int pwidth, int plength);
void DrawAngledLine(int x, int y, int x1, int y1, int size, int color);

void setFont(GFXfont const & font);

void epd_update();

#endif