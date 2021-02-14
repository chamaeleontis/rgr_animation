#include <DrawLib.h>
#include <GL/glut.h>
clock_t curTime,startTime;
std::vector <Figure> les;
std::vector <Figure> Trava;
std::vector <Figure> Sozved;
Figure Fon;
Figure Tree;
Figure Travinka;
Figure tarelka;
Figure Zvezd;

void animateScene(int value){
    glutPostRedisplay();
    glutTimerFunc(1000 / 60,animateScene,1);
}
void drawZvezd(Figure Zvezd){
    glPushMatrix();
    glScalef(0.18,0.18,0.18);
    glTranslated(Zvezd.x,Zvezd.y,0);
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex2f(0.1, 0);
    glVertex2f(-0.1, 0);
    glVertex2f(0, 0.12);
    glColor3f(1,1,1);
    glVertex2f(0.1, 0);
    glVertex2f(-0.1, 0);
    glVertex2f(0, -0.12);
    glColor3f(1,1,1);
    glVertex2f(0, 0.1);
    glVertex2f(-0.12, 0);
    glVertex2f(0, -0.1);
    glColor3f(1,1,1);
    glVertex2f(0, 0.1);
    glVertex2f(0.12, 0);
    glVertex2f(0, -0.1);
    glEnd();
    glPopMatrix();
}
void drawSozved(){
    glPushMatrix();
    curTime = clock() - startTime;
    if(curTime > 11000){
    for(int i=0; i < Sozved.size(); i++)
        {drawZvezd (Sozved[i]); }
    }
    glPopMatrix();
}
void initSozved(){
    srand(666);
    Figure Zvezd;

    for (int i=0; i<300; i++) {
        Zvezd.x = 0.1*(rand()%150)-10;
        Zvezd.y = 0.1*(rand()%120)+0.5;
        Sozved.push_back(Zvezd);
}
}

void drawFon(Figure f){

    glPushMatrix();
    curTime = clock();
    float phi = curTime*0.00018;
    float x = sin(phi);
    float y = cos(phi);
    float w = sin(phi+3.14);
    float q = cos(phi+3.14);
    float del = curTime*0.00018;
    if(y>0.2)
      f.r = 0.0, f.g = 0.0, f.b = cos(del);
        else if (y<0.2 & y>-0.2 & x>0)
          f.r = 0, f.g = 0, f.b = 0.1;
             else if(y<-0.2)
               f.r = 0, f.g = 0, f.b = 0.1;
                   else if(y<0.2 & y>-0.2 & x<0)
                       {f.r = 0,  f.g = 0, f.b = 1; }


    glBegin(GL_QUADS);
    glColor3f(f.r,f.g,f.b);
    glVertex2f(1.0,-0.2);
    glVertex2f(1.0,1.0);
    glVertex2f(-1.0,1.0);
    glVertex2f(-1.0,-0.2);
    glEnd();
    glPushMatrix();
    curTime = clock() - startTime;
    if(curTime > 11000){
    for(int i=0; i < Sozved.size(); i++)
        {drawZvezd (Sozved[i]); }
    }
    glPopMatrix();
    glPushMatrix();
    glTranslatef(w,q,.0);
    glScalef(0.23,0.23,.23);
    glBegin(GL_TRIANGLE_FAN);
    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    for(float i=0;i<2*M_PI;i+=M_PI/18)
    glVertex2f (cos(i),sin(i));
    glPopMatrix();
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(x,y,.0);
    glScalef(0.23,0.23,.23);
    glBegin(GL_TRIANGLE_FAN);
    glPushMatrix();
    glColor3f(1.0,0.95,0.3);
    for(float i=0;i<2*M_PI;i+=M_PI/18)
    glVertex2f (cos(i),sin(i));
    glPopMatrix();
    glEnd();
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.08,0.15,0.05);
    glVertex2f(1.0,0.19);
    glVertex2f(1.0,-1.0);
    glVertex2f(-1.0,-1.0);
    glVertex2f(-1.0,0);
    glEnd();
    glPopMatrix();


}

