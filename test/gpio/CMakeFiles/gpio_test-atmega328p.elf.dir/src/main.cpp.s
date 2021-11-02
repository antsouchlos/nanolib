	.file	"main.cpp"
__SP_H__ = 0x3e
__SP_L__ = 0x3d
__SREG__ = 0x3f
__tmp_reg__ = 0
__zero_reg__ = 1
	.text
.Ltext0:
	.cfi_sections	.debug_frame
.global	main
	.type	main, @function
main:
.LFB9:
	.file 1 "/home/andreas/git/arduino_lib/test/gpio/src/main.cpp"
	.loc 1 7 12
	.cfi_startproc
	push r28
	.cfi_def_cfa_offset 3
	.cfi_offset 28, -2
	push r29
	.cfi_def_cfa_offset 4
	.cfi_offset 29, -3
	push __tmp_reg__
	.cfi_def_cfa_offset 5
	in r28,__SP_L__
	in r29,__SP_H__
	.cfi_def_cfa_register 28
/* prologue: function */
/* frame size = 1 */
/* stack size = 3 */
.L__stack_usage = 3
	.loc 1 8 44
	movw r24,r28
	adiw r24,1
	call _ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EEC1Ev
	.loc 1 10 14
	ldi r22,lo8(1)
	movw r24,r28
	adiw r24,1
	call _ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE5writeEb
	.loc 1 12 12
	ldi r24,0
	ldi r25,0
/* epilogue start */
	.loc 1 13 1
	pop __tmp_reg__
	pop r29
	pop r28
	ret
	.cfi_endproc
.LFE9:
	.size	main, .-main
	.section	.text._ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EEC2Ev,"axG",@progbits,_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EEC5Ev,comdat
	.weak	_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EEC2Ev
	.type	_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EEC2Ev, @function
_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EEC2Ev:
.LFB11:
	.file 2 "/home/andreas/git/arduino_lib/test/../arduino_lib/Gpio.h"
	.loc 2 17 2
	.cfi_startproc
	push r28
	.cfi_def_cfa_offset 3
	.cfi_offset 28, -2
	push r29
	.cfi_def_cfa_offset 4
	.cfi_offset 29, -3
	rcall .
	.cfi_def_cfa_offset 6
	in r28,__SP_L__
	in r29,__SP_H__
	.cfi_def_cfa_register 28
/* prologue: function */
/* frame size = 2 */
/* stack size = 4 */
.L__stack_usage = 4
	std Y+2,r25
	std Y+1,r24
.LBB2:
	.loc 2 18 16
	ldd r24,Y+1
	ldd r25,Y+2
	call _ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE13set_directionEv
.LBE2:
	.loc 2 19 2
	nop
/* epilogue start */
	pop __tmp_reg__
	pop __tmp_reg__
	pop r29
	pop r28
	ret
	.cfi_endproc
.LFE11:
	.size	_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EEC2Ev, .-_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EEC2Ev
	.weak	_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EEC1Ev
	.set	_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EEC1Ev,_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EEC2Ev
	.section	.text._ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE5writeEb,"axG",@progbits,_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE5writeEb,comdat
	.weak	_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE5writeEb
	.type	_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE5writeEb, @function
_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE5writeEb:
.LFB13:
	.loc 2 21 7
	.cfi_startproc
	push r28
	.cfi_def_cfa_offset 3
	.cfi_offset 28, -2
	push r29
	.cfi_def_cfa_offset 4
	.cfi_offset 29, -3
	rcall .
	push __tmp_reg__
	.cfi_def_cfa_offset 7
	in r28,__SP_L__
	in r29,__SP_H__
	.cfi_def_cfa_register 28
/* prologue: function */
/* frame size = 3 */
/* stack size = 5 */
.L__stack_usage = 5
	std Y+2,r25
	std Y+1,r24
	std Y+3,r22
	.loc 2 23 50
	ldd r24,Y+3
	call _ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE5writeEh
	.loc 2 24 2
	nop
/* epilogue start */
	pop __tmp_reg__
	pop __tmp_reg__
	pop __tmp_reg__
	pop r29
	pop r28
	ret
	.cfi_endproc
