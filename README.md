# Nanolib

A modern C++ library implementing a Hardware Abstraction Layer for the Arduino Nano. It aims to minimize the potential for runtime errors
by moving the configuration of peripherals to compile-time.

## Compiling

### The Library

As this is a header only library, it is enough to simply include the desired header files.

### The examples

1. Install the necessary tools
```shell
$ sudo apt-get install arduino-avr-core avr-binutils avr-gcc avr-libc avrdude 
```

2. Clone the repo and enter the examples folder
```shell
$ git clone git@github.com:antsouchlos/nanolib.git && cd nanolib/examples
```
3. Select the example to compile in `CMakeLists.txt`
```cmake
...
add_avr_executable(gpio src/gpio/gpio.cpp)
...
```

4. Create the build directory and build the project
```shell
$ cmake -B build -S . && cmake --build build
```

5. Upload the compiled binary onto the arduino
```shell
$ cd build && make flash
```

## Tests

Unit testing is done with the `googletest` framework.

1. Clone the repo
```shell
$ git clone git@github.com:antsouchlos/nanolib.git && cd nanolib
```

2. Clone the googletest submodule and enter the unit-test directory
```shell
$ git submodule init && git submodule update && cd test
```

3. Create the build directory and build the project
```shell
$ cmake -B build -S . && cmake --build build
```

4. Run the tests
```shell
$ ctest --test-dir build
```

## Usage

Examples for all supported peripherals can be found in the `examples` folder. The following is only meant to give a rough overview
of how the library is to be used.

#### General

In order to be able to validate a given configuration at compile-time, throughout this library there is heavy usage of
`static_assert`. Because `static_assert` requires constant expressions, most of the configuration of the peripherals is
done through templates:

```c++
Gpio<Port::F, Pin::_2, Direction::out> led_blue;
```

#### Advanced configuration
[TODO]

#### Compile-time config checking
[TODO - Example]

#### System class
[TODO]

#### A working example
[TODO]

