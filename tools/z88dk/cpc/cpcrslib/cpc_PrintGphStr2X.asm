; ******************************************************
; **       Librer�a de rutinas para Amstrad CPC       **
; **	   Ra�l Simarro, 	  Artaburu 2007       **
; ******************************************************

GLOBAL cpc_PrintGphStr2X


GLOBAL cpc_PrintGphStr0
GLOBAL direcc_destino0

.cpc_PrintGphStr2X
;preparaci�n datos impresi�n. El ancho y alto son fijos!
	ld ix,2
	add ix,sp
	
	ld l,(ix+0)
	ld h,(ix+1)	;destino
	;ld (cpc_PrintGphStr0+direcc_destino0),hl
	
   	ld e,(ix+2)
	ld d,(ix+3)	;texto origen
	ld a,1
 JP cpc_PrintGphStr0