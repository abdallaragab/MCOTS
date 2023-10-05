/*
  * File:  TFT_Config.h 
 *	SWC:    TFT
 *	Version: 1.0 
 *  Created on: 27-06-2023 
 *  Author: Abdallah Ragab 
 */
#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H


//reset pin
#define TFT_RES		GPIO_u8PortA,GPIO_Pin3

//chip select pin
#define TFT_CSX		GPIO_u8PortA,GPIO_Pin1

//serial clock pin
#define TFT_SCL		GPIO_u8PortA,GPIO_Pin5

// D0 pin
#define TFT_SDA		GPIO_u8PortA,GPIO_Pin7

//command/parameter selection pin
#define TFT_WRX		GPIO_u8PortA,GPIO_Pin2





#endif // TFT_CONFIG_H
