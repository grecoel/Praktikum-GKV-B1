// Gege Centiana Putra
// 24060123120024
// Informatika B

#include <GL/glut.h>

// Joint angles
static int shoulder = 0, elbow = 0, wrist = 0;
static int thumb = 0, index_finger = 0, middle_finger = 0, ring_finger = 0, pinky = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    
    // Shoulder
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Elbow
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Wrist
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)wrist, 0.0, 0.0, 1.0);
    glTranslatef(0.5, 0.0, 0.0);
    
    // Palm
    glPushMatrix();
    glScalef(1.0, 0.5, 1.2);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Thumb
    glPushMatrix();
    glTranslatef(0.0, -0.3, 0.5);
    glRotatef((GLfloat)thumb, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, 0.3);
    glScalef(0.3, 0.2, 0.6);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Index finger
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.4);
    glRotatef((GLfloat)index_finger, 0.0, 1.0, 0.0);
    glTranslatef(0.35, 0.0, 0.0);
    glScalef(0.7, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Middle finger
    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.1);
    glRotatef((GLfloat)middle_finger, 0.0, 1.0, 0.0);
    glTranslatef(0.4, 0.0, 0.0);
    glScalef(0.8, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Ring finger
    glPushMatrix();
    glTranslatef(0.5, 0.0, -0.2);
    glRotatef((GLfloat)ring_finger, 0.0, 1.0, 0.0);
    glTranslatef(0.35, 0.0, 0.0);
    glScalef(0.7, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    
    // Pinky finger
    glPushMatrix();
    glTranslatef(0.5, 0.0, -0.5);
    glRotatef((GLfloat)pinky, 0.0, 1.0, 0.0);
    glTranslatef(0.25, 0.0, 0.0);
    glScalef(0.5, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
    
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        // Shoulder controls
        case 's': 
            shoulder = (shoulder + 5) % 360;
            glutPostRedisplay();
            break;
        case 'S': 
            shoulder = (shoulder - 5) % 360;
            glutPostRedisplay();
            break;
        
        // Elbow controls
        case 'e': 
            elbow = (elbow + 5) % 360;
            glutPostRedisplay();
            break;
        case 'E': 
            elbow = (elbow - 5) % 360;
            glutPostRedisplay();
            break;
        
        // Wrist controls
        case 'w': 
            wrist = (wrist + 5) % 360;
            glutPostRedisplay();
            break;
        case 'W': 
            wrist = (wrist - 5) % 360;
            glutPostRedisplay();
            break;
        
        // Thumb controls
        case 't': 
            thumb = (thumb + 5) % 90;
            glutPostRedisplay();
            break;
        case 'T': 
            thumb = (thumb - 5) % 90;
            if (thumb < 0) thumb += 90;
            glutPostRedisplay();
            break;
        
        // Index finger controls
        case 'i': 
            index_finger = (index_finger + 5) % 90;
            glutPostRedisplay();
            break;
        case 'I': 
            index_finger = (index_finger - 5) % 90;
            if (index_finger < 0) index_finger += 90;
            glutPostRedisplay();
            break;
        
        // Middle finger controls
        case 'm': 
            middle_finger = (middle_finger + 5) % 90;
            glutPostRedisplay();
            break;
        case 'M': 
            middle_finger = (middle_finger - 5) % 90;
            if (middle_finger < 0) middle_finger += 90;
            glutPostRedisplay();
            break;
        
        // Ring finger controls
        case 'r': 
            ring_finger = (ring_finger + 5) % 90;
            glutPostRedisplay();
            break;
        case 'R': 
            ring_finger = (ring_finger - 5) % 90;
            if (ring_finger < 0) ring_finger += 90;
            glutPostRedisplay();
            break;
        
        // Pinky finger controls
        case 'p': 
            pinky = (pinky + 5) % 90;
            glutPostRedisplay();
            break;
        case 'P': 
            pinky = (pinky - 5) % 90;
            if (pinky < 0) pinky += 90;
            glutPostRedisplay();
            break;
        
        // Exit
        case 27: // Escape key untuk keluar
            exit(0);
            break;
        
        default:
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
