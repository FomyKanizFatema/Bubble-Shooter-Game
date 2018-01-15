#include<iostream>
#include<Windows.h>
#include <MMSystem.h>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<string.h>
#include<sstream>
#define TRUE true
#define FALSE false

using namespace std;


GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat high_shininess[] = { 100.0f };



int playBg=0;
bool full_screen = FALSE;
int  gameState = 0;
int glut_pane_id = 0;
float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
float cloudX=0.0;
float cloudY=0.0;

float currentbubble1X=0.0;
float shooterY=0.0;
float lifeMeterX=0.0;
/*float bubble1Y=-1.5;
float bubble2Y=-1.1;
float bubble3Y=-1.2;
float bubble4Y=-1.3;
float bubble5Y=-1.4;
float bubble6Y=-1.5;
float bubble7Y=-1.10;
float bubble8Y=-1.2;
float bubble9Y=-1.1;
float bubble10Y=-1.4;*/

/*float bubble1Y=0.3;
float bubble2Y=0.3;
float bubble3Y=0.3;
float bubble4Y=0.3;
float bubble5Y=0.3;

float bubble6Y=-0.2;
float bubble7Y=-0.2;
float bubble8Y=-0.2;
float bubble9Y=-0.2;
float bubble10Y=-0.2;

float bubble11Y=-0.6;
float bubble12Y=-0.6;
float bubble13Y=-0.6;
float bubble14Y=-0.6;
float bubble15Y=-0.6;

float bubble16Y=-1;
float bubble17Y=-1;
float bubble18Y=-1;
float bubble19Y=-1;
float bubble20Y=-1;

float bubble1X=-0.70;
float bubble2X=-0.40;
float bubble3X=-0.1;
float bubble4X=0.2;
float bubble5X=0.5;

float bubble6X=-0.70;
float bubble7X=-0.40;
float bubble8X=-0.1;
float bubble9X=0.2;
float bubble10X=0.5;

float bubble11X=-0.70;
float bubble12X=-0.40;
float bubble13X=-0.1;
float bubble14X=0.2;
float bubble15X=0.5;

float bubble16X=-0.70;
float bubble17X=-0.40;
float bubble18X=-0.1;
float bubble19X=0.2;
float bubble20X=0.5;

*/


float bubble1Y=0.3;
float bubble2Y=0.2;
float bubble3Y=0.1;
float bubble4Y=0.2;
float bubble5Y=0.3;

float bubble6Y=-0.2;
float bubble7Y=-0.1;
float bubble8Y=-0.3;
float bubble9Y=-0.3;
float bubble10Y=-0.2;

float bubble11Y=-0.6;
float bubble12Y=-0.6;
float bubble13Y=-0.5;
float bubble14Y=-0.9;
float bubble15Y=-0.6;

float bubble16Y=-0.9;
float bubble17Y=-1;
float bubble18Y=-1.1;
float bubble19Y=-.81;
float bubble20Y=-1;

float bubble1X=-0.70;
float bubble2X=-0.40;
float bubble3X=-0.1;
float bubble4X=0.2;
float bubble5X=0.5;

float bubble6X=-0.90;
float bubble7X=-0.60;
float bubble8X=-0.3;
float bubble9X=0.3;
float bubble10X=0.6;

float bubble11X=-0.70;
float bubble12X=-0.40;
float bubble13X=0.0;
float bubble14X=0.2;
float bubble15X=0.5;

float bubble16X=-0.90;
float bubble17X=-0.50;
float bubble18X=-0.2;
float bubble19X=-0.1;
float bubble20X=0.5;

float r=0.071;
float mouseX=0;
float mouseY=0;
float allBubbleTransX=0.2;


float meterX=0;
float wave1=0.6;
float wave2=0.5;
float wave3=0.35;
float wave4=0.2;
float wave5=0.05;
float wave6=-0.1;
float wave7=-0.25;
int time=00;
int score=0;
/*float wave1=0.0;
float wave2=0.3;
float wave3=0.25;
float wave4=0.2;*/



void display(void);
void init(void);
void set_debug_window_size(void);
void switch_to_full_screen(void);
void SampleGameModeKeyboard( unsigned char cChar, int nMouseX, int nMouseY );
void glut_OpenGL_call_backs(void);
void drawstring(float x,float y,float z,char *string);
void setFont(void *font);
void keyboardStartFunc(unsigned char key, int x, int y);
void drawStartButton();
void drawBubble(void);
void drawShooter();
void drawHeader();
void drawBackground();
void reshape (int w, int h);
void drawHeader2();
void drawHeadline();
void drawMoon();
char* IntToChar(int number);
void drawScore(int score);
void drawEnd();

void playClickSound(){
    PlaySound(TEXT("click.wav"), NULL, SND_FILENAME| SND_ASYNC);

}
void playBackgroundSound(int k){

    PlaySound(TEXT("F:\\bg.wav"), NULL, SND_FILENAME| SND_NODEFAULT);


}
/*void playBackgroundSoundS(){

    PlaySound(TEXT("F:\\bg.wav"),NULL, SND_LOOP);


}*/
void playOverSound(int k){
   PlaySound(TEXT("gameover.wav"), NULL,  SND_FILENAME);
}
void quitOverSound(){
    PlaySound(TEXT("F:\\gameover.wav"), NULL, NULL);

}


