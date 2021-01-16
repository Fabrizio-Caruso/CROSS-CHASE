; VGA charset for the Gamate conio implementation

.export fontdata

.rodata

fontdata:
        .byte   $00, $00, $00, $00, $00, $00, $00, $00

    .byte 0,  0,  0,255,  0,  0,  0,  0
        ; .byte   %00000000
        ; .byte   %00000000
        ; .byte   %00000000
        ; .byte   %11111111
        ; .byte   %00000000
        ; .byte   %00000000
        ; .byte   %00000000
        ; .byte   %00000000

    .byte 24, 24, 24, 48, 24, 12, 24, 24
        ; .byte   %00010000
        ; .byte   %00010000
        ; .byte   %00010000
        ; .byte   %00011000
        ; .byte   %00110000
        ; .byte   %00010000
        ; .byte   %00010000
        ; .byte   %00010000

; down
    .byte 24, 36, 24,102,153, 24, 36, 102
	 ; .byte    %00011000
	 ; .byte    %00100100
	 ; .byte    %00011000
	 ; .byte    %01100110
	 ; .byte    %10011001
	 ; .byte    %00011000
	 ; .byte    %00100100
	 ; .byte    %01100110

; up
    .byte 24, 60, 24,102,153, 24, 36,102
	 ; .byte    %00011000
	 ; .byte    %00111100
	 ; .byte    %00011000
	 ; .byte    %01100110
	 ; .byte    %10011001
	 ; .byte    %00011000
	 ; .byte    %00100100
	 ; .byte    %01100110

; right
    .byte 24, 52, 25,118,152, 24, 20, 20
	 ; .byte    %00011000
	 ; .byte    %00110100
	 ; .byte    %00011001
	 ; .byte    %01110111
	 ; .byte    %10011000
	 ; .byte    %00011000
	 ; .byte    %00101000
	 ; .byte    %00101000	 

; left
    .byte 24, 44,152,110, 25, 24, 40, 40
	 ; .byte    %00011000
	 ; .byte    %00101100
	 ; .byte    %10011000
	 ; .byte    %11101110
	 ; .byte    %00011001
	 ; .byte    %00011000
	 ; .byte    %00101000
	 ; .byte    %00101000	 

; bomb
    .byte 60, 66,165,153,153,165, 66, 60
	 ; .byte    %00111100
	 ; .byte    %01000010
	 ; .byte    %10100101
	 ; .byte    %10011001
	 ; .byte    %10011001
	 ; .byte    %10100101
	 ; .byte    %01000010
	 ; .byte    %00111100

; skull
    .byte 60, 66,165,129, 90, 36, 36, 60
	 ; .byte    %00111100
	 ; .byte    %01000010
	 ; .byte    %10100101
	 ; .byte    %10000001
	 ; .byte    %01011010
	 ; .byte    %00100100
	 ; .byte    %00100100
	 ; .byte    %00111100 


; ghost
    .byte 189,66,165,129,129,153,129,126
	 ; .byte    %10111101
	 ; .byte    %01000010
	 ; .byte    %10100101
	 ; .byte    %10000001
	 ; .byte    %10000001
	 ; .byte    %10011001
	 ; .byte    %10000001
	 ; .byte    %01111110


; dead ghost
.byte 189,66,165,165,129,153,129,126
;.byte $00,$80,$7e,$c8,$f8,$c0,$80,$00

; power-up S
    .byte 0, 60, 102,223,231,122, 36, 24
; .byte $00,$3c,$66,$df,$e7,$7a,$24,$18

; power-up F
.byte 0,60,66,207,195,102,36,24
; .byte $00,$3C,$42,$CF,$C3,$66,$24,$14
        
; unused power-up H
.byte $00,$3c,$5a,$db,$c3,$5A,$3c,$18

; gun
.byte 0,128,126,200,248,192,128,  0
; .byte $00,$80,$7e,$c8,$f8,$c0,$80,$00
 
; power-up H 
;.byte   $99, $5A, $3C, $E7, $E7, $3C, $5A, $99
; .byte $00,$3c,$5a,$db,$c3,$5A,$3c,$18
.byte 0,60,90,219,195,90,60,24

; bullet
; .byte   $80, $E0, $F8, $FE, $F8, $E0, $80, $00
; .byte 0,  0,  8, 56, 28, 16,  0,  0
.byte 0,  0,  8, 56, 28, 16,  0,  0

;        .byte   $02, $0E, $3E, $FE, $3E, $0E, $02, $00
; .byte 24, 36, 24,  0,153,  0, 36,102
.byte 24, 36, 24,  0,153,  0, 36,102

; rocket
; .byte   $18, $3C, $7E, $18, $18, $7E, $3C, $18
.byte  24, 60, 60, 60,126, 90, 66, 66


