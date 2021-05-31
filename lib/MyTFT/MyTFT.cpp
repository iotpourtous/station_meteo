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
    case 4:
      fillScreen(TFT_BLACK);
      break;
    case 1:
      fillRect(0, 0, 319, 31, TFT_RED);
      drawRect(0, 0, 319, 240, TFT_RED);
      fillRect(1, 32, 317, 207, TFT_BLACK);
      break;
    case 2:
      fillRect(0, 0, 319, 31, TFT_BLUE);
      drawRect(0, 0, 319, 240, TFT_BLUE);
      fillRect(1, 32, 317, 207, TFT_BLACK);
      break;
    case 3:
      fillRect(0, 0, 319, 31, TFT_GREEN);
      drawRect(0, 0, 319, 240, TFT_GREEN);
      fillRect(1, 32, 317, 207, TFT_BLACK);
      break;
    case 0:
      fillRect(0, 0, 319, 31, TFT_WHITE);
      drawRect(0, 0, 319, 240, TFT_WHITE);
    default:
      fillRect(1, 32, 317, 207, TFT_BLACK);
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

void MyTFT::afficheEcran0(
    DateTime date,
    float temperature,
    float humidity,
    unsigned int pressure)
{

  if (_currentDate.minute() != date.minute())
  {
    _currentDate = date;
    char dateTimeFormat[] = "DD/MM/YYYY hh:mm";
    setTextColor(TFT_BLACK, TFT_WHITE);
    loadFont("Metal-Up-Your-Ear-24");
    drawCentreString(" " + String(_currentDate.toString(dateTimeFormat)) + " ", 160, 6, 1);
  }
  if (_currentTemperature != temperature)
  {
    _currentTemperature = temperature;
    setTextColor(TFT_RED, TFT_BLACK);
    loadFont("Metal-Up-Your-Ear-48");
    drawCentreString(" " + (String)_currentTemperature + "C ", 100, 60, 1);
  }
  if (_currentHumidity != humidity)
  {
    _currentHumidity = humidity;
    setTextColor(TFT_BLUE, TFT_BLACK);
    loadFont("Metal-Up-Your-Ear-48");
    drawCentreString(" " + (String)_currentHumidity + "% ", 160, 120, 1);
  }
  if (_currentPressure != pressure)
  {
    _currentPressure = pressure;
    setTextColor(TFT_GREEN, TFT_BLACK);
    loadFont("Metal-Up-Your-Ear-48");
    drawCentreString(" " + (String)_currentPressure + "hPa ", 220, 180, 1);
  }
}

void MyTFT::afficheEcran1(
    DateTime date,
    float temperature)
{

  if (_currentDate.minute() != date.minute())
  {
    _currentDate = date;
    char dateTimeFormat[] = "DD/MM/YYYY hh:mm";
    setTextColor(TFT_BLACK, TFT_RED);
    loadFont("Metal-Up-Your-Ear-24");
    drawCentreString(" " + String(_currentDate.toString(dateTimeFormat)) + " ", 160, 6, 1);
  }
  if (_currentTemperature != temperature)
  {
    _currentTemperature = temperature;
    setTextColor(TFT_RED, TFT_BLACK);
    loadFont("Metal-Up-Your-Ear-60");
    drawCentreString(" " + (String)_currentTemperature + "C ", 160, 120, 1);
  }
}

void MyTFT::afficheEcran2(
    DateTime date,
    float humidity)
{

  if (_currentDate.minute() != date.minute())
  {
    _currentDate = date;
    char dateTimeFormat[] = "DD/MM/YYYY hh:mm";
    setTextColor(TFT_BLACK, TFT_BLUE);
    loadFont("Metal-Up-Your-Ear-24");
    drawCentreString(" " + String(_currentDate.toString(dateTimeFormat)) + " ", 160, 6, 1);
  }

  if (_currentHumidity != humidity)
  {
    _currentHumidity = humidity;
    setTextColor(TFT_BLUE, TFT_BLACK);
    loadFont("Metal-Up-Your-Ear-60");
    drawCentreString(" " + (String)_currentHumidity + "% ", 160, 120, 1);
  }
}

void MyTFT::afficheEcran3(
    DateTime date,
    unsigned int pressure)
{

  if (_currentDate.minute() != date.minute())
  {
    _currentDate = date;
    char dateTimeFormat[] = "DD/MM/YYYY hh:mm";
    setTextColor(TFT_BLACK, TFT_GREEN);
    loadFont("Metal-Up-Your-Ear-24");
    drawCentreString(" " + String(_currentDate.toString(dateTimeFormat)) + " ", 160, 6, 1);
  }
  if (_currentPressure != pressure)
  {
    _currentPressure = pressure;
    setTextColor(TFT_GREEN, TFT_BLACK);
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
    setTextColor(TFT_YELLOW, TFT_BLACK);
    loadFont("Metal-Up-Your-Ear-60");
    drawCentreString(" " + String(_currentDate.toString(timeFormat)) + " ", 160, 80, 1);
    loadFont("Metal-Up-Your-Ear-36");
    drawCentreString(" " + dayOfTheWeek + " " + (_currentDate.toString(dateFormat)), 160, 140, 1);
  }
}