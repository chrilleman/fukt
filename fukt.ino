#include <Arduino.h>
#include <U8glib.h>

#define led13 13
U8GLIB_SSD1306_128X64 oled(U8G_I2C_OPT_NONE);
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

  oled.firstPage();
  do
  {
    UpdateDisplay(23.4,54.3);
  }while(oled.nextPage());
}

void UpdateDisplay(double temp, double hum)
{
  oled.setFont(u8g_font_helvB10);
  oled.drawStr(0,12,"Temperature");
  char charBuf[50];
  
  oled.setFont(u8g_font_helvB18);
  sprintf(charBuf, "%d degC",temp);
  oled.drawStr(0,36,charBuf);
  //str.toCharArray(charBuf,50);
  //oled.drawLine(0,15,127,15);
  
  //char h[] = "0.0";
  //oled.drawStr(0,32,"Humidity: ");
  //oled.drawLine(0,35,127,35);
  
  
}
