#include <Arduino.h>
#include <U8glib.h>
#include <DHT.h>

#define led13 13
int counter = 0;
float temperature = 0;
float humidity = 0;
U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

void setup()
{
  pinMode(led13, OUTPUT);
}

void loop()
{
  digitalWrite(led13,HIGH);
  delay(1000);
  digitalWrite(led13,LOW);
  delay(500);
  counter++;
  oled.firstPage();
  do
  {
    ReadSensor(&temperature, &humidity);
    UpdateDisplay(temperature, humidity);
  }while(oled.nextPage());
}

void ReadSensor(float * temp, float * hum)
{
  *temp = dht.readTemperature();
  *hum = dht.readHumidity();  
}

void UpdateDisplay(float temp, float hum)
{
  char charBuf[50];
  oled.setFont(u8g_font_helvB10);
  oled.drawStr(0,12,"Temperature C:");
  
  oled.setFont(u8g_font_helvB12);
  dtostrf(temp,5,2,charBuf);
  oled.drawStr(0,30,charBuf);

  oled.setFont(u8g_font_helvB10);
  oled.drawStr(0,44,"Humidity %");

  oled.setFont(u8g_font_helvB12);
  dtostrf(hum,5,2,charBuf);
  oled.drawStr(0,64,charBuf);
}
