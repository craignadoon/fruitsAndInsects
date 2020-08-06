/// #include <string>
/// #include "ngl/Camera.h"
/// #include <ngl/ShaderLib.h>
/// #include <ngl/Texture.h>
/// #include "ngl/TransformStack.h"
/// #include <ngl/Transformation.h>
/// #include "ngl/Types.h"
/// #include <ngl/VAOPrimitives.h>

/// @file   gameWorld.h
/// @brief  this class creates the surrounding environment for the game
/// @author Navpreet Kaur Pawar
/// @version 1.0
/// @date   27/03/13 Updated to NCCA Coding standard
/// Revision History : \n
/// Initial Version : 27/03/13
/// @class gameEntities
/// @brief this class creates the sphere primitive to define the game environment

#ifndef __GAMEWORLD_H__
#define __GAMEWORLD_H__

#include <string>
#include "ngl/Camera.h"
#include "ngl/ShaderLib.h"
#include "ngl/Texture.h"
#include "ngl/TransformStack.h"
#include "ngl/Transformation.h"
#include "ngl/Types.h"
#include "ngl/VAOPrimitives.h"

class gameWorld
{
  public :
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Constructor
    //----------------------------------------------------------------------------------------------------------------------
    gameWorld(std::string _texture,
            std::string _texture2
           , ngl::Camera *_cam);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief deconstructor
    //----------------------------------------------------------------------------------------------------------------------
    ~gameWorld();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Draw method for drawing the world
    ///  @param[in]     _shaderName     the shader
    ///  @param[in]     _transformStack the transformation stack
    ///  @param[in]     _cam            the camera
    //----------------------------------------------------------------------------------------------------------------------
    void draw(
                const std::string &_shaderName,
                ngl::TransformStack &_transformStack
                )const ;
  private :
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief texture 1
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_texID;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief texture 2
    //----------------------------------------------------------------------------------------------------------------------
    GLuint m_texID2;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the camera
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Camera *m_camera;
};

#endif
