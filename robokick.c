#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define PI 3.14159265358979
#define G 9.80665

double arc, b_ang;
double ang;
double x, y;
double xr, yr;
double vx, vy;
char simu_flag = 99;
char ivent_flag = 99;
double f_ang = 300, ff_ang;
double dt = 0.001;
float e = -0.7;
float teikou = 0.9;

struct Ball{
  double r;
  GLfloat iti_x;
  GLfloat iti_y;
  float vx, vy;
};

struct Ball ball[] = {
  7, 0, 0, 0, 0,
};

struct Foot {
  double iti_x;
  double iti_y;
  double dotx1, doty1;
  double dotx2, doty2;
  double dotx3, doty3;
  double dotx4, doty4;
  double dotx5, doty5;
  double dotx6, doty6;
  double dotx7, doty7;
  double r_itix, r_itiy, r, itir, r_katamuki;
  GLfloat footp;
  double center;
};

struct Foot foot = {
  -20, 22.0, 2.5, 2.5, -2.5, 2.5, -2.5, -30, 2.5, -30, 5, -30, 5, -25, 2.5, -25, 5, -27.5, 2.5, 27.042, 11.537, 30, 1.5,
};

struct Yuka{
  double kax;
  double kay;
};

struct Yuka yuka[] = {
  -100, 0,
  400, 0,
};

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
//床　壁  
  glPushMatrix();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex2d(yuka[0].kax, yuka[0].kay - ball[0].r);
  glVertex2d(yuka[1].kax, yuka[1].kay - ball[0].r);
  glEnd();
  glPopMatrix();
//ボール　
//ピンク半球  
  glPushMatrix();
  glTranslatef(ball[0].iti_x, ball[0].iti_y, 0.0);
  glRotated((double)ang, 0.0, 0.0, 1.0);
  glColor3f(1.0, 0.7, 1.0);
  for(arc = 90; arc <= 180; arc += 10){
    b_ang = PI * arc / 180.0;
    glBegin(GL_POLYGON);
    x = ball[0].r * cos(b_ang);
    y = ball[0].r * sin(b_ang);
    glVertex2d(x, y);
  }
  glVertex2d(0,0);
  glEnd();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(ball[0].iti_x, ball[0].iti_y, 0.0);
  glRotated((double)ang, 0.0, 0.0, 1.0);
  glColor3f(1.0, 0.7, 1.0);
  for(arc = 270; arc <= 360; arc += 10){
    b_ang = PI * arc / 180.0;
    glBegin(GL_POLYGON);
    x = ball[0].r * cos(b_ang);
    y = ball[0].r * sin(b_ang);
    glVertex2d(x, y);
  }
  glVertex2d(0,0);
  glEnd();
  glPopMatrix();
//水色半球
  glPushMatrix();
  glTranslatef(ball[0].iti_x, ball[0].iti_y, 0.0);
  glRotated((double)ang, 0.0, 0.0, 1.0);
  glColor3f(0.7, 1.0, 1.0);
  for(arc = 180; arc <= 270; arc += 10){
    b_ang = PI * arc / 180.0;
    glBegin(GL_POLYGON);
    x = ball[0].r * cos(b_ang);
    y = ball[0].r * sin(b_ang);
    glVertex2d(x, y);
  }
  glVertex2d(0,0);
  glEnd();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(ball[0].iti_x, ball[0].iti_y, 0.0);
  glRotated((double)ang, 0.0, 0.0, 1.0);
  glColor3f(0.7, 1.0, 1.0);
  for(arc = 0; arc <= 90; arc += 10){
    b_ang = PI * arc / 180.0;
    glBegin(GL_POLYGON);
    x = ball[0].r * cos(b_ang);
    y = ball[0].r * sin(b_ang);
    glVertex2d(x, y);
  }
  glVertex2d(0,0);
  glEnd();
  glPopMatrix();
//ボール枠線
  glPushMatrix();
  glTranslatef(ball[0].iti_x, ball[0].iti_y, 0.0);
  glColor3f(0.3, 0.2, 0.1);
  for(arc = 0; arc <= 360; arc += 10){
    b_ang = PI * arc / 180.0;
    glBegin(GL_LINE_LOOP);
    x = ball[0].r * cos(b_ang);
    y = ball[0].r * sin(b_ang);
    glVertex2d(x, y);
  }
  glEnd();
  glPopMatrix();
//足
//つま先
  glPushMatrix();
  glTranslatef(foot.iti_x, foot.iti_y, 0.0);
  glRotated((double)f_ang, 0.0, 0.0, 1.0);
  glColor3f(1.0, 1.0, 0.4);
  for(arc = -90; arc <= 90; arc += 10){
    b_ang = PI * arc / 180.0;
    glBegin(GL_POLYGON);
    x = foot.r * cos(b_ang) + foot.r_itix;
    y = foot.r * sin(b_ang) + foot.r_itiy;
    glVertex2d(x, y);
  }
  glEnd();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(foot.iti_x, foot.iti_y, 0.0);
  glRotated((double)f_ang, 0.0, 0.0, 1.0);
  glColor3f(1.0, 0.0, 0.0);
  for(arc = -90; arc <= 90; arc += 10){
    b_ang = PI * arc / 180.0;
    glBegin(GL_LINE_STRIP);
    x = foot.r * cos(b_ang) + foot.r_itix;
    y = foot.r * sin(b_ang) + foot.r_itiy;
    glVertex2d(x, y);
  }
  glEnd();
  glPopMatrix();
