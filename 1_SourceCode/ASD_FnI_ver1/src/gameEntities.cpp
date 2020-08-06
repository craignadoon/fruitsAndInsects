//----------------------------------------------------------------------------------------------------------------------
/// @file   gameEntities.h
/// @brief  this class contains all meshes required in the game
/// using this class, we load meshes once which can be attached to objects in game
//----------------------------------------------------------------------------------------------------------------------
#include "include/gameEntities.h"
//----------------------------------------------------------------------------------------------------------------------
gameEntities::~gameEntities()
{
    std::map <std::string, ngl::Obj *> ::iterator ge_begin = m_gameentity.begin();
    std::map <std::string, ngl::Obj *> ::iterator ge_end   = m_gameentity.end();

    while(ge_begin != ge_end)
    {
        delete ge_begin->second;
        ++ge_begin;
    }
}
//----------------------------------------------------------------------------------------------------------------------
void gameEntities::addGameEntity(const std::string &_name,
                                 const std::string &_mesh)
{
    ngl::Obj *mesh = new ngl::Obj(_mesh);
    mesh->createVAO();
    m_gameentity[_name] = mesh;
}
//----------------------------------------------------------------------------------------------------------------------
void gameEntities::addGameEntity(const std::string &_name,
                                 const std::string &_mesh,
                                 const std::string &_texture)
{
    ngl::Obj *mesh = new ngl::Obj(_mesh,_texture);
    mesh->createVAO();
    m_gameentity[_name]=mesh;
}
//----------------------------------------------------------------------------------------------------------------------
ngl::Obj *gameEntities::getGameEntity(std::string _name)
{
    std::map <std::string, ngl::Obj *>::const_iterator ge_begin  = m_gameentity.begin();
    std::map <std::string, ngl::Obj *>::const_iterator ge_entity = m_gameentity.find(_name);  //name of the game entity
    //if it is not the end of the map
    if(ge_begin != m_gameentity.end() && ge_entity != m_gameentity.end())
    {
        return ge_entity->second;  //return the game entity name
    }

}
//----------------------------------------------------------------------------------------------------------------------
void gameEntities::draw(std::string _name) const
{
    std::map <std::string, ngl::Obj *>::const_iterator ge_begin  = m_gameentity.begin();
    std::map <std::string, ngl::Obj *>::const_iterator ge_entity = m_gameentity.find(_name);  //name of the game entity
    //if it is not the end of the map
    if(ge_begin != m_gameentity.end() && ge_entity != m_gameentity.end())
    {
        ge_entity->second->draw();
    }
}
//----------------------------------------------------------------------------------------------------------------------
