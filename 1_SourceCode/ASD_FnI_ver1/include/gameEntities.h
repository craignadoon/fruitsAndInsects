/// #include <map>
/// #include <string>
/// #include "ngl/Obj.h"

/// @file   gameEntities.h
/// @brief  this class contains all the meshes used in the game
/// @author Navpreet Kaur Pawar
/// @version 1.0
/// @date   27/03/13 Updated to NCCA Coding standard
/// Revision History : \n
/// Initial Version : 27/03/13
/// @class gameEntities
/// @brief this class contains all meshes required in the game
/// using this class, we load meshes once which can be attached to objects in game

#ifndef GAMEENTITIES_H
#define GAMEENTITIES_H

#include <map>
#include <string>
#include "ngl/Obj.h"

class gameEntities
{
public:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Constructor
    //----------------------------------------------------------------------------------------------------------------------
    gameEntities(){;}
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief deconstructor
    //----------------------------------------------------------------------------------------------------------------------
    ~gameEntities();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method to add a mesh with no texture
    /// @param[in] _name    the name of the model to use for lookup
    /// @param[in] _mesh    the path / name of the mesh
    //----------------------------------------------------------------------------------------------------------------------
    void addGameEntity(
                        const std::string &_name,
                        const std::string &_mesh
                        );
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief add a mesh with a texture
    /// @param[in] the name of the model we wish to use for lookup
    /// @param[in] the path / name of the mesh
    /// @param[in] the path / name of the texture
    //----------------------------------------------------------------------------------------------------------------------
    void addGameEntity(
                        const std::string &_name,
                        const std::string &_mesh,
                        const std::string &_texture
                        );
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief accesor to the model, incase the caller
    /// wishes to modify the mesh etc
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Obj *getGameEntity(std::string _name);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method to draw the mesh, all tx must be executed before
    /// the call to draw
    ///  @param[in] the name of the mesh to draw
    //----------------------------------------------------------------------------------------------------------------------
    void draw(std::string _name) const;

private:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief a map to hold our meshes by name
    //----------------------------------------------------------------------------------------------------------------------
    std::map <std::string, ngl::Obj *>m_gameentity;

}; //end class
#endif // GAMEENTITIES_H
//----------------------------------------------------------------------------------------------------------------------
