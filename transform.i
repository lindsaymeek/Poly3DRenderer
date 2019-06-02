
		IFND	_TRANSFORM_I

SORT_MAX	=	4096			;maximum 4096 objects

_TRANSFORM_I	=	1

;Camera and world objects structure

CAM_LIST	=	0			;list of active objects
CAM_PAN		=	CAM_LIST+listsize	;camera pan,tilt,roll
CAM_TILT	=	CAM_PAN+2
CAM_ROLL	=	CAM_TILT+2
CAM_XO		=	CAM_ROLL+2		;camera location
CAM_YO		=	CAM_XO+4
CAM_ZO		=	CAM_YO+4

CAM_L_XO	=	CAM_ZO+4		;light source location
CAM_L_YO	=	CAM_L_XO+4
CAM_L_ZO	=	CAM_L_YO+4

CAM_SORT_I	=	CAM_L_ZO+4
CAM_SORT_L	=	CAM_SORT_I+2		;sort storage index

CAM_R11		=	CAM_SORT_L+4*SORT_MAX	;objects to sort
CAM_R21		=	CAM_R11+4
CAM_R31		=	CAM_R21+4
CAM_D1		=	CAM_R31+4

CAM_R12		=	CAM_D1+4
CAM_R22		=	CAM_R12+4
CAM_R32		=	CAM_R22+4
CAM_D2		=	CAM_R32+4

CAM_R13		=	CAM_D2+4
CAM_R23		=	CAM_R13+4
CAM_R33		=	CAM_R23+4
CAM_D3		=	CAM_R33+4

CAM_SIZE	=	CAM_D3+4

;Object structure v2.0

OBJ_NODE	=	0		;Attach node

OBJ_PANLR	=	OBJ_NODE+nodesize	;Requested rotation
OBJ_PANL	=	OBJ_PANLR+2		;Current rotation

OBJ_TILTLR	=	OBJ_PANL+2
OBJ_TILTL	=	OBJ_TILTLR+2

OBJ_ROLLLR	=	OBJ_TILTL+2
OBJ_ROLLL	=	OBJ_ROLLLR+2

OBJ_SPAN	=	OBJ_ROLLL+2
OBJ_CPAN	=	OBJ_SPAN+2
OBJ_STILT	=	OBJ_CPAN+2
OBJ_CTILT	=	OBJ_STILT+2
OBJ_SROLL	=	OBJ_CTILT+2
OBJ_CROLL	=	OBJ_SROLL+2

OBJ_XO		=	OBJ_CROLL+2	;Object origin in world coordinates
OBJ_YO		=	OBJ_XO+4
OBJ_ZO		=	OBJ_YO+4

OBJ_SCALE	=	OBJ_ZO+4	;Scaling on object size

OBJ_VISIBLE	=	OBJ_SCALE+2	;Visible flag (0=no visible)
OBJ_UNDRAWN	=	OBJ_VISIBLE+2	;Drawn flag (0=not drawn)

OBJ_XT		=	OBJ_UNDRAWN+2	;Bounding box for object
OBJ_YT		=	OBJ_XT+2
OBJ_XS		=	OBJ_YT+2
OBJ_YS		=	OBJ_XS+2

OBJ_POINT_LIST	=	OBJ_YS+2	;List of points

OBJ_POLY_LIST	=	OBJ_POINT_LIST+listsize	;List of polygons

OBJ_SIZE	=	OBJ_POLY_LIST+listsize

;Point structure v2.0

PNT_NODE	=	0		;attach node

PNT_XS		=	PNT_NODE+nodesize
PNT_YS		=	PNT_XS+2

PNT_XW		=	PNT_YS+2	;World coordinate of point
PNT_YW		=	PNT_XW+4
PNT_ZW		=	PNT_YW+4

PNT_XL		=	PNT_ZW+4	;original reference point (local)
PNT_YL		=	PNT_XL+2
PNT_ZL		=	PNT_YL+2

PNT_XLR		=	PNT_ZL+2	;second reference point
PNT_YLR		=	PNT_XLR+4
PNT_ZLR		=	PNT_YLR+4
	
PNT_SIZE	=	PNT_ZLR+4

		ENDC