; left missile
; .byte   $66, $66, $66, $66, $66, $00, $66, $00
.byte 0,  0,240, 63, 63,240,  0,  0

; right missile
; .byte   $7F, $DB, $DB, $7B, $1B, $1B, $1B, $00
.byte 0,  0, 15,252,252, 15,  0,  0

;        .byte   $3E, $63, $38, $6C, $6C, $38, $CC, $78
; dead ghost
.byte 189,66,165,165,129,153,129,126

        ;.byte   $00, $00, $00, $00, $7E, $7E, $7E, $00
        ;.byte   $18, $3C, $7E, $18, $7E, $3C, $18, $FF
        ;.byte   $18, $3C, $7E, $18, $18, $18, $18, $00
        ;.byte   $18, $18, $18, $18, $7E, $3C, $18, $00
        ;.byte   $00, $18, $0C, $FE, $0C, $18, $00, $00
        ;.byte   $00, $30, $60, $FE, $60, $30, $00, $00
        
        .byte 255,255,0,48,48,0,255,255

        .byte 255,255,0,48,48,0,255,255

        .byte 255,255,0,48,48,0,255,255

        .byte 255,255,0,48,48,0,255,255

        .byte 255,255,0,48,48,0,255,255

        .byte 255,255,0,48,48,0,255,255
        .byte   $00, $00, $C0, $C0, $C0, $FE, $00, $00
        .byte   $00, $24, $66, $FF, $66, $24, $00, $00
        .byte   $00, $18, $3C, $7E, $FF, $FF, $00, $00
        .byte   $00, $FF, $FF, $7E, $3C, $18, $00, $00
        .byte   $00, $00, $00, $00, $00, $00, $00, $00
        .byte   $30, $78, $78, $78, $30, $00, $30, $00
        .byte   $6C, $6C, $6C, $00, $00, $00, $00, $00
        .byte   $6C, $6C, $FE, $6C, $FE, $6C, $6C, $00
        .byte   $30, $7C, $C0, $78, $0C, $F8, $30, $00
        .byte   $00, $C6, $CC, $18, $30, $66, $C6, $00
        .byte   $38, $6C, $38, $76, $DC, $CC, $76, $00
        .byte   $60, $60, $C0, $00, $00, $00, $00, $00
        .byte   $18, $30, $60, $60, $60, $30, $18, $00
        .byte   $60, $30, $18, $18, $18, $30, $60, $00
        .byte   $00, $66, $3C, $FF, $3C, $66, $00, $00
        .byte   $00, $30, $30, $FC, $30, $30, $00, $00
        .byte   $00, $00, $00, $00, $00, $30, $30, $60
        .byte   $00, $00, $00, $FC, $00, $00, $00, $00
        .byte   $00, $00, $00, $00, $00, $30, $30, $00
        .byte   $06, $0C, $18, $30, $60, $C0, $80, $00
        .byte   $7C, $C6, $CE, $DE, $F6, $E6, $7C, $00
        .byte   $30, $70, $30, $30, $30, $30, $FC, $00
        .byte   $78, $CC, $0C, $38, $60, $CC, $FC, $00
        .byte   $78, $CC, $0C, $38, $0C, $CC, $78, $00
        .byte   $1C, $3C, $6C, $CC, $FE, $0C, $1E, $00
        .byte   $FC, $C0, $F8, $0C, $0C, $CC, $78, $00
        .byte   $38, $60, $C0, $F8, $CC, $CC, $78, $00
        .byte   $FC, $CC, $0C, $18, $30, $30, $30, $00
        .byte   $78, $CC, $CC, $78, $CC, $CC, $78, $00
        .byte   $78, $CC, $CC, $7C, $0C, $18, $70, $00
        .byte   $00, $30, $30, $00, $00, $30, $30, $00
        .byte   $00, $30, $30, $00, $00, $30, $30, $60
        .byte   $18, $30, $60, $C0, $60, $30, $18, $00
        .byte   $00, $00, $FC, $00, $00, $FC, $00, $00
        .byte   $60, $30, $18, $0C, $18, $30, $60, $00
        .byte   $78, $CC, $0C, $18, $30, $00, $30, $00
        .byte   $7C, $C6, $DE, $DE, $DE, $C0, $78, $00
        .byte   $30, $78, $CC, $CC, $FC, $CC, $CC, $00
        .byte   $FC, $66, $66, $7C, $66, $66, $FC, $00
        .byte   $3C, $66, $C0, $C0, $C0, $66, $3C, $00
        .byte   $F8, $6C, $66, $66, $66, $6C, $F8, $00
        .byte   $7E, $60, $60, $78, $60, $60, $7E, $00
        .byte   $7E, $60, $60, $78, $60, $60, $60, $00
        .byte   $3C, $66, $C0, $C0, $CE, $66, $3E, $00
        .byte   $CC, $CC, $CC, $FC, $CC, $CC, $CC, $00
        .byte   $78, $30, $30, $30, $30, $30, $78, $00
        .byte   $1E, $0C, $0C, $0C, $CC, $CC, $78, $00
        .byte   $E6, $66, $6C, $78, $6C, $66, $E6, $00
        .byte   $60, $60, $60, $60, $60, $60, $7E, $00
        .byte   $C6, $EE, $FE, $FE, $D6, $C6, $C6, $00
        .byte   $C6, $E6, $F6, $DE, $CE, $C6, $C6, $00
        .byte   $38, $6C, $C6, $C6, $C6, $6C, $38, $00
        .byte   $FC, $66, $66, $7C, $60, $60, $F0, $00
        .byte   $78, $CC, $CC, $CC, $DC, $78, $1C, $00
        .byte   $FC, $66, $66, $7C, $6C, $66, $E6, $00
        .byte   $78, $CC, $E0, $70, $1C, $CC, $78, $00
        .byte   $FC, $30, $30, $30, $30, $30, $30, $00
        .byte   $CC, $CC, $CC, $CC, $CC, $CC, $FC, $00
        .byte   $CC, $CC, $CC, $CC, $CC, $78, $30, $00
        .byte   $C6, $C6, $C6, $D6, $FE, $EE, $C6, $00
        .byte   $C6, $C6, $6C, $38, $38, $6C, $C6, $00
        .byte   $CC, $CC, $CC, $78, $30, $30, $78, $00
        .byte   $FE, $06, $0C, $18, $30, $60, $FE, $00
        .byte   $78, $60, $60, $60, $60, $60, $78, $00
        .byte   $C0, $60, $30, $18, $0C, $06, $02, $00
        .byte   $78, $18, $18, $18, $18, $18, $78, $00
        .byte   $10, $38, $6C, $C6, $00, $00, $00, $00
        .byte   $00, $00, $00, $00, $00, $00, $00, $FF
        .byte   $30, $30, $18, $00, $00, $00, $00, $00
        .byte   $00, $00, $78, $0C, $7C, $CC, $76, $00
        .byte   $E0, $60, $60, $7C, $66, $66, $DC, $00
        .byte   $00, $00, $78, $CC, $C0, $CC, $78, $00
        .byte   $1C, $0C, $0C, $7C, $CC, $CC, $76, $00
        .byte   $00, $00, $78, $CC, $FC, $C0, $78, $00
        .byte   $38, $6C, $60, $F0, $60, $60, $F0, $00
        .byte   $00, $00, $76, $CC, $CC, $7C, $0C, $F8
        .byte   $E0, $60, $6C, $76, $66, $66, $E6, $00
        .byte   $30, $00, $70, $30, $30, $30, $78, $00
        .byte   $0C, $00, $0C, $0C, $0C, $CC, $CC, $78
        .byte   $E0, $60, $66, $6C, $78, $6C, $E6, $00
        .byte   $70, $30, $30, $30, $30, $30, $78, $00
        .byte   $00, $00, $CC, $FE, $FE, $D6, $C6, $00
        .byte   $00, $00, $F8, $CC, $CC, $CC, $CC, $00
        .byte   $00, $00, $78, $CC, $CC, $CC, $78, $00
        .byte   $00, $00, $DC, $66, $66, $7C, $60, $F0
        .byte   $00, $00, $76, $CC, $CC, $7C, $0C, $1E
        .byte   $00, $00, $DC, $76, $66, $60, $F0, $00
        .byte   $00, $00, $7C, $C0, $78, $0C, $F8, $00
        .byte   $10, $30, $7C, $30, $30, $34, $18, $00
        .byte   $00, $00, $CC, $CC, $CC, $CC, $76, $00
        .byte   $00, $00, $CC, $CC, $CC, $78, $30, $00
        .byte   $00, $00, $C6, $D6, $FE, $FE, $6C, $00
        .byte   $00, $00, $C6, $6C, $38, $6C, $C6, $00
        .byte   $00, $00, $CC, $CC, $CC, $7C, $0C, $F8
        .byte   $00, $00, $FC, $98, $30, $64, $FC, $00
        .byte   $1C, $30, $30, $E0, $30, $30, $1C, $00
        .byte   $18, $18, $18, $00, $18, $18, $18, $00
        .byte   $E0, $30, $30, $1C, $30, $30, $E0, $00
        .byte   $76, $DC, $00, $00, $00, $00, $00, $00
        .byte   $00, $10, $38, $6C, $C6, $C6, $FE, $00

