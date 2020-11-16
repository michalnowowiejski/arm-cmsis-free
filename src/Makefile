CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld

LDFLAGS = -T linkerscript.ld

CFLAGS = -c -O0 --specs=nosys.specs -mthumb -mcpu=cortex-m0 -Wall
ifeq (1,$(DEBUG))
	CFLAGS += -g
endif

nucleo-f091rc: main.o startup.o
	$(LD) $(LDFLAGS) -Map=$@.map -o $@.elf $^

main.o: main.c
	$(CC) $(CFLAGS) -o $@ $^

startup.o: startup.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f *.o *.elf *.map