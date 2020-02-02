/*
 * @file i2.c
 * @author xpress_embedo
 * @date 1 Feb, 2020
 * 
 * @brief Main File of the Project
 *
 */

#include "main.h"
#include "OLED.h"

/* Local Variables */
static uint32_t millisecond = 0;
const uint8_t bank[1024] = {
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128,   0,  64, 128,   0,  98,  68,   8,  16,   0, 128,  72, 132,   0,   0,  96,  32,   0, 192,  64,   0, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128,  16, 132, 121,   4,   3,   1, 128,   0,   0,   0,   0,   0,   0,   0,  24,  23,  16,   0,   0,   0,  32,  32,  64, 128, 128,   1,  34, 156, 112, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128,   0,  64, 192,   0,  96,  64,  16,  64,  96,  32, 128,  64,   0, 128,   0,   0,   0,   0,   0,   0,  32,  16,   0,   0,   0,   4,   0,   0,   0,   3,   0,   3,   0,   4,   4,   6,   8,  16, 112, 192,   0,   0,   0,   0,   0,   0,   0,   0, 128,  32,   0,   0,   8,   1,   7,   6,   4,   6,   4,   7,   4,   4,   0,   8,   8,  16, 112, 192,   0,   0,   0,   0,   0,   0,   0,   0, 240,   0,   0, 122, 122,   0,  64,   0,   2,   0,   4, 248,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   0, 128, 128,   0,  64, 128,   0,  96, 128,  48,  96,  24,  24,  32,  12,  20,  18,   6,  12,   3,   7,   4,   3,   3,  26,   1,  31, 125,  60,  60,  60, 125,  25,   6,   2,   3,   5,   4,   2,   9,  12,   6,  18,  10,  36,  48,  64,  96,  48, 192, 192,  32, 160, 192,  64,  16, 144,   0,   8,   8,   4,   6,   1,   0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   0,   0,   0,   0,   0,   0,  32,  32,  32,  32,  32,   0,  16,  16,   8,  12,   6,   3, 128, 128, 128,   0,   0, 192, 192, 128, 255,   0,   0,   7,  69,   8, 192, 135,   0,   0, 128, 255,   8, 224, 240, 240, 224, 192, 192, 128,   0,   0,   0,   0,   0,   0,
  0,   0,   0,   1,   1,   1, 129,   1,  63,  33,  33,  33,  33, 123,  63,  37,  37,  37,  63, 187,  33,  33,  33,  57,  37,  35, 163,  39,  47,  61,  57,  49,  33,  35,  63,  39,  37,  45,  57,  57,  63,  63,  33,  33,  59, 127,  63,  37,  37,  37,  47,  59,  57,  49, 225,  33,  33,  33,  33,  63,  33,   1, 192,   0, 224,  32,  32,   0,   0,   0,  48,  48,  32,   0, 136, 152, 152,  16, 128, 140,  76,  72,  64,   0, 198, 230,  36,  32,   0,   3, 227, 242,  16,  16,   1,   1,   9, 248, 248,   0,   0,   4, 255,   0,   0, 141, 136, 152, 144,  61,   1,   0, 218, 255,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 254, 252, 252, 248,
  0,   0,   0,   0,   0,   0,   0,   0, 255,   0,   0,   0,   0, 255,  86,   0,   0,   0,   0, 255,   0,   0,   0,   0, 255, 255,  16, 172, 244,  62,  37,  39,  35,  34,  34, 226,  34,  34,  34,  35,  37,  38,  58, 228, 248,   0, 255, 255,   0,   0,   0, 255, 255,   0,   0, 255,   0,   0,   0,   0,   0,   0,   0,   0, 255,   2,   0,   0, 127,  65,  65,   0,  63,  63,   0,   0,  32,  32,  63,  63,   0, 128, 128, 128, 159, 159, 144, 144, 128, 128, 143, 143, 136,   8,  72,  72,  64, 199,  71, 192, 192,   4,  15,   0,  16,   5,  33,  34,  38,  32,  48,   0,  15,   6,   0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  0,   0,   0,   0,   0,   0,  64,  64, 127,  64,  64,  64,  64, 127, 107,  64,  64,  64,  64, 127,  64,  64,  64,  64, 127, 127,  64,  84, 127,  64,  64,  64,  64,  64,  64, 127,  64,  64,  64,  64,  64,  64,  64, 127, 127,  64, 127, 127,  64,  64,  64, 127, 127,  64,  64, 127,  64,  64,  64,  64,  64,  64,  64, 240, 255,   0,   0,   0,   0,   1,   1,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255,  64, 255, 255,   0,  16,  16,  16,  16,  16,  16,  16, 255,   0, 255, 255,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 255,  63, 255,  15, 255, 255, 255, 255, 255, 255, 255, 255, 255,
  0,   0,   0,   0,   0,   0,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   6,   0,   0,   0,   0,   0,  63,  43,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  47,  32,  63,  63,  32,  32,  32,  32,  32,  32,  32,  32,  63,  32,  47,  47,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  40,  63,  32,  32,  32,  47,  63,  47,  47,  63,  63,  63,  63,  63
};

