#include <stdint.h>

#define RAM_START 0x20000000U
#define RAM_SIZE (32 * 1024)
#define STACK_START (RAM_START + RAM_SIZE)

extern uint32_t _text;
extern uint32_t _etext;
extern uint32_t _data;
extern uint32_t _edata;
extern uint32_t _bss;
extern uint32_t _ebss;

extern void main(void);

void Reset_Handler(void)
{
  uint32_t size = (uint32_t)&_edata - (uint32_t)&_etext;
  uint32_t* offs = &_etext;

  for (int i = 0; i < size; i++)
  {
    *(&_data + i) = *offs++;
  }

  size = (uint32_t)&_ebss - (uint32_t)&_bss;

  for (int i = 0; i < size; i++)
  {
    *(&_bss + i) = 0;
  }

  main();
  return;
}

void Default_Handler(void)
{
  return;
}

uint32_t vectors[] __attribute__((section(".isr_vector"))) = {
  STACK_START,
  (uint32_t)&Reset_Handler,
  (uint32_t)&Default_Handler
};
