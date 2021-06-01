#include "MyTFT.h"

void MyTFT::init()
{
  if (!SPIFFS.begin())
  {
    Serial.println("SPIFFS initialisation failed!");
    while (1)
      yield();
  }

  TFT_eSPI::init();
  setRotation(1);
}

void MyTFT::affiche(
    DateTime date,
    float temperature,
    float humidity,
    unsigned int pressure,
    String dayOfTheWeek,
    unsigned int screen)
{
  if (_currentScreen != screen)
  {
    _currentScreen = screen;
    _currentDate = DateTime();
    _currentTemperature = 0;
    _currentHumidity = 0;
    _currentPressure = 0;

    switch (_currentScreen)
    {
    case 0:
      drawBackGround(color_type_t::DARKGREY_SCREEN);
      break;
    case 1:
      drawBackGround(color_type_t::TEMPERATURE_SCREEN);
      break;
    case 2:
      drawBackGround(color_type_t::HUMIDITY_SCREEN);
      break;
    case 3:
      drawBackGround(color_type_t::PRESSURE_SCREEN);
      break;
    case 4:
      fillScreen(TFT_BLACK);
      break;
    }
  }

  if (_currentScreen == 0)
    afficheEcran0(date, temperature, humidity, pressure);
  else if (_currentScreen == 1)
    afficheEcran1(date, temperature);
  else if (_currentScreen == 2)
    afficheEcran2(date, humidity);
  else if (_currentScreen == 3)
    afficheEcran3(date, pressure);
  else if (_currentScreen == 4)
    afficheEcran4(date, dayOfTheWeek);
}

void MyTFT::drawBackGround(unsigned int color)
{
  fillRect(0, 0, 319, 31, color);
  drawRect(0, 0, 319, 240, color);
  fillRect(1, 32, 317, 207, TFT_BLACK);
}

void MyTFT::afficheEcran0(
    DateTime date,
    float temperature,
    float humidity,
    unsigned int pressure)
{
  afficheHeure(date, color_type_t::DARKGREY_SCREEN);
  if (_currentTemperature != temperature)
  {
    _currentTemperature = temperature;
    setTextColor(color_type_t::TEMPERATURE_SCREEN, TFT_BLACK);
    loadFont("Metal-Up-Your-Ear-48");
    drawCentreString(" " + (String)_currentTemperature + "C ", 100, 60, 1);
  }
  if (_currentHumidity != humidity)
  {
    _currentHumidity = humidity;
    setTextColor(color_type_t::HUMIDITY_SCREEN, TFT_BLACK);
    loadFont("Metal-Up-Your-Ear-48");
    drawCentreString(" " + (String)_currentHumidity + "% ", 160, 120, 1);
  }
  if (_currentPressure != pressure)
  {
    _currentPressure = pressure;
    setTextColor(color_type_t::PRESSURE_SCREEN, TFT_BLACK);
    loadFont("Metal-Up-Your-Ear-48");
    drawCentreString(" " + (String)_currentPressure + "hPa ", 220, 180, 1);
  }
}

void MyTFT::afficheEcran1(
    DateTime date,
    float temperature)
{
  afficheHeure(date, color_type_t::TEMPERATURE_SCREEN);
  if (_currentTemperature != temperature)
  {
    _currentTemperature = temperature;
    setTextColor(color_type_t::TEMPERATURE_SCREEN, TFT_BLACK);
    loadFont("Metal-Up-Your-Ear-60");
    drawCentreString(" " + (String)_currentTemperature + "C ", 160, 120, 1);
  }
}

void MyTFT::afficheEcran2(
    DateTime date,
    float humidity)
{
  afficheHeure(date, color_type_t::HUMIDITY_SCREEN);
  if (_currentHumidity != humidity)
  {
    _currentHumidity = humidity;
    setTextColor(color_type_t::HUMIDITY_SCREEN, TFT_BLACK);
    loadFont("Metal-Up-Your-Ear-60");
    drawCentreString(" " + (String)_currentHumidity + "% ", 160, 120, 1);
  }
}

void MyTFT::afficheEcran3(
    DateTime date,
    unsigned int pressure)
{
  afficheHeure(date, color_type_t::PRESSURE_SCREEN);
  if (_currentPressure != pressure)
  {
    _currentPressure = pressure;
    setTextColor(color_type_t::PRESSURE_SCREEN, TFT_BLACK);
    loadFont("Metal-Up-Your-Ear-60");
    drawCentreString(" " + (String)_currentPressure + "hPa ", 160, 120, 1);
  }
}

void MyTFT::afficheEcran4(
    DateTime date,
    String dayOfTheWeek)
{

  if (_currentDate.minute() != date.minute())
  {
    _currentDate = date;
    char dateFormat[] = "DD/MM/YYYY";
    char timeFormat[] = "hh:mm";
    setTextColor(color_type_t::DATETIME_SCREEN, TFT_BLACK);
    loadFont("Metal-Up-Your-Ear-60");
    drawCentreString(" " + String(_currentDate.toString(timeFormat)) + " ", 160, 80, 1);
    loadFont("Metal-Up-Your-Ear-36");
    drawCentreString(" " + dayOfTheWeek + " " + (_currentDate.toString(dateFormat)), 160, 140, 1);
  }
}

void MyTFT::afficheHeure(
    DateTime date,
    unsigned int backgroundColor)
{
  if (_currentDate.minute() != date.minute())
  {
    _currentDate = date;
    char dateTimeFormat[] = "DD/MM/YYYY hh:mm";
    setTextColor(TFT_BLACK, backgroundColor);
    loadFont("Metal-Up-Your-Ear-24");
    drawCentreString(" " + String(_currentDate.toString(dateTimeFormat)) + " ", 160, 6, 1);
  }
}