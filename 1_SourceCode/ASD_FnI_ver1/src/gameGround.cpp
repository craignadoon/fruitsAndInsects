//----------------------------------------------------------------------------------------------------------------------
/// @class gameGround
/// @brief this class creates the ground plane for the basket to move on#include "include/gameGround.h"
//----------------------------------------------------------------------------------------------------------------------
#include "include/gameGround.h"
//----------------------------------------------------------------------------------------------------------------------
/// @brief Constructor
//----------------------------------------------------------------------------------------------------------------------
gameGround::gameGround()
{
    m_pos.set(0,-30,0);
}
//----------------------------------------------------------------------------------------------------------------------
/// @brief Constructor
//----------------------------------------------------------------------------------------------------------------------
gameGround::gameGround(
                        gameEntities *_m,
                        ngl::Camera *_cam
                        )
{
    m_cam          = _cam;
    m_gameentity   = _m;
    m_pos.set(0,-30,0);
}
//----------------------------------------------------------------------------------------------------------------------
/// @brief deconstructor
//----------------------------------------------------------------------------------------------------------------------
gameGround::~gameGround()
{
    delete m_gameentity;
    delete m_cam;
}
//----------------------------------------------------------------------------------------------------------------------
void gameGround::drawGameGround(
                                const std::string &_shaderName,
                                ngl::TransformStack &_transformStack,
                                ngl::Camera *_cam
                                )
{
    ngl::ShaderLib *shader = ngl::ShaderLib::instance();        //create an instance of the shader
    shader->use(_shaderName);

    _transformStack.pushTransform();
    {
        _transformStack.getCurrentTransform().setPosition(m_pos);;    //transformation stack
        loadMatricesToShader(_transformStack,_cam);
        m_gameentity->draw("GameWorld");
    }
    _transformStack.popTransform();
}
//----------------------------------------------------------------------------------------------------------------------
void gameGround::loadMatricesToShader(
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