.LFE13:
	.size	_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE5writeEb, .-_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE5writeEb
	.section	.text._ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE13set_directionEv,"axG",@progbits,_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE13set_directionEv,comdat
	.weak	_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE13set_directionEv
	.type	_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE13set_directionEv, @function
_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE13set_directionEv:
.LFB15:
	.loc 2 35 7
	.cfi_startproc
	push r28
	.cfi_def_cfa_offset 3
	.cfi_offset 28, -2
	push r29
	.cfi_def_cfa_offset 4
	.cfi_offset 29, -3
	rcall .
	.cfi_def_cfa_offset 6
	in r28,__SP_L__
	in r29,__SP_H__
	.cfi_def_cfa_register 28
/* prologue: function */
/* frame size = 2 */
/* stack size = 4 */
.L__stack_usage = 4
	std Y+2,r25
	std Y+1,r24
	.loc 2 37 60
	call _ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeILj1EEEvv
	.loc 2 41 2
	nop
/* epilogue start */
	pop __tmp_reg__
	pop __tmp_reg__
	pop r29
	pop r28
	ret
	.cfi_endproc
.LFE15:
	.size	_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE13set_directionEv, .-_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE13set_directionEv
	.section	.text._ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE5writeEh,"axG",@progbits,_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE5writeEh,comdat
	.weak	_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE5writeEh
	.type	_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE5writeEh, @function
_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE5writeEh:
.LFB16:
	.file 3 "/home/andreas/git/arduino_lib/test/../arduino_lib/Register.h"
	.loc 3 72 17
	.cfi_startproc
	push r16
	.cfi_def_cfa_offset 3
	.cfi_offset 16, -2
	push r17
	.cfi_def_cfa_offset 4
	.cfi_offset 17, -3
	push r28
	.cfi_def_cfa_offset 5
	.cfi_offset 28, -4
	push r29
	.cfi_def_cfa_offset 6
	.cfi_offset 29, -5
	rcall .
	.cfi_def_cfa_offset 8
	in r28,__SP_L__
	in r29,__SP_H__
	.cfi_def_cfa_register 28
/* prologue: function */
/* frame size = 2 */
/* stack size = 6 */
.L__stack_usage = 6
	std Y+2,r24
	.loc 3 76 36
	call _ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv
	.loc 3 76 16
	movw r30,r24
	ld r24,Z
	std Y+1,r24
	.loc 3 77 14
	ldd r24,Y+1
	andi r24,lo8(-65)
	std Y+1,r24
	.loc 3 78 24
	ldd r24,Y+2
	mov r24,r24
	ldi r25,0
	.loc 3 78 30
	mov r17,r24
	lsr r17
	lsr r17
	mov r16,r24
	swap r16
	lsl r16
	lsl r16
	andi r16,lo8(-64)
	.loc 3 78 21
	mov r25,r16
	ldd r24,Y+1
	or r24,r25
	.loc 3 78 14
	std Y+1,r24
	.loc 3 80 25
	ldd r17,Y+1
	.loc 3 80 22
	call _ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv
	.loc 3 80 25
	movw r30,r24
	st Z,r17
	.loc 3 81 5
	nop
/* epilogue start */
	pop __tmp_reg__
	pop __tmp_reg__
	pop r29
	pop r28
	pop r17
	pop r16
	ret
	.cfi_endproc
.LFE16:
	.size	_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE5writeEh, .-_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE5writeEh
	.section	.text._ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeILj1EEEvv,"axG",@progbits,_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeILj1EEEvv,comdat
	.weak	_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeILj1EEEvv
	.type	_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeILj1EEEvv, @function
_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeILj1EEEvv:
.LFB17:
	.loc 3 65 48
	.cfi_startproc
	push r28
	.cfi_def_cfa_offset 3
	.cfi_offset 28, -2
	push r29
	.cfi_def_cfa_offset 4
	.cfi_offset 29, -3
	in r28,__SP_L__
	in r29,__SP_H__
	.cfi_def_cfa_register 28
/* prologue: function */
/* frame size = 0 */
/* stack size = 2 */
.L__stack_usage = 2
	.loc 3 69 14
	ldi r24,lo8(1)
	call _ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeEh
	.loc 3 70 5
	nop
