This is a simple bare metal CMSIS-free totally useless while loop program.
It is my attempt to better understand gcc linking proces and Cortex-M0 booting sequence.

Build steps:
1. You need to have installed gcc-arm-none-eabi toolchain, openocd and gdb-multiarch.
2. "$ cd src/" and run "$ make" or "$ DEBUG=1 make" for debug symbols. Defaulting to stm32 nucleo F091RC target.

Run/Debug steps (for stm32 nucleo F091RC):
1. In "src" run "$ openocd -f board/st_nucleo_f0.cfg -c "program nucleo-f091rc.elf verify reset""
2. Open another terminal window and run "$ gdb-multiarch nucleo-f091rc.elf"
3. (gdb) target extended-remote localhost:3333
4. (gdb) monitor reset halt
5. You are now entering reset vector handler :)
