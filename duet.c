#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

#define PI 3.14159265358979

double arc, ang_s;
double ang;
double x, y;

double z_x1, z_y1, z_x2, z_y2;

struct Ball {
  int r;
  int iti_x;
  int iti_y;
};

struct Ball ball[2] = {
  30,  120, 0,
  30, -120, 0,
};

double zb1, zb2;

struct Block{
  int bl1_x;
  int bl1_y;
  int bl2_x;
  int bl2_y;
  int bl3_x;
  int bl3_y;
  int bl4_x;
  int bl4_y;
};

struct Block block[] = {
  -70, 0, -70, 50, 70, 50, 70, 0,
  -250, 300, -250, 350, 0, 350, 0, 300,
  0, 600, 0, 650, 250, 650, 250, 600,
  -50, 900, -50, 950, 50, 950, 50, 900,
  -250, 900, -250, 950, -135, 950, -135, 900,  //5
  135, 900, 135, 950, 250, 950, 250, 900,
  -50, 1200, -50, 1250, 250, 1250, 250, 1200,
  -50, 1500, -50, 1550, 250, 1550, 250, 1500,
  -250, 1800, -250, 1850, 50, 1850, 50, 1800,
  -250, 2100, -250, 2150, 50, 2150, 50, 2100,  //10
  -250, 2400, -250, 2450, -50, 2450, -50, 2400,
  50, 2400, 50, 2450, 250, 2450, 250, 2400,
};

int cnt_block = 12;

int i;
char die_flag = 99;
char simu_flag = 99;
double scroll_x = 0, scroll_y = 0;

void idle(){
  glutPostRedisplay();
}

void drawString3D(const char *str, float charSize, float lineWidth)
{
  glPushMatrix();
  glPushAttrib(GL_LINE_BIT);
  glScaled(0.01 * charSize, 0.01 * charSize, 0.01);
  glLineWidth(lineWidth);
  while(*str){
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *str);
    ++str;
  }
  glPopAttrib();
  glPopMatrix();
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  //操作　枠
  glPushMatrix();
  glColor3f(0.7, 0.7, 0.7);
  for(arc=0;arc<=360;arc+=10){
    ang_s = PI*arc/180.0;
    glBegin(GL_LINE_LOOP);
    x = ball[0].iti_x * cos(ang_s);
    y = ball[0].iti_x * sin(ang_s);
    glVertex2d(x, y);
  }
  glEnd();
  glPopMatrix();

  //初期状態
  if(die_flag==99){
    glPushMatrix ();
    glColor3f( 1.0, 1.0, 1.0 );  
    glTranslatef(-200.0, 300.0, 0); 
    drawString3D("Press ' s ' to start", 30.0, 2.0); 
    glPopMatrix ();   
  }
  

  if(die_flag == 1){
  
  //敵ブロック
    for(i = 0; i < cnt_block; i ++){
      glPushMatrix();
      glTranslatef(0.0, scroll_y + 250, 0.0);
      glColor3f(0.9, 0.9, 1.0);
      glBegin(GL_QUADS);
      glVertex2d(block[i].bl1_x,block[i].bl1_y);
      glVertex2d(block[i].bl2_x,block[i].bl2_y);
      glVertex2d(block[i].bl3_x,block[i].bl3_y);
      glVertex2d(block[i].bl4_x,block[i].bl4_y);
      glEnd();
      glPopMatrix();
    }
// 赤の操作　ボール
  glPushMatrix();
  glColor3f(1.0, 0.0, 0.0);
  glRotated((double)ang, 0.0, 0.0, 1.0);
  for(arc = 0; arc <= 360; arc += 10){
    ang_s = PI * arc / 180.0;
    glBegin(GL_POLYGON);
    x = ball[0].r * cos(ang_s) + ball[0].iti_x;
    y = ball[0].r * sin(ang_s) + ball[0].iti_y;
    glVertex2d(x, y);
  }
  glEnd();
  glPopMatrix();

//青の操作　ボール
  glPushMatrix();
  glColor3f(0.0, 0.0, 1.0);
  glRotated((double)ang, 0.0, 0.0, 1.0);
  for(arc = 0; arc <= 360; arc += 10){
    ang_s = PI * arc / 180.0;
    glBegin(GL_POLYGON);
    x = ball[1].r * cos(ang_s) + ball[1].iti_x;
    y = ball[1].r * sin(ang_s) + ball[1].iti_y;
    glVertex2d(x, y);
  }
  glEnd();
  glPopMatrix();

  }
  glutSwapBuffers();
}

