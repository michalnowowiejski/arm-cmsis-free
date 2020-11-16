MEMORY
{
  FLASH (rx) : ORIGIN = 0x08000000, LENGTH = 256K
  CODE (rx)  : ORIGIN = 0x00000000, LENGTH = 256K
  RAM (rxw)  : ORIGIN = 0x20000000, LENGTH = 32K
}

ENTRY(Reset_Handler)

SECTIONS
{
  .text :
  {
    _text = .;
    *(.isr_vector)
    . = _text + 0x188;
    *(.text)
    _etext = .;
  } > CODE AT> FLASH

  .data :
  {
    _data = .;
    KEEP(*(.data))
    _edata = .;
  } > RAM AT> FLASH

  .bss :
  {
    _bss = .;
    KEEP(*(.bss))
    _ebss = .;
  } > RAM
}