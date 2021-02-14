#ifndef DRAWLIB_H
#define DRAWLIB_H
#include <GL/glut.h>
#include <ctime>
#include <cmath>
#include <vector>

struct Figure {
    float r,g,b,k,z,s;
    float x,y,q,w;};

extern clock_t curTime,startTime;

void animateScene(int value);
void drawFon(Figure f);
void drawTree(Figure f);
void drawLes();
void initLes();
void drawTravinka(Figure f);
void drawTrava();
void initTrava();
void drawTarelka();
void drawLetim(Figure f);
void drawZvezd(Figure f);
void drawSozved();
void initSozved();
void drawCat(float r, float g, float b);
void drawDosvidanya();
void drawDraw();
#endif // DRAWLIB_H
