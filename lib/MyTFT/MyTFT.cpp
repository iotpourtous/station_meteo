#include "MyTFT.h"

void MyTFT::init()
{
  TFT_eSPI::init();
  setRotation(1);
}

void MyTFT::display(
    DateTime date,
    float temperature,
    float humidity,
    unsigned int pressure,
    String dayOfTheWeek,
    unsigned int screen)
{

  boolean refreshDisplay = false;

  if (_currentScreen != screen)
  {
    _currentScreen = screen;
    refreshDisplay = true;
  }

  switch (_currentScreen)
  {
  case 0:
    displayMainScreen(date, temperature, humidity, pressure, refreshDisplay);
    break;
  case 1:
    displayTemperatureScreen(date, temperature, refreshDisplay);
    break;
  case 2:
    displayHumidityScreen(date, humidity, refreshDisplay);
    break;
  case 3:
    displayPressureScreen(date, pressure, refreshDisplay);
    break;
  case 4:
    displayDateTimeScreen(date, dayOfTheWeek, refreshDisplay);
    break;
  }
}

void MyTFT::displayMainScreen(
    DateTime date,
    float temperature,
    float humidity,
    unsigned int pressure,
    boolean refreshDisplay)
{
  displayBackGround(MAIN_SCREEN, refreshDisplay);
  displayDateTime(date, MAIN_SCREEN, refreshDisplay);

  if (_currentTemperature != temperature || refreshDisplay)
  {
    _currentTemperature = temperature;
    setTextColor(TEMPERATURE_SCREEN, TFT_BLACK);
    loadFont(FONT_48);
    drawCentreString(" " + (String)_currentTemperature + "C ", 100, 60, 1);
  }

  if (_currentHumidity != humidity || refreshDisplay)
  {
    _currentHumidity = humidity;
    setTextColor(HUMIDITY_SCREEN, TFT_BLACK);
    loadFont(FONT_48);
    drawCentreString(" " + (String)_currentHumidity + "% ", 160, 120, 1);
  }

  if (_currentPressure != pressure || refreshDisplay)
  {
    _currentPressure = pressure;
    setTextColor(PRESSURE_SCREEN, TFT_BLACK);
    loadFont(FONT_48);
    drawCentreString(" " + (String)_currentPressure + "hPa ", 220, 180, 1);
  }
}

void MyTFT::displayTemperatureScreen(
    DateTime date,
    float temperature,
    boolean refreshDisplay)
{
  displayBackGround(TEMPERATURE_SCREEN, refreshDisplay);
  displayDateTime(date, TEMPERATURE_SCREEN, refreshDisplay);

  if (_currentTemperature != temperature || refreshDisplay)
  {
    _currentTemperature = temperature;
    displayData(TEMPERATURE_SCREEN, " " + (String)_currentTemperature + "C ");
  }
}

void MyTFT::displayHumidityScreen(
    DateTime date,
    float humidity,
    boolean refreshDisplay)
{
  displayBackGround(HUMIDITY_SCREEN, refreshDisplay);
  displayDateTime(date, HUMIDITY_SCREEN, refreshDisplay);

  if (_currentHumidity != humidity || refreshDisplay)
  {
    _currentHumidity = humidity;
    displayData(HUMIDITY_SCREEN, " " + (String)_currentHumidity + "% ");
  }
}

void MyTFT::displayPressureScreen(
    DateTime date,
    unsigned int pressure,
    boolean refreshDisplay)
{
  displayBackGround(PRESSURE_SCREEN, refreshDisplay);
  displayDateTime(date, PRESSURE_SCREEN, refreshDisplay);

  if (_currentPressure != pressure || refreshDisplay)
  {
    _currentPressure = pressure;
    displayData(PRESSURE_SCREEN, " " + (String)_currentPressure + "hPa ");
  }
}

void MyTFT::displayDateTimeScreen(
    DateTime date,
    String dayOfTheWeek,
    boolean refreshDisplay)
{
  if (refreshDisplay)
    fillScreen(TFT_BLACK);

  if (_currentDate.minute() != date.minute() || refreshDisplay)
  {
    _currentDate = date;
    char dateFormat[] = "DD/MM/YYYY";
    char timeFormat[] = "hh:mm";
    setTextColor(DATETIME_SCREEN, TFT_BLACK);
    loadFont(FONT_60);
    drawCentreString(" " + String(_currentDate.toString(timeFormat)) + " ", 160, 80, 1);
    loadFont(FONT_36);
    drawCentreString(" " + dayOfTheWeek + " " + (_currentDate.toString(dateFormat)), 160, 140, 1);
  }
}

void MyTFT::displayBackGround(unsigned int color, boolean refreshDisplay)
{
  if (refreshDisplay)
  {
    fillRect(0, 0, 319, 31, color);
    drawRect(0, 0, 319, 240, color);
    fillRect(1, 32, 317, 207, TFT_BLACK);
  }
}

void MyTFT::displayData(unsigned int color, String testToDisplay)
{
  setTextColor(color, TFT_BLACK);
  loadFont(FONT_60);
  drawCentreString(testToDisplay, 160, 120, 1);
}

void MyTFT::displayDateTime(
    DateTime date,
    unsigned int backgroundColor,
    boolean refreshDisplay)
{
  if (_currentDate.minute() != date.minute() || refreshDisplay)
  {
    _currentDate = date;
    char dateTimeFormat[] = "DD/MM/YYYY hh:mm";
    setTextColor(TFT_BLACK, backgroundColor);
    loadFont(FONT_24);
    drawCentreString(" " + String(_currentDate.toString(dateTimeFormat)) + " ", 160, 6, 1);
  }
}