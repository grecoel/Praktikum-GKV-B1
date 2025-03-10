/*
Gege Centiana PUtra
24060123120024
GKV B1
*/

#include <GL/glut.h>
#include <cmath>

void drawCircle(float x, float y, float radius, float r, float g, float b) {
    int num_segments = 100;  
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float dx = radius * cosf(theta);
        float dy = radius * sinf(theta);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
}

void drawDetailedWheel(float x, float y, float outerRadius) {
    drawCircle(x, y, outerRadius, 0.0, 0.0, 0.0);
    drawCircle(x, y, outerRadius * 0.7, 0.8, 0.8, 0.8);
    drawCircle(x, y, outerRadius * 0.3, 0.6, 0.6, 0.6);
    
    glColor3f(0.7, 0.7, 0.7);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    for (int i = 0; i < 8; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / 8.0f;
        float dx = outerRadius * 0.65 * cosf(theta);
        float dy = outerRadius * 0.65 * sinf(theta);
        glVertex2f(x, y);
        glVertex2f(x + dx, y + dy);
    }
    glEnd();
    glLineWidth(1.0);
}

void drawCar() {
    glBegin(GL_QUADS);
    glColor3f(0.1, 0.1, 0.5);
    glVertex2f(-0.6, -0.15);
    glVertex2f(0.6, -0.15);
    glColor3f(0.2, 0.2, 0.8);
    glVertex2f(0.6, 0.1);
    glVertex2f(-0.6, 0.1);
    glEnd();
    
    glColor3f(0.1, 0.1, 0.4);
    glBegin(GL_QUADS);
    glVertex2f(-0.6, -0.15);
    glVertex2f(0.6, -0.15);
    glVertex2f(0.6, -0.18);
    glVertex2f(-0.6, -0.18);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.2, 0.2, 0.7);
    glVertex2f(-0.35, 0.1);
    glVertex2f(0.25, 0.1);
    glColor3f(0.3, 0.3, 0.9);
    glVertex2f(0.2, 0.28);
    glVertex2f(-0.25, 0.28);
    glEnd();
    
    glColor3f(0.7, 0.9, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(0.25, 0.1);
    glVertex2f(0.2, 0.28);
    glVertex2f(0.05, 0.28);
    glVertex2f(0.05, 0.1);
    glEnd();
    
    glColor3f(0.7, 0.9, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.05, 0.1);
    glVertex2f(-0.05, 0.28);
    glVertex2f(-0.25, 0.28);
    glVertex2f(-0.35, 0.1);
    glEnd();
    
    glLineWidth(2.0);
    glColor3f(0.1, 0.1, 0.5);
    
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.25, -0.12);
    glVertex2f(0.25, 0.1);
    glVertex2f(-0.05, 0.1);
    glVertex2f(-0.05, -0.12);
    glEnd();
    
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.05, -0.12);
    glVertex2f(-0.05, 0.1);
    glVertex2f(-0.35, 0.1);
    glVertex2f(-0.35, -0.12);
    glEnd();
    
    glColor3f(1.0, 1.0, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(0.58, 0.0);
    glVertex2f(0.58, 0.08);
    glVertex2f(0.51, 0.08);
    glVertex2f(0.51, 0.0);
    glEnd();
    
    glColor3f(1.0, 1.0, 0.6);
    drawCircle(0.54, 0.04, 0.03, 1.0, 1.0, 0.6);
    
    glColor3f(0.9, 0.1, 0.1);
    glBegin(GL_QUADS);
    glVertex2f(-0.58, 0.0);
    glVertex2f(-0.58, 0.08);
    glVertex2f(-0.51, 0.08);
    glVertex2f(-0.51, 0.0);
    glEnd();
    
    glColor3f(1.0, 0.0, 0.0);
    drawCircle(-0.54, 0.04, 0.03, 1.0, 0.3, 0.3);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawCar();
    drawDetailedWheel(-0.4, -0.18, 0.08);
    drawDetailedWheel(0.4, -0.18, 0.08);
    glutSwapBuffers();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Car Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