/* epilogue start */
	pop r29
	pop r28
	ret
	.cfi_endproc
.LFE17:
	.size	_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeILj1EEEvv, .-_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeILj1EEEvv
	.section	.text._ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv,"axG",@progbits,_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv,comdat
	.weak	_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv
	.type	_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv, @function
_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv:
.LFB18:
	.loc 3 60 29
	.cfi_startproc
	push r28
	.cfi_def_cfa_offset 3
	.cfi_offset 28, -2
	push r29
	.cfi_def_cfa_offset 4
	.cfi_offset 29, -3
	in r28,__SP_L__
	in r29,__SP_H__
	.cfi_def_cfa_register 28
/* prologue: function */
/* frame size = 0 */
/* stack size = 2 */
.L__stack_usage = 2
	.loc 3 61 69
	ldi r24,lo8(37)
	ldi r25,0
/* epilogue start */
	.loc 3 62 5
	pop r29
	pop r28
	ret
	.cfi_endproc
.LFE18:
	.size	_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv, .-_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv
	.section	.text._ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeEh,"axG",@progbits,_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeEh,comdat
	.weak	_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeEh
	.type	_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeEh, @function
_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeEh:
.LFB20:
	.loc 3 72 17
	.cfi_startproc
	push r16
	.cfi_def_cfa_offset 3
	.cfi_offset 16, -2
	push r17
	.cfi_def_cfa_offset 4
	.cfi_offset 17, -3
	push r28
	.cfi_def_cfa_offset 5
	.cfi_offset 28, -4
	push r29
	.cfi_def_cfa_offset 6
	.cfi_offset 29, -5
	rcall .
	.cfi_def_cfa_offset 8
	in r28,__SP_L__
	in r29,__SP_H__
	.cfi_def_cfa_register 28
/* prologue: function */
/* frame size = 2 */
/* stack size = 6 */
.L__stack_usage = 6
	std Y+2,r24
	.loc 3 76 36
	call _ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv
	.loc 3 76 16
	movw r30,r24
	ld r24,Z
	std Y+1,r24
	.loc 3 77 14
	ldd r24,Y+1
	andi r24,lo8(-65)
	std Y+1,r24
	.loc 3 78 24
	ldd r24,Y+2
	mov r24,r24
	ldi r25,0
	.loc 3 78 30
	mov r17,r24
	lsr r17
	lsr r17
	mov r16,r24
	swap r16
	lsl r16
	lsl r16
	andi r16,lo8(-64)
	.loc 3 78 21
	mov r25,r16
	ldd r24,Y+1
	or r24,r25
	.loc 3 78 14
	std Y+1,r24
	.loc 3 80 25
	ldd r17,Y+1
	.loc 3 80 22
	call _ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv
	.loc 3 80 25
	movw r30,r24
	st Z,r17
	.loc 3 81 5
	nop
/* epilogue start */
	pop __tmp_reg__
	pop __tmp_reg__
	pop r29
	pop r28
	pop r17
	pop r16
	ret
	.cfi_endproc
.LFE20:
	.size	_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeEh, .-_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeEh
	.section	.text._ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv,"axG",@progbits,_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv,comdat
	.weak	_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv
	.type	_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv, @function
_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv:
.LFB21:
	.loc 3 60 29
	.cfi_startproc
	push r28
	.cfi_def_cfa_offset 3
	.cfi_offset 28, -2
	push r29
	.cfi_def_cfa_offset 4
	.cfi_offset 29, -3
	in r28,__SP_L__
	in r29,__SP_H__
	.cfi_def_cfa_register 28
/* prologue: function */
/* frame size = 0 */
/* stack size = 2 */
.L__stack_usage = 2
	.loc 3 61 69
	ldi r24,lo8(36)
	ldi r25,0
/* epilogue start */
	.loc 3 62 5
	pop r29
	pop r28
	ret
	.cfi_endproc
.LFE21:
	.size	_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv, .-_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv
	.text
