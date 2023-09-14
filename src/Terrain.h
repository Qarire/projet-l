#ifndef _TERRAIN_H
#define _TERRAIN_H


class Terrain {

private:
    
    int dimx, dimy; /** @brief les deux dimension du terrain */

public:

    Terrain();
    /** @brief Constructeur par défaut; **/
    
    Terrain(unsigned int x, unsigned int y);
    /** @brief Constructeur par copie */
    
    ~Terrain();
    /** @brief Destructeur par défaut **/

    unsigned int getDimx() const;
    /** @brief Recupere la dimension x du Terrain **/

    unsigned int getDimy() const;
    /** @brief Recupere la dimension du y du Terrain **/


}
#endif
