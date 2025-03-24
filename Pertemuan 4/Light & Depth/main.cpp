#include <GL/glut.h>
#include <math.h>

float angle = 0.0, deltaAngle = 0.0, ratio;
float x = 0.0f, y = 1.75f, z = 15.0f; 
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
int deltaMove = 0;

void Reshape(int w, int h) {
    if (h == 0) h = 1;
    ratio = (float)w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45, ratio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
}

void orientMe(float ang) {
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void moveMeFlat(int dir) {
    x += dir * lx * 0.1;
    z += dir * lz * 0.1;
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
}

void Grid() {
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
    for (float i = -50; i <= 50; i += 1.5) {
        glVertex3f(i, 0, -50); glVertex3f(i, 0, 50);
        glVertex3f(-50, 0, i); glVertex3f(50, 0, i);
    }
    glEnd();
}

void KotakKayu() {
    // Depan
    glBegin(GL_QUADS);
    glVertex3f(-3.0f, -3.0f, 3.0f);
    glVertex3f(3.0f, -3.0f, 3.0f);
    glVertex3f(3.0f, 3.0f, 3.0f);
    glVertex3f(-3.0f, 3.0f, 3.0f);
    glEnd();
    // ... (implementasi sisi lain serupa)
}

GLfloat light_ambient[] = {0.5f, 0.5f, 0.5f, 1.0f};
GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat light_position[] = {0.0f, 20.0f, 10.0f, 1.0f};

void lighting() {
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(x, y, z, x + lx, y + ly, z + lz, 0.0f, 1.0f, 0.0f);
    Grid();
    KotakKayu();
    glutSwapBuffers();
}

void pressKey(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_LEFT: deltaAngle = -0.01f; break;
        case GLUT_KEY_RIGHT: deltaAngle = 0.01f; break;
        case GLUT_KEY_UP: deltaMove = 1; break;
        case GLUT_KEY_DOWN: deltaMove = -1; break;
    }
}

void releaseKey(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT) deltaAngle = 0.0f;
    if (key == GLUT_KEY_UP || key == GLUT_KEY_DOWN) deltaMove = 0;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(640, 480);
    glutCreateWindow("3D Lighting");
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutDisplayFunc(display);
    glutReshapeFunc(Reshape);
    lighting();
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
