//----------------------------------------------------------------------------------------------------------------------
/// @file   basket.cpp
/// @brief  basket class for the player to catch the falling characters
//----------------------------------------------------------------------------------------------------------------------
#include "include/basket.h"
//----------------------------------------------------------------------------------------------------------------------
const static float s_xExtents=30;
const static float s_yExtents=30;
const static float s_zExtents=30;
//----------------------------------------------------------------------------------------------------------------------
basket::basket(
                ngl::Vec3 _pos,
                gameEntities *_m,
                ngl::Camera *_cam
                )
{
//initialze the basket
    //basket radius
    m_basketRad = 5;
    //basket position
    m_basketPos  = _pos;
    // the game entity mesh
    m_GameEntity = _m;
    //the camera
    m_camera = _cam;
    //basket's rotation
    m_basketRot  = 0;
    //set the basket/player's initial score to null
    m_basketScore = 0;
    //the initial shield for the player/basket
    m_basketShield = 10;
    //basket's flag to check if hit by stone, set to 'false' initially
    m_hit=false;
}
//----------------------------------------------------------------------------------------------------------------------
basket::basket()
{
    //basket radius
    m_basketRad = 5;
    //basket position
    m_basketPos.set(0,-25,0);
    //set the basket/player's initial score to null
    m_basketScore = 0;
    //the initial shield for the player/basket
    m_basketShield = 10;
}
//----------------------------------------------------------------------------------------------------------------------
basket::~basket()
{
    delete m_GameEntity;
}

//----------------------------------------------------------------------------------------------------------------------
void basket::drawBasket(
                        const std::string &_shaderName,
                        ngl::TransformStack &_transformStack,
                        ngl::Camera *_cam
                        )
{
    //create an instance of the shader
    ngl::ShaderLib *shader = ngl::ShaderLib::instance();
    shader->use(_shaderName);

    //the camera eye is set to basket's position
    ngl::Vec4 _pos;
    _pos.set(m_basketPos);
    _pos.set(m_basketPos.m_x,m_basketPos.m_y+30,m_basketPos.m_z-60);
    _cam->setEye(_pos);

    //transformations
    _transformStack.pushTransform();
    {
        _transformStack.setPosition(m_basketPos);
        _transformStack.setRotation(0,m_basketRot,0);
        loadMatricesToShader(_transformStack,_cam);
        //check if the basket is hit by stone
        if (m_hit)
        {
            // if yes, draw the mesh for hit basket
            m_GameEntity->draw("hitbasket");
        }
        else
        {
            m_GameEntity->draw("basket");
        }
        //draw the normal basket mesh
        m_GameEntity->draw("basket");
    }
     _transformStack.popTransform();
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}
//----------------------------------------------------------------------------------------------------------------------
template<typename T>
void clamp(
            T& v,
            const T& m,
            const T& M
            )
{
    v = std::min(M,std::max(m,v));
}
//----------------------------------------------------------------------------------------------------------------------
void basket::moveBasket(
                        float bx,
                        float bz
                        )
{
    //updating the basket position in x and z axis
    m_basketPos.m_x += bx;
    m_basketPos.m_z += bz;
    // making sure that the basket stays in the permissible area
    clamp(m_basketPos.m_x,-s_xExtents,+s_xExtents);
    clamp(m_basketPos.m_z,-s_zExtents,+s_zExtents);
}
//----------------------------------------------------------------------------------------------------------------------

void basket::rotateBasket(
                            float _rot
                          )
{
    //basket's rotation
    m_basketRot += _rot;
}
//----------------------------------------------------------------------------------------------------------------------
void basket::reduceShield()
{
    //reducing the shield value by 1 if hit by a stone
    m_basketShield = m_basketShield - 1;
}
//----------------------------------------------------------------------------------------------------------------------
int basket::getBasketShield()
{
    return m_basketShield;
}
//----------------------------------------------------------------------------------------------------------------------
void basket::updateScore(int &_type)
{
    //for falling chartype - fruit
    if(_type == 1)
    {
        //increase score
        m_basketScore+=100;
    }
    //for falling chartype - insect
    if(_type == 2)
    {
        //decrease score
        m_basketScore-=50;
    }
}
//----------------------------------------------------------------------------------------------------------------------
int basket::getBasketScore()
{
    return m_basketScore;
}
//----------------------------------------------------------------------------------------------------------------------
ngl::Vec3 basket::getBasketPos()
{
    return m_basketPos;
}
//----------------------------------------------------------------------------------------------------------------------
float basket::getBasketRad()
{
    return m_basketRad;
}
//----------------------------------------------------------------------------------------------------------------------
void basket::loadMatricesToShader(
                                    ngl::TransformStack &_tx,
                                    ngl::Camera *_cam
                                  ) const
{
    ngl::ShaderLib *shader=ngl::ShaderLib::instance();

    ngl::Mat4 MV;
    ngl::Mat4 MVP;
    MV=_tx.getCurrAndGlobal().getMatrix()*_cam->getViewMatrix() ;
    MVP=MV*_cam->getProjectionMatrix();
    shader->setShaderParamFromMat4("MVP",MVP);
}
//----------------------------------------------------------------------------------------------------------------------
