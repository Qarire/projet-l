#ifndef _TERRAIN_H
#define _TERRAIN_H


class Terrain {

private:
    
    unsigned int dimx, dimy; /** @brief les deux dimension du terrain */

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

    void setDimx(unsigned int dimx1);
    /** @brief Modifie la dimension en x du Terrain **/
    void setDimy(unsigned int dimy1);
    /** @brief Modifie la dimension en y du Terrain **/

};
#endif
