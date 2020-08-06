//----------------------------------------------------------------------------------------------------------------------
/// @class fallingChars
/// @brief this class creates the falling characters of type - fruit, insects, and stones
///         the class associates the id, points, type with each object
//----------------------------------------------------------------------------------------------------------------------
#include "include/fallingChars.h"

const static int s_numPoints=10;
const static int FallingChars_num = 100;
int fallingCharCount=0;
//----------------------------------------------------------------------------------------------------------------------
fallingChars::fallingChars()
{
     m_fradius = 2;
     m_id = NULL;
     FallingChars_arr->set(0.0f,30.0f,0.0f);
     chartype = fruit;
}
//----------------------------------------------------------------------------------------------------------------------
fallingChars::fallingChars(
                            gameEntities *_m,
                            ngl::Camera *_cam
                           )
{
    m_gameentity= _m;
    f_camera = _cam;
    m_fradius = 2;
    m_id = NULL;
    chartype = fruit;
}
//----------------------------------------------------------------------------------------------------------------------
/// @brief deconstructor
//----------------------------------------------------------------------------------------------------------------------
fallingChars::~fallingChars()
{
    delete m_gameentity;
    delete m_id;
    delete FallingChars_arr;
    delete collectedFlag;

}
//----------------------------------------------------------------------------------------------------------------------
int fallingChars::getNumberOfFallingChars()
{
    return FallingChars_num;
}
//----------------------------------------------------------------------------------------------------------------------
void fallingChars::setFallingCharPos()
{
    FallingChars_arr = new ngl::Vec3[FallingChars_num];
    m_id = new int[FallingChars_num];

    ngl::Random *rand=ngl::Random::instance();
    for(int f =0; f<FallingChars_num; ++f)
    {
        //generating random position for the characters
        FallingChars_arr[f]=rand->getRandomVec3();
        FallingChars_arr[f].m_x=FallingChars_arr[f].m_x*10.0f*3.0f;
        FallingChars_arr[f].m_y = 30.0f;
        FallingChars_arr[f].m_z=FallingChars_arr[f].m_z*23.0f;
        m_id[f]=f;
        collectedFlag[f] = false;
        setFallingCharTypePoints(f);
    }
}
//----------------------------------------------------------------------------------------------------------------------
void fallingChars::setFallingCharTypePoints(int &i)
{
    if (m_id[i]<60)
    {
        chartype = fruit;
        FallingChars_points = 100;
    }
    else{
        if (m_id[i]>80)
        {
            chartype = stone;
            FallingChars_points = 0;
        }
        else
        {
            chartype = insect;
            FallingChars_points = -50;
        }
    }

}
//----------------------------------------------------------------------------------------------------------------------
void fallingChars::draw_FallingChars(const std::string &_shader,ngl::Camera *_cam)
{
    ngl::ShaderLib *shader=ngl::ShaderLib::instance();
    (*shader)[_shader]->use();

    for( int i=0; i<FallingChars_num; ++i)
    {
        FallingChars_transform.getCurrentTransform().setPosition(FallingChars_arr[i]);
        ngl::Mat4 MVP = FallingChars_transform.getCurrentTransform().getMatrix() * _cam->getVPMatrix();
        shader->setShaderParamFromMat4("MVP",MVP);
        int ctype = getFallingCharType(i);
        if (ctype == 1)
            {
                m_gameentity->draw("FallingChars_fruit");
            }
            else {
                if (ctype == 2)
                    {
                    m_gameentity->draw("FallingChars_insect");
                    }
                else {if (ctype == 3)
                        {
                            m_gameentity->draw("FallingChars_stone");
                        }
                      }
                    }

    }

 }
//----------------------------------------------------------------------------------------------------------------------

int fallingChars::getFallingCharType(int &i)
{
    if (m_id[i]<60)
    {
        return fruit;
    }
    else{
        if (m_id[i]>80)
        {
            return stone;
        }
        else
        {
            return insect;
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
int fallingChars::getFallingCharPoints(int &i)
{
    if (m_id[i]<60)
    {
        return 100;
    }
    else{
        if (m_id[i]>80)
        {
            return 0;
        }
        else
        {
            return -50;
        }
    }
}
//----------------------------------------------------------------------------------------------------------------------
ngl::Vec3 * fallingChars::getFallingCharPos()
{
    return FallingChars_arr;
}
//----------------------------------------------------------------------------------------------------------------------
int fallingChars::getFallingCharRad()
{
    return m_fradius;
}
//----------------------------------------------------------------------------------------------------------------------
int fallingChars::getFallingCharID(int & current)
{
    return m_id[current];
}
//----------------------------------------------------------------------------------------------------------------------
void fallingChars::move_FallingChars()
{
    for(int i=0;i<FallingChars_num;++i)
    {
        if((FallingChars_arr[i].m_y <= -26.0) && (collectedFlag[i] == false))
        {
            FallingChars_arr[i].m_y = 30.0;
        }
        ngl::Random *rand=ngl::Random::instance();
        float randfall=10*(rand->randomPositiveNumber());
        FallingChars_arr[i].m_y-=1/randfall;  //reduce y to make them fall
    }
}
//----------------------------------------------------------------------------------------------------------------------
