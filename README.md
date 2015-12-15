# bbb_lcd_lm35_c
Code to print the lecture of a LM35 temp sensor on a 16x2 LCD display using the C programming language.

This code uses the library shared by https://github.com/nunoalves/BeagleBone-HD44780 and also some changes implemented by https://github.com/estef150892/Beaglebone-lcd-c to make the code run into the newer Beaglebone Black as it runs on a different kernel than the original one.

The code presented in this repository needs two libraries: beagle_gpio.c and beagle_hd44780.c which, along with their respective header files, have to be on the same working directory than the program, so that it can compile and run correctly. The instructions to configure the ADC and the pins, to compile the program and to run it are in the Instructions.txt file.

The connection from the Beaglebone to the LCD is as follows (Open the README.md file to see it clerly).
BBB       LCD
P9_12     E
P9_13     RS
P9_15     DB4
P8_11     DB5
P8_12     DB6
P8_14     DB7
