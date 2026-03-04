#ifndef _STD_TYPE_H_ 
#define _STD_TYPE_H_ 


/*unsigned data */

typedef unsigned char              u8  ; 
typedef unsigned short int         u16  ; 
typedef unsigned long int          u32  ; 
typedef unsigned long long int     u64  ; 



/*signed data */

typedef  signed char              s8  ; 
typedef  signed short int         s16  ; 
typedef  signed long int          s32  ; 
typedef  signed long long int     s64  ; 
		 

/*floating date*/

typedef   float     f32  ;
typedef   double    f64 ; 


/*bool data type : T or f */ 

typedef enum {F,T}Bool ; 


/*null pointer */

#define    null   ((void*)0)

/*NUL  Char */

#define  nul   '\0'


#endif 