void mouse(int button, int state, int x, int y) {
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        playClickSound();

        mouseX=(x/(float(GetSystemMetrics(SM_CXSCREEN)/2))-1)-allBubbleTransX;
        mouseY=(-y/(float(GetSystemMetrics(SM_CYSCREEN)/2))+1);


        cout<<"BubbleX ->"<< bubble1X<<" "<<"MouseX->"<<mouseX<<endl;
        cout<<"BubbleY ->"<< bubble1Y<<" "<<"MouseY->"<<mouseY<<endl<<endl;
        cout<<"BubbleX ->"<< bubble1X-0.1<<"<<"<<mouseX<<"<<"<<bubble1X+0.1<<endl<<endl;


    if((mouseX>=(bubble1X-r)) &&(mouseX<=(bubble1X+r))&& (mouseY>=(bubble1Y-r)) &&(mouseY<=(bubble1Y+r)) )

        {   bubble1Y=-1.1;
            score++;

            cout<<"Detected Bubble 1"<<endl;
        }
    if((mouseX>=(bubble2X-r)) &&(mouseX<=(bubble2X+r))&& (mouseY>=(bubble2Y-r)) &&(mouseY<=(bubble2Y+r)) )

        {
            bubble2Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }
    if((mouseX>=(bubble3X-r)) &&(mouseX<=(bubble3X+r))&& (mouseY>=(bubble3Y-r)) &&(mouseY<=(bubble3Y+r)) )

        {
            bubble3Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }

    if((mouseX>=(bubble4X-r)) &&(mouseX<=(bubble4X+r))&& (mouseY>=(bubble4Y-r)) &&(mouseY<=(bubble4Y+r)) )

        {
            bubble4Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }
    if((mouseX>=(bubble5X-r)) &&(mouseX<=(bubble5X+r))&& (mouseY>=(bubble5Y-r)) &&(mouseY<=(bubble5Y+r)) )

        {
            bubble5Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }

    if((mouseX>=(bubble6X-r)) &&(mouseX<=(bubble6X+r))&& (mouseY>=(bubble6Y-r)) &&(mouseY<=(bubble6Y+r)) )

        {
            bubble6Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }

    if((mouseX>=(bubble7X-r)) &&(mouseX<=(bubble7X+r))&& (mouseY>=(bubble7Y-r)) &&(mouseY<=(bubble7Y+r)) )

        {
            bubble7Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }
    if((mouseX>=(bubble8X-r)) &&(mouseX<=(bubble8X+r))&& (mouseY>=(bubble8Y-r)) &&(mouseY<=(bubble8Y+r)) )

        {
            bubble8Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }
    if((mouseX>=(bubble9X-r)) &&(mouseX<=(bubble9X+r))&& (mouseY>=(bubble9Y-r)) &&(mouseY<=(bubble9Y+r)) )

        {
            bubble9Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }
    if((mouseX>=(bubble10X-r)) &&(mouseX<=(bubble10X+r))&& (mouseY>=(bubble10Y-r)) &&(mouseY<=(bubble10Y+r)) )

        {
            bubble10Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }
////Next 11-20 Bubbles

if((mouseX>=(bubble11X-r)) &&(mouseX<=(bubble11X+r))&& (mouseY>=(bubble11Y-r)) &&(mouseY<=(bubble11Y+r)) )

        {   bubble11Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }
    if((mouseX>=(bubble12X-r)) &&(mouseX<=(bubble12X+r))&& (mouseY>=(bubble12Y-r)) &&(mouseY<=(bubble12Y+r)) )

        {
            bubble12Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }
    if((mouseX>=(bubble13X-r)) &&(mouseX<=(bubble13X+r))&& (mouseY>=(bubble13Y-r)) &&(mouseY<=(bubble13Y+r)) )

        {
            bubble13Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }

    if((mouseX>=(bubble14X-r)) &&(mouseX<=(bubble14X+r))&& (mouseY>=(bubble14Y-r)) &&(mouseY<=(bubble14Y+r)) )

        {
            bubble14Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }
    if((mouseX>=(bubble15X-r)) &&(mouseX<=(bubble15X+r))&& (mouseY>=(bubble15Y-r)) &&(mouseY<=(bubble15Y+r)) )

        {
            bubble15Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }

    if((mouseX>=(bubble16X-r)) &&(mouseX<=(bubble16X+r))&& (mouseY>=(bubble16Y-r)) &&(mouseY<=(bubble16Y+r)) )

        {
            bubble16Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }

    if((mouseX>=(bubble17X-r)) &&(mouseX<=(bubble17X+r))&& (mouseY>=(bubble17Y-r)) &&(mouseY<=(bubble17Y+r)) )

        {
            bubble17Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }
    if((mouseX>=(bubble18X-r)) &&(mouseX<=(bubble18X+r))&& (mouseY>=(bubble18Y-r)) &&(mouseY<=(bubble18Y+r)) )

        {
            bubble18Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }
    if((mouseX>=(bubble19X-r)) &&(mouseX<=(bubble19X+r))&& (mouseY>=(bubble19Y-r)) &&(mouseY<=(bubble19Y+r)) )

        {
            bubble19Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }
    if((mouseX>=(bubble20X-r)) &&(mouseX<=(bubble20X+r))&& (mouseY>=(bubble20Y-r)) &&(mouseY<=(bubble20Y+r)) )

        {
            bubble20Y=-1.1;
            score++;
            cout<<"Detected Bubble 1"<<endl;
        }


//end of collision
   }
}



void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho (-1.5, 1.5, -1.5*(GLfloat)h/(GLfloat)w,
         1.5*(GLfloat)h/(GLfloat)w, -10.0, 10.0);
   else
      glOrtho (-1.5*(GLfloat)w/(GLfloat)h,
         1.5*(GLfloat)w/(GLfloat)h, -1.5, 1.5, -10.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}


void startGame(){

    glutDisplayFunc(drawStartButton);
}

