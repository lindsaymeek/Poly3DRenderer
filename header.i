
;Header for the directory WORK:ASSEM/POLYFILLA

				IFND WORK_ASSEM_POLYFILLA
WORK_ASSEM_POLYFILLA		=	1

CUSTOM			=	1
		include	"chk_root:global.i"

;Includes for external directories
		include	"chk_root:INIT.i"
		include	"chk_root:LISTS.i"
		include	"chk_root:SOUND.i"
		include	"chk_root:IRQ.i"
		include	"chk_root:TASKER.i"
		include	"chk_root:SCREEN.i"
		include	"chk_root:RING.i"
		include	"chk_root:DEBUG.i"
		include	"chk_root:TEXT.i"
		include	"chk_root:KEYBOARD.i"

;Includes for this directory
		include	"POLY32.i"
		include	"TRANSFORM.i"

				ENDC
