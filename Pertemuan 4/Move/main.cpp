//# Gege Centiana Putra
//# 24060123120024
//# teapot

#include <GL/glut.h>
#include <stdlib.h>

double rotAngle = 10.0; 
double rotAngle1 = 10.0;

void init() {
    glClearColor(0, 0, 0, 0);
    glClearDepth(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotated(rotAngle, 0, 1, 0);  // Rotasi sumbu Y
    glRotated(rotAngle1, 1, 0, 0); // Rotasi sumbu X
    glColor3f(1.0, 0.1, 0.1);
    glutSolidTeapot(1);
    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char k, int x, int y) {
    switch(k) {
        case 'a': rotAngle += 5; break;
        case 'y': rotAngle1 += 5; break;
        case 'b': rotAngle1 -= 5; break;
        case '1': rotAngle -= 5; break;
        case 'q': exit(0);
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Kamera OpenGL");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
    return 0;
}
