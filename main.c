#include "naglowki.h"

SDL_Window *window = NULL;
SDL_Surface *screenSurface = NULL;
SDL_Surface *mapa = NULL;
SDL_Surface *bohater = NULL;
SDL_Surface *przeciwnik_niebieski = NULL;
SDL_Surface *przeciwnik_zielony = NULL;
SDL_Surface *przeciwnik_pistacjowy = NULL;
SDL_Surface *zloto = NULL;
SDL_Surface *punkty = NULL;
SDL_Surface *nerka = NULL;
SDL_Surface *die = NULL;
SDL_Rect offset_mapa;
SDL_Rect offset_bohater;
SDL_Rect offset_przeciwnik_niebieski;
SDL_Rect offset_przeciwnik_zielony;
SDL_Rect offset_przeciwnik_pistacjowy;
SDL_Rect offset_zloto;
SDL_Rect offset_punkty;
SDL_Rect offset_score;
SDL_Rect offset_nerka;
SDL_Rect offset_die;

SDL_Color text_color = {0,0,0,0};

struct pole
{
    int x;
    int y;
};

int init()
{
	int success=1;

if(SDL_Init(SDL_INIT_EVERYTHING) < 0 )
	{
		printf("SDL could not initialize! SDL_Error: %s\n",SDL_GetError());
		success=0;
	}
else
	{
		window = SDL_CreateWindow("Gold_fever",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
		if(window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n",SDL_GetError());
			success=0;
		}
		else
		{
			screenSurface = SDL_GetWindowSurface(window);
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFA, 0xEB, 0xD7 ) );
		}
	}
return success;
}
int loadMedia()
{
	int success=1;

	mapa = SDL_LoadBMP( "Graphics/mapa_kolorowana.bmp" );
	if(mapa == NULL )
	{
		printf("Unable to load image %s! SDL Error: %s\n","mapa_kolorowana.bmp",SDL_GetError());
		success=0;
	}

	bohater = SDL_LoadBMP( "Graphics/bohater.bmp" );
	if(bohater == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n","mapa_kolorowana.bmp",SDL_GetError());
		success=0;
    }

    przeciwnik_niebieski = SDL_LoadBMP( "Graphics/przeciwnik_niebieski.bmp" );
	if(przeciwnik_niebieski == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n","pzeciwnik_niebieski.bmp",SDL_GetError());
		success=0;
    }

     przeciwnik_zielony = SDL_LoadBMP( "Graphics/przeciwnik_zielony.bmp" );
	if(przeciwnik_zielony == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n","pzeciwnik_zielony.bmp",SDL_GetError());
		success=0;
    }

     przeciwnik_pistacjowy = SDL_LoadBMP( "Graphics/przeciwnik_pistacjowy.bmp" );
	if(przeciwnik_pistacjowy == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n","pzeciwnik_pistacjowy.bmp",SDL_GetError());
		success=0;
    }

    zloto = SDL_LoadBMP("Graphics/zloto.bmp");
    if(zloto == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n","zloto.bmp",SDL_GetError());
		success=0;
    }

       punkty = SDL_LoadBMP("Graphics/punkty.bmp");
    if(punkty == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n","punkty.bmp",SDL_GetError());
		success=0;
    }
    nerka = SDL_LoadBMP("Graphics/nerka.bmp");
    if(nerka == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n","nerka.bmp",SDL_GetError());
		success=0;
    }
    die = SDL_LoadBMP("Graphics/die.bmp");
    if(die == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n","die.bmp",SDL_GetError());
		success=0;
    }
	return success;
}
void close()
{
	SDL_FreeSurface(punkty);
	punkty = NULL;
	SDL_FreeSurface(bohater);
	bohater = NULL;
	SDL_FreeSurface(przeciwnik_niebieski);
	przeciwnik_niebieski = NULL;
	SDL_FreeSurface(przeciwnik_pistacjowy);
	przeciwnik_pistacjowy = NULL;
	SDL_FreeSurface(przeciwnik_zielony);
	przeciwnik_zielony = NULL;
	SDL_FreeSurface(nerka);
	nerka = NULL;
	SDL_FreeSurface(die);
	die = NULL;
	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}