.Letext0:
	.file 4 "/home/andreas/git/arduino_lib/test/../arduino_lib/periph_base.h"
	.file 5 "/home/andreas/git/arduino_lib/test/../arduino_lib/constexpr_util.h"
	.file 6 "/home/andreas/git/arduino_lib/test/../arduino_lib/register_map.h"
	.file 7 "/usr/avr/include/stdint.h"
	.file 8 "/home/andreas/git/arduino_lib/test/../arduino_lib/type_traits.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x4ce
	.word	0x3
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF49
	.byte	0x4
	.long	.LASF50
	.long	.LASF51
	.long	.Ldebug_ranges0+0
	.long	0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF0
	.uleb128 0x3
	.long	.LASF16
	.byte	0x7
	.byte	0x7e
	.byte	0x16
	.long	0x3d
	.uleb128 0x4
	.long	0x2c
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x5
	.byte	0x2
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.long	.LASF3
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF4
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF5
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF6
	.uleb128 0x6
	.long	.LASF9
	.byte	0x4
	.byte	0x8
	.byte	0xb
	.long	0x320
	.uleb128 0x7
	.long	.LASF7
	.byte	0x2
	.long	0x44
	.byte	0x4
	.byte	0xb
	.byte	0xc
	.long	0x98
	.uleb128 0x8
	.string	"B"
	.byte	0
	.uleb128 0x8
	.string	"C"
	.byte	0x1
	.uleb128 0x8
	.string	"D"
	.byte	0x2
	.byte	0
	.uleb128 0x9
	.string	"Pin"
	.byte	0x2
	.long	0x44
	.byte	0x4
	.byte	0xc
	.byte	0xc
	.long	0xd2
	.uleb128 0x8
	.string	"_0"
	.byte	0
	.uleb128 0x8
	.string	"_1"
	.byte	0x1
	.uleb128 0x8
	.string	"_2"
	.byte	0x2
	.uleb128 0x8
	.string	"_3"
	.byte	0x3
	.uleb128 0x8
	.string	"_4"
	.byte	0x4
	.uleb128 0x8
	.string	"_5"
	.byte	0x5
	.uleb128 0x8
	.string	"_6"
	.byte	0x6
	.uleb128 0x8
	.string	"_7"
	.byte	0x7
	.byte	0
	.uleb128 0x7
	.long	.LASF8
	.byte	0x2
	.long	0x44
	.byte	0x4
	.byte	0xd
	.byte	0xc
	.long	0xef
	.uleb128 0x8
	.string	"in"
	.byte	0
	.uleb128 0x8
	.string	"out"
	.byte	0x1
	.byte	0
	.uleb128 0x6
	.long	.LASF10
	.byte	0x5
	.byte	0x5
	.byte	0x1e
	.long	0x277
	.uleb128 0xa
	.long	.LASF11
	.byte	0x1
	.byte	0x6
	.byte	0xc
	.byte	0x8
	.long	0x151
	.uleb128 0xa
	.long	.LASF12
	.byte	0x1
	.byte	0x6
	.byte	0x18
	.byte	0x9
	.long	0x12e
	.uleb128 0xb
	.long	.LASF13
	.byte	0x6
	.byte	0x19
	.byte	0x1c
	.long	0x38
	.byte	0x1
	.byte	0x1
	.uleb128 0xc
	.long	.LASF14
	.long	0x7a
	.byte	0
	.byte	0
	.uleb128 0xd
	.long	.LASF52
	.byte	0x1
	.byte	0x6
	.byte	0x20
	.byte	0x9
	.uleb128 0xb
	.long	.LASF13
	.byte	0x6
	.byte	0x21
	.byte	0x1c
	.long	0x38
	.byte	0x1
	.byte	0x1
	.uleb128 0xc
	.long	.LASF14
	.long	0x7a
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0xa
	.long	.LASF15
	.byte	0x1
	.byte	0x3
	.byte	0x23
	.byte	0x8
	.long	0x178
	.uleb128 0x3
	.long	.LASF17
	.byte	0x3
	.byte	0x24
	.byte	0xb
	.long	0x178
	.uleb128 0xc
	.long	.LASF18
	.long	0x3d
	.byte	0x1
	.uleb128 0xe
	.string	"T"
	.byte	0
	.uleb128 0x3
	.long	.LASF19
	.byte	0x3
	.byte	0xe
	.byte	0x7
	.long	0x2c
	.uleb128 0xf
	.long	.LASF53
	.byte	0x1
	.byte	0x3
	.byte	0x38
	.byte	0x7
	.long	0x1f0
	.uleb128 0x3
	.long	.LASF20
	.byte	0x3
	.byte	0x3a
	.byte	0xb
	.long	0x15e
	.uleb128 0x10
	.long	0x191
	.uleb128 0x4
	.long	0x191
	.uleb128 0x11
	.byte	0x1
	.long	.LASF22
	.byte	0x3
	.byte	0x3c
	.byte	0x1d
	.long	.LASF23
	.long	0x342
	.byte	0x1
	.uleb128 0x12
	.byte	0x1
	.long	.LASF25
	.byte	0x3
	.byte	0x48
	.byte	0x11
	.long	.LASF26
	.byte	0x1
	.byte	0x1
	.long	0x1d2
	.uleb128 0x13
	.long	0x191
	.byte	0
	.uleb128 0x14
	.long	.LASF31
	.long	0x108
	.uleb128 0xc
	.long	.LASF21
	.long	0x3d
	.byte	0x6
	.uleb128 0xc
	.long	.LASF18
	.long	0x3d
	.byte	0x1
	.byte	0
	.uleb128 0x15
	.long	.LASF32
	.byte	0x1
	.byte	0x3
	.byte	0x38
	.byte	0x7
	.uleb128 0x3
	.long	.LASF20
	.byte	0x3
	.byte	0x3a
	.byte	0xb
	.long	0x15e
	.uleb128 0x10
	.long	0x1f9
	.uleb128 0x4
	.long	0x1f9
	.uleb128 0x11
	.byte	0x1
	.long	.LASF22
	.byte	0x3
	.byte	0x3c
	.byte	0x1d
	.long	.LASF24
	.long	0x348
	.byte	0x1
	.uleb128 0x12
	.byte	0x1
	.long	.LASF25
	.byte	0x3
	.byte	0x48
	.byte	0x11
	.long	.LASF27
	.byte	0x1
	.byte	0x1
	.long	0x23a
	.uleb128 0x13
	.long	0x1f9
	.byte	0
	.uleb128 0x12
	.byte	0x1
	.long	.LASF28
	.byte	0x3
	.byte	0x41
	.byte	0x30
	.long	.LASF29
	.byte	0x1
	.byte	0x1
	.long	0x258
	.uleb128 0xc
	.long	.LASF30
	.long	0x4b
	.byte	0x1
	.byte	0
	.uleb128 0x14
	.long	.LASF31
	.long	0x12e
	.uleb128 0xc
	.long	.LASF21
	.long	0x3d
	.byte	0x6
	.uleb128 0xc
	.long	.LASF18
	.long	0x3d
	.byte	0x1
	.byte	0
	.byte	0
	.uleb128 0x15
	.long	.LASF33
	.byte	0x1
	.byte	0x2
	.byte	0xc
	.byte	0x7
	.uleb128 0x16
	.byte	0x1
	.long	.LASF34
	.byte	0x2
	.byte	0x11
	.byte	0x2
	.long	.LASF35
	.byte	0x1
	.byte	0x1
	.long	0x297
	.long	0x29e
	.uleb128 0x17
	.long	0x330
	.byte	0x1
	.byte	0
	.uleb128 0x16
	.byte	0x1
	.long	.LASF25
	.byte	0x2
	.byte	0x15
	.byte	0x7
	.long	.LASF36
	.byte	0x1
	.byte	0x1
	.long	0x2b5
	.long	0x2c1
	.uleb128 0x17
	.long	0x330
	.byte	0x1
	.uleb128 0x13
	.long	0x33b
	.byte	0
	.uleb128 0x18
	.byte	0x1
	.long	.LASF54
	.byte	0x2
	.byte	0x1a
	.byte	0x7
	.long	.LASF55
	.long	0x33b
	.byte	0x1
	.byte	0x1
	.long	0x2dc
	.long	0x2e3
	.uleb128 0x17
	.long	0x330
	.byte	0x1
	.byte	0
	.uleb128 0x19
	.byte	0x1
	.long	.LASF37
	.byte	0x2
	.byte	0x23
	.byte	0x7
	.long	.LASF38
	.byte	0x1
	.long	0x2f9
	.long	0x300
	.uleb128 0x17
	.long	0x330
	.byte	0x1
	.byte	0
	.uleb128 0xc
	.long	.LASF14
	.long	0x7a
	.byte	0
	.uleb128 0xc
	.long	.LASF39
	.long	0x98
	.byte	0x6
	.uleb128 0xc
	.long	.LASF40
	.long	0xd2
	.byte	0x1
	.byte	0
	.byte	0
	.uleb128 0x1a
	.string	"std"
	.byte	0x8
	.byte	0x5
	.byte	0xb
	.uleb128 0x1b
	.byte	0x1
	.byte	0x4
	.byte	0x11
	.long	0x6e
	.uleb128 0x1c
	.byte	0x2
	.long	0x277
	.uleb128 0x4
	.long	0x330
	.uleb128 0x2
	.byte	0x1
	.byte	0x2
	.long	.LASF41
	.uleb128 0x1c
	.byte	0x2
	.long	0x19d
	.uleb128 0x1c
	.byte	0x2
	.long	0x205
	.uleb128 0x1d
	.long	0x20f
	.long	.LFB21
	.long	.LFE21
	.byte	0x1
	.byte	0x9c
	.uleb128 0x1e
	.long	0x221
	.long	.LFB20
	.long	.LFE20
	.byte	0x1
	.byte	0x9c
	.long	0x3a2
	.uleb128 0x1f
	.long	.LASF42
	.byte	0x3
	.byte	0x48
	.byte	0x1e
	.long	0x1f9
	.byte	0x2
	.byte	0x8c
	.sleb128 2
	.uleb128 0x20
	.long	.LASF43
	.byte	0x3
	.byte	0x49
	.byte	0x21
	.long	.LASF44
	.long	0x20a
	.byte	0x1
	.sleb128 -65
	.uleb128 0x21
	.long	.LASF46
	.byte	0x3
	.byte	0x4c
	.byte	0x10
	.long	0x1f9
	.byte	0x2
	.byte	0x8c
	.sleb128 1
	.byte	0
	.uleb128 0x1d
	.long	0x1a7
	.long	.LFB18
	.long	.LFE18
	.byte	0x1
	.byte	0x9c
	.uleb128 0x1e
	.long	0x23a
	.long	.LFB17
	.long	.LFE17
	.byte	0x1
	.byte	0x9c
	.long	0x3cf
	.uleb128 0xc
	.long	.LASF30
	.long	0x4b
	.byte	0x1
	.byte	0
	.uleb128 0x1e
	.long	0x1b9
	.long	.LFB16
	.long	.LFE16
	.byte	0x1
	.byte	0x9c
	.long	0x414
	.uleb128 0x1f
	.long	.LASF42
	.byte	0x3
	.byte	0x48
	.byte	0x1e
	.long	0x191
	.byte	0x2
	.byte	0x8c
	.sleb128 2
	.uleb128 0x20
	.long	.LASF43
	.byte	0x3
	.byte	0x49
	.byte	0x21
	.long	.LASF45
	.long	0x1a2
	.byte	0x1
	.sleb128 -65
	.uleb128 0x21
	.long	.LASF46
	.byte	0x3
	.byte	0x4c
	.byte	0x10
	.long	0x191
	.byte	0x2
	.byte	0x8c
	.sleb128 1
	.byte	0
	.uleb128 0x22
	.long	0x2e3
	.long	0x42b
	.long	.LFB15
	.long	.LFE15
	.byte	0x1
	.byte	0x9c
	.long	0x439
	.uleb128 0x23
	.long	.LASF47
	.long	0x336
	.byte	0x1
	.byte	0x2
	.byte	0x8c
	.sleb128 1
	.byte	0
	.uleb128 0x22
	.long	0x29e
	.long	0x450
	.long	.LFB13
	.long	.LFE13
	.byte	0x1
	.byte	0x9c
	.long	0x46d
	.uleb128 0x23
	.long	.LASF47
	.long	0x336
	.byte	0x1
	.byte	0x2
	.byte	0x8c
	.sleb128 1
	.uleb128 0x1f
	.long	.LASF42
	.byte	0x2
	.byte	0x15
	.byte	0x12
	.long	0x33b
	.byte	0x2
	.byte	0x8c
	.sleb128 3
	.byte	0
	.uleb128 0x24
	.long	0x280
	.long	0x47b
	.byte	0x2
	.long	0x486
	.uleb128 0x25
	.long	.LASF47
	.long	0x336
	.byte	0x1
	.byte	0
	.uleb128 0x26
	.long	0x46d
	.long	.LASF56
	.long	0x4a1
	.long	.LFB11
	.long	.LFE11
	.byte	0x1
	.byte	0x9c
	.long	0x4aa
	.uleb128 0x27
	.long	0x47b
	.byte	0x2
	.byte	0x8c
	.sleb128 1
	.byte	0
	.uleb128 0x28
	.byte	0x1
	.long	.LASF48
	.byte	0x1
	.byte	0x7
	.byte	0x5
	.long	0x44
	.long	.LFB9
	.long	.LFE9
	.byte	0x1
	.byte	0x9c
	.uleb128 0x29
	.string	"led"
	.byte	0x1
	.byte	0x8
	.byte	0x2c
	.long	0x277
	.byte	0x2
	.byte	0x8c
	.sleb128 1
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x55
	.uleb128 0x6
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x16
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x39
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0xd
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x30
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xe
	.uleb128 0x2f
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0xf
	.uleb128 0x2
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x10
	.uleb128 0x35
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x11
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x2007
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0
	.byte	0
	.uleb128 0x12
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x2007
	.uleb128 0xe
	.uleb128 0x32
	.uleb128 0xb
	.uleb128 0x3c
	.uleb128 0xc
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x13
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x14
	.uleb128 0x2f
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x15
	.uleb128 0x2
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x16
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x2007
	.uleb128 0xe
	.uleb128 0x32
	.uleb128 0xb
	.uleb128 0x3c
	.uleb128 0xc
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x17
	.uleb128 0x5
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x34
	.uleb128 0xc
	.byte	0
	.byte	0
	.uleb128 0x18
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x2007
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x32
	.uleb128 0xb
	.uleb128 0x3c
	.uleb128 0xc
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x19
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x2007
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0xc
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1a
	.uleb128 0x39
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x1b
	.uleb128 0x3a
	.byte	0
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x18
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1c
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1d
	.uleb128 0x2e
	.byte	0
	.uleb128 0x47
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x1e
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x47
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x1f
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x20
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x2007
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x1c
	.uleb128 0xd
	.byte	0
	.byte	0
	.uleb128 0x21
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x22
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x47
	.uleb128 0x13
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x23
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x34
	.uleb128 0xc
	.uleb128 0x2
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x24
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x47
	.uleb128 0x13
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x20
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x25
	.uleb128 0x5
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x34
	.uleb128 0xc
	.byte	0
	.byte	0
	.uleb128 0x26
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2007
	.uleb128 0xe
	.uleb128 0x64
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x27
	.uleb128 0x5
	.byte	0
	.uleb128 0x31
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x28
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x29
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x5c
	.word	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0
	.word	0
	.word	0
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.LFB11
	.long	.LFE11-.LFB11
	.long	.LFB13
	.long	.LFE13-.LFB13
	.long	.LFB15
	.long	.LFE15-.LFB15
	.long	.LFB16
	.long	.LFE16-.LFB16
	.long	.LFB17
	.long	.LFE17-.LFB17
	.long	.LFB18
	.long	.LFE18-.LFB18
	.long	.LFB20
	.long	.LFE20-.LFB20
	.long	.LFB21
	.long	.LFE21-.LFB21
	.long	0
	.long	0
	.section	.debug_ranges,"",@progbits
