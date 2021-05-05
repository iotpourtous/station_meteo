#include "MyTFT.h"

void MyTFT::init() {
  TFT_eSPI::init();
  setRotation(1);
}

void MyTFT::afficheHeure(DateTime heure, String dayOfTheWeek, boolean full)
{
  char dateTimeFormat[] = "DD/MM/YYYY hh:mm";
  Serial.println("currentDatetime : " + String(heure.toString(dateTimeFormat)));
  setTextColor(TFT_BLACK, TFT_WHITE);
  if (!full)
  {
    loadFont("Metal-Up-Your-Ear-24");
    drawCentreString(" " + String(heure.toString(dateTimeFormat)) + " ", 160, 6, 1);
  }
  else
  {
    char dateFormat[] = "DD/MM/YYYY";
    char timeFormat[] = "hh:mm";
    fillScreen(TFT_BLACK);
    setTextColor(TFT_YELLOW, TFT_BLACK);
    loadFont("Metal-Up-Your-Ear-48");
    drawCentreString(" " + String(heure.toString(timeFormat)) + " ", 160, 80, 1);
    loadFont("Metal-Up-Your-Ear-36");
    drawCentreString(" " + dayOfTheWeek + " " + (heure.toString(dateFormat)), 160, 140, 1);
  }
}

void MyTFT::afficheTemperature(String temperature, boolean full)
{
  Serial.println("currentTemperature : " + temperature + "°C");
  setTextColor(TFT_RED, TFT_BLACK);
  if (!full)
  {
    loadFont("Metal-Up-Your-Ear-48");
    drawCentreString(" " + temperature + "C ", 160, 60, 1);
  }
  else
  {
    loadFont("Metal-Up-Your-Ear-48");
    fillRect(1, 32, 317, 207, TFT_BLACK);
    drawCentreString(" " + temperature + "C ", 160, 120, 1);
  }
}

void MyTFT::afficheHumidite(String humidite, boolean full)
{
  Serial.println("currentHumidity : " + humidite + "%");
  setTextColor(TFT_BLUE, TFT_BLACK);
  if (!full)
  {
    loadFont("Metal-Up-Your-Ear-48");
    drawCentreString(" " + humidite + "% ", 160, 120, 1);
  }
  else
  {
    loadFont("Metal-Up-Your-Ear-48");
    fillRect(1, 32, 317, 207, TFT_BLACK);
    drawCentreString(" " + humidite + "% ", 160, 120, 1);
  }
}

void MyTFT::affichePression(String pressure, boolean full)
{
  Serial.println("currentPressure : " + pressure + "hPa");
  setTextColor(TFT_GREEN, TFT_BLACK);

  if (!full)
  {
    loadFont("Metal-Up-Your-Ear-48");
    drawCentreString(" " + pressure + "hPa ", 160, 180, 1);
  }
  else
  {
    loadFont("Metal-Up-Your-Ear-48");
    fillRect(1, 32, 317, 207, TFT_BLACK);
    drawCentreString(" " + pressure + "hPa ", 160, 120, 1);
  }
}

void MyTFT::afficheHeader(DateTime currentDate)
{
  fillRect(0, 0, 319, 31, TFT_WHITE);
  drawRect(0, 31, 319, 209, TFT_WHITE);
  afficheHeure(currentDate);
}

void MyTFT::afficheEcranAccueil(
    DateTime currentDate,
    float currentTemperature,
    float currentHumidity,
    int currentPressure)
{

  loadFont("Metal-Up-Your-Ear-24");
  setTextColor(TFT_WHITE, TFT_BLACK);
  fillScreen(TFT_BLACK);
  afficheHeader(currentDate);
  afficheTemperature((String)(currentTemperature));
  afficheHumidite((String)(currentHumidity));
  affichePression((String)(currentPressure));
}
/*
TFT_eSPI tft = TFT_eSPI();


void init() {
    
  tft.init();
  tft.setRotation(1);
}

void afficheHeure(DateTime heure, String dayOfTheWeek, boolean full)
{
  char dateTimeFormat[] = "DD/MM/YYYY hh:mm";
  Serial.println("currentDatetime : " + String(heure.toString(dateTimeFormat)));
  tft.setTextColor(TFT_BLACK, TFT_WHITE);
  if (!full)
  {
    tft.loadFont("Metal-Up-Your-Ear-24");
    tft.drawCentreString(" " + String(heure.toString(dateTimeFormat)) + " ", 160, 6, 1);
  }
  else
  {
    char dateFormat[] = "DD/MM/YYYY";
    char timeFormat[] = "hh:mm";
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_YELLOW, TFT_BLACK);
    tft.loadFont("Metal-Up-Your-Ear-48");
    tft.drawCentreString(" " + String(heure.toString(timeFormat)) + " ", 160, 80, 1);
    tft.loadFont("Metal-Up-Your-Ear-36");
    tft.drawCentreString(" " + dayOfTheWeek + " " + (heure.toString(dateFormat)), 160, 140, 1);
  }
}

void afficheTemperature(String temperature, boolean full)
{
  Serial.println("currentTemperature : " + temperature + "°C");
  tft.setTextColor(TFT_RED, TFT_BLACK);
  if (!full)
  {
    tft.loadFont("Metal-Up-Your-Ear-48");
    tft.drawCentreString(" " + temperature + "C ", 160, 60, 1);
  }
  else
  {
    tft.loadFont("Metal-Up-Your-Ear-48");
    tft.fillRect(1, 32, 317, 207, TFT_BLACK);
    tft.drawCentreString(" " + temperature + "C ", 160, 120, 1);
  }
}

void afficheHumidite(String humidite, boolean full)
{
  Serial.println("currentHumidity : " + humidite + "%");
  tft.setTextColor(TFT_BLUE, TFT_BLACK);
  if (!full)
  {
    tft.loadFont("Metal-Up-Your-Ear-48");
    tft.drawCentreString(" " + humidite + "% ", 160, 120, 1);
  }
  else
  {
    tft.loadFont("Metal-Up-Your-Ear-48");
    tft.fillRect(1, 32, 317, 207, TFT_BLACK);
    tft.drawCentreString(" " + humidite + "% ", 160, 120, 1);
  }
}

void affichePression(String pressure, boolean full)
{
  Serial.println("currentPressure : " + pressure + "hPa");
  tft.setTextColor(TFT_GREEN, TFT_BLACK);

  if (!full)
  {
    tft.loadFont("Metal-Up-Your-Ear-48");
    tft.drawCentreString(" " + pressure + "hPa ", 160, 180, 1);
  }
  else
  {
    tft.loadFont("Metal-Up-Your-Ear-48");
    tft.fillRect(1, 32, 317, 207, TFT_BLACK);
    tft.drawCentreString(" " + pressure + "hPa ", 160, 120, 1);
  }
}

void afficheHeader(DateTime currentDate)
{
  tft.fillRect(0, 0, 319, 31, TFT_WHITE);
  tft.drawRect(0, 31, 319, 209, TFT_WHITE);
  afficheHeure(currentDate);
}

void afficheEcranAccueil(
    DateTime currentDate,
    float currentTemperature,
    float currentHumidity,
    int currentPressure)
{

  tft.loadFont("Metal-Up-Your-Ear-24");
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.fillScreen(TFT_BLACK);
  afficheHeader(currentDate);
  afficheTemperature((String)(currentTemperature));
  afficheHumidite((String)(currentHumidity));
  affichePression((String)(currentPressure));
}
*/