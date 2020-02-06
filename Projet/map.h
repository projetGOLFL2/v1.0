#define TX 240
#define TY 80

typedef enum{
  VIDE, MUR, BALLE, TRAINEE
}map_objet;

void *lire_map(char *s);
void aff_map(int *p);
