robot: robot.o
	avr-objcopy -j .text -j .data -R .eeprom -O ihex robot.elf robot.hex

estrategia.o: estrategia.c
	avr-gcc -c -g -mmcu=atmega128 -Os -Wall estrategia.c

infra.o: infra.c infra.h
	avr-gcc -c -g -mmcu=atmega128 -Os -Wall infra.c

ultra.o: ultra.c ultra.h
	avr-gcc -c -g -mmcu=atmega128 -Os -Wall ultra.c

motor.o: motor.c motor.h
	avr-gcc -c -g -mmcu=atmega128 -Os -Wall motor.c

robot.o: estrategia.o infra.o ultra.o motor.o
	avr-gcc -g -mmcu=atmega128 -Os -Wall estrategia.o infra.o ultra.o motor.o -o robot.elf

clean:
	rm *.o robot.elf robot.hex