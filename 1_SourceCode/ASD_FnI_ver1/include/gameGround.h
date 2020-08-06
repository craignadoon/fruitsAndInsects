/// #include <iostream>
/// #include "ngl/Camera.h"
/// #include "ngl/Material.h"
/// #include "ngl/Texture.h"
/// #include "ngl/ShaderLib.h"
/// #include "ngl/TransformStack.h"
/// #include "ngl/Vec3.h"
/// #include "include/gameEntities.h"

/// @file   gameGround.h
/// @brief  this class creates the ground/plane for the game
/// @author Navpreet Kaur Pawar
/// @version 1.0
/// @date   27/03/13 Updated to NCCA Coding standard
/// Revision History : \n
/// Initial Version : 27/03/13
/// @class gameEntities
/// @brief this class creates the ground plane for the basket to move on

#ifndef GAMEGROUND_H
#define GAMEGROUND_H

#include <iostream>
#include "ngl/Camera.h"
#include "ngl/Material.h"
#include "ngl/Texture.h"
#include "ngl/ShaderLib.h"
#include "ngl/TransformStack.h"
#include "ngl/Vec3.h"
#include "gameEntities.h"
class gameGround
{
public:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Constructor
    //----------------------------------------------------------------------------------------------------------------------
    gameGround();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Constructor
    //----------------------------------------------------------------------------------------------------------------------
    gameGround(
                gameEntities *_m,
                ngl::Camera *_cam
                );
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief destructor
    //----------------------------------------------------------------------------------------------------------------------
    ~gameGround();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Draw method for drawing the ground
    ///  @param[in]     _shaderName     the shader
    ///  @param[in]     _transformStack the transformation stack
    ///  @param[in]     _cam            the camera
    //----------------------------------------------------------------------------------------------------------------------
    void drawGameGround(
                        const std::string &_shaderName,
                        ngl::TransformStack &_transformStack,
                        ngl::Camera *_cam
                        );
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief load all the transform values to the shader
    /// @param[in]  _tx     the current transform to load
    ///  @param[in] _cam    the camera
    //----------------------------------------------------------------------------------------------------------------------
    void loadMatricesToShader(
                               ngl::TransformStack &_tx,
                               ngl::Camera *_cam
                             )const;
private:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the position of the ground
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 m_pos;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the camera
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Camera *m_cam;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief game entity's pointer to draw the ground
    //----------------------------------------------------------------------------------------------------------------------
    gameEntities *m_gameentity;
}; //end class
#endif // GAMEGROUND_H
//----------------------------------------------------------------------------------------------------------------------
