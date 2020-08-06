//----------------------------------------------------------------------------------------------------------------------
/// @brief the main re-sizable window which contains a GLWindow widget used to hold our
/// basic gl applications
//----------------------------------------------------------------------------------------------------------------------
#include "include/MainWindow.h"
#include "ui_MainWindow.h"

//----------------------------------------------------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    //create GL window and parent it to this
    m_gl = new gameManager(this);
    //set main grid layout for the main window
    m_ui->s_mainWindowGridLayout->addWidget(m_gl,0,0,2,1);
    // grab keyboard input from the central widget
    // that houses the main gameplay
    m_ui->centralwidget->grabKeyboard();
    // the play button
    connect(m_ui->m_play,SIGNAL(clicked()),m_gl,SLOT(setPlay()));
    // the pause button
    connect(m_ui->m_pause,SIGNAL(clicked()),m_gl,SLOT(setPause()));
    // the game resume button
    connect(m_ui->m_resume,SIGNAL(clicked()),m_gl,SLOT(setResume()));
    // the game exit button
    connect(m_ui->m_exit,SIGNAL(clicked()),m_gl,SLOT(exit_game()));
    //progress bar
    connect(this,SIGNAL(updateBar()),this,SLOT(updateProgBar()));
    // label to update the basket's shield value
    connect(m_gl,SIGNAL(updateShield()),this,SLOT(updateShieldLabel()));
    // label to update player's score value
    connect(m_gl,SIGNAL(updateScore()),this,SLOT(updateScoreLabel()));
}
//----------------------------------------------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete m_ui;
    delete m_gl;
}
//----------------------------------------------------------------------------------------------------------------------
void MainWindow::keyReleaseEvent(QKeyEvent *_event)
{
    // once we have processed any key here pass the event
    // onto the GLWindow class to do more processing
    m_gl->processKeyUp(_event);
}
//----------------------------------------------------------------------------------------------------------------------
void MainWindow::keyPressEvent(
                               QKeyEvent *_event
                              )
{
    // check if there is any update in number of catches
    catchprog();
    // this method is called every time the main window recives a key event.
    // we then switch on the key value and set the camera in the GLWindow
    switch (_event->key())
    {
      case Qt::Key_Escape : QApplication::exit(EXIT_SUCCESS); break;
      case Qt::Key_F : showFullScreen(); break;
      case Qt::Key_N : showNormal(); break;
      case Qt::Key_Up: m_gl->moveBasket_gl();
      default : break;
    }
    // once we have processed any key here pass the event
    // onto the GLWindow class to do more processing
    m_gl->processKeyDown(_event);
}
//----------------------------------------------------------------------------------------------------------------------
bool MainWindow::catchprog()
{
    //if there is an increase in catch count, then return true
    currCatchCount = m_gl->catchProgress();
    if (prevCatchCount < currCatchCount)
    {
        // emit the signal to update bar
        emit updateBar();
        prevCatchCount = currCatchCount;
        return true;
    }
    else
    {
        prevCatchCount = currCatchCount;
        return false;
    }
}
//----------------------------------------------------------------------------------------------------------------------
void MainWindow::updateProgBar()
{
    int progvalue = m_gl->catchProgress();
    //progress = value
    //std::cout<<"\n on_m_progress_valueChanged: value = "<<value;
    m_ui->m_progress->setValue(progvalue);
}
//----------------------------------------------------------------------------------------------------------------------
template<typename S>
std::string value_to_string(const S& val)
{
    std::stringstream ss;
    ss<<val;
    return ss.str();
}
void MainWindow::updateShieldLabel()
{
    int shieldVal = m_gl->shieldLeft();
    std::string shield =  value_to_string(shieldVal);
    m_ui->m_shield->setText(shield.c_str());
}
//----------------------------------------------------------------------------------------------------------------------
void MainWindow::updateScoreLabel()
{
    int scoreVal = m_gl->playerScore();
    std::string score = value_to_string(scoreVal);
    m_ui->m_score->setText(score.c_str());
}
//----------------------------------------------------------------------------------------------------------------------