void simu(){
  switch (simu_flag){
  //左クリック　右回転
    case 'l':
      ang = ang + 0.015;
      if(ang > 360.0)
        ang = ang - 360.0;
      glutPostRedisplay();
      break;
  //右クリック　左回転
    case 'r':
      ang = ang - 0.015;
      if(ang < -360.0)
        ang = ang + 360.0;
      glutPostRedisplay();
      break;
    default:
      break;
  }
  scroll_y -= 0.015;
  glutPostRedisplay();
}  

void timer(int value){
  switch (die_flag){
    case 1:
      glutIdleFunc(simu);
      //ブロックの当たり判定
      z_x1 = ball[0].iti_x * cos(ang/180*PI);
      z_y1 = ball[0].iti_x *sin(ang/180*PI);
      z_x2 = ball[0].iti_x * cos((ang+180)/180*PI);
      z_y2 = ball[0].iti_x * sin((ang+180)/180*PI);
      for(i = 0; i < cnt_block ; i ++){
      zb1 = block[i].bl1_y + scroll_y + 250;
      zb2 = block[i].bl2_y + scroll_y + 250;
//      printf("%g, %g\n", zb1, zb2);
      if(block[i].bl1_x - ball[0].r < z_x2 && z_x2 < block[i].bl3_x + ball[0].r){
        if(zb1 < z_y2 && z_y2 < zb2)
          exit(0);
      }

      if(block[i].bl1_x - ball[0].r < z_x1 && z_x1 < block[i].bl3_x + ball[0].r){
          if(zb1 < z_y1 && z_y1 < zb2)
            exit(0);
        }
      if(zb1 - ball[0].r < z_y2 && z_y2 < zb2 + ball[0].r){
        if(block[i].bl1_x < z_x2 && z_x2 < block[i].bl3_x)
          exit(0);
      }
      if(zb1 - ball[0].r < z_y1 && z_y1 < zb2 + ball[0].r){
        if(block[i].bl1_x < z_x1 && z_x1 < block[i].bl3_x)
          exit(0);
      }
      }
        
      break;
    default:
      break;
  }

  glutTimerFunc(3 , timer , 0);   
}

void mouse(int button, int state, int x, int y){
  switch(button){
    case GLUT_LEFT_BUTTON:
      if(state == GLUT_DOWN){
        simu_flag = 'l';
      }else{
        simu_flag = 99;
     }
      break;
    case GLUT_RIGHT_BUTTON:
      if(state == GLUT_DOWN){
        simu_flag = 'r';
      }else{
        simu_flag = 99;
      }
      break;
    default:
      break;
  }
}


void keyboard(unsigned char key, int x, int y){
  if ( key == 's') die_flag = 1;
  else if ( key == '\x1b' || key == 'q' || key == 'Q' ) exit(0);
}

void reshape(int w, int h){
  glViewport( 0, 0, w, h );
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-225.0, 225.0, -225.0, 575.0, -1.0, 1.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void init(){
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glShadeModel(GL_FLAT);
}

int main(int argc, char *argv[]){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutInitWindowSize (450, 800);
  glutInitWindowPosition(700,200);
  glutCreateWindow(argv[0]);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutDisplayFunc(display);
  glutTimerFunc(15, timer, 0);
  init();
  glutMainLoop();
  return 0;
}
