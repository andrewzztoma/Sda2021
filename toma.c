#include "toma.h"
Polygone liste_nouv(){
    Polygone p ;
    p.queue=NULL;
    p.tete=NULL;
    return p;
}

Polygone insert_t(Polygone p , sommet s){
    ElementPolygone *cour = p.tete;

    while (cour!=NULL)
    {
        if (cour->s.x==s.x&&cour->s.y==s.y)
        {
            return p;
        }
        cour=cour->suivant;
    }
    ElementPolygone *new = MALLOC(ElementPolygone);
    new->precedent=NULL;
    new->s=s;
    new->suivant=p.tete;
    if (p.tete != NULL) 
    {
     p.tete->precedent = new;
    }
    else 
    {
     p.queue = new;
    }
    p.tete=new;
    return p;

}

Polygone suppr_t(Polygone p){ //liste non vide 
    if (p.tete==p.queue)
    {
        FREE(p.tete);
        return liste_nouv();
    }
    
    ElementPolygone* ancien_tete = p.tete;
    p.tete = p.tete->suivant;
    p.tete->precedent= NULL;
    FREE(ancien_tete);
    return p;

}
Polygone fermer(Polygone p){ //p non vide 
    if (p.tete->precedent==p.queue && p.queue ->suivant== p.tete)
    {
        return p;
    }
    
    if (p.tete==p.queue)
    {
        p.tete->suivant=p.tete->precedent=p.tete;
    }
    else
    {
        p.tete->precedent=p.queue;
        p.queue->suivant=p.tete;
    }

    return p;
}

Polygone ouvrir_t(Polygone p){ //p non vide 
    
    if (p.tete->precedent == NULL && p.queue->suivant == NULL)
    {
        return p;
    }
    else
    {
        p.tete->precedent =NULL;
        p.queue->suivant = NULL;
        return p;
    }
}

Polygone suppr_i(Polygone p , Nat n){ //p non vide et n appartient a long(p)
    if (n==0) return suppr_t(p);
    ElementPolygone *temp = p.tete;
    for (Nat i = 0 ;i < n && temp != NULL; i++)
    {
        temp= temp->suivant;
    }
    ElementPolygone *prev = temp->precedent;
    ElementPolygone *next = temp->suivant;
    if(prev!=NULL) prev->suivant=next;
    if(next!=NULL) next->precedent=prev;
    if(temp==p.queue)p.queue=prev;
    FREE(temp);
    return p;


    
}

Nat dist(sommet a, sommet b){ return abs(b.x - a.x)+ abs(b.y - a.y);}

Nat perimetre(Polygone p){ //p non vide 
    Nat perim = 0;
    ElementPolygone *temp = p.tete;
    do
    {
        perim+=dist(temp->s,temp->suivant->s);
        temp=temp->suivant;

    } while (temp!=p.queue);

    return perim;
    

}
