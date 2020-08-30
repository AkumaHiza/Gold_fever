#include "naglowki.h"
int plan_mapy[15][15]={{0,0,2,0,0,0,0,2,0,0,0,0,0,0,0},  // 0 - there is no wall either on the top or to the right
                       {0,0,2,0,3,0,0,2,0,0,2,0,0,0,0},  // 1 - there is a wall on the top but no on the right
                       {1,1,2,0,0,1,1,2,0,0,2,2,1,1,1},  // 2 - there is no wall on the top, but there is on the right
                       {2,0,0,2,0,0,0,0,1,1,1,0,2,0,0},  // 3 - there is wall on the top and to the right
                       {1,1,0,3,2,0,0,3,0,2,1,1,1,0,0},
                       {0,0,1,1,3,1,1,3,0,0,1,1,1,1,1},
                       {0,0,0,0,2,0,0,2,0,0,0,1,0,0,0},
                       {1,1,3,0,2,0,0,0,1,1,3,0,1,1,1},
                       {0,0,2,0,2,0,0,1,1,1,2,0,2,0,0},
                       {0,2,2,0,3,0,0,1,1,1,2,0,2,1,0},
                       {1,1,2,0,0,0,2,1,1,1,1,0,2,1,0},
                       {0,0,2,0,0,0,2,0,2,0,0,0,0,0,0},
                       {0,0,0,0,1,1,2,0,2,1,0,2,0,1,1},
                       {1,1,0,0,3,0,2,0,2,0,2,2,0,1,1},
                       {0,0,2,0,2,0,1,1,1,1,1,2,0,1,1}};

struct pole
{
    int x;
    int y;
};
//if there is wall around
bool na_prawo_sciana(struct pole p)
{
return ( plan_mapy[p.y][p.x]==2 || plan_mapy[p.y][p.x]==3);
}
bool na_dole_sciana(struct pole p)
{
    return ( plan_mapy[p.y+1][p.x]==1 || plan_mapy[p.y+1][p.x]==3);
}
bool na_lewo_sciana(struct pole p)
{
    return ( plan_mapy[p.y][p.x-1]==2 || plan_mapy[p.y][p.x-1]==3);
}
bool na_gorze_sciana(struct pole p)
{
    return ( plan_mapy[p.y][p.x]==1 || plan_mapy[p.y][p.x]==3);
}
bool prawy_brzeg_planszy(struct pole p)
{
    return p.x >= 14;
}
bool lewy_brzeg_planszy(struct pole p)
{
    return p.x <= 0;
}
bool gorny_brzeg_planszy(struct pole p)
{
    return p.y <= 0;
}
bool dolny_brzeg_planszy(struct pole p)
{
    return p.y >= 14;
}
//where is closest
char gdzie_najblizej(struct pole pole_przeciwnika)
{
    int x=abs(pole_bohatera.x - pole_przeciwnika.x);
    int y=abs(pole_bohatera.y - pole_przeciwnika.y);
    if(x==0) return 'y';
    if(y==0) return 'x';
    if(y>x)return 'x';
    else return 'y';
}
//the same area
int to_samo_pole(struct pole pole_przeciwnika, struct pole wczesniejsze_pole)
{
    if( (pole_przeciwnika.x == wczesniejsze_pole.x) && (pole_przeciwnika.y == wczesniejsze_pole.y) ) return 1;
    else return 0;
}
//if area is taken
bool zajete(int x, int y)
{
  if(x == pole_przeciwnika_niebieskiego.x && y == pole_przeciwnika_niebieskiego.y) return true;
  if(x == pole_przeciwnika_zielonego.x && y == pole_przeciwnika_zielonego.y) return true;
  if(x == pole_przeciwnika_pistacjowego.x && y == pole_przeciwnika_pistacjowego.y) return true;
  if(x == pole_zlota.x && y == pole_zlota.y) return true;
  return false;
}
//if player is dead
int zabojstwo(struct pole pole_bohatera)
{
  if(pole_bohatera.x == pole_przeciwnika_niebieskiego.x && pole_bohatera.y == pole_przeciwnika_niebieskiego.y) return 1;
  if(pole_bohatera.x == pole_przeciwnika_zielonego.x && pole_bohatera.y == pole_przeciwnika_zielonego.y) return 1;
  if(pole_bohatera.x == pole_przeciwnika_pistacjowego.x && pole_bohatera.y == pole_przeciwnika_pistacjowego.y) return 1;
  return 0;
}
