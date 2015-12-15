// Standar libraries
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <time.h>
// LCD libraries, must be in the same working directory
#include "beagle_gpio.h"
#include "beagle_hd44780.h"

#include <fcntl.h>     //define O_WONLY and O_RDONLY

// Path to the 4th ADC files
#define SYSFS_ADC_DIR "/sys/bus/iio/devices/iio:device0/in_voltage4_raw"
#define MAX_BUFF 64     //This is plenty large  

// Function to read the ADC value and return it as an integer
int readAnalog() {
    int fd, value;
    char buf[MAX_BUFF];
    char ch[5];
    ch[4]=0;
    
    snprintf(buf, sizeof(buf), SYSFS_ADC_DIR);
    fd=open(buf, O_RDONLY);
    read(fd,ch,4);
    close(fd);
    value = atoi(ch);
    
    return value;
}

int main()
{
	int i, value;
	float temp;
    char valueS[50];

	// Here the pins that will be used to controll the LCD are specified
	int selectedPins[]={P8_14,P8_12,P8_11,P9_15,P9_13,P9_12};
	// Description of each of the above pins used
	const char *pinDescription[] = {"DB7","DB6","DB5","DB4","RS","E"};

	struct gpioID enabled_gpio[6];    
	// Instruction to initialize the LCD in 4 bit mode
    initialize_Screen(enabled_gpio,selectedPins);	
    
    // Clear screen
	clear_Screen(enabled_gpio);
	
	// The goto_ScreenLine moves to the first position of the specified line
	// the first line is specified with the 0
	goto_ScreenLine(0,enabled_gpio);
	// Instruction to write in the LCD
	stringToScreen("Temperature: ",enabled_gpio);
	
	// An infinite while is not used so that the terminate_screen below can be reached
	// this is necessary in order to be able to re run the program with no conflicts
	for (i=0; i<10; i++) {
		value = readAnalog();					// Reads the analog value using the above function
		temp = (float)value/22.75;				// Converts the returned value into its corresponding temperature value
		sprintf(valueS, "%.02f C  ", temp);		// Converts the integer value to a string, adding the C of celcious degrees	
		goto_ScreenLine(1,enabled_gpio);		// Moves the cursor to the second LCD line
		stringToScreen(valueS,enabled_gpio);	// Prints the temperature value
		sleep(1);
	}
	
	// Clear screen
	clear_Screen(enabled_gpio);
	
	// It is always necessary to reach this function, to terminate the LCD properly
    terminate_Screen(enabled_gpio,selectedPins);

	return 1;
}
