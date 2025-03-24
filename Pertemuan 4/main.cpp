//Gege Centiana Putra
//24060123120024

#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <cstdio>

//-----------------------------------------------------
// Variabel global untuk mengontrol posisi dan rotasi mobil
//-----------------------------------------------------
float carPosX     = 0.0f;  // posisi mobil sumbu X
float carPosZ     = 0.0f;  // posisi mobil sumbu Z
float carRotateY  = 0.0f;  // rotasi mobil sumbu Y (horizontal)
float carRotateX  = 0.0f;  // rotasi mobil sumbu X (vertikal)

// Variabel untuk mengontrol kamera
float cameraX = 0.0f;
float cameraY = 6.0f;  
float cameraZ = 10.0f; 

//-----------------------------------------------------
// Fungsi inisialisasi pencahayaan
//-----------------------------------------------------
void initLighting()
{
    glEnable(GL_DEPTH_TEST);       t
    glEnable(GL_LIGHTING);         
    glEnable(GL_LIGHT0);            

    // Properti cahaya
    GLfloat lightAmbient[]  = {0.2f, 0.2f, 0.2f, 1.0f};  
    GLfloat lightDiffuse[]  = {0.7f, 0.7f, 0.7f, 1.0f}; 
    GLfloat lightSpecular[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat lightPosition[] = {5.0f, 15.0f, 5.0f, 1.0f}; 

    glLightfv(GL_LIGHT0, GL_AMBIENT,  lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    // Agar warna dari glColor mempengaruhi pencahayaan (material)
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

//-----------------------------------------------------
// Fungsi untuk menggambar lantai/grid
//-----------------------------------------------------
void drawGrid(float size = 40.0f, float step = 1.5f)  // Parameter diubah
{
    glDisable(GL_LIGHTING); // matikan lighting sementara agar grid terlihat jelas
    glColor3f(0.6f, 0.6f, 0.6f);  // Diubah dari kode asli

    glBegin(GL_LINES);
    for (float i = -size; i <= size; i += step)
    {
        // Garis sejajar sumbu Z
        glVertex3f(i, 0.0f, -size);
        glVertex3f(i, 0.0f,  size);

        // Garis sejajar sumbu X
        glVertex3f(-size, 0.0f, i);
        glVertex3f( size, 0.0f, i);
    }
    glEnd();

    glEnable(GL_LIGHTING); // nyalakan lagi lighting
}

//-----------------------------------------------------
// Fungsi untuk menggambar kotak (badan mobil, atap, dsb.)
// sizeX, sizeY, sizeZ adalah panjang sumbu x, y, z
//-----------------------------------------------------
void drawBox(float sizeX, float sizeY, float sizeZ)
{
    // Setengah ukuran agar pusatnya di (0,0,0)
    float x = sizeX / 2.0f;
    float y = sizeY / 2.0f;
    float z = sizeZ / 2.0f;

    glBegin(GL_QUADS);
    // DEPAN
    glNormal3f(0, 0, 1);
    glVertex3f(-x, -y,  z);
    glVertex3f( x, -y,  z);
    glVertex3f( x,  y,  z);
    glVertex3f(-x,  y,  z);

    // BELAKANG
    glNormal3f(0, 0, -1);
    glVertex3f( x, -y, -z);
    glVertex3f(-x, -y, -z);
    glVertex3f(-x,  y, -z);
    glVertex3f( x,  y, -z);

    // ATAS
    glNormal3f(0, 1, 0);
    glVertex3f(-x,  y,  z);
    glVertex3f( x,  y,  z);
    glVertex3f( x,  y, -z);
    glVertex3f(-x,  y, -z);

    // BAWAH
    glNormal3f(0, -1, 0);
    glVertex3f(-x, -y, -z);
    glVertex3f( x, -y, -z);
    glVertex3f( x, -y,  z);
    glVertex3f(-x, -y,  z);

    // KIRI
    glNormal3f(-1, 0, 0);
    glVertex3f(-x, -y, -z);
    glVertex3f(-x, -y,  z);
    glVertex3f(-x,  y,  z);
    glVertex3f(-x,  y, -z);

    // KANAN
    glNormal3f(1, 0, 0);
    glVertex3f( x, -y,  z);
    glVertex3f( x, -y, -z);
    glVertex3f( x,  y, -z);
    glVertex3f( x,  y,  z);

    glEnd();
}

//-----------------------------------------------------
// Fungsi untuk menggambar mobil
//-----------------------------------------------------
void drawCar()
{
    // BADAN UTAMA
    glPushMatrix();
      glColor3f(0.1f, 0.5f, 0.8f); // Biru 
      drawBox(2.5f, 0.6f, 1.2f);
    glPopMatrix();

    // ATAP
    glPushMatrix();
      glColor3f(0.8f, 0.1f, 0.1f); // Merah 
      glTranslatef(0.0f, 0.5f, 0.0f); // letakkan atap di atas badan
      drawBox(1.6f, 0.5f, 1.0f);  // Ukuran sedikit diubah
    glPopMatrix();

    // BAGIAN DEPAN (misal "bemper depan")
    glPushMatrix();
      glColor3f(0.3f, 0.3f, 0.3f); // Abu-abu (sedikit diubah)
      glTranslatef(0.0f, -0.05f, 0.75f); // geser ke depan
      drawBox(2.5f, 0.3f, 0.2f);
    glPopMatrix();

    // BAGIAN BELAKANG (bemper belakang)
    glPushMatrix();
      glColor3f(0.3f, 0.3f, 0.3f);
      glTranslatef(0.0f, -0.05f, -0.75f); // geser ke belakang
      drawBox(2.5f, 0.3f, 0.2f);
    glPopMatrix();

    // RODA (4 buah) menggunakan glutSolidTorus
    glColor3f(0.1f, 0.1f, 0.1f); // Hitam (sedikit diubah)
    float wheelOffsetX = 1.0f;   // jarak roda ke tengah mobil (X)
    float wheelOffsetZ = 0.6f;   // jarak roda ke tengah mobil (Z)
    float wheelY       = -0.4f;  // posisi roda di Y

    // Roda depan kiri
    glPushMatrix();
      glTranslatef(-wheelOffsetX, wheelY,  wheelOffsetZ);
      glutSolidTorus(0.08, 0.17, 10, 10);  
    glPopMatrix();

    // Roda depan kanan
    glPushMatrix();
      glTranslatef(wheelOffsetX, wheelY,  wheelOffsetZ);
      glutSolidTorus(0.08, 0.17, 10, 10); 
    glPopMatrix();

    // Roda belakang kiri
    glPushMatrix();
      glTranslatef(-wheelOffsetX, wheelY, -wheelOffsetZ);
      glutSolidTorus(0.08, 0.17, 10, 10);  
    glPopMatrix();

    // Roda belakang kanan
    glPushMatrix();
      glTranslatef(wheelOffsetX, wheelY, -wheelOffsetZ);
      glutSolidTorus(0.08, 0.17, 10, 10);  
    glPopMatrix();
}

//-----------------------------------------------------
// Fungsi display
//-----------------------------------------------------
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Set camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(cameraX, cameraY, cameraZ,   // posisi kamera
              0.0f, 0.0f, 0.0f,           // titik fokus
              0.0f, 1.0f, 0.0f);          // arah atas

    // Gambar lantai/grid
    drawGrid();

    // Gambar mobil
    glPushMatrix();
      // Translasi mobil sesuai posisinya
      glTranslatef(carPosX, 0.0f, carPosZ);

      // Rotasi mobil (Y => belok kiri/kanan, X => menyesuaikan, opsional)
      glRotatef(carRotateY, 0.0f, 1.0f, 0.0f);
      glRotatef(carRotateX, 1.0f, 0.0f, 0.0f);

      // Panggil fungsi gambar mobil
      drawCar();
    glPopMatrix();

    glutSwapBuffers();
}

//-----------------------------------------------------
// Fungsi callback saat tombol keyboard biasa ditekan
//-----------------------------------------------------
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q': // keluar program
    case 27:  // ESC
        exit(0);
        break;
    case 'a':
        carRotateY += 5.0f; // rotasi mobil ke kiri
        break;
    case 'd':
        carRotateY -= 5.0f; // rotasi mobil ke kanan
        break;
    case 'w':
        carRotateX += 5.0f; // rotasi mobil ke depan (miring)
        break;
    case 's':
        carRotateX -= 5.0f; // rotasi mobil ke belakang (miring)
        break;
    // Tombol tambahan
    case 'r':
        // Reset posisi dan rotasi mobil
        carPosX = 0.0f;
        carPosZ = 0.0f;
        carRotateX = 0.0f;
        carRotateY = 0.0f;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

//-----------------------------------------------------
// Fungsi callback saat tombol spesial (panah) ditekan
// Di sini kita atur translasi mobil
//-----------------------------------------------------
void specialKey(int key, int x, int y)
{
    float speed = 0.5f;  
    
    switch (key)
    {
    case GLUT_KEY_LEFT:
        carPosX -= speed;
        break;
    case GLUT_KEY_RIGHT:
        carPosX += speed;
        break;
    case GLUT_KEY_UP:
        carPosZ -= speed;
        break;
    case GLUT_KEY_DOWN:
        carPosZ += speed;
        break;
    }
    glutPostRedisplay();
}

//-----------------------------------------------------
// Fungsi reshape, dipanggil saat jendela diubah ukurannya
//-----------------------------------------------------
void reshape(int w, int h)
{
    if (h == 0) h = 1;
    float ratio = 1.0f * w / h;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, ratio, 0.5, 1000.0);  

    glMatrixMode(GL_MODELVIEW);
}

//-----------------------------------------------------
// Fungsi init
//-----------------------------------------------------
void initGL()
{
    glClearColor(0.9, 0.9, 0.9, 1.0); 
    initLighting();                  // inisialisasi pencahayaan
}

//-----------------------------------------------------
// Fungsi main
//-----------------------------------------------------
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mobil 3D dengan Depth dan Lighting - OpenGL");

    initGL();

    // Registrasi callback
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKey);

    // Masuk ke loop utama
    glutMainLoop();
    return 0;
}