void drawTarelka(){
    glPushMatrix();


    glTranslatef(0,0,.0);
    glScalef(0.26,0.26,.26);
    glBegin(GL_TRIANGLE_FAN);
    glPushMatrix();
    glColor3f(0.5,0,0);
    for(float i=0;i<2*M_PI;i+=M_PI/18)
    glVertex2f (cos(i),sin(i));
    glPopMatrix();
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,0,.0);
    glScalef(0.25,0.25,.25);
    glBegin(GL_TRIANGLE_FAN);
    glPushMatrix();
    glColor3f(0.22,0.45,0.66);
    for(float i=0;i<2*M_PI;i+=M_PI/18)
    glVertex2f (cos(i),sin(i));
    glPopMatrix();
    glEnd();
    glPopMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.45,0,0);
    glVertex2f(0.25,0);
    glVertex2f(-0.25,0);
    glVertex2f(-0.25,-0.3);
    glVertex2f(0.25,-0.3);
    glEnd();
    glBegin(GL_TRIANGLES);
    glColor3f(0.45,0,0);
    glVertex2f(0.25, 0);
    glVertex2f(0.7, -0.3);
    glVertex2f(0.25, -0.3);
    glColor3f(0.45,0,0);
    glVertex2f(-0.25, 0);
    glVertex2f(-0.7, -0.3);
    glVertex2f(-0.25, -0.3);
    glEnd();

    glPushMatrix();
    glTranslatef(0,-0.17,.0);
    glScalef(0.03,0.03,.03);
    glBegin(GL_TRIANGLE_FAN);
    glPushMatrix();
    glColor3f(0.9,0.9,0.06);
    for(float i=0;i<2*M_PI;i+=M_PI/18)
    glVertex2f (cos(i),sin(i));
    glPopMatrix();
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-0.3,-0.17,.0);
    glScalef(0.03,0.03,.03);
    glBegin(GL_TRIANGLE_FAN);
    glPushMatrix();
    glColor3f(0.9,0.9,0.06);
    for(float i=0;i<2*M_PI;i+=M_PI/18)
    glVertex2f (cos(i),sin(i));
    glPopMatrix();
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.3,-0.17,.0);
    glScalef(0.03,0.03,.03);
    glBegin(GL_TRIANGLE_FAN);
    glPushMatrix();
    glColor3f(0.9,0.9,0.06);
    for(float i=0;i<2*M_PI;i+=M_PI/18)
    glVertex2f (cos(i),sin(i));
    glPopMatrix();
    glEnd();
    glPopMatrix();

}
void drawLetim(Figure tarelka){
    glPushMatrix();
            tarelka.r = 1.0, tarelka.g = 1.0, tarelka.b = 0.6;
            curTime = clock() - startTime;
            float x=-11.2, y=-1.2;
            if(curTime < 12000)
               {x =x+curTime*0.0009;}
            else if (curTime > 12000 & curTime < 15000)
            {
                x =-11.2+12000*0.0009;
            }
            else if (curTime > 15000)
            {
                x =-11.2+12000*0.0009;
                y=y+(curTime-15000)*0.0009;
            }
            glScalef(0.7,0.7,0.7);
            glTranslatef(x,y+1.7,0);
            drawTarelka();
            glPopMatrix();

}

void drawTree(Figure Tree){
        glPushMatrix();
        glTranslatef(0,-1,0);
        glScalef(0.7, 0.7, 0);
        glTranslated(Tree.x,Tree.y, 0);
        glBegin(GL_TRIANGLES);
        glColor3f(Tree.r,Tree.g,Tree.b);
        glVertex2f(1, -0.7);
        glVertex2f(0.3, -0.7);
        glColor3f(1,1,1);
        glVertex2f(0.65, -0.2);
        glColor3f(Tree.r,Tree.g,Tree.b);
        glVertex2f(0.4, -0.4);
        glVertex2f(0.9, -0.4);
        glColor3f(1,1,1);
        glVertex2f(0.65, 0);
        glColor3f(Tree.k,Tree.z,Tree.s);
        glVertex2f(0.7, -0.7);
        glVertex2f(0.6, -0.7);
        glVertex2f(0.7, -0.8);
        glColor3f(Tree.k,Tree.z,Tree.s);
        glVertex2f(0.6, -0.8);
        glVertex2f(0.6, -0.7);
        glVertex2f(0.7, -0.8);
        glEnd();
        glPopMatrix();
    }
