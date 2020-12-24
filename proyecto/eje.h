#ifndef EJE_H
#define EJE_H


class Coordenada
{
public:
    int col;
    int fil;
    Coordenada(int a, int b);
    friend bool operator== (const Coordenada &a,const Coordenada &b){
        return a.fil == b.fil && b.col == a.col;
    }
};

#endif // EJE_H