//Objects Moving logic
void update(int value) {
    wave2+=0.005f;
    if(wave2>0.6){
        wave2=0.1;
    }

    wave3+=0.005f;
    if(wave3>0.6){
        wave3=-0.0;
    }

    wave4+=0.005f;
    if(wave4>0.6){
        wave4=-0.1;
    }

    wave5+=0.005f;
    if(wave5>0.6){
        wave5=-0.2;
    }

    wave6+=0.005f;
    if(wave6>0.6){
        wave6=-0.3;
    }

    wave7+=0.005f;
    if(wave7>0.6){
        wave7=-0.4;
    }


meterX+=0.002f;
if(meterX>0.6){
        meterX=0;
        gameState=2;
    }



float bubbleMotionY=0.02f;
float limit=0.8;
    bubble1Y+=bubbleMotionY;
    if(bubble1Y>limit){
        bubble1Y=-1;
    }


     bubble2Y+=bubbleMotionY;
    if(bubble2Y>limit){
        bubble2Y=-1;
    }

    bubble3Y+=bubbleMotionY;
    if(bubble3Y>limit){
        bubble3Y=-1;
    }


     bubble4Y+=bubbleMotionY;
    if(bubble4Y>limit){
        bubble4Y=-1;
    }

    bubble5Y+=bubbleMotionY;
    if(bubble5Y>limit){
        bubble5Y=-1;
    }


     bubble6Y+=bubbleMotionY;
    if(bubble6Y>limit){
       bubble6Y=-1;
    }

    bubble7Y+=bubbleMotionY;
    if(bubble7Y>limit){
         bubble7Y=-1;
    }


     bubble8Y+=bubbleMotionY;
    if(bubble8Y>limit){
         bubble8Y=-1;
    }
    bubble9Y+=bubbleMotionY;
    if(bubble9Y>limit){
        bubble9Y=-1;
    }


     bubble10Y+=bubbleMotionY;
    if(bubble10Y>limit){
        bubble10Y=-1;
    }

 bubble11Y+=bubbleMotionY;
    if(bubble11Y>limit){
         bubble11Y=-1;
    }


     bubble12Y+=bubbleMotionY;
    if(bubble12Y>limit){
         bubble12Y=-1;
    }

    bubble13Y+=bubbleMotionY;
    if(bubble13Y>limit){
         bubble13Y=-1;
    }


     bubble14Y+=bubbleMotionY;
    if(bubble14Y>limit){
         bubble14Y=-1;
    }

    bubble15Y+=bubbleMotionY;
    if(bubble15Y>limit){
        bubble15Y=-1;
    }


     bubble16Y+=bubbleMotionY;
    if(bubble16Y>limit){
         bubble16Y=-1;
    }

    bubble17Y+=bubbleMotionY;
    if(bubble17Y>limit){
         bubble17Y=-1;
    }


     bubble18Y+=bubbleMotionY;
    if(bubble18Y>limit){
      bubble18Y=-1;
    }
    bubble19Y+=bubbleMotionY;
    if(bubble19Y>limit){
         bubble19Y=-1;
    }


     bubble20Y+=bubbleMotionY;
    if(bubble20Y>limit){
         bubble20Y=-1;
    }



    cloudX+=.03f;
    if(cloudX>1.5){
        cloudX=-1.1;
    }
    cloudY+=0.5f;
    if(cloudY==0.5f){
        cloudY=0.0;
    }
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

   void init(void)
{

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);


    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

// DIsplay Code

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    switch(gameState){
    case 0:
        {
           // bool p=PlaySoundA(TEXT("click.wav"), NULL, SND_ALIAS);
            //cout<<p;

            //sndPlaySound("bg.wav",SND_SYNC);
            drawStartButton();
            glutKeyboardFunc(keyboardStartFunc);
            break;
        }
    case 1:
        {
           // playBackgroundSound();

//playBg=1;
//playBackgroundSoundS();
            init();
            drawBackground();
            drawBubble();
            drawMoon();
            drawHeader();
            glutSetCursor(GLUT_CURSOR_CROSSHAIR);




            break;
        }




        case 2:{
            //playBg=0;
            drawEnd();
             glutSetCursor(GLUT_CURSOR_NONE);
                      //  playOverSound();

             gameState=3;

            break;
        }

        case 3:{

           drawEnd();
           glutSetCursor(GLUT_CURSOR_NONE);
           playOverSound(1);
           break;

           }


    }
    glFlush();
	glutSwapBuffers();
}



void initRendering() {
	glEnable(GL_DEPTH_TEST);
}


int main(int argc, char **argv)
{
  glutInit(&argc, argv) ;
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(300, 100);
  glut_pane_id=glutCreateWindow("Ballon Shooter");
  //glClearColor(0,1,1,0);
  //init();
//PlaySound(TEXT("bg.wav"), NULL, SND_FILENAME);


  initRendering();
  glut_OpenGL_call_backs();

  glutReshapeFunc(reshape);
  switch_to_full_screen();

  //PlaySound("hu.mp3", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
  glutMouseFunc(mouse);
  glutTimerFunc(25, update, 0);
  glutMainLoop();
  return 0;                      /* ANSI C requires main to return int. */
}
 void bubble(){
                //glutSolidSphere(r,100,100);
                glutSolidSphere(r,30,30);
 }
//Bubble Draeing code
void drawBubble(void)

