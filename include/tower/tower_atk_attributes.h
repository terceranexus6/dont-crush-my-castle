//TITLE: TOWER_ATK_ATTRIBUTES_H
//PROJECT: DON´T CRUSH MY CASTLE
//AUTHOR: Andrés Ortiz
//VERSION: 0.7.5
//DESCRIPTION: defines the kind of attack of buildings
#ifndef TOWER_ATK_ATTRIBUTES
#define TOWER_ATK_ATTRIBUTES

#include "al_anim.h"
enum atk_type {shoot_atk,explosion_atk,continuous_atk};
const string tower_atk_xml_value="Tower_Atk";
//defines the atributes of an attack
struct atk_attributes {
    ALLEGRO_BITMAP *bitmap; //attack bitmap
    al_anim collision_anim; //collision animation (explosion) or continuous
    unsigned int damage; //damage of the attack
    unsigned int range; //range of damage in pixels
    double delay; //delay (in seconds) between attacks (except continuous)
    atk_type type;
    double speed; //speed of attack (in pixels/second)
    //string name ¿?
    //METHODS
    atk_attributes();
    atk_attributes(const XMLElement *attributes_root,const ALLEGRO_TIMER *timer);
    atk_attributes(ALLEGRO_BITMAP *bitmap,al_anim collision_anim,unsigned int damage,unsigned int range,unsigned int delay,double speed,atk_type type=shoot_atk);
    ~atk_attributes();

    bool read_xml(const XMLElement *atk_root,const ALLEGRO_TIMER *timer);
    //clear data (dont destroy animations)
    void clear();
    //destroy all bitmaps and clear data
    void destroy();
    bool check() const;
};
#endif