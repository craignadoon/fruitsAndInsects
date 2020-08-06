//----------------------------------------------------------------------------------------------------------------------
/// @class gameEntities
/// @brief this class creates the sphere primitive to define the game environment
//----------------------------------------------------------------------------------------------------------------------
#include "include/gameWorld.h"
//----------------------------------------------------------------------------------------------------------------------
gameWorld::gameWorld(
                        std::string _texture,
                        std::string _texture2,
                        ngl::Camera *_cam
                    )
{
    ngl::Texture t(_texture);
    m_texID=t.setTextureGL();
    ngl::Texture t2(_texture2);
    m_texID2=t2.setTextureGL();
    ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();
    prim->createSphere("starmap",100,200);
    m_camera=_cam;
}
//----------------------------------------------------------------------------------------------------------------------
gameWorld::~gameWorld()
{
    delete m_camera;
}
//----------------------------------------------------------------------------------------------------------------------
void gameWorld::draw(
                    const std::string &_shaderName,
                    ngl::TransformStack &_transformStack
                    )const
{
    ngl::ShaderLib *shader=ngl::ShaderLib::instance();
    ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();

    glEnable (GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    shader->use(_shaderName);

    _transformStack.pushTransform();
    {
        glBindTexture(GL_TEXTURE_2D,m_texID);
        prim->draw("starmap");
    }
    _transformStack.popTransform();
    glDisable(GL_BLEND);
}
//----------------------------------------------------------------------------------------------------------------------
