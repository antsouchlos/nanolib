# [Name yet to be decided]

A C++ library for the Arduino Nano. It aims to minimize potential runtime errors by moving the configuration of
peripherals to compile-time.

## Overview

Examples for all supported peripherals can be found in the `examples` folder. The following is only meant to give a rough overview
of how the library is to be used.

### General

In order to be able to validate a given configuration at compile-time, throughout this library there is heavy usage of
`static_assert`. Because `static_assert` requires constant expressions, most of the configuration of the peripherals is
done through templates:

```c++
Gpio<Port::F, Pin::_2, Direction::out> led_blue;
```

### Advanced configuration
[TODO]

### Compile-time config checking
[TODO - Example]

### System class
[TODO]

## A working example
[TODO]