.Ldebug_ranges0:
	.long	.Ltext0
	.long	.Letext0
	.long	.LFB11
	.long	.LFE11
	.long	.LFB13
	.long	.LFE13
	.long	.LFB15
	.long	.LFE15
	.long	.LFB16
	.long	.LFE16
	.long	.LFB17
	.long	.LFE17
	.long	.LFB18
	.long	.LFE18
	.long	.LFB20
	.long	.LFE20
	.long	.LFB21
	.long	.LFE21
	.long	0
	.long	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF8:
	.string	"Direction"
.LASF14:
	.string	"Port_"
.LASF18:
	.string	"Length_"
.LASF36:
	.string	"_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE5writeEb"
.LASF49:
	.string	"GNU C++20 11.2.0 -mn-flash=1 -mdouble=32 -mlong-double=64 -mmcu=avr5 -g -gdwarf-3 -gstrict-dwarf -O0 -O0 -pedantic-errors -std=c++20 -mn-flash=1 -mno-skip-bug -fno-rtti -fno-enforce-eh-specs -fno-exceptions"
.LASF42:
	.string	"value"
.LASF16:
	.string	"uint8_t"
.LASF45:
	.string	"_ZZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE5writeEhE4mask"
.LASF29:
	.string	"_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeILj1EEEvv"
