/*!
 * @file        main.c
 *
 * @brief       Main program body
 *
 * @version     V1.0.0
 *
 * @date        2021-07-26
 *
 */

#include "main.h"
#include "soft_i2c.h"

/* delay macros */
#define STEP_DELAY_MS                    50


/* delay variable */
static __IO uint32_t fac_us;
static __IO uint32_t fac_ms;


#define BUF_SIZE                         8
#define TEST_1
//#define TEST_2

uint8_t tx_buf[BUF_SIZE] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
uint8_t rx_buf[BUF_SIZE] = {0};

/**
  * @brief  error handler program
  * @param  i2c_status
  * @retval none
  */
void error_handler(void)
{
  while(1)
  {
    APM_MINI_LEDInit(LED3);
    delay_ms(500);
  }
}

/**
  * @brief  compare whether the valus of buffer 1 and buffer 2 are equal.
  * @param  buffer1: buffer 1 address.
            buffer2: buffer 2 address.
  * @retval 0: equal.
  *         1: unequal.
  */
uint32_t buffer_compare(uint8_t* buffer1, uint8_t* buffer2, uint32_t len)
{
  uint32_t i;
  
  for(i = 0; i < len; i++)
  {
    if(buffer1[i] != buffer2[i])
    {
      return 1;
    }
  }

  return 0;
}

/**
  * @brief  main function.
  * @param  none
  * @retval none
  */
int main(void)
{
  
  APM_MINI_LEDInit(LED2);
  APM_MINI_LEDInit(LED3);
  delay_init();
  i2c_config();
  

       
#if defined (TEST_1)   

    /* start the transmission process */  
    if(i2c_master_transmit(0xA0, tx_buf, BUF_SIZE) == 1)
    { 
      error_handler();
    }

    delay_ms(10);
    
    /* start the rtransmission process */  
    if(i2c_master_receive(0xA0, rx_buf, BUF_SIZE) == 1)
    { 
      error_handler();
    }  

#endif
    
#if defined (TEST_2)

    /* write data to memory device */  
    if(i2c_memory_write(0xA0, 0, tx_buf, BUF_SIZE) == 1)
    {
      error_handler();
    }
   
    delay_ms(10);
   
    /* read data from memory device */  
    if(i2c_memory_read(0xA0, 0, rx_buf, BUF_SIZE) == 1)
    { 
      error_handler();
    }

#endif
    
    if(buffer_compare(tx_buf, rx_buf, BUF_SIZE) == 0)
    {
      APM_MINI_LEDInit(LED2);
    }
    else
    {
      error_handler();
    }


}




/**
  * @brief  initialize delay function   
  * @param  none
  * @retval none
  */
void delay_init()
{
  /* configure systick */
  SysTick_ConfigCLKSource(SYSTICK_CLK_SOURCE_HCLK);
  fac_us = SystemCoreClock / (1000000U);
  fac_ms = fac_us * (1000U);
}

/**
  * @brief  inserts a delay time.
  * @param  nus: specifies the delay time length, in microsecond.
  * @retval none
  */
void delay_us(uint32_t nus)
{
  uint32_t temp = 0;
  SysTick->LOAD = (uint32_t)(nus * fac_us);
  SysTick->VAL = 0x00;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk ;
  do
  {
    temp = SysTick->CTRL;
  }while((temp & 0x01) && !(temp & (1 << 16)));

  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
  SysTick->VAL = 0x00;
}

/**
  * @brief  inserts a delay time.
  * @param  nms: specifies the delay time length, in milliseconds.
  * @retval none
  */
void delay_ms(uint16_t nms)
{
  uint32_t temp = 0;
  while(nms)
  {
    if(nms > STEP_DELAY_MS)
    {
      SysTick->LOAD = (uint32_t)(STEP_DELAY_MS * fac_ms);
      nms -= STEP_DELAY_MS;
    }
    else
    {
      SysTick->LOAD = (uint32_t)(nms * fac_ms);
      nms = 0;
    }
    SysTick->VAL = 0x00;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
    do
    {
      temp = SysTick->CTRL;
    }while((temp & 0x01) && !(temp & (1 << 16)));

    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    SysTick->VAL = 0x00;
  }
}

/**
  * @brief  inserts a delay time.
  * @param  sec: specifies the delay time, in seconds.
  * @retval none
  */
void delay_sec(uint16_t sec)
{
  uint16_t index;
  for(index = 0; index < sec; index++)
  {
    delay_ms(500);
    delay_ms(500);
  }
}
