#include <GL/glut.h>
#include <DrawLib.h>

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawDraw();
    glutSwapBuffers();
}

int main(int argc, char* argv[]) {
    initLes();
    initTrava();
    initSozved();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Lesson - 0, Start");
    glutDisplayFunc(renderScene);
    startTime = clock();
    glutTimerFunc(1000/60,animateScene,1);
    glutMainLoop();
    return 0;
}