const uint8_t house[1024] = {
  0,   0,   0,   0,   4,  10,  58,  62, 122, 210, 208, 208, 208, 208, 208,  48, 188,  60, 172, 172, 246, 247, 255, 110, 254, 190, 126, 126,  92, 152,  96,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 128, 128,   0, 129, 129, 141, 143, 136, 192,  80, 208, 200,   8,   8, 140,  12,  58,  58,  71, 130, 135,   0, 161, 208, 112, 240, 160, 166, 166, 153, 139, 142, 141, 143,  15,  27,  23,  23,  27,  15,  15, 143, 190, 187, 191, 159, 204, 140, 143, 246, 246, 246, 230, 189, 255, 177, 189, 238, 195,  76,   0,   0,
  0,   0,   0,   0,   0,   0,   0,  24,  28, 222, 126, 123,  57,  63, 125, 120,  15,  15,   3,   3,  65, 193, 225, 193, 192, 192,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  98,  99,  29, 153, 192,  66, 199, 132, 132, 133, 135,   0,   0, 128,  80, 120,  81, 113, 118, 126,  63,  31,  22, 227, 253, 248, 224, 192, 193, 194, 194, 194, 195, 129,   0,   1, 131, 131, 191, 191, 230, 234, 234, 188, 248, 241, 195,  66,  71, 129, 133, 133, 174, 255, 255, 247, 255, 255, 254, 254, 255, 251, 253, 210, 208,   0,   0,
  0,   0,   0,   0,  32,  60,  52, 247, 254, 241, 245, 239, 255, 188, 182, 254, 252, 230, 243, 233, 247, 151, 153, 255, 247, 243, 223, 221, 252, 120, 120, 248, 104, 120, 248, 112, 112,  48,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  16,  17,  17,  17,  17,  16,  16,  16,  16,  16,  16,  16,  16,  16,  31,  31,  31,  31,  17,  17,  17,  17,  17,  17,  17,  18,  18,  25,  25,  44,  15,  31,  63,  63, 111, 127,  58,  63, 119, 119, 255, 191,  53,  22,  31,  11,  31,  31,  47,  63,  63, 255, 207, 255, 255,  47,  37,   0,
  0,   0,   0,   0,   0,   0,  32, 251, 255, 255, 255, 255, 255, 131, 129, 193, 227, 227,  51,  55, 229, 199,   7,  15,  11,  27,  31,  28,  56, 240,  96,  96,  97,  97,  97,  97,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96, 224,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  96,  97,  99,  98, 102, 108, 248, 240,  96,  96,   0, 255, 255, 255, 255,   0,   0,   0,
  0,   0,   0,   0,   2,  23,  29,  33,  33, 255, 255, 255, 255, 167, 167,  58,  24, 120, 248, 232, 121, 123, 122, 158, 144,   0, 252, 158, 159, 127,  96, 128,  14,  10,  10,  10,  10,  10,  10,  14,   0,   0,   0,  14,  10,  10,  10,  10,  10,  14,  14,   0,   0, 128, 255, 248, 232, 192, 192, 254, 254, 254,  34,  34,  34,  34,  34,  34, 254,  34,  34,  34,  34,  34,  34,  34, 254, 254, 254,  50,   0,   0,   0, 254, 130, 186,  58,  58,  98,  98,  98,  98,   2, 254,   0,   0,   0, 254, 254, 254, 254,  34,  34,  34,  34, 254, 254,  34,  34,  34,  34,  34, 254, 254, 254, 224, 127, 255, 194, 222, 126, 255, 255, 255, 255,   0,   0,   0,
  0,   0,   0,   0,   0, 128, 128, 128,  96, 191, 255, 127, 255, 255, 225, 195, 207, 140, 137,   8,   8,   8,   8,  25,  63,  59,  11,  79,  79,  73, 233, 254, 168, 160, 160,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  32,  60,  63,  39,  47,  63,  63, 125,  73,   9, 225,  64,  72, 120, 120, 120, 121,  73,  65,  77,  81,  25, 121,  73, 121,  49, 113,  73,  73, 200, 200, 120, 127,  80,  81,  64,  64,  64,  80,  80, 240, 224, 127,  24, 152, 144, 201, 233, 249, 249,  56, 136,   8, 144, 241, 121, 120, 160, 248, 240, 112,   9, 121,  63, 127, 120, 104,  77,  76, 124, 255, 255, 255, 255, 248,   0,   0,
  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   3,   3,   3,   6,   6,  12,  12,  24,  24,  16,  48,  32,  96,  96, 192, 192, 128, 128,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   0,   2,   2,   6,   6,   0,   0,   4,   0,   0,   2,   2,  34,  98,  98, 208, 209, 145, 145,  16,  16,  16,   8,   8,   8,   4,   6,   2,   1,   1,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0, 128, 128, 192, 192, 224, 224, 248, 231, 239, 255, 119,  67,   0,   0,
  0,   0,   0,   0,   0,   0,   0, 128, 128,   0, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192,  64,  64,  64,  64,  64,  64,  64,  64,  64,  64,  64,  64,  64,  64,  64,  64,  64,  64,  96,  64,  64,  65,  65,  99,  99,  98, 102, 102, 108, 108, 120, 120, 120, 112, 112,  32,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   1,   1,   1,   3,   2,   6,   6,  12,  12,  24,  24,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  48,  16,  16,   0,   0,   0,   0,   0,   0
};