void drawLes(){
    glPushMatrix();
    for(int i=0; i < les.size(); i++)
        {drawTree (les[i]);}
    glPopMatrix();
}
void initLes(){
    srand(77);
    Figure Tree;
    for (int i=0; i<7; i++) {
        Tree.x = 0.1*(rand()%15)-0.45;
        Tree.y = 0.1*(rand()%15)+0.6;
        Tree.r=0.039;
        Tree.g=0.196;
        Tree.b=0.126;
        Tree.k= .59;
        Tree.z=.30;
        Tree.s=0;
        les.push_back(Tree);
    }
}

void DrawTravinka(Figure Travinka){
    glPushMatrix();
    glTranslated(Travinka.x,Travinka.y, 0);
    glBegin(GL_TRIANGLES);
    glColor3f(Travinka.r,Travinka.g,Travinka.b);
    glVertex2f(0, 0);
    glVertex2f(0, 0.12);
    glVertex2f(0.1, 0);
    glVertex2f(0.111, 0.11);
    glVertex2f(0.12, 0);
    glVertex2f(0.1, 0);
    glVertex2f(0.12, 0);
    glVertex2f(0.16, 0);
    glVertex2f(0.16, 0.125);
    glEnd();
    glPopMatrix();
}
void drawTrava(){
    glPushMatrix();
    for(int i=0; i < Trava.size(); i++)
        { DrawTravinka(Trava[i]);
    }
    glPopMatrix();
}
void initTrava(){
    srand(777);
    Figure Travinka;
    for (int i=0; i<15; i++) {
        Travinka.x = 0.1*(rand()%11)-1;
        Travinka.y = 0.1*(rand()%11)-1;
        Travinka.r=0.20;
        Travinka.g=0.35;
        Travinka.b=0.123;
        Trava.push_back(Travinka);
    }
}

