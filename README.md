# bbb_lcd_lm35_c
Code to print the lecture of a LM35 temp sensor on a 16x2 LCD display using the C programming language.

This code uses the library shared by https://github.com/nunoalves/BeagleBone-HD44780 and also some changes implemented by https://github.com/estef150892/Beaglebone-lcd-c to make the code run into the newer Beaglebone Black as it runs on a different kernel than the original one.

The code presented in this repository needs two libraries: beagle_gpio.c and beagle_hd44780.c which, along with their respective header files, have to be on the same working directory than the program, so that it can compile and run correctly. The instructions on how to wireh the ADC, LCD and BBB, configure the ADC and the pins, compile the program and run it are in the Instructions.txt file.