//足
  glPushMatrix();
  glTranslatef(foot.iti_x, foot.iti_y, 0.0);
  glRotated((double)f_ang, 0.0, 0.0, 1.0);
  glColor3f(1.0, 1.0, 0.4);
  glBegin(GL_QUADS);
  glVertex2d(foot.dotx1, foot.doty1);
  glVertex2d(foot.dotx2, foot.doty2);
  glVertex2d(foot.dotx3, foot.doty3);
  glVertex2d(foot.dotx4, foot.doty4);
  glEnd();
  glPopMatrix();
//脛
  glPushMatrix();
  glTranslatef(foot.iti_x, foot.iti_y, 0.0);
  glRotated((double)f_ang, 0.0, 0.0, 1.0);
  glColor3f(1.0, 1.0, 0.4);
  glBegin(GL_QUADS);
  glVertex2d(foot.dotx4, foot.doty4);
  glVertex2d(foot.dotx5, foot.doty5);
  glVertex2d(foot.dotx6, foot.doty6);
  glVertex2d(foot.dotx7, foot.doty7);
  glEnd();
  glPopMatrix();
  glPushMatrix();
  glTranslatef(foot.iti_x, foot.iti_y, 0.0);
  glRotated((double)f_ang, 0.0, 0.0, 1.0);
  glColor3f(1.0, 0.0, 0.0);
  glBegin(GL_LINE_STRIP);
  glVertex2d(foot.dotx6, foot.doty6);
  glVertex2d(foot.dotx7, foot.doty7);
  glVertex2d(foot.dotx1, foot.doty1);
  glVertex2d(foot.dotx2, foot.doty2);
  glVertex2d(foot.dotx3, foot.doty3);
  glVertex2d(foot.dotx4, foot.doty4);
  glVertex2d(foot.dotx5, foot.doty5);
  glEnd();
  glPopMatrix();
//回転中心
  glPushMatrix();
  glTranslatef(foot.iti_x, foot.iti_y, 0.0);
  glRotated((double)f_ang, 0.0, 0.0, 1.0);
  glColor3f(1.0, 0.0, 0.0);
  for(arc = 0; arc <= 360; arc += 10){
    b_ang = PI * arc / 180.0;
    glBegin(GL_POLYGON);
    x = foot.center * cos(b_ang);
    y = foot.center * sin(b_ang);
    glVertex2d(x, y);
  }
  glEnd();
  glPopMatrix();  
  
  glutSwapBuffers();
}

void simu(){
  switch(ivent_flag){
    case 99:
      switch(simu_flag){
//左クリック　右回転
        case 'l':
          ang = ang + 0.1;
          if(ang > 360.0)
            ang = ang - 360.0;
//左に進む
          ball[0].iti_x -= 0.01;
          glutPostRedisplay();
          break;
//右クリック　左回転
        case 'r':
          ang = ang - 0.1;
          if(ang < -360.0)
            ang = ang + 360.0;
//右に進む
          ball[0].iti_x += 0.01;
          glutPostRedisplay();
          break;
//足を回転
        case 'f':
          f_ang += 0.1;
          if(f_ang < 360.0)
            f_ang = f_ang - 360.0;
//つま先の座標
          ff_ang = f_ang + foot.r_katamuki - 90.0;
          xr = foot.itir * cos(ff_ang / 180.0 * PI) + foot.iti_x;
          yr = foot.itir * sin(ff_ang / 180.0 * PI) + foot.iti_y;
//当たり判定
          if(sqrt((ball[0].iti_x - xr)*(ball[0].iti_x - xr)+(ball[0].iti_y - yr)*(ball[0].iti_y - yr)) < ball[0].r + foot.r)
          ivent_flag = 1;
//力から速度への変換
          vx = ball[0].iti_x - xr;
          vx *= foot.footp;
          ball[0].vx = vx / (ball[0].r + foot.r);
          vy = ball[0].iti_y - yr;
          vy *= foot.footp;
          ball[0].vy = vy / (ball[0].r + foot.r);
          break;
        default:
          break;
      }
      break;
//衝撃後のボール描写
    case 1:
      ang -= vx / ball[0].r * 2 * dt;
      if(ang < -360.0)
        ang = ang + 360.0;
      ball[0].iti_x += ball[0].vx * dt;
      ball[0].iti_y += ball[0].vy * dt - G * dt * dt/2;
      ball[0].vy -= G *dt;
      if(ball[0].iti_y <= 0){
        ball[0].vy = (ball[0].vy) * e;
        ball[0].iti_y = 0;
        ball[0].vx *= teikou;
        if(ball[0].vx < 0.001){
          ball[0].vx = 0;
          ivent_flag = 99;
          simu_flag = 99;
          f_ang = 300;
        }
      }
      glutPostRedisplay();
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
  switch(button){
//クリック時のみ実行
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
//足の回転
  if( key == ' ') simu_flag = 'f';
//終了コマンド
  if(key == 'q'| key == 'Q'| key == '\033')exit(0);
}

void resize(int w, int h){
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
//座標軸定義
  glOrtho(-50.0, 300.0, -20.0, 80.0, -1.5, 1.5);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void init(){
  glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char *argv[]){
//表示位置
  glutInitWindowPosition(50, 50);
//表示大きさ
  glutInitWindowSize(1400, 400);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutReshapeFunc(resize);
  glutIdleFunc(simu);
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  init();
  
  glutMainLoop();
  return 0;
}