void drawCat(float r, float g, float b) {
    glPushMatrix();
    glTranslated(-0.15,-0.3,0);
    glBegin(GL_TRIANGLES);
    glColor3f(r, g, b);
    glVertex2f(0, 0.2);
    glColor3f(1, 1, 1);
    glVertex2f(-0.1, 0.4);
    glColor3f(1, 1, 1);
    glVertex2f(-0.3, 0.1);

    glColor3f(1, 1, 1);
    glVertex2f(-0.3, 0.1);
    glColor3f(r, g, b);
    glVertex2f(-0.1, 0.4);
    glColor3f(r, g,b);
    glVertex2f(-0.5, 0.4);

    glColor3f(1, 1, 1);
    glVertex2f(0, 0.2);
    glColor3f(1, 1, 1);
    glVertex2f(.05, 0.4);
    glColor3f(r, g, b);
    glVertex2f(-0.1, 0.4);

    glColor3f(r, g, b);
    glVertex2f(0.05, 0.4);
    glColor3f(1, 1, 1);
    glVertex2f(-0.1, 0.5);
    glColor3f(r, g, b);
    glVertex2f(-0.1, 0.4);

    glColor3f(r, g, b);
    glVertex2f(-0.1, 0.4);
    glColor3f(1, 1, 1);
    glVertex2f(-0.5, 0.4);
    glColor3f(1, 1, 1);
    glVertex2f(-0.3, 0.5);

    glColor3f(1, 1, 1);
    glVertex2f(-0.1, 0.4);
    glColor3f(r, g, b);
    glVertex2f(-0.1, 0.5);
    glColor3f(1, 1, 1);
    glVertex2f(-0.3, 0.5);

    glColor3f(1, 1, 1);
    glVertex2f(0.05, 0.4);
    glColor3f(1, 1, 1);
    glVertex2f(-0.1, 0.5);
    glColor3f(r, g, b);
    glVertex2f(0.1, 0.7);

    glColor3f(r, g, b);
    glVertex2f(-0.5, 0.5);
    glColor3f(1, 1, 1);
    glVertex2f(-0.5, 0.4);
    glColor3f(1, 1, 1);
    glVertex2f(-0.3, 0.5);

    glColor3f(r, g, b);
    glVertex2f(-0.5, 0.5);
    glColor3f(r, g, b);
    glVertex2f(-0.5, 0.4);
    glColor3f(1, 1, 1);
    glVertex2f(-0.65, 0.4);

    glColor3f(1, 1, 1);
    glVertex2f(-0.5, 0.5);
    glColor3f(r, g, b);
    glVertex2f(-0.7, 0.7);
    glColor3f(r, g, b);
    glVertex2f(-0.65, 0.4);

    glColor3f(1, 1, 1);
    glVertex2f(-0.3, 0.1);
    glColor3f(1, 1, 1);
    glVertex2f(-0.6, 0.2);
    glColor3f(1, 1, 1);
    glVertex2f(-0.5, 0.4);

    glColor3f(1, 1, 1);
    glVertex2f(-0.65, 0.4);
    glColor3f(r, g, b);
    glVertex2f(-0.6, 0.2);
    glColor3f(1, 1, 1);
    glVertex2f(-0.5, 0.4);

    glColor3f(r, g, b);
    glVertex2f(0, 0.2);
    glColor3f(1, 1, 1);
    glVertex2f(0, -0.2);
    glColor3f(r, g, b);
    glVertex2f(-0.3, 0.1);

    glColor3f(1, 1, 1);
    glVertex2f(-0.3, 0.1);
    glColor3f(1, 1, 1);
    glVertex2f(0, -0.2);
    glColor3f(r, g, b);
    glVertex2f(-0.4, -0.6);

    glColor3f(1, 1, 1);
    glVertex2f(-0.6, -0.8);
    glColor3f(r, g, b);
    glVertex2f(-0.2, -0.8);
    glColor3f(1, 1, 1);
    glVertex2f(-0.4, -0.6);

    glColor3f(r, g, b);
    glVertex2f(0, 0.2);
    glColor3f(r, g, b);
    glVertex2f(0.4, -0.3);
    glColor3f(1, 1, 1);
    glVertex2f(-0.2, -0.8);

    glColor3f(1, 1, 1);
    glVertex2f(0, 0.2);
    glColor3f(1, 1, 1);
    glVertex2f(-0.4, -0.6);
    glColor3f(r, g, b);
    glVertex2f(-0.2, -0.8);

    glColor3f(r, g, b);
    glVertex2f(-0.2, -0.8);
    glColor3f(1, 1, 1);
    glVertex2f(0.4, -0.3);
    glColor3f(1, 1, 1);
    glVertex2f(0.4, -0.6);

    glColor3f(1, 1, 1);
    glVertex2f(-0.2, -0.8);
    glColor3f(r, g, b);
    glVertex2f(0.4, -0.8);
    glColor3f(1, 1, 1);
    glVertex2f(0.4, -0.6);

    glColor3f(r, g, b);
    glVertex2f(0.6, -0.8);
    glColor3f(1, 1, 1);
    glVertex2f(0.4, -0.8);
    glColor3f(r, g, b);
    glVertex2f(0.4, -0.6);

    glColor3f(1, 1, 1);
    glVertex2f(0.6, -0.8);
    glColor3f(r, g, b);
    glVertex2f(0.8, -0.8);
    glColor3f(1, 1, 1);
    glVertex2f(0.4, -0.6);

    glColor3f(1, 1, 1);
    glVertex2f(0.8, -0.8);
    glColor3f(r, g, b);
    glVertex2f(0.6, -0.8);
    glColor3f(1, 1, 1);
    glVertex2f(0.8, -0.5);
    glEnd();
    glPopMatrix();

}
void drawDosvidanya(){

    glPushMatrix();

    curTime = clock() - startTime;
    float x=1, y=-0.5, v=5;
    if(curTime < 5600)
       {x =x-curTime*0.00023;}
    else if (curTime > 5600 & curTime < 12000)
    {
        x =1-5600*0.00023;
    }
    else if(curTime>12000 & curTime<15000)
    {   x=1-5600*0.00023;
        v=(v+(curTime-12000)*0.01);
        y=y+(curTime-12000)*0.00023; }
    else if(curTime>15000)
    {x=10;y=10;}
    glTranslatef(x, y, 0);
    glScalef(1/v,1/v,1/v);
    drawCat(0.98, 0.6, 0.75);
    glPopMatrix();
}

void drawDraw(){

    drawFon(Fon);
    drawLes();
    drawTrava();
    drawDosvidanya();
    drawLetim(tarelka);
}

