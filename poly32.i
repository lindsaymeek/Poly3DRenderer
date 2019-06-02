
		IFND	_POLY32_I

_POLY32_I	=	1

;Screen info structure (used for minimising clear operation)

SCREEN_X1	=	0
SCREEN_Y1	=	SCREEN_X1+2
SCREEN_X2	=	SCREEN_Y1+2
SCREEN_Y2	=	SCREEN_X2+2
SCREEN_SIZE	=	SCREEN_Y2+2

POLY_NODE	=	0
POLY_VERTICES	=	POLY_NODE+nodesize
POLY_COLOUR	=	POLY_VERTICES+2			;main colour
POLY_TEXTURE	=	POLY_COLOUR+2			;mask that defines cross hatch between the two
POLY_VISIBLE	=	POLY_TEXTURE+2
POLY_HIGHEST	=	POLY_VISIBLE+2
POLY_X		=	POLY_HIGHEST+2
POLY_Y		=	POLY_X+2
POLY_XS		=	POLY_Y+2
POLY_YS		=	POLY_XS+2
POLY_DATA	=	POLY_YS+2
POLY_VERTICE	=	POLY_DATA+4

POLY_SIZE	=	POLY_VERTICE	;Note: +SIZE*4

;
;Point X and Y offsets
;

POINT_X		=	nodesize
POINT_Y		=	POINT_X+2

		ENDC

