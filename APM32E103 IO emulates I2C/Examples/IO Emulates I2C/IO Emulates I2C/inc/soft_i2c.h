#ifndef __SOFT_I2C_H
#define __SOFT_I2C_H

#include "main.h"

#define I2Cx_SCL_PIN                     GPIO_PIN_6
#define I2Cx_SCL_GPIO_PORT               GPIOB
#define I2Cx_SCL_GPIO_CLK                RCM_APB2_PERIPH_GPIOB

#define I2Cx_SDA_PIN                     GPIO_PIN_7
#define I2Cx_SDA_GPIO_PORT               GPIOB
#define I2Cx_SDA_GPIO_CLK                RCM_APB2_PERIPH_GPIOB


/** @defgroup I2C_library_exported_functions
  * @{
  */

void     i2c_config         (void);

uint8_t i2c_master_transmit (uint16_t address, uint8_t* pdata, uint16_t size);
uint8_t i2c_master_receive  (uint16_t address, uint8_t* pdata, uint16_t size);
         
uint8_t i2c_memory_write    (uint16_t address, uint16_t mem_address, uint8_t* pdata, uint16_t size);
uint8_t i2c_memory_read     (uint16_t address, uint16_t mem_address, uint8_t* pdata, uint16_t size);



#endif
















