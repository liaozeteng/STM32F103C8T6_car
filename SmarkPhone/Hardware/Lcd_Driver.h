//  功能描述   : 1.8寸LCD 4接口演示例程(STM32系列)
/******************************************************************************
//本程序适用与STM32F103C8
//              GND   电源地
//              VCC   接5V或3.3v电源
//              SCL   接PA5（SCL）
//              SDA   接PA7（SDA）
//              RES   接PA1
//              DC    接PA2
//              CS    接PA4 
//							BL		接PA3
*******************************************************************************/
#include "stm32f1xx_hal.h"

#define RED  		0xf800
#define GREEN		0x07e0
#define BLUE 		0x001f
#define WHITE		0xffff
#define BLACK		0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D   	//灰色0
#define GRAY1   0x8410    //灰色1
#define GRAY2   0x4208    //灰色2

#define LCD_CTRLA   	  GPIOA		//定义TFT数据端口
#define LCD_CTRLB   	  GPIOB		//定义TFT数据端口

#define LCD_SCL        	GPIO_Pin_5	//PB13--->>TFT --SCL/SCK
#define LCD_SDA        	GPIO_Pin_7	//PB15 MOSI--->>TFT --SDA/DIN
#define LCD_CS        	GPIO_Pin_4  //MCU_PB11--->>TFT --CS/CE

#define LCD_LED        	GPIO_Pin_10  //MCU_PB9--->>TFT --BL
#define LCD_RS         	GPIO_Pin_1	//PB11--->>TFT --RS/DC
#define LCD_RST     		GPIO_Pin_0	//PB10--->>TFT --RST

//#define LCD_CS_SET(x) LCD_CTRL->ODR=(LCD_CTRL->ODR&~LCD_CS)|(x ? LCD_CS:0)

//液晶控制口置1操作语句宏定义
/*
#define	LCD_SCL_SET  	LCD_CTRLA->BSRR=LCD_SCL    
#define	LCD_SDA_SET  	LCD_CTRLA->BSRR=LCD_SDA   
#define	LCD_CS_SET  	LCD_CTRLA->BSRR=LCD_CS  
*/
#define	LCD_LED_SET  	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_SET)//BLK
#define	LCD_RS_SET  	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_SET)//DC
#define	LCD_RST_SET  	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_SET)//RST

//液晶控制口置0操作语句宏定义
/*
#define	LCD_SCL_CLR  	LCD_CTRLA->BRR=LCD_SCL  
#define	LCD_SDA_CLR  	LCD_CTRLA->BRR=LCD_SDA 
#define	LCD_CS_CLR  	LCD_CTRLA->BRR=LCD_CS 
*/    
#define	LCD_LED_CLR  	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_RESET)//BLK
#define	LCD_RST_CLR  	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET)//RST
#define	LCD_RS_CLR  	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_2,GPIO_PIN_RESET)//DC

#define LCD_DATAOUT(x) LCD_DATA->ODR=x; //数据输出
#define LCD_DATAIN     LCD_DATA->IDR;   //数据输入

#define LCD_WR_DATA(data){\
LCD_RS_SET;\
LCD_CS_CLR;\
LCD_DATAOUT(data);\
LCD_WR_CLR;\
LCD_WR_SET;\
LCD_CS_SET;\
} 

//void LCD_GPIO_Init(void);
void Lcd_WriteIndex(uint8_t Index);
void Lcd_WriteData(uint8_t Data);
void Lcd_WriteReg(uint8_t Index,uint8_t Data);
uint16_t Lcd_ReadReg(uint8_t LCD_Reg);
void Lcd_Reset(void);
void Lcd_Init(void);
void Lcd_Clear(uint16_t Color);
void Lcd_SetXY(uint16_t x,uint16_t y);
void Gui_DrawPoint(uint16_t x,uint16_t y,uint16_t Data);
unsigned int Lcd_ReadPoint(uint16_t x,uint16_t y);
void Lcd_SetRegion(uint16_t x_start,uint16_t y_start,uint16_t x_end,uint16_t y_end);
void LCD_WriteData_16Bit(uint16_t Data);

