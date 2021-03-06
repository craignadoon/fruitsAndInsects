/// #include "ngl/Camera.h"
/// #include "ngl/Mat4.h"
/// #include "ngl/Material.h"
/// #include "ngl/Obj.h"
/// #include "ngl/Random.h"
/// #include "ngl/ShaderLib.h"
/// #include "ngl/TransformStack.h"
/// #include "ngl/VAOPrimitives.h"
/// #include "ngl/Vec3.h"
/// #include "gameEntities.h"
/// #include <iostream>

/// @file   fallingChars.h
/// @brief  this class creates the falling characters which the player has to catch
/// @author Navpreet Kaur Pawar
/// @version 1.0
/// @date   27/03/13 Updated to NCCA Coding standard
/// Revision History : \n
/// Initial Version : 27/03/13
/// @class fallingChars
/// @brief this class creates the falling characters of type - fruit, insects, and stones
///         the class associates the id, points, type with each object

#ifndef FALLINGCHARS_H
#define FALLINGCHARS_H

#include "ngl/Camera.h"
#include "ngl/Mat4.h"
#include "ngl/Material.h"
#include "ngl/Obj.h"
#include "ngl/Random.h"
#include "ngl/ShaderLib.h"
#include "ngl/TransformStack.h"
#include "ngl/VAOPrimitives.h"
#include "ngl/Vec3.h"
#include "gameEntities.h"
#include <iostream>

class fallingChars
{
public:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Constructor
    //----------------------------------------------------------------------------------------------------------------------
    fallingChars();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Constructor
    ///  @param[in]     _m      game entity mesh
    ///  @param[in]     _cam    camera
    //----------------------------------------------------------------------------------------------------------------------
    fallingChars(
                 gameEntities *_m,
                 ngl::Camera *_cam
                 );
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief deonstructor
    //----------------------------------------------------------------------------------------------------------------------
    ~fallingChars();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Draw method for drawing the falling characters
    ///  @param[in]     _shader the shader
    ///  @param[in]     _cam    the camera
    //----------------------------------------------------------------------------------------------------------------------
    void draw_FallingChars(const std::string &_shader,
                           ngl::Camera *_cam);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method to move the falling characters in y direction only
    //----------------------------------------------------------------------------------------------------------------------
    void move_FallingChars();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief falling character types
    //----------------------------------------------------------------------------------------------------------------------
    enum fallingCharsType {fruit = 1, insect = 2, stone = 3};
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method to get falling character type
    //----------------------------------------------------------------------------------------------------------------------
    int getFallingCharType(int &i);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method to get falling character ID
    //----------------------------------------------------------------------------------------------------------------------
    int getFallingCharID(int & current);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief  method to get falling haracter position
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 * getFallingCharPos();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method to get falling character radius
    //----------------------------------------------------------------------------------------------------------------------
    int getFallingCharRad();
    //----------------------------------------------------------------------------------------------------------------------
    /// method to get falling character points for each type
    //----------------------------------------------------------------------------------------------------------------------
    int getFallingCharPoints(int &i);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method to set falling character type and points
    //----------------------------------------------------------------------------------------------------------------------
    void setFallingCharTypePoints(int &i);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief falling character radius
    //----------------------------------------------------------------------------------------------------------------------
    float m_fradius;
    //----------------------------------------------------------------------------------------------------------------------
    /// method to set falling character position
    //----------------------------------------------------------------------------------------------------------------------
    void setFallingCharPos();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief current falling character position
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 currentFallingCharPos;
    //----------------------------------------------------------------------------------------------------------------------
    /// current falling character
    //----------------------------------------------------------------------------------------------------------------------
    int currentFallingChar;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method to get the number of falling characters
    //----------------------------------------------------------------------------------------------------------------------
    int getNumberOfFallingChars();
    //----------------------------------------------------------------------------------------------------------------------
    /// status for each falling character if it is collected or not
    //----------------------------------------------------------------------------------------------------------------------
     bool * collectedFlag;
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief falling character positions
     //----------------------------------------------------------------------------------------------------------------------
     ngl::Vec3 *FallingChars_arr;

private:
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief game entity
     //----------------------------------------------------------------------------------------------------------------------
     const gameEntities *m_gameentity;
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief camera
     //----------------------------------------------------------------------------------------------------------------------
     const ngl::Camera *f_camera;
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief transformation stack
     //----------------------------------------------------------------------------------------------------------------------
     ngl::TransformStack f_transform;
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief float colour values
     //----------------------------------------------------------------------------------------------------------------------
     GLfloat *m_colours;
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief points for falling characters
     //----------------------------------------------------------------------------------------------------------------------
     int FallingChars_points;
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief transformation stack
     //----------------------------------------------------------------------------------------------------------------------
     ngl::TransformStack FallingChars_transform;
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief charater type
     //----------------------------------------------------------------------------------------------------------------------
     fallingCharsType chartype;
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief id for each falling character
     //----------------------------------------------------------------------------------------------------------------------
     int *m_id;
}; //end class
#endif // FALLINGCHARS_H
//----------------------------------------------------------------------------------------------------------------------
