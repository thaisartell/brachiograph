.include "xc.inc"

.text                       ;BP (put the following data in ROM(program memory))

; This is a library, thus it can *not* contain a _main function: the C file will
; define main().  However, we will need a .global statement to make available ASM
; functions to C code.
; All functions utilized outside of this file will need to have a leading 
; underscore (_) and be included in a comment delimited list below.
.global _delay_100_us, _delay_1_ms, _setCLKDIV
    
_setCLKDIV:
    bclr    CLKDIV,#8                 ;BP
    return

_delay_100_us:	    ; goal is 1600
		    ; 2 cycle for call
    repeat #1593    ; 1 cycle
    nop		    ; 1+1593 cycle
    return	    ; 3 cycle
    
_delay_1_ms:	    ; goal is 16000
		    ; 2 cycle for call
    repeat #15993   ; 1 cycle
    nop		    ; 1+1593 cycle
    return	    ; 3 cycle