.LASF37:
	.string	"set_direction"
.LASF41:
	.string	"bool"
.LASF19:
	.string	"uint_single_t"
.LASF54:
	.string	"read"
.LASF5:
	.string	"long long int"
.LASF38:
	.string	"_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE13set_directionEv"
.LASF32:
	.string	"RegisterValue<periph::periph_detail::gpio_register_set::DDRx<(periph::Port)0>, 6, 1>"
.LASF3:
	.string	"long int"
.LASF13:
	.string	"address"
.LASF12:
	.string	"PORTx<(periph::Port)0>"
.LASF7:
	.string	"Port"
.LASF11:
	.string	"gpio_register_set"
.LASF30:
	.string	"Value"
.LASF28:
	.string	"write<1>"
.LASF1:
	.string	"unsigned char"
.LASF0:
	.string	"signed char"
.LASF6:
	.string	"long long unsigned int"
.LASF17:
	.string	"type"
.LASF2:
	.string	"unsigned int"
.LASF23:
	.string	"_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv"
.LASF53:
	.string	"RegisterValue<periph::periph_detail::gpio_register_set::PORTx<(periph::Port)0>, 6, 1>"
.LASF34:
	.string	"Gpio"
.LASF44:
	.string	"_ZZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeEhE4mask"
.LASF25:
	.string	"write"
