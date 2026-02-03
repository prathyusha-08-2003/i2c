#include <stdint.h>
#include "i2c.h"
//#include <stdio.h>
#include "gpio.h"

int main(void)
{
	gpio_init();
	i2c_gpio_init();
	i2c_config_init();
	i2c_write(0x76, 0xF4, 0x27);
	int received_data=i2c_read(0x76, 0xD0);
	if(received_data==0x58)
	{
		GPIOC_ODR = (1 << 13);
	}
                
//	printf("Hello");
//	GPIOC_ODR_off &=  ~(1 << 13);  
	return 0;
}