/* Local Function */
void timer0_init( void );
void system_init( void );
void test_draw_lines( void );
void test_draw_v_h_lines( void );
void test_draw_rectangles( void );
void test_draw_circles( void );
void test_text_display( void );
void test_images( void );

/* Start From Here*/
void main(void) 
{
  uint32_t timestamp = 0;
  system_init();
  OLED_ClearDisplay();
  OLED_Update();
  Delay_ms(1000);
  OLED_FillDisplay();
  OLED_Update();
  Delay_ms(1000);
  OLED_ClearDisplay();
  // Draw Single Pixel
  OLED_DrawPixel(10, 10, WHITE);
  OLED_Update();
  Delay_ms(1000);
  OLED_ClearDisplay();

  // Draw Many Lines
  test_draw_lines();
  OLED_Update();
  Delay_ms(1000);
  OLED_ClearDisplay();

  // Draw Vertical and Horizontal Lines
  test_draw_v_h_lines();
  OLED_Update();
  Delay_ms(1000);
  OLED_ClearDisplay();

  // Draw Rectangles
  test_draw_rectangles();
  OLED_Update();
  Delay_ms(1000);
  OLED_ClearDisplay();

  // Draw Circles
  test_draw_circles();
  OLED_Update();
  Delay_ms(1000);
  OLED_ClearDisplay();

  // Text
  test_text_display();
  OLED_Update();
  Delay_ms(1000);
  OLED_ClearDisplay();
  OLED_Update();

  // Image
  while(1)
  {
    test_images();
    OLED_Update();
  }
  return;
}

/* Function Definitions */

/**
 * @breif Initialize the system
 */
void system_init( void )
{
  // Initialize 1ms Timer
  timer0_init ();
  // Initialize OLED
  OLED_Init ();
  Delay_ms(100);
}

/**
 * @brief Counts milliseconds till startup
 * @return This function returns the number of milliseconds elapsed till the 
 * system is powered up.
 */