int main(int argc, char *args[])
{
    char* score = malloc(sizeof(char) * 4);
    strcpy(score, "0");
    int score2 = 0;
    int fontsize = 37;


    offset_mapa.x=300;
    offset_mapa.y=50;

    offset_bohater.x=734;
    offset_bohater.y=486;
    pole_bohatera.x=7;
    pole_bohatera.y=7;

    offset_score.x=1200;
    offset_score.y=206;

    srand(time(NULL));
    struct pole losowe;
    losowe.x=rand()%15;
    losowe.y=rand()%15;
    offset_zloto.x=447+(przesuniecie*losowe.x);
    offset_zloto.y=199+(przesuniecie*losowe.y);
    pole_zlota.x=losowe.x;
    pole_zlota.y=losowe.y;

    offset_przeciwnik_niebieski.x=447;
    offset_przeciwnik_niebieski.y=199;
    pole_przeciwnika_niebieskiego.x=0;
    pole_przeciwnika_niebieskiego.y=0;
    w_p_n.x=-1;
    w_p_n.y=-1;

    offset_przeciwnik_zielony.x=900;
    offset_przeciwnik_zielony.y=322;
    pole_przeciwnika_zielonego.x=11;
    pole_przeciwnika_zielonego.y=3;
    w_p_z.x=-1;
    w_p_z.y=-1;

    offset_przeciwnik_pistacjowy.x=1021;
    offset_przeciwnik_pistacjowy.y=773;
    pole_przeciwnika_pistacjowego.x=14;
    pole_przeciwnika_pistacjowego.y=14;
    w_p_p.x=-1;
    w_p_p.y=-1;

    offset_punkty.x=1100;
    offset_punkty.y=180;

    int quit = 0;
    SDL_Event e;

	if(init()==0 || TTF_Init() == -1)
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		if(loadMedia()==0)
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
		    while(quit==0)
            {
                while( SDL_PollEvent( &e ) != 0 )
                {
                    if( e.type == SDL_KEYDOWN )
                    {
                        switch( e.key.keysym.sym )
                        {
                            case SDLK_x:
	                        quit = 1;
                            break;

                            case SDLK_RIGHT:
                            case SDLK_d:
                                if(!prawy_brzeg_planszy(pole_bohatera) && !na_prawo_sciana(pole_bohatera) )
                                {
                            offset_bohater.x=offset_bohater.x + przesuniecie;
                            pole_bohatera.x=pole_bohatera.x+1;
                                }
                            break;

                            case SDLK_DOWN:
                            case SDLK_s:
                                if(!dolny_brzeg_planszy(pole_bohatera) && !na_dole_sciana(pole_bohatera))
                                {
                            offset_bohater.y=offset_bohater.y + przesuniecie;
                            pole_bohatera.y=pole_bohatera.y+1;
                                }
                            break;

                            case SDLK_UP:
                            case SDLK_w:
                                if(!gorny_brzeg_planszy(pole_bohatera) && !na_gorze_sciana(pole_bohatera))
                                {
                            offset_bohater.y=offset_bohater.y - przesuniecie;
                            pole_bohatera.y=pole_bohatera.y-1;
                                }
                            break;

                            case SDLK_LEFT:
                            case SDLK_a:
                                if(!lewy_brzeg_planszy(pole_bohatera) && !na_lewo_sciana(pole_bohatera))
                                {
                            offset_bohater.x=offset_bohater.x - przesuniecie;
                            pole_bohatera.x=pole_bohatera.x-1;
                                }
                            break;
                        }
int zmiana=0;
if(gdzie_najblizej (pole_przeciwnika_niebieskiego) == 'x')  //Movement of the blue snake horizontally
{
    if(!zajete(pole_przeciwnika_niebieskiego.x+1,pole_przeciwnika_niebieskiego.y) && (pole_bohatera.x > pole_przeciwnika_niebieskiego.x) && !prawy_brzeg_planszy(pole_przeciwnika_niebieskiego) && !na_prawo_sciana(pole_przeciwnika_niebieskiego) && to_samo_pole(pole_przeciwnika_niebieskiego,w_p_n)==0 )
    {
    zmiana=1;
    w_p_n.x=pole_przeciwnika_niebieskiego.x;
    pole_przeciwnika_niebieskiego.x = pole_przeciwnika_niebieskiego.x+1;
    offset_przeciwnik_niebieski.x = offset_przeciwnik_niebieski.x + przesuniecie;
    }
    else if(!zajete(pole_przeciwnika_niebieskiego.x-1,pole_przeciwnika_niebieskiego.y) && !lewy_brzeg_planszy(pole_przeciwnika_niebieskiego) && !na_lewo_sciana(pole_przeciwnika_niebieskiego) && to_samo_pole(pole_przeciwnika_niebieskiego,w_p_n)==0)
    {
    zmiana=1;
    w_p_n.x=pole_przeciwnika_niebieskiego.x;
    pole_przeciwnika_niebieskiego.x = pole_przeciwnika_niebieskiego.x-1;
    offset_przeciwnik_niebieski.x = offset_przeciwnik_niebieski.x - przesuniecie;
    }
}
if(zmiana==0)  //Movement of the blue snake vertically
{
    if(!zajete(pole_przeciwnika_niebieskiego.x,pole_przeciwnika_niebieskiego.y+1) && (pole_bohatera.y > pole_przeciwnika_niebieskiego.y) && !dolny_brzeg_planszy(pole_przeciwnika_niebieskiego) && !na_dole_sciana(pole_przeciwnika_niebieskiego) && to_samo_pole(pole_przeciwnika_niebieskiego,w_p_n)==0 )
    {
    w_p_n.y=pole_przeciwnika_niebieskiego.y;
    pole_przeciwnika_niebieskiego.y = pole_przeciwnika_niebieskiego.y+1;
    offset_przeciwnik_niebieski.y = offset_przeciwnik_niebieski.y + przesuniecie;
    }
    else if(!zajete(pole_przeciwnika_niebieskiego.x,pole_przeciwnika_niebieskiego.y-1) && !gorny_brzeg_planszy(pole_przeciwnika_niebieskiego) && !na_gorze_sciana(pole_przeciwnika_niebieskiego) && to_samo_pole(pole_przeciwnika_niebieskiego,w_p_n)==0)
    {
    w_p_n.y=pole_przeciwnika_niebieskiego.y;
    pole_przeciwnika_niebieskiego.y = pole_przeciwnika_niebieskiego.y-1;
    offset_przeciwnik_niebieski.y = offset_przeciwnik_niebieski.y - przesuniecie;
    }
}

                    zmiana=0;
                    if(gdzie_najblizej (pole_przeciwnika_zielonego) == 'x') //Movement of the green snake horizontally
                    {
                        if(!zajete(pole_przeciwnika_zielonego.x+1,pole_przeciwnika_zielonego.y) && (pole_bohatera.x > pole_przeciwnika_zielonego.x) && !prawy_brzeg_planszy(pole_przeciwnika_zielonego) && !na_prawo_sciana(pole_przeciwnika_zielonego) && to_samo_pole(pole_przeciwnika_zielonego,w_p_z)==0 )
                        {
                        zmiana=1;
                        w_p_z.x=pole_przeciwnika_zielonego.x;
                        pole_przeciwnika_zielonego.x = pole_przeciwnika_zielonego.x+1;
                        offset_przeciwnik_zielony.x = offset_przeciwnik_zielony.x + przesuniecie;
                        }
                        else if(!zajete(pole_przeciwnika_zielonego.x-1,pole_przeciwnika_zielonego.y) && !lewy_brzeg_planszy(pole_przeciwnika_zielonego) && !na_lewo_sciana(pole_przeciwnika_zielonego) && to_samo_pole(pole_przeciwnika_zielonego,w_p_z)==0)
                        {
                        zmiana=1;
                        w_p_z.x=pole_przeciwnika_zielonego.x;
                        pole_przeciwnika_zielonego.x = pole_przeciwnika_zielonego.x-1;
                        offset_przeciwnik_zielony.x = offset_przeciwnik_zielony.x - przesuniecie;
                        }
                    }
                    else if(zmiana==0) //Movement of the green snake vertically
                    {
                        if(!zajete(pole_przeciwnika_zielonego.x,pole_przeciwnika_zielonego.y+1) && (pole_bohatera.y > pole_przeciwnika_zielonego.y) && !dolny_brzeg_planszy(pole_przeciwnika_zielonego) && !na_dole_sciana(pole_przeciwnika_zielonego) && to_samo_pole(pole_przeciwnika_zielonego,w_p_z)==0 )
                        {
                        w_p_z.y=pole_przeciwnika_zielonego.y;
                        pole_przeciwnika_zielonego.y = pole_przeciwnika_zielonego.y+1;
                        offset_przeciwnik_zielony.y = offset_przeciwnik_zielony.y + przesuniecie;
                        }
                        else if(!zajete(pole_przeciwnika_zielonego.x,pole_przeciwnika_zielonego.y-1) && !gorny_brzeg_planszy(pole_przeciwnika_zielonego) && !na_gorze_sciana(pole_przeciwnika_zielonego) && to_samo_pole(pole_przeciwnika_zielonego,w_p_z)==0)
                        {
                        w_p_z.y=pole_przeciwnika_zielonego.y;
                        pole_przeciwnika_zielonego.y = pole_przeciwnika_zielonego.y-1;
                        offset_przeciwnik_zielony.y = offset_przeciwnik_zielony.y - przesuniecie;
                        }
                    }

zmiana=0;
if(gdzie_najblizej (pole_przeciwnika_pistacjowego) == 'x') //Movement of the pistachio snake horizontally
{
    if(!zajete(pole_przeciwnika_pistacjowego.x+1,pole_przeciwnika_pistacjowego.y) && (pole_bohatera.x > pole_przeciwnika_pistacjowego.x) && !prawy_brzeg_planszy(pole_przeciwnika_pistacjowego) && !na_prawo_sciana(pole_przeciwnika_pistacjowego) && to_samo_pole(pole_przeciwnika_pistacjowego,w_p_p)==0 )
    {
    zmiana=1;
    w_p_p.x=pole_przeciwnika_pistacjowego.x;
    pole_przeciwnika_pistacjowego.x = pole_przeciwnika_pistacjowego.x+1;
    offset_przeciwnik_pistacjowy.x = offset_przeciwnik_pistacjowy.x + przesuniecie;
    }
    else if(!zajete(pole_przeciwnika_pistacjowego.x-1,pole_przeciwnika_pistacjowego.y) && !lewy_brzeg_planszy(pole_przeciwnika_pistacjowego) && !na_lewo_sciana(pole_przeciwnika_pistacjowego) && to_samo_pole(pole_przeciwnika_pistacjowego,w_p_p)==0)
    {
    zmiana=1;
    w_p_p.x=pole_przeciwnika_pistacjowego.x;
    pole_przeciwnika_pistacjowego.x = pole_przeciwnika_pistacjowego.x-1;
    offset_przeciwnik_pistacjowy.x = offset_przeciwnik_pistacjowy.x - przesuniecie;
    }
}
else if(zmiana==0) //Movement of the pistachio snake vertically
{
    if(!zajete(pole_przeciwnika_pistacjowego.x,pole_przeciwnika_pistacjowego.y+1) && (pole_bohatera.y > pole_przeciwnika_pistacjowego.y) && !dolny_brzeg_planszy(pole_przeciwnika_pistacjowego) && !na_dole_sciana(pole_przeciwnika_pistacjowego) && to_samo_pole(pole_przeciwnika_pistacjowego,w_p_p)==0 )
    {
    w_p_p.y=pole_przeciwnika_pistacjowego.y;
    pole_przeciwnika_pistacjowego.y = pole_przeciwnika_pistacjowego.y+1;
    offset_przeciwnik_pistacjowy.y = offset_przeciwnik_pistacjowy.y + przesuniecie;
    }
    else if(!zajete(pole_przeciwnika_pistacjowego.x,pole_przeciwnika_pistacjowego.y-1) && !gorny_brzeg_planszy(pole_przeciwnika_pistacjowego) && !na_gorze_sciana(pole_przeciwnika_pistacjowego) && to_samo_pole(pole_przeciwnika_pistacjowego,w_p_p)==0)
    {
    w_p_p.y=pole_przeciwnika_pistacjowego.y;
    pole_przeciwnika_pistacjowego.y = pole_przeciwnika_pistacjowego.y-1;
    offset_przeciwnik_pistacjowy.y = offset_przeciwnik_pistacjowy.y - przesuniecie;
    }
}

if(pole_bohatera.x == pole_zlota.x && pole_bohatera.y == pole_zlota.y) //Collecting gold
{
    losowe.x=rand()%15;
    losowe.y=rand()%15;
    offset_zloto.x=447+(przesuniecie*losowe.x);
    offset_zloto.y=199+(przesuniecie*losowe.y);
    pole_zlota.x=losowe.x;
    pole_zlota.y=losowe.y;
    score2++;
    sprintf(score, "%d", score2);
}
                    }

    TTF_Font* font = TTF_OpenFont("prettyfont.ttf", fontsize);
    if(font == NULL) printf("Can't load font!");
    SDL_Surface *liczba_punktow = TTF_RenderText_Solid(font,score,text_color);

    //Everything on the screen

			SDL_BlitSurface(mapa, NULL,screenSurface, &offset_mapa );
			SDL_BlitSurface(bohater, NULL,screenSurface, &offset_bohater );
			SDL_BlitSurface(przeciwnik_niebieski, NULL,screenSurface, &offset_przeciwnik_niebieski );
			SDL_BlitSurface(przeciwnik_zielony, NULL,screenSurface, &offset_przeciwnik_zielony );
			SDL_BlitSurface(przeciwnik_pistacjowy, NULL,screenSurface, &offset_przeciwnik_pistacjowy );
			SDL_BlitSurface(zloto, NULL,screenSurface, &offset_zloto );
			SDL_BlitSurface(punkty, NULL,screenSurface, &offset_punkty );
			SDL_BlitSurface(liczba_punktow,NULL,screenSurface, &offset_score);

        if(zabojstwo(pole_bohatera)==1) //Dying
        {
        quit=1;
        break;
        }
        else SDL_UpdateWindowSurface(window);
                }
            }
		}

	}
    fontsize=100;
	TTF_Font* font = TTF_OpenFont("prettyfont.ttf", fontsize);
    if(font == NULL) printf("Can't load font!");
    SDL_Surface *liczba_punktow = TTF_RenderText_Solid(font,score,text_color);

    //Player's kidney on the screen
	offset_nerka.x=offset_bohater.x;
    offset_nerka.y=offset_bohater.y;
    SDL_BlitSurface(nerka, NULL, screenSurface, &offset_nerka);

    //Updating  window
    SDL_UpdateWindowSurface(window);
    SDL_Delay(2000);

    offset_die.x=offset_mapa.x;
    offset_die.y=offset_mapa.y;
    offset_score.x=530;
    offset_score.y=620;
    SDL_FillRect(screenSurface,NULL, 0xFAEBDB);

    SDL_BlitSurface(die, NULL, screenSurface, &offset_die);
    SDL_BlitSurface(liczba_punktow,NULL,screenSurface, &offset_score);
    SDL_UpdateWindowSurface(window);
    SDL_Delay(3000);
	close();
    return 0;
}
