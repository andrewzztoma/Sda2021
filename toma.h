#include "base.h"
#ifndef TOMA_H
#define TOMA_H

typedef struct {
    Nat x;
    Nat y;
}sommet;

// structures sommet et polygone
typedef struct elementPolygone {
sommet s;
struct elementPolygone* suivant;
struct elementPolygone* precedent;
} ElementPolygone;
typedef struct {
ElementPolygone* tete;
ElementPolygone* queue;
} Polygone;

Polygone liste_nouv ();
Polygone insert_t(Polygone p , sommet s);
Polygone  suppr_t(Polygone p);
Polygone fermer(Polygone p );
Polygone ouvrir(Polygone p);
Polygone suppr_i(Polygone p , Nat n);


#endif


