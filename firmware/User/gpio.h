#ifndef __GPIO_H
#define __GPIO_H

#include "ch32v20x_gpio.h"
#include "ch32v20x_rcc.h"

#define RB_Pin GPIO_Pin_2
#define RB_GPIO_Port GPIOA

#define LB_Pin GPIO_Pin_6
#define LB_GPIO_Port GPIOA

#define MB_Pin GPIO_Pin_1
#define MB_GPIO_Port GPIOA

#define RHQ_Pin GPIO_Pin_3
#define RHQ_GPIO_Port GPIOA

#define LVQ_Pin GPIO_Pin_4
#define LVQ_GPIO_Port GPIOA

#define BH_Pin GPIO_Pin_5
#define BH_GPIO_Port GPIOA

#define FV_Pin GPIO_Pin_7
#define FV_GPIO_Port GPIOA


void GPIO_Config();


#endif
