# PIC18 GPIO HAL & Button Driver

## Overview
This project implements a reusable, interrupt-safe GPIO Hardware Abstraction Layer (HAL) and a button driver using external using interrupts for the PIC18F4550 microcontroller.

The goal is demostrate clean embedded firmware architecture, whit a strictseparation between:
-hardware access
-driver logic
-application logic

## Key Concepts Demostrated
-GPIO abstraction using `gpio.h / gpio.c`
-Safe register access (avoids Read-Modify-Write issues)
-External interrupt handling (INT0)
-ISR-safe event signaling using software flags
-Minimal ISR design
-Application logic independent of hardware registers

## Project Architecture

-inc/
 -gpio.h       
 -button.h     
 -config.h     
-src/
 -gpio.c       
 -button.c     
-main.c        
-Makefile
-build

## GPIO HAL Design
-Output writes use LAT registers
-Input reads use PORT registers
-Shadow registers are used to prevent RMW hazards
-No direct register access outside the HAL

## Button Driver Design
-Button connected to RB0/INT0
-External interrupt triggers on falling edge
-ISR only sets a software event flag
-Debounce and state validation handled in main context
-Driver exposes a clean API:
 -`button_event_pending()`
 -`button_process()`
 -`button_get_state()`

## Application Flow
1. System initializes GPIO HAL and button driver
2. A button press triggers the external interrupt (INT0)
3. The ISR executes and sets a software event flag
4. The main loop detects the pending button event
5. Button debounce and state validation are processed in main context
6. Application logic reacts to the validated button state

## Build & Flash
```
make all
makle flash
```

## Target MCU
-PIC18F4550
-Compiler: XC8
-Clock: 20 MHz
