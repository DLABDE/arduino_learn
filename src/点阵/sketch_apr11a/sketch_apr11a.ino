#include "LedControl.h"

/*
 pin 2 is connected to the DataIn 
 pin 4 is connected to the CLK 
 pin 3 is connected to LOAD 
 */
LedControl lc=LedControl(2,4,3,1);//共一个设备
char k=0;
void setup() {
  lc.shutdown(0,false);//关闭第0个设备的节电模式
  lc.setIntensity(0,1);//第0个设备的亮度（0-15）
  lc.clearDisplay(0);//清屏
}


void loop() { 
  byte a[2]={B00000000,B00000000};
  byte b[2]={B01100110,B00000000};
  byte c[2]={B11111111,B00100100};
  byte d[2]={B11111111,B01111110};
  byte e[2]={B11111111,B01111110};
  byte f[2]={B01111110,B00111100};
  byte g[2]={B00111100,B00011000};
  byte h[2]={B00011000,B00000000};
  for(char i=0;i<2;i++)
  {
    lc.setIntensity(0,1);
    if(i)
      lc.setIntensity(0,8);
    lc.setRow(0,0,a[i]);//设置行，第0的设备，第0行
    lc.setRow(0,1,b[i]);
    lc.setRow(0,2,c[i]);
    lc.setRow(0,3,d[i]);
    lc.setRow(0,4,e[i]);
    lc.setRow(0,5,f[i]);
    lc.setRow(0,6,g[i]);
    lc.setRow(0,7,h[i]);
    if(k==3)
    {
      delay(370);
      k=0;
    }
    else
    {
      delay(170);
      k++;
    }
  }
}
