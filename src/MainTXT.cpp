#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32

#include "winTXT.h"
#include <vector>
#include "Jeu.h"

#include<time.h>
#include <ctime>

using namespace std;

void txtAff(WinTXT & win, const Jeu & jeu) {
	const Terrain &ter = jeu.getTerrain();
	const vector<Personnage> &per = jeu.getPersonnage();
	win.clear();
    
    //Affichage des personnages
    for(unsigned int i=0;i<per.size();i++)
    {
        win.print(per.at(i).getpos().getX(),per.at(i).getpos().getY(),'P');

    }

    //Affichage du Terrain
	for(unsigned int i=0;i<ter.getDimx();i++) // 1ere ligne horizontale
	{
		win.print(i,0,'*');
	}

	for(unsigned int j=0;j<ter.getDimy();j++) //Les 2 lignes verticales
	{
		win.print(0,j,'*');
		win.print(ter.getDimx()-1,j,'*');
	}

	for(unsigned int i=0;i<ter.getDimx();i++) // 2e ligne horizontale
	{
		win.print(i,ter.getDimy()-1,'*');
	}
	
	win.draw();


}

void txtBoucle (Jeu & jeu) {

	WinTXT win (jeu.getTerrain().getDimx(),jeu.getTerrain().getDimy());

	bool stop = false;
	
	
    vector<Personnage> personnageList = jeu.getPersonnage();
       
      

	do
	{
		txtAff(win,jeu);
        
		for(int i = 0; i < personnageList.size(); i++) {
			personnageList[i].Update(0);
		}
		
		#ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

    } while (!stop);

}


int main(int argc, char** argv)
{
	termClear();
	Jeu jeu;
	txtBoucle(jeu);
	termClear();

	return 0;
}