uint32_t millis( void )
{
  uint32_t time = 0;
  GIE = 0;
  time = millisecond;
  GIE = 1;
  return time;
}

/**
 * @brief Initialize Timer0 Module to generate 1ms interrupt
 */
void timer0_init( void )
{
  // Code Generated Using mikroC Timer Calculator
  T0CON	= 0x88;
  TMR0H	= 0xD1;
  TMR0L = 0x20;
  ENABLE_INT();
  TMR0IE = 1;
}

/**
 * PIC18F Interrupt Service Routine
 */
void __interrupt() ISR_ROUTINE( void )
{
  if( TMR0IF )
  {
    TMR0IF = 0;
    TMR0H	= 0xD1;
    TMR0L = 0x20;
    millisecond++;
  }
}

void test_draw_lines( void )
{
  uint8_t i;
  for ( i=0; i<OLED_Width(); i+=4)
  {
    OLED_Line(0, 0, i, OLED_Height()-1, WHITE);
    OLED_Update();
  }
  for ( i=0; i<OLED_Height(); i+=4 )
  {
    OLED_Line(0, 0, OLED_Width()-1, i, WHITE);
    OLED_Update();
  }
}

void test_draw_v_h_lines( void )
{
  uint8_t i;
  // Horizontal lines test
  for( i=0; i< OLED_Height(); i+=4 )
  {
   OLED_H_Line(0, OLED_Width()-1, i, WHITE);
   OLED_Update();
  }
  Delay_ms(1000);
  OLED_ClearDisplay();
  OLED_Update();
  // Vertical lines test
  for( i=0; i< OLED_Width(); i+=4 )
  {
    OLED_V_Line(0, OLED_Height()-1, i, WHITE);
    OLED_Update();
  }
}

void test_draw_rectangles( void )
{
  uint8_t i;
  for ( i=0; i<OLED_Height()/2; i+=2)
  {
    OLED_Rectangle(i, i, OLED_Width()-1-i, OLED_Height()-1-i, WHITE);
    OLED_Update();
    Delay_ms(250);
  }
  Delay_ms(1000);
  OLED_ClearDisplay();
  OLED_Update();
  for( i=OLED_Height()/2; i>0; i-- )
  {
    OLED_Rectangle(i,i, OLED_Width()-i, OLED_Height()-i, WHITE );
  }
}

void test_draw_circles( void )
{
  uint8_t i;
  for( i=0; i<OLED_Width()/2; i+=5 )
  {
    OLED_Circle(OLED_Width()/2, OLED_Height()/2, i , WHITE);
    OLED_Update();
  }
}

void test_text_display( void )
{
  OLED_SetFont( SMALL_FONTS );
  OLED_Write_Text(0,0,"ABCDEFGHIJKLMNOPQRSTU");
  OLED_Write_Text(0,8,"VWXYZ0123456789~!@#$%");
  OLED_Update();
  Delay_ms(1000);
  OLED_Write_Text(0,16,"abcdefghijklmnopqrstu");
  OLED_Write_Text(0,24,"vwxyz");
  OLED_Update();
  OLED_ClearDisplay();
  Delay_ms(1000);
  OLED_SetFont( TINY_FONTS );
  OLED_Write_Text(0,0,"ABCDEFGHIJLKLMNOPQRSTUVWXYZ");
  OLED_Write_Text(0,8,"abcdefghijklmnopqrstuvwxyz");
  OLED_Write_Text(0,16,"0123456789");
  OLED_Update();
  Delay_ms(1000);
  OLED_ClearDisplay();
  OLED_Update();
}

void test_images( void )
{
  OLED_Image(bank);
  OLED_Update();
  Delay_ms(1000);
  OLED_InvertDisplay(TRUE);
  OLED_Update();
  Delay_ms(1000);
  OLED_InvertDisplay(FALSE);

  OLED_Image(house);
  OLED_Update();
  Delay_ms(1000);
  OLED_InvertDisplay(TRUE);
  OLED_Update();
  Delay_ms(1000);
  OLED_InvertDisplay(FALSE);
  Delay_ms(1000);
}