.LASF48:
	.string	"main"
.LASF9:
	.string	"periph"
.LASF47:
	.string	"this"
.LASF46:
	.string	"data"
.LASF52:
	.string	"DDRx<(periph::Port)0>"
.LASF35:
	.string	"_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EEC4Ev"
.LASF20:
	.string	"uint_t"
.LASF4:
	.string	"long unsigned int"
.LASF21:
	.string	"StartBit_"
.LASF33:
	.string	"Gpio<(periph::Port)0, (periph::Pin)6, (periph::Direction)1>"
.LASF43:
	.string	"mask"
.LASF27:
	.string	"_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE5writeEh"
.LASF55:
	.string	"_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EE4readEv"
.LASF26:
	.string	"_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set5PORTxILNS_4PortE0EEELh6ELh1EE5writeEh"
.LASF40:
	.string	"Direction_"
.LASF51:
	.string	"/home/andreas/git/arduino_lib/test/gpio"
.LASF24:
	.string	"_ZN6periph13periph_detail13RegisterValueINS0_17gpio_register_set4DDRxILNS_4PortE0EEELh6ELh1EE12get_addr_ptrEv"
.LASF50:
	.string	"/home/andreas/git/arduino_lib/test/gpio/src/main.cpp"
.LASF31:
	.string	"Register_"
.LASF56:
	.string	"_ZN6periph4GpioILNS_4PortE0ELNS_3PinE6ELNS_9DirectionE1EEC2Ev"
.LASF22:
	.string	"get_addr_ptr"
.LASF10:
	.string	"periph_detail"
.LASF15:
	.string	"required_int_t<1, void>"
.LASF39:
	.string	"Pin_"
	.ident	"GCC: (GNU) 11.2.0"
