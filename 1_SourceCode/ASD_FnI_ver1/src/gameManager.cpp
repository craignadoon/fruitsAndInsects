//----------------------------------------------------------------------------------------------------------------------
/// @class gameManager
/// @brief our main glwindow widget for NGL applications all drawing elements are
/// put in this file.
/// it is the game's main class and create the game world with all its haracters.
/// it checks for collisions between the falling characters and the basket
//----------------------------------------------------------------------------------------------------------------------
#include "include/gameManager.h"
//----------------------------------------------------------------------------------------------------------------------
/// @brief the increment for x/y translation with mouse movement
//----------------------------------------------------------------------------------------------------------------------
const static float INCREMENT=0.01;
//----------------------------------------------------------------------------------------------------------------------
/// @brief the increment for the wheel zoom
//----------------------------------------------------------------------------------------------------------------------
const static float ZOOM=0.1;
//----------------------------------------------------------------------------------------------------------------------
/// @brief basket's update in position
//----------------------------------------------------------------------------------------------------------------------
const static float g_BasketUpdate=2.5;
//----------------------------------------------------------------------------------------------------------------------
/// @brief random height for the collected falling characters in the basket
//----------------------------------------------------------------------------------------------------------------------
ngl::Random *randmove = ngl::Random::instance();
float moveup = randmove->randomPositiveNumber(6);
//----------------------------------------------------------------------------------------------------------------------
gameManager::gameManager(QWidget *_parent): QGLWidget( new CreateCoreGLContext(QGLFormat::defaultFormat()), _parent )
{
    // set this widget to have the initial keyboard focus
    setFocus();
    // re-size the widget to that of the parent (in this case the GLFrame passed in on construction)
    this->resize(_parent->size());
    // now we start a timer and assign it to the g_updatetimer_basket variable
    m_updateTimer = startTimer(60);
    m_redrawTimer = startTimer(120);
    // clear the key set
    m_keysPressed.clear();
    //game play and pause flags
    playFlag = false;
    pauseFLag = false;
    //mouse rotation values set to 0
    m_rotate=false;
    m_spinXFace=0;
    m_spinYFace=0;
    m_origX=0;
    m_origY=0;
}
//----------------------------------------------------------------------------------------------------------------------
gameManager::~gameManager()
{
    delete m_gameWorld;
    delete m_gameGround;
    delete m_fallingChars;
    delete m_Basket;
    delete m_light;
    delete m_cam;
}
//----------------------------------------------------------------------------------------------------------------------
/// @brief This virtual function is called once before the first call to paintGL() or resizeGL(),
/// and then once whenever the widget has been assigned a new QGLContext.
/// This function should set up any required OpenGL context rendering flags, defining display lists, etc.
//----------------------------------------------------------------------------------------------------------------------
void gameManager::initializeGL()
{
    // Black Background
    glClearColor(0, 0, 0, 1.0f);
    // enable depth testing for drawing
    glEnable(GL_DEPTH_TEST);
    // we need to initialise the NGL lib, under windows and linux we also need to
    // initialise GLEW, under windows this needs to be done in the app as well
    // as the lib hence the WIN32 define
    ngl::NGLInit *Init = ngl::NGLInit::instance();
    Init->initGlew();
    #ifdef WIN32
        glewInit(); // need a local glew init as well as lib one for windows
    #endif
    // load the shader and set the values
    // grab an instance of shader manager
    ngl::ShaderLib *shader=ngl::ShaderLib::instance();
    // shader - Phong
    shader->createShaderProgram("Phong");
    // now we are going to create empty shaders for Frag and Vert
    shader->attachShader("PhongVertex",ngl::VERTEX);
    shader->attachShader("PhongFragment",ngl::FRAGMENT);
    // attach the source
    shader->loadShaderSource("PhongVertex","others/Phong.vs");
    shader->loadShaderSource("PhongFragment","others/Phong.fs");
    // compile the shaders
    shader->compileShader("PhongVertex");
    shader->compileShader("PhongFragment");
    // add them to the program
    shader->attachShaderToProgram("Phong","PhongVertex");
    shader->attachShaderToProgram("Phong","PhongFragment");
    // now bind the shader attributes for most NGL primitives we use the following
    // layout attribute 0 is the vertex data (x,y,z)
    shader->bindAttribute("Phong",0,"inVert");
    // attribute 1 is the UV data u,v (if present)
    shader->bindAttribute("Phong",1,"inUV");
    // attribute 2 are the normals x,y,z
    shader->bindAttribute("Phong",2,"inNormal");
    // now we have associated this data we can link the shader
    shader->linkProgramObject("Phong");
    // and make it active ready to load values
    (*shader)["Phong"]->use();

    // texture shader
    ngl::ShaderLib *shader1=ngl::ShaderLib::instance();
    // we are creating a shader called Texture
    shader1->createShaderProgram("Texture");
    // now we are going to create empty shaders for Frag and Vert
    shader1->attachShader("TextureVertex",ngl::VERTEX);
    shader1->attachShader("TextureFragment",ngl::FRAGMENT);
    // attach the source
    shader1->loadShaderSource("TextureVertex","others/TextureVertex.glsl");
    shader1->loadShaderSource("TextureFragment","others/TextureFragment.glsl");
    // compile the shaders
    shader1->compileShader("TextureVertex");
    shader1->compileShader("TextureFragment");
    // add them to the program
    shader1->attachShaderToProgram("Texture","TextureVertex");
    shader1->attachShaderToProgram("Texture","TextureFragment");
    // now we have associated this data we can link the shader
    shader1->linkProgramObject("Texture");
    // (*shader1)["Texture"]->use();

    //CAMERA
    ngl::Vec3 from(0,20,-80);
    ngl::Vec3 to(0,0,0);
    ngl::Vec3 up(0,1,0);
    // load the coordinates to camera
    m_cam= new ngl::Camera(from,to,up,ngl::PERSPECTIVE);
    // set the shape using FOV 45 Aspect Ratio based on Width and Height
    // The final two are near and far clipping planes of 0.5 and 10
    m_cam->setShape(45,(float)720.0/576.0,0.05,350,ngl::PERSPECTIVE);
    shader1->setShaderParam3f("viewerPos",m_cam->getEye().m_x,m_cam->getEye().m_y,m_cam->getEye().m_z);

    //LIGHT -after the camera(to pass the transpose of projection mx to LIGHT, for eye space correction
    ngl::Mat4 iv=m_cam->getViewMatrix();
    iv.transpose();
    m_light = new ngl::Light(ngl::Vec3(50,50,2),ngl::Colour(1,1,1,1),ngl::Colour(1,1,1,1),ngl::DIRECTIONALLIGHT);
    m_light->setAttenuation(1,0,0);
    m_light->setTransform(iv);
    // load these values to the shader as well
    m_light->loadToShader("light");

    //GAME CHARACTERS
    // create the basket with an initial catch count of zero
    catchCount = 0; //no of catches in the basket;
    m_Basket = new basket(ngl::Vec3(0,-30,0),&m_gameentity,m_cam);
    // falling characters
    m_fallingChars = new fallingChars(&m_gameentity,m_cam);
    // set the position o falling characters
    m_fallingChars->setFallingCharPos();
    // game ground
    m_gameGround = new gameGround(&m_gameentity,m_cam);
    // game world/environment
    m_gameWorld = new gameWorld("textures/JungleBackground.png","textures/JungleBackground.png",m_cam);

    //game heads up display text
    m_hud = new ngl::Text(QFont("Arial",30));

    // add GAME ENTITY meshes and textures
    m_gameentity.addGameEntity("basket","models/fruitBasket.obj","textures/wickerBasket.png");
    m_gameentity.addGameEntity("hitbasket","models/gardenBasket.obj","textures/damage.png");
    m_gameentity.addGameEntity("FallingChars_fruit","models/fallingFruit.obj","textures/redfruit.png");
    m_gameentity.addGameEntity("FallingChars_insect","models/insect.obj","textures/greenOrangeInsect.png");
    m_gameentity.addGameEntity("FallingChars_stone","models/stone.obj","textures/rock.png");
    m_gameentity.addGameEntity("GameWorld","models/gameGround.obj","textures/ground.png");
}

