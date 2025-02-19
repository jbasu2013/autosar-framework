/////////////////////////////////////////////////////// 
//  Copyright 2015 Stephan Hage.
//  Copyright 2015 Christopher Kormanyos.
//  Distributed under the Boost 
//  Software License, Version 1.0. 
//  (See accompanying file LICENSE_1_0.txt 
//  or copy at http://www.boost.org/LICENSE_1_0.txt ) 
//

// ATSAM3X EABI Cortex-M3 startup code
// Switched to C++ and modified for STM32F103x by Chris.

#include <Bsw/Common/Std_Types.h>
#include <Bsw/Common/Cpu/McalCpu.h>
#include <Bsw/Mcal/Reg/Reg.h>

EXTERN_C int main();

namespace crt
{
  void init_ram();
  void init_ctors();
}

EXTERN_C void __my_startup() __attribute__((used, noinline));

void __my_startup()
{
  // Load the stack pointer.
  // The stack pointer is automatically loaded from
  // the base position of the interrupt vector table.
  // So do nothing here.

  // Initialize statics from ROM to RAM.
  // Zero-clear non-initialized static RAM.
  crt::init_ram();

  // Call all ctor initializations.
  crt::init_ctors();

  // Call main (and never return).
  asm volatile("ldr r3, =main");
  asm volatile("blx r3");

  // Catch an unexpected return from main.
  for(;;)
  {
    // Replace with a loud error if desired.
    mcal::cpu::nop();
  }
}