{

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
     glLightfv(GL_LIGHT0, GL_POSITION, light_position);



    glPushMatrix();
     glTranslatef(allBubbleTransX, 0, 0.0);
   //glRotatef(_angle,1,0,0);

                //--------------------this is the first bubble----------------
                glPushMatrix();
                //glRotatef(_angle,1,0,0);
                glColor3f(0,1,1);
                glTranslatef(bubble1X, bubble1Y, 0.0); //we need this bubbles Y co ordinates value whic can be got by bubble1Y
                glScalef(0.65,1,1);
                bubble();// we know the radious of the solid sphere 0.15
                glPopMatrix();

                //----------------end of the 1st bubble------------------

                //--------------------this is the 2nd bubble----------------
                glPushMatrix();
                glColor3f(0.7,0.3,1);
                glTranslatef(bubble2X, bubble2Y, 0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();
                 //----------------end of the 2nd bubble------------------



                //--------------------this is the 3rd bubble----------------

                glPushMatrix();
                glColor3f(0.7,0.5,0.6);
                //glColor3f(1,0,0);
                glTranslatef(bubble3X, bubble3Y, 0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();
                 //----------------end of the 3rd bubble------------------



                //--------------------this is the 4th bubble----------------
                glPushMatrix();
                glColor3f(0.7,1,0.6);
                glTranslatef(bubble4X, bubble4Y, 0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();

                 //----------------end of the 4th bubble------------------



                 //--------------------this is the 5th bubble----------------


                glPushMatrix();
                glColor3f(1,0.1,1);
                glTranslatef(bubble5X, bubble5Y, 0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();
                //----------------end of the 5th bubble------------------

                //--------------------this is the 6th bubble----------------
                glPushMatrix();
                glColor3f(0,1,1);
                glTranslatef(bubble6X, bubble6Y, 0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();
                //----------------end of the 6th bubble------------------


                //--------------------this is the 7th bubble----------------
                glPushMatrix();
                glColor3f(0.7,0.3,1);
                glTranslatef(bubble7X, bubble7Y, 0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();
                //----------------end of the 7th bubble------------------

                //--------------------this is the 8th bubble----------------
                glPushMatrix();
                glColor3f(0.7,0.5,0.6);
                glTranslatef(bubble8X, bubble8Y, 0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();
                //----------------end of the 8th bubble------------------

                //--------------------this is the 9th bubble----------------
                glPushMatrix();
                glColor3f(0,1,1);
                glTranslatef(bubble9X, bubble9Y, 0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();
                //----------------end of the 9th bubble------------------

                //--------------------this is the 10th bubble----------------
                glPushMatrix();
                glColor3f(0.7,0.3,1);
                glTranslatef(bubble10X, bubble10Y, 0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();
                //----------------end of the 10th bubble------------------
///// Second 10 Bubble 11-20

                //--------------------this is the first bubble----------------

                glPushMatrix();
                glColor3f(1,0,0);
                glTranslatef(bubble11X, bubble11Y, 0.0); //we need this bubbles Y co ordinates value whic can be got by bubble1Y
                glScalef(0.65,1,1);
                bubble(); // we know the radious of the solid sphere 0.15
                glPopMatrix();

                //----------------end of the 1st bubble------------------

                //--------------------this is the 2nd bubble----------------
                glPushMatrix();
                glColor3f(0.7,0.3,1);
                glTranslatef(bubble12X, bubble12Y, 0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();
                 //----------------end of the 2nd bubble------------------



                //--------------------this is the 3rd bubble----------------

                glPushMatrix();
                glColor3f(0.7,0.5,0.6);
                glTranslatef(bubble13X,bubble13Y, 0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();
                 //----------------end of the 3rd bubble------------------



                //--------------------this is the 4th bubble----------------
                glPushMatrix();
                glColor3f(0.7,1,0.6);
                 glTranslatef(bubble14X,bubble14Y, 0.0);
                glScalef(0.65,1,1);
               bubble();
                glPopMatrix();

                 //----------------end of the 4th bubble------------------



                 //--------------------this is the 5th bubble----------------


                glPushMatrix();
                glColor3f(1,0.1,1);
                 glTranslatef(bubble15X,bubble15Y, 0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();
                //----------------end of the 5th bubble------------------

                //--------------------this is the 6th bubble----------------
                glPushMatrix();
                glColor3f(0,1,1);
                glTranslatef(bubble16X,bubble16Y, 0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();
                //----------------end of the 6th bubble------------------


                //--------------------this is the 7th bubble----------------
                glPushMatrix();
                glColor3f(0.7,0.3,1);
                glTranslatef(bubble17X,bubble17Y,  0.0);
                glScalef(0.65,1,1);
               bubble();
                glPopMatrix();
                //----------------end of the 7th bubble------------------

                //--------------------this is the 8th bubble----------------
                glPushMatrix();
                glColor3f(0.7,0.5,0.6);
                glTranslatef(bubble18X, bubble18Y, 0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();
                //----------------end of the 8th bubble------------------

                //--------------------this is the 9th bubble----------------
                glPushMatrix();
                glColor3f(0,1,1);
                glTranslatef(bubble19X, bubble19Y,0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();
                //----------------end of the 9th bubble------------------

                //--------------------this is the 10th bubble----------------
                glPushMatrix();
                glColor3f(0.7,0.3,1);
                glTranslatef(bubble20X, bubble20Y, 0.0);
                glScalef(0.65,1,1);
                bubble();
                glPopMatrix();

                //----------------end of the 10th bubble------------------


////End of 11-20Bubbles


glPopMatrix();


    glFlush();

}



void SampleGameModeKeyboard( unsigned char cChar, int nMouseX, int nMouseY )
{
  static int toggleMode=true;
  if( cChar == 27 ) exit(0);

  if (toggleMode)
  {
    set_debug_window_size();
    toggleMode=!toggleMode;
  }
  else
  {
    switch_to_full_screen();
    toggleMode=!toggleMode;
  }
}



void glut_OpenGL_call_backs()
{
  //glutKeyboardFunc(keyboardStartFunc);
  glutKeyboardFunc( SampleGameModeKeyboard );
  glutDisplayFunc(display);
};

void switch_to_full_screen(void)
{
  char mode_string[24];

  full_screen = TRUE;

  sprintf(mode_string, "%dx%d:32@60", glutGet(GLUT_SCREEN_WIDTH),
  glutGet(GLUT_SCREEN_HEIGHT));
  glutGameModeString(mode_string);
  if(glutGameModeGet(GLUT_GAME_MODE_POSSIBLE))
  {
    printf("GameMode %s is possible\n", mode_string);
                                 // destroys the current graphics window
    glutDestroyWindow(glut_pane_id);
    glutEnterGameMode();
    glut_OpenGL_call_backs();
                                 // hide the cursor
    glutSetCursor(GLUT_CURSOR_NONE);
  }
  else
  {
    printf("GameMode %s NOT possible\n", mode_string);
    glutFullScreen();
  }



  if(glutGameModeGet(GLUT_GAME_MODE_ACTIVE))
  {
    printf("GameMode is now active...\n");
  }
  else
  {
    //printf("GameMode is NOT active\n");
  }

}


void set_debug_window_size(void)
{
  int screen_width, screen_length;

  full_screen = FALSE;

  if(glutGameModeGet(GLUT_GAME_MODE_ACTIVE))
  {
    printf("returning from GameMode\n");
    glutLeaveGameMode();
    glut_pane_id = glutCreateWindow("Bubble Shooter");
    glut_OpenGL_call_backs();
  }


}

void *currentfont;
void setFont(void *font)
{
 currentfont=font;                      // Set the currentfont to the font
}
void drawstring(float x,float y,float z,char *string)
{
 char *c;
 glRasterPos3f(x,y,z);
 for(c=string;*c!='\0';c++)
 { glColor3f(0.0,0.0,0.0);
  glutBitmapCharacter(currentfont,*c);
 }
}


void keyboardStartFunc(unsigned char key, int x, int y)
{
    if (gameState == 0)
	{
		if (key ==13)
		{       //gameStopped=false;
                //glutDisplayFunc(drawBubble);
			    //score=0;

			gameState = 1;
			//seconds=0;
			//drawBubble();
		}
	}

	if (gameState == 2)
	{
		if (key ==13)
		{       //gameStopped=false;
                //glutDisplayFunc(drawBubble);
			    score=0;

			gameState = 1;
			//seconds=0;
			//drawBubble();
		}
	}
	if (gameState == 3)
	{
		if (key ==13)
		{
			    score=0;
            //quitOverSound();
			gameState = 1;
			//seconds=0;
			//drawBubble();
		}
	}
	if(key == 27) {
        //quitOverSound();
		exit(1);
	}
}


void drawStartButton(){
    glPushMatrix();
	glTranslated(0, 0.0, 0);
	glScalef(0.1, 0.1, 0.1);
	glScalef(4, 1, 0.1);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(1.5);
	glTranslated(-0.52, -0.15, 0);
	glScalef(2, 2, 0.1);
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0, 1.0, 1.0);
	drawstring(0,0,0,"ENTER TO START, ESC TO EXIT");
	glPopMatrix();


}

void drawMoon(){
    //moon

    glPushMatrix();
     glTranslatef(0.8, 0.7, .5);
     glRotated(90,1,0,0);


     glScalef(1,1.7,1);
     glScalef(0.5,0.5,1);
     glColor3f(1,1,1);
     glutSolidSphere(0.09,60,60);



    glPopMatrix();

}






void drawHeader(){
     glDisable(GL_DEPTH_TEST);
     glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHT0);
    glDisable(GL_NORMALIZE);
    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHTING);
    glPushMatrix();

	glTranslated(-1, 1, 0);
	glScalef(1, 0.1, 0.1);
	glScalef(3, 2.7, 0.1);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(1.5);



	glPopMatrix();


	glPushMatrix();
    glTranslated(0.25, 0.9, 0);
	glScalef(1, 0.1, 0.1);
	glScalef(0.7, 1.5, 0.1);
	glColor3f(.3, 0.9, 0.5);
	glutSolidCube(1);
	glPopMatrix();
	//life meter
	glPushMatrix();
    glTranslated(0.25, 0.9, 0);
	glScalef(meterX, 0.08, 0.1);
	glColor3f(1, 1, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	//SCORE Background
	glPushMatrix();
    glTranslated(0.8, 0.9, 0);
	glScalef(1, 0.1, 0.1);
	glScalef(0.3, 1.5, 0.1);
	glColor3f(.3, 0.9, 0.5);
	glutSolidCube(1);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-0.9, 0.875, 0);
	glScalef(2, 7, 1);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1.0, 1.0, 1.0);
	drawstring(0,0,0," SHOOT THE BUBBLES ");
	glPopMatrix();




    glPushMatrix();
	glTranslatef(0.68, 0.88, 0);
	glScalef(2, 2, 0.1);
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0, 1.0, 1.0);
	drawstring(0,0,0," SCORE: ");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.85, 0.88, 0);
	glScalef(2, 2, 0.1);
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0, 1.0, 1.0);
	char s[10]={'\0'};
    sprintf(s, "%d", score);
    drawstring(0,0,0,s);
	glPopMatrix();


}




void drawBackground(){

   glDisable(GL_DEPTH_TEST);
     glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHT0);
    glDisable(GL_NORMALIZE);
    glDisable(GL_COLOR_MATERIAL);
    glDisable(GL_LIGHTING);
 /*glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);*/

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
  //glEnable(GL_LIGHTING);
  //glEnable(GL_LIGHTING);

//place
glPushMatrix();


                                    //hill
  glPushMatrix();

         glPushMatrix();
         glEnable(GL_LIGHTING);
         glTranslatef(-0.9,0.2,0);
         glRotated(-60,1,0,0);
         glColor3f(0,0.9,0);
         glutSolidCone(0.3,0.55,100,199);
         glPopMatrix();

         glPushMatrix();
         glEnable(GL_LIGHTING);
         glTranslatef(-0.5,0.2,0);
         glRotated(-60,1,0,0);
         glColor3f(0,0.9,0);
         glutSolidCone(0.6,0.6,100,199);
         glPopMatrix();


         glPushMatrix();
         glEnable(GL_LIGHTING);
         glTranslatef(-0.7,0.2,0);
         glRotated(-60,1,0,0);
         glColor3f(0,0.9,0);
         glutSolidCone(0.5,0.55,100,199);
         glPopMatrix();

          glPushMatrix();
         glEnable(GL_LIGHTING);
         glTranslatef(-0.1,0.2,0);
         glRotated(-60,1,0,0);
         glColor3f(0,0.9,0);
         glutSolidCone(0.35,0.5,100,199);
         glPopMatrix();


         glPushMatrix();
         glEnable(GL_LIGHTING);
         glTranslatef(-0.3,0.2,0);
         glRotated(-60,1,0,0);
         glColor3f(0,0.9,0);
         glutSolidCone(0.5,0.5,100,199);
         glPopMatrix();



                   glPushMatrix();
                    glEnable(GL_LIGHTING);
                     glTranslatef(-0.9,0.4,0);
                      glRotated(60,1,0,0);
                     glColor3f(0,0.7,0);
                     glScalef(4,0.1,0.1);
                     glutSolidIcosahedron();
                    glPopMatrix();

                    //trees
glPushMatrix();
glTranslatef(0.67,0.5,1);
glScalef(0.4,0.4,0.5);

//tree1
   glPushMatrix();
    glTranslatef(-0.1,0.3,0);
     glRotated(1,0,0,1);
              glPushMatrix();
             // glDisable(GL_LIGHTING);
              glTranslatef(-0.6,-0.15,0);
              glRotated(-80,0,1,0);
              glColor3f(0.81,0.5,0.14);
              glScalef(0.1,1.5,0.03);
              glutSolidCube(0.5);
              glPopMatrix();

               glPushMatrix();
               //glTranslatef(-0.5,0,0);
               glScalef(1.2,1.2,1);
               glEnable(GL_LIGHTING);


                   /*glPushMatrix();
                    glTranslatef(-0.5,0.0,0);
                    glColor3f(0,1,0);
                  glScalef(0.3,0.25,1);
                  glutSolidSphere(0.3,130,120);
                  glPopMatrix();*/


                     glPushMatrix();
                    glTranslatef(-0.5,0.1,0);
                  glColor3f(0,1,0.14);
                  glScalef(0.18,.3,1);
                  glutSolidSphere(0.3,130,120);
                   glPopMatrix();

                   glPushMatrix();
                    glTranslatef(-0.53,0.05,0);
                  glColor3f(0,1,0.14);
                  glScalef(0.2,.25,1);
                  glutSolidSphere(0.3,130,120);
                   glPopMatrix();

                   glPushMatrix();
                    glTranslatef(-0.47,0.05,0);
                  glColor3f(0,1,0.14);
                  glScalef(0.2,.25,1);
                  glutSolidSphere(0.3,130,120);
                   glPopMatrix();
             glPopMatrix();
glPopMatrix();

//tree3
   glPushMatrix();
    glTranslatef(-0.24,0.35,0);
     glRotated(1,0,0,1);
              glPushMatrix();
              glEnable(GL_LIGHTING);
              glTranslatef(-0.6,-0.15,0);
              glRotated(-80,0,1,0);
              glColor3f(0.81,0.5,0.14);
              glScalef(0.1,1.5,0.03);
              glutSolidCube(0.5);
               glPopMatrix();

               glPushMatrix();
               //glTranslatef(-0.5,0,0);
               glScalef(1.2,1.2,1);


                   /*glPushMatrix();
                    glTranslatef(-0.5,0.0,0);
                    glColor3f(0,1,0);
                  glScalef(0.3,0.25,1);
                  glutSolidSphere(0.3,130,120);
                  glPopMatrix();*/


                     glPushMatrix();
                    glTranslatef(-0.5,0.1,0);
                  glColor3f(0,1,0.14);
                  glScalef(0.18,.3,1);
                  glutSolidSphere(0.3,130,120);
                   glPopMatrix();

                   glPushMatrix();
                    glTranslatef(-0.53,0.05,0);
                  glColor3f(0,1,0.14);
                  glScalef(0.2,.25,1);
                  glutSolidSphere(0.3,130,120);
                   glPopMatrix();

                   glPushMatrix();
                    glTranslatef(-0.47,0.05,0);
                  glColor3f(0,1,0.14);
                  glScalef(0.2,.25,1);
                  glutSolidSphere(0.3,130,120);
                   glPopMatrix();
             glPopMatrix();
glPopMatrix();



//tree2
   glPushMatrix();
    glTranslatef(0.05,0.35,0);
     glRotated(1,0,0,1);
              glPushMatrix();
              glEnable(GL_LIGHTING);
              glTranslatef(-0.6,-0.15,0);
              glRotated(-80,0,1,0);
              glColor3f(0.81,0.5,0.14);
              glScalef(0.1,1.5,0.03);
              glutSolidCube(0.5);
              glPopMatrix();

               glPushMatrix();
               glScalef(1.2,1.2,1);


                    glPushMatrix();
                    glTranslatef(-0.5,0.1,0);
                    glColor3f(0,1,0.14);
                    glScalef(0.18,.3,1);
                    glutSolidSphere(0.3,130,120);
                    glPopMatrix();

                    glPushMatrix();
                    glTranslatef(-0.53,0.05,0);
                    glColor3f(0,1,0.14);
                    glScalef(0.2,.25,1);
                    glutSolidSphere(0.3,130,120);
                    glPopMatrix();

                    glPushMatrix();
                    glTranslatef(-0.47,0.05,0);
                    glColor3f(0,1,0.14);
                    glScalef(0.2,.25,1);
                    glutSolidSphere(0.3,130,120);
                    glPopMatrix();
             glPopMatrix();
glPopMatrix();


//tree4
   glPushMatrix();
    glTranslatef(-0.34,0.23,0);
     glRotated(1,0,0,1);
              glPushMatrix();
              glEnable(GL_LIGHTING);
              glTranslatef(-0.6,-0.15,0);
              glRotated(-80,0,1,0);
              glColor3f(0.81,0.5,0.14);
              glScalef(0.1,1.5,0.03);
              glutSolidCube(0.5);
              glPopMatrix();

               glPushMatrix();
               glScalef(1.2,1.2,1);

                    glPushMatrix();
                    glTranslatef(-0.5,0.1,0);
                    glColor3f(0,1,0.14);
                    glScalef(0.18,.3,1);
                    glutSolidSphere(0.3,130,120);
                    glPopMatrix();

                    glPushMatrix();
                    glTranslatef(-0.53,0.05,0);
                    glColor3f(0,1,0.14);
                    glScalef(0.2,.25,1);
                    glutSolidSphere(0.3,130,120);
                    glPopMatrix();

                    glPushMatrix();
                    glTranslatef(-0.47,0.05,0);
                    glColor3f(0,1,0.14);
                    glScalef(0.2,.25,1);
                    glutSolidSphere(0.3,130,120);
                    glPopMatrix();
             glPopMatrix();
glPopMatrix();


                        glPopMatrix();



  glPopMatrix();

              glPushMatrix();
              glEnable(GL_LIGHTING);
              glTranslatef(0.0,-1.2,0);
              glColor3f(1,0.6,0);
              glScalef(2,3.09,1);
              glutSolidCube(1);
              glPopMatrix();
glPopMatrix();



  //tree1
   glPushMatrix();
    glTranslatef(-0.1,0.3,0);
     glRotated(1,0,0,1);
                glPushMatrix();
                glEnable(GL_LIGHTING);
                glTranslatef(-0.6,-0.15,0);
                glRotated(-60,1,0,0);
                glColor3f(0.81,0.5,0.14);
                glScalef(0.1,1,0.03);
                glutSolidCone(0.24,15,10,10);
                glPopMatrix();

               glPushMatrix();
               glScalef(1.2,1.2,1);


                    glPushMatrix();
                    glTranslatef(-0.5,0.1,0);
                    glColor3f(0,1,0.14);
                    glScalef(0.18,.3,1);
                    glutSolidSphere(0.3,130,120);
                    glPopMatrix();

                    glPushMatrix();
                    glTranslatef(-0.53,0.05,0);
                    glColor3f(0,1,0.14);
                    glScalef(0.2,.25,1);
                    glutSolidSphere(0.3,130,120);
                    glPopMatrix();

                    glPushMatrix();
                    glTranslatef(-0.47,0.05,0);
                    glColor3f(0,1,0.14);
                    glScalef(0.2,.25,1);
                    glutSolidSphere(0.3,130,120);
                    glPopMatrix();
             glPopMatrix();
glPopMatrix();

//tree3
   glPushMatrix();
    glTranslatef(-0.24,0.35,0);
     glRotated(1,0,0,1);
                glPushMatrix();
                glEnable(GL_LIGHTING);
                glTranslatef(-0.6,-0.15,0);
                glRotated(-60,1,0,0);
                glColor3f(0.81,0.5,0.14);
                glScalef(0.1,1,0.03);
                glutSolidCone(0.24,15,10,10);
                glPopMatrix();

                glPushMatrix();

                glScalef(1.2,1.2,1);

                        glPushMatrix();
                        glTranslatef(-0.5,0.1,0);
                        glColor3f(0,1,0.14);
                        glScalef(0.18,.3,1);
                        glutSolidSphere(0.3,130,120);
                        glPopMatrix();

                        glPushMatrix();
                        glTranslatef(-0.53,0.05,0);
                        glColor3f(0,1,0.14);
                        glScalef(0.2,.25,1);
                        glutSolidSphere(0.3,130,120);
                        glPopMatrix();

                        glPushMatrix();
                        glTranslatef(-0.47,0.05,0);
                        glColor3f(0,1,0.14);
                        glScalef(0.2,.25,1);
                        glutSolidSphere(0.3,130,120);
                        glPopMatrix();
             glPopMatrix();
glPopMatrix();



//tree2
   glPushMatrix();
    glTranslatef(0.05,0.35,0);
     glRotated(1,0,0,1);
              glPushMatrix();
              glEnable(GL_LIGHTING);
              glTranslatef(-0.6,-0.15,0);
              glRotated(-60,1,0,0);
              glColor3f(0.81,0.5,0.14);
              glScalef(0.1,1,0.03);
              glutSolidCone(0.24,15,10,10);
              glPopMatrix();

              glPushMatrix();

                  glScalef(1.2,1.2,1);


                   glPushMatrix();
                   glTranslatef(-0.5,0.1,0);
                   glColor3f(0,1,0.14);
                   glScalef(0.18,.3,1);
                   glutSolidSphere(0.3,130,120);
                   glPopMatrix();

                   glPushMatrix();
                   glTranslatef(-0.53,0.05,0);
                   glColor3f(0,1,0.14);
                   glScalef(0.2,.25,1);
                   glutSolidSphere(0.3,130,120);
                   glPopMatrix();

                   glPushMatrix();
                   glTranslatef(-0.47,0.05,0);
                   glColor3f(0,1,0.14);
                   glScalef(0.2,.25,1);
                   glutSolidSphere(0.3,130,120);
                   glPopMatrix();
             glPopMatrix();
glPopMatrix();


//tree4
   glPushMatrix();
    glTranslatef(-0.34,0.23,0);
     glRotated(1,0,0,1);
              glPushMatrix();
              glEnable(GL_LIGHTING);
              glTranslatef(-0.6,-0.15,0);
              glRotated(-60,1,0,0);
              glColor3f(0.81,0.5,0.14);
              //glScalef(0.00005,5,1);
               glScalef(0.1,1,0.03);
              //glutSolidCube(0.5);
              glutSolidCone(0.24,15,10,10);
               glPopMatrix();

               glPushMatrix();
               //glTranslatef(-0.5,0,0);
               glScalef(1.2,1.2,1);


                   /*glPushMatrix();
                    glTranslatef(-0.5,0.0,0);
                    glColor3f(0,1,0);
                  glScalef(0.3,0.25,1);
                  glutSolidSphere(0.3,130,120);
                  glPopMatrix();*/


                     glPushMatrix();
                    glTranslatef(-0.5,0.1,0);
                  glColor3f(0,1,0.14);
                  glScalef(0.18,.3,1);
                  glutSolidSphere(0.3,130,120);
                   glPopMatrix();

                   glPushMatrix();
                    glTranslatef(-0.53,0.05,0);
                  glColor3f(0,1,0.14);
                  glScalef(0.2,.25,1);
                  glutSolidSphere(0.3,130,120);
                   glPopMatrix();

                   glPushMatrix();
                    glTranslatef(-0.47,0.05,0);
                  glColor3f(0,1,0.14);
                  glScalef(0.2,.25,1);
                  glutSolidSphere(0.3,130,120);
                   glPopMatrix();
             glPopMatrix();
glPopMatrix();









//River
  glPushMatrix();
  GLfloat light_position[] = { -1.50f, 0.1f, 5.0f, 0.0f };
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  GLfloat river_light_ambient[]  = { 0.0f, 0.3f, .4f, 0.5f };
  glLightfv(GL_LIGHT0, GL_AMBIENT,  river_light_ambient);



      glPushMatrix();
       //glDisable(GL_LIGHTING);
      glTranslatef(0.6,-0.29,0);
      glColor3f(0,0.5,1);
      glScalef(2,1.1,1);
      glutSolidSphere(0.6,260,260);
      //glutSolidTorus(0.01,0.1,60,60);
      glPopMatrix();

      glPushMatrix();
      glTranslatef(0.6,-0.29,0);
      glColor3f(0,0.5,1);
      glScalef(2,1.1,1);
      glutSolidSphere(wave2,260,260);
      glPopMatrix();

      glPushMatrix();
      glTranslatef(0.6,-0.29,0);
      glColor3f(0,0.5,1);
      glScalef(2,1.1,1);
      glutSolidSphere(wave3,260,260);
      glPopMatrix();

      glPushMatrix();
      glTranslatef(0.6,-0.29,0);
      glColor3f(0,0.5,1);
      glScalef(2,1.1,1);
      glutSolidSphere(wave4,260,260);
      glPopMatrix();


      glPushMatrix();
      glTranslatef(0.6,-0.29,0);
      glColor3f(0,0.5,1);
      glScalef(2,1.1,1);
      glutSolidSphere(wave5,260,260);
      glPopMatrix();

      glPushMatrix();
      glTranslatef(0.6,-0.29,0);
      glColor3f(0,0.5,1);
      glScalef(2,1.1,1);
      glutSolidSphere(wave6,260,260);
      glPopMatrix();

      glPushMatrix();
      glTranslatef(0.6,-0.29,0);
      glColor3f(0,0.5,1);
      glScalef(2,1.1,1);
      glutSolidSphere(wave7,260,260);
      glPopMatrix();
glPopMatrix();


    glFlush();
}

void drawEnd(){
    glPushMatrix();
	glTranslated(0, 0.0, 0);
	glScalef(0.1, 0.1, 0.1);
	glScalef(5, 4, 0.1);
	glColor3f(1.0, 0.0, 0.0);
	glutSolidCube(1.5);

	glPushMatrix();
        glPushMatrix();
        glTranslated(-0.2, 0.2, 0);
        glScalef(2, 2, 0.1);
        setFont(GLUT_BITMAP_TIMES_ROMAN_24);
        glColor3f(1.0, 1.0, 1.0);
        drawstring(0,0,0,"GAME OVER");
        glPopMatrix();

        glPushMatrix();
        glTranslated(-0.2, -0.1, 0);
        glScalef(2, 2, 0.1);
        setFont(GLUT_BITMAP_TIMES_ROMAN_24);
        glColor3f(1.0, 1.0, 1.0);
        drawstring(0,0,0,"SCORE:");
        glPopMatrix();

        glPushMatrix();
        glTranslatef(0.2, -0.1, 0);
        glScalef(2, 2, 0.1);
        setFont(GLUT_BITMAP_HELVETICA_18);
        glColor3f(1.0, 1.0, 0.3);
        char buffer[10]={'\0'};
        sprintf(buffer, "%d", score);
        drawstring(0,0,0,buffer);
        glPopMatrix();

        glPushMatrix();
        glTranslated(-0, -0.5, 0);
        glScalef(0.1, 0.1, 0.1);
        glScalef(10, 2, 0.1);
        glColor3f(0.0, 0.9, 0.3);
        glutSolidCube(1.5);

        glPushMatrix();
        glTranslated(-0.7, -0.2, 0);
        glScalef(2, 2, 0.1);
        setFont(GLUT_BITMAP_HELVETICA_18);
        glColor3f(1.0, 1.0, 1.0);
        drawstring(0,0,0,"         PRESS ENTER TO PLAY AGAIN/ESC TO EXIT");
        glPopMatrix();
        glPopMatrix();
	glFlush();
}

