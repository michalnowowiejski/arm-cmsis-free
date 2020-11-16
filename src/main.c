#include <stdint.h>

uint32_t counter_uninit = 0;
uint32_t counter_init = 1;

int main(void)
{
  while(1)
  {
    counter_uninit++;
    counter_init = counter_uninit;
  }
}
