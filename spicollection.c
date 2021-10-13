/* Raspberry Pi do not have ADC.
 * Therefore, MCP3208 can be a solution.
 * Careful choice of GPIO which supports SPI communication
 *
 * ADC: MCP3208
 * SPI Pins:
 * 	PIN 23, GPIO 11 -> MCP3208 CLK
 * 	PIN 19, GPIO 10 -> MCP3208 DIN
 * 	PIN 21, GPIO 9 -> MCP3208 DOUT
 * 	PIN 24, GPIO 8 -> MCP3208 CS/SHDN
 * 	PIN 1, 3.3V -> MCP3208 VDD
 *	GND -> MCP3208 GND */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>

#define MCP3208_CS 10 /* WiringPi = 10, BCM = 8 */
#define SPI_CHANNEL 0
#define SPI_SPEED 1000000

#define FNAME "Output.txt"

int read_adc(uint8_t ADC_CH)
{
	uint8_t buff[3];
	int ADC_VAL = 0;
	buff[0] = 0x06 | ((ADC_CH & 0x07) >> 2);
	buff[1] = ((ADC_CH & 0x07) << 6);
	buff[2] = 0x00;

	digitalWrite(MCP3208_CS, 0);
	wiringPiSPIDataRW(SPI_CHANNEL, buff, 3);

	buff[1] = 0x0f & buff[1];
	ADC_VAL = (buff[1] << 8) | buff[2];

	digitalWrite(MCP3208_CS, 1);
	return ADC_VAL;
}

int main(void)
{
	int MAV[1000][1000] = { 0, };
	uint8_t ADC_CH = 0;
	int ADC_VAL;
	int temp;
	uint8_t index = 0;
	FILE *fp;
	for (int i = 0; i < 1000; i++)
	{
		temp += abs(read_adc(ADC_CH));
		delay(1);
	}
	int ref_value = temp / 1000;
	temp = 0;
	while(1)
	{
		int current_value = abs(read_adc(ADC_CH));
		fopen_s(&fp, FNAME, "w");

		if ((2*re_value) <= current_value)
		{
			for (int j = 0; j < 1000; j++)
			{
				for (int k = 0; k < 100; k++)
				{
					temp += abs(read_adc(ADC_CH));
				}
				MAV[index][j] = temp / 100;
				fprintf(fp, "%d ", MAV[index][j]);
				index += 1;
				temp = 0;
				delay(1);
			}
			printf("Data was collected in Line %d\n", j);
			fprintf(fp, "\n");
			if (j == 999)
			{
				break;
				return 0;
			}
		}
	}
}
