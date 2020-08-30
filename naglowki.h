#ifndef NAGLOWKI_H_
#define NAGLOWKI_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <time.h>
#include <string.h>

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900
#define przesuniecie  41

int plan_mapy[15][15];

struct pole;
struct pole pole_bohatera;
struct pole pole_przeciwnika_niebieskiego;
struct pole pole_przeciwnika_zielonego;
struct pole pole_przeciwnika_pistacjowego;
struct pole pole_zlota;

struct pole w_p_n;
struct pole w_p_z;
struct pole w_p_p;

bool na_prawo_sciana(struct pole);
bool na_dole_sciana(struct pole);
bool na_lewo_sciana(struct pole);
bool na_gorze_sciana(struct pole);

bool prawy_brzeg_planszy(struct pole);
bool lewy_brzeg_planszy(struct pole);
bool gorny_brzeg_planszy(struct pole);
bool dolny_brzeg_planszy(struct pole);

char gdzie_najblizej(struct pole);
int to_samo_pole(struct pole,struct pole);
bool zajete(int,int);
int zabojstwo(struct pole);

#endif // NAGLOWKI_H_
