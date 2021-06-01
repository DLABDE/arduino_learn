#include "FastLED.h" 

   
//配置       
#define NUM_LEDS 60             // LED灯珠数量
#define DATA_PIN 6              // Arduino输出控制信号引脚
#define LED_TYPE WS2812         // LED灯带型号
#define COLOR_ORDER GRB         // RGB灯珠中红色、绿色、蓝色LED的排列顺序
uint8_t max_bright =20;       // LED亮度控制变量，可使用数值为 0 ～ 255

#define twinkleInterval  15    //  闪烁间隔时间 (毫秒)
#define twinkleChance 150        //  闪烁数量，数值越大闪烁越多（0-255）



//初始化
CRGB leds[NUM_LEDS];            // 建立光带leds
void setup() { 
  LEDS.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);  // 初始化光带 
  FastLED.setBrightness(max_bright);                            // 设置光带亮度
}



//用户
void user_make()
{
  fill_palette (leds, 60, 0, 8, HeatColors_p, 255, LINEARBLEND );  
}


//说明
  /*基本控制*/
  
  /*设置单个灯
  leds[0] = CRGB::Green;          // 设置光带中第一个灯珠颜色为红色，leds[0]为第一个灯珠，leds[1]为第二个灯珠
或者
  leds[0].r = 255;     // 将光带上第1个LED灯珠的RGB数值中R数值设置为255
  leds[0].g = 125;     // 将光带上第1个LED灯珠的RGB数值中G数值设置为255
  leds[0].b = 0;       // 将光带上第1个LED灯珠的RGB数值中B数值设置为0

  设置整体颜色
  fill_solid(leds, 30, CRGB::Red);//将leds光带的从头数30个灯珠设置为红颜色。
  fill_solid(leds+5, 3, CRGB::Red);//将leds光带的从头数第6个灯珠开始算起的3个灯珠设置为红颜色。

  彩虹
  fill_rainbow(leds, 30, beginHue, deltaHue);//将leds光带的从头数30个灯珠设置为渐变彩虹色。beginHue参数为起始色调数值。deltaHue为相邻LED灯珠色调差。
  fill_rainbow(leds+5, 30, 0, 1);//将leds光带的从头数30个灯珠设置为渐变彩虹色。起始色调数值为0。相邻LED灯珠色调差为1。

  渐变色
  fill_gradient_RGB(leds, 0, CRGB::Red, 29, CRGB::Blue)
  将leds光带的从头数30个灯珠设置为渐变色。灯带头部起始颜色为红色。灯带尾部结束颜色为蓝色。灯带中间为由红色到蓝色的渐变色。
  
  fill_gradient(leds, 0, CHSV(50, 255,255) , 29, CHSV(150,255,255), SHORTEST_HUES)
  将leds光带的从头数30个灯珠设置为渐变色。灯带头部起始颜色为HSV(50, 255,255)色彩。灯带尾部结束颜色为CHSV(150,255,255)色彩。灯带颜色过度采用短色调过渡方式。
  
  fill_gradient(leds, 0, CHSV(50, 255,255) , 29, CHSV(150,255,255), LONGEST_HUES)
  将leds光带的从头数30个灯珠设置为渐变色。灯带头部起始颜色为HSV(50, 255,255)色彩。灯带尾部结束颜色为CHSV(150,255,255)色彩。灯带颜色过度采用长色调过渡方式。


  使用色板
  fill_palette (leds, 30, 0, 8, OceanColors_p, 255, LINEARBLEND )
  将leds光带的从头数30个灯珠设置为渐变色。渐变色的色彩全部来自FastLED预设色板OceanColors_p。
  灯带头部第一个灯珠的色板色彩序号为0，相邻的两个灯珠见色板色彩序列号差8。色彩过渡为线性过渡效果。
  //系统预设版
    CloudColors_p
    LavaColors_p
    OceanColors_p
    ForestColors_p
    RainbowColors_p
    RainbowStripeColors_p
    PartyColors_p
    HeatColors_p
  
  */



//执行
void loop() { 
  user_make();
  FastLED.show();                // 更新LED色彩
  //delay(5);                     // 等待500毫秒
}
