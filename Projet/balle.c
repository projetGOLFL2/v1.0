#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "map.h"

#define RAYONBALLE 3
#define DEGTORAD 0.0174533

void creer_balle(int *p, int x, int y){
  //*(p + y*TX + x - 1*TX    ) = 1;
  //*(p + y*TX + x        - 1) = 1;
  *(p + y*TX + x           ) = BALLE;
  //*(p + y*TX + x        + 1) = 1;
  //*(p + y*TX + x + 1*TX    ) = 1;
}

double detecte_mur(int *p, int x, int y){
  double i ;
  double angle = 0 ;
  double cptangle = 0 ;
  double xa, ya ;
  printf("Oui \n") ;

  for(i = 0 ; i < 360 ; i += 15){
    printf("%d",*(p + x + y*TX + (int)((cos(i * DEGTORAD)) * RAYONBALLE) + (int)((sin(i * DEGTORAD)) * RAYONBALLE)));
    if(*(p + x + y*TX + (int)(cos(i * DEGTORAD)) * RAYONBALLE + (int)(sin(i * DEGTORAD)) * RAYONBALLE) == MUR){
      angle += i ;
      cptangle++ ;
      printf("Angle : %.1f ; Cpt : %.1f\n",angle,cptangle);
    }
  }
  if(cptangle == 0)
    return(-1) ;
  return(angle / cptangle) ;
}