//----------------------------------------------------------------------------------------------------------------------
/// @brief  This virtual function is called whenever the widget has been resized.
///         The new size is passed in width and height.
//----------------------------------------------------------------------------------------------------------------------
void gameManager::resizeGL(int _w,int _h)
{
  glViewport(0,0,_w,_h);
  m_cam->setShape(45,(float)_w/_h,0.5,150,ngl::PERSPECTIVE);
  m_hud->setScreenSize(_w,_h);

}
//----------------------------------------------------------------------------------------------------------------------
void gameManager::loadMatricesToShader(ngl::TransformStack &_tx)
{
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  ngl::Mat4 MVP=m_cam->getVPMatrix() * _tx.getCurrAndGlobal().getMatrix();
  shader->setShaderParamFromMat4("MVP",MVP);

}
//----------------------------------------------------------------------------------------------------------------------
/// @brief  This virtual function is called whenever the widget needs to be painted.
///         this is our main drawing routine
//----------------------------------------------------------------------------------------------------------------------
void gameManager::paintGL()
{

  // clear the screen and depth buffer
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  // build our transform stack
  ngl::Transformation trans;
  //trans.setRotation(m_spinX);
  // Rotation based on the mouse position for our global transform
  ngl::Mat4 rotX;
  ngl::Mat4 rotY;
  // create the rotation matrices
  rotX.rotateX(m_spinXFace);
  rotY.rotateY(m_spinYFace);
  // multiply the rotations
  ngl::Mat4 final=rotY*rotX;
  // add the translations
  final.m_m[3][0] = m_modelPos.m_x;
  final.m_m[3][1] = m_modelPos.m_y;
  final.m_m[3][2] = m_modelPos.m_z;
  // set this in the TX stack
  trans.setMatrix(final);
  m_transformStack.setGlobal(trans);

  //draw the game entities
  m_Basket->drawBasket("Texture",m_transformStack,m_cam);
  m_fallingChars->draw_FallingChars("Texture",m_cam);
  m_gameGround->drawGameGround("Texture",m_transformStack,m_cam);
  m_gameWorld->draw("Texture",m_transformStack);

  // check if basket's shield is over. if yes, game over..
  if ((m_Basket->getBasketShield()) <= 0)
  {
       m_hud->setColour(1,1,1);
       m_hud->renderText(20,40,QString("Game Over...!!!"));
       m_hud = new ngl::Text(QFont("Arial",15));
       m_hud->setColour(0.9,0.8,0.7);
       m_hud->renderText(20,100,QString("...u shud have avoided the stones"));
       playFlag = false;
  }
  // continue to move the characters if there is no pause or exit.
  if((playFlag == true) && (pauseFLag == false))
   {
    moveFallingChars_gl();
    moveBasket_gl();
   }
}
//----------------------------------------------------------------------------------------------------------------------
void gameManager::setPlay()
{
    playFlag = true;
}
//----------------------------------------------------------------------------------------------------------------------
void gameManager::setPause()
{
    pauseFLag = true;
}
//----------------------------------------------------------------------------------------------------------------------
void gameManager::setResume()
{
    pauseFLag = false;
}
//----------------------------------------------------------------------------------------------------------------------
/// @brief this overloaded method is called every time the timers trigger
//----------------------------------------------------------------------------------------------------------------------
void gameManager::timerEvent(QTimerEvent *_event)
{
    // the usual process is to check the event timerID and compare it to
    // any timers we have started with startTimer
    if (_event->timerId() == m_updateTimer)
    {
        checkCatch();
    }
    if (_event->timerId() == m_redrawTimer)
    {
        updateGL();
    }
}
//----------------------------------------------------------------------------------------------------------------------
void gameManager::moveBasket_gl()
{
    // first we reset the movement values
    float xDirection=0.0;
    //float yDirection=0.0;
    float zDirection=0.0;

    float rotation=0.0;
    foreach(Qt::Key key, m_keysPressed)
    {
        switch (key)
        {
            case Qt::Key_Left :  { xDirection =  g_BasketUpdate /*+ m_velo*/; break;}
            case Qt::Key_Right : { xDirection = -g_BasketUpdate /*+ m_velo*/; break;}
            case Qt::Key_Up :    { zDirection =  g_BasketUpdate; break;}
            case Qt::Key_Down :  { zDirection = -g_BasketUpdate; break;}
            case Qt::Key_R :     { rotation=1.0; break;}
            default : break;
        }
    }
    m_Basket->moveBasket(xDirection,zDirection);
    // if the set is non zero size we can update the basket movement
    // then tell openGL to re-draw
    if(m_keysPressed.size() !=0)
    {
        m_Basket->moveBasket(xDirection,zDirection);
        m_Basket->rotateBasket(rotation);
    }
}
//----------------------------------------------------------------------------------------------------------------------
void gameManager::moveFallingChars_gl()
{
    m_fallingChars->move_FallingChars();
}
//----------------------------------------------------------------------------------------------------------------------
/// @brief this method is called from the MainWindow class and passed
/// the key event from that, if we didn't need to process the events in main
/// window we could just overload this as the keyPressEvent and only process here.
//----------------------------------------------------------------------------------------------------------------------
void gameManager::processKeyDown(QKeyEvent *_event)
{
    // add to our keypress set the values of any keys pressed
    m_keysPressed += (Qt::Key)_event->key();
}
//----------------------------------------------------------------------------------------------------------------------
/// @brief in this case this method is called from the MainWindow class and passed
/// the key event from that, if we didn't need to process the events in main
/// window we could just overload this as the keyPressEvent and only process here.
//----------------------------------------------------------------------------------------------------------------------
void gameManager::processKeyUp(QKeyEvent *_event)
{
    // remove from our key set any keys that have been released
    m_keysPressed -= (Qt::Key)_event->key();
}
//----------------------------------------------------------------------------------------------------------------------
bool gameManager::basketFallingCharCollision(
                                ngl::Vec3 _pos1,
                                float _rad1,
                                ngl::Vec3 _pos2,
                                float _rad2
                                )
{
    ngl::Vec3 relPos;

    //distance between basket and falling char
    GLfloat dist;
    GLfloat minDist;
    GLfloat len;

    relPos = _pos1 - _pos2;
    len = relPos.length();
    dist = len*len;
    minDist = _rad1 + _rad2;

    //check if there is a catch
    if(dist<= (minDist * minDist))
    {   return true;    }
    else
    {   return false;   }
}
//----------------------------------------------------------------------------------------------------------------------
void gameManager::checkCatch()
{

    float basketRad=m_Basket->getBasketRad();
    float fallingCharRad = 2.0f;

    int fallingCharNum = m_fallingChars->getNumberOfFallingChars();

    for(int i=0;i<fallingCharNum;++i)
    {
        ngl::Vec3 basketPos=m_Basket->getBasketPos();
        ngl::Vec3 * fallingCharPos = m_fallingChars->getFallingCharPos();

        bool charCatch = basketFallingCharCollision(basketPos,
                                                    basketRad,
                                                    fallingCharPos[i],
                                                    fallingCharRad);
        if ((charCatch == true) && (m_fallingChars->collectedFlag[i] == false))
        {
            // increase the catch count
            catchCount++;
            // set the collected flag for the falling character to true,
            // so that it is not available for collection again
            m_fallingChars->collectedFlag[i] = true;
            // get the type of collected falling character
            int ftype = m_fallingChars->getFallingCharType(i);
            m_Basket->updateScore(ftype);
            emit updateScore();
            if (ftype == 3)
            {
                m_Basket->reduceShield();
                emit updateShield();
                m_Basket->m_hit = true;
                m_Basket->drawBasket("Texture",m_transformStack,m_cam);
            }
            m_Basket->m_hit = false;
        }
        if(m_fallingChars->collectedFlag[i] == true)
        {
            float moveside = randmove->randomNumber(2);
            ngl::Vec3 newPos = m_Basket->getBasketPos();
            newPos.m_x -=moveside;
            newPos.m_y +=moveup;
            m_fallingChars->FallingChars_arr[i] = newPos;
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
int gameManager::catchProgress()
{
    return catchCount;
}
//----------------------------------------------------------------------------------------------------------------------
int gameManager::shieldLeft()
{
    return(m_Basket->getBasketShield());
}
//----------------------------------------------------------------------------------------------------------------------
int gameManager::playerScore()
{
    return(m_Basket->getBasketScore());
}
//----------------------------------------------------------------------------------------------------------------------
void gameManager::exit_game()
{
    QApplication::exit(EXIT_SUCCESS);
}

//----------------------------------------------------------------------------------------------------------------------
template<typename MO>
void clampmouse(MO& v, const MO& m, const MO& M)
{
    v = std::min(M,std::max(m,v));
}
void gameManager::mouseMoveEvent (
                                    QMouseEvent * _event
                                 )
{
    // note the method buttons() is the button state when event was called
    // this is different from button() which is used to check which button was
    // pressed when the mousePress/Release event is generated
    if(m_rotate && _event->buttons() == Qt::LeftButton)
    {
      int diffx=_event->x()-m_origX;
      int diffy=_event->y()-m_origY;
      //m_spinXFace += (float) 0.5f * diffy;
      m_spinXFace += (float) 0.5f * diffy;
      m_spinYFace += (float) 0.5f * diffx;
      clampmouse (m_spinXFace, 5, 25);
      m_origX = _event->x();
      m_origY = _event->y();
      updateGL();
    }
    // right mouse translate code
    else if(m_translate && _event->buttons() == Qt::RightButton)
    {
      int diffX = (int)(_event->x() - m_origXPos);
      int diffY = (int)(_event->y() - m_origYPos);
      m_origXPos=_event->x();
      m_origYPos=_event->y();
      m_modelPos.m_x += INCREMENT * diffX;
      m_modelPos.m_y -= INCREMENT * diffY;
      updateGL();
    }
}
//----------------------------------------------------------------------------------------------------------------------
void gameManager::mousePressEvent (
                                    QMouseEvent * _event
                                  )
{
    // this method is called when the mouse button is pressed in this case we
    // store the value where the maouse was clicked (x,y) and set the Rotate flag to true
    if(_event->button() == Qt::LeftButton)
    {
      m_origX = _event->x();
      m_origY = _event->y();
      m_rotate =true;
    }
    // right mouse translate mode
    else if(_event->button() == Qt::RightButton)
    {
      m_origXPos = _event->x();
      m_origYPos = _event->y();
      m_translate=true;
    }
}
//----------------------------------------------------------------------------------------------------------------------
void gameManager::mouseReleaseEvent (
                                        QMouseEvent * _event
                                    )
{
    // this event is called when the mouse button is released
    // we then set Rotate to false
    if (_event->button() == Qt::LeftButton)
    {
        m_rotate=false;
    }
    // right mouse translate mode
    if (_event->button() == Qt::RightButton)
    {
        m_translate=false;
    }
}
//----------------------------------------------------------------------------------------------------------------------
void gameManager::wheelEvent(
                                QWheelEvent *_event
                            )
{
    // check the diff of the wheel position (0 means no change)
    if(_event->delta() > 0)
    {
        m_modelPos.m_z+=ZOOM;
    }
    else if(_event->delta() <0 )
    {
        m_modelPos.m_z-=ZOOM;
    }
    updateGL();
}
//----------------------------------------------------------------------------------------------------------------------
