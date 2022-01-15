#include "Macros.h"
#include "STD_TYPES.h"
#include "GPIO_interface.h"
#include "SysTick_interface.h"
#include "SYSCNTRL_interface.h"
#include "TIMER0_interface.h"
#include "DHT11_interface.h"
#include "UART_interface.h"

u8 u8RH1 = 0;
u8 u8RH2 = 0;
u8 u8Temp1 = 0;
u8 u8Temp2 = 0;

void APP_vidInit(void)
{

}


void APP_vidGetTemperature(void)
{
	DHT11_vidInit();
	DHT11_vidStart();
	if(DHT11_u8CheckResponse() == 1)
	{
	u8RH1 = DHT11_u8ReadByte();
	u8RH2 = DHT11_u8ReadByte();
	u8Temp1 = DHT11_u8ReadByte();
	u8Temp2 = DHT11_u8ReadByte();
	UART0_vidSendString("Temperature: ");
	UART_vidSendNumber(UART0_vidSendByte,u8Temp1);
	UART0_vidSendString(" C");
	UART0_vidSendByte('\r');
	UART0_vidSendByte('\n');
	UART0_vidSendString("Humidity: ");
	UART_vidSendNumber(UART0_vidSendByte,u8RH1);
	UART0_vidSendByte('\r');
	UART0_vidSendByte('\n');
	}
}