
#include <GL/glut.h>  // Include GLUT header here
#include <stdlib.h>
#include <math.h>


//float p=-2.3;
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void init(void)
{
    glClearColor (0.6, 0.7, 0.7, 0.0);
    glOrtho(0, 2000.0, 0, 1600, -1.0, 1.0);
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    //glPushMatrix();

    // Upper Section //

    // Upper Rectangle background
    glColor3f(0.3f, 0.2f, 0.7f);  // Set color to Purple

    glBegin(GL_QUADS);  // Draw a square Background
    glVertex3d(0.0, 800.0, 0.0);
    glVertex3d(2000.0, 800.0, 0.0);
    glVertex3d(2000.0, 1600.0, 0.0);
    glVertex3d(0.0, 1600.0, 0.0);
    glEnd();

    //.....Hills Section.....//

    // Hill Middle
    glColor3f(0.3f, 0.4f, 0.1f);  // Set color to Darker Green

    glBegin(GL_TRIANGLES);  // Draw a square
    glVertex3d(400.0, 800.0, 0.0);
    glVertex3d(1600.0, 800.0, 0.0);
    glVertex3d(1000.0, 1300.0, 0.0);
    glEnd();

    // Hill Left
    glColor3f(0.3f, 0.5f, 0.3f);  // Set color to Darker Green

    glBegin(GL_QUADS);  // Draw a square Background
    glVertex3d(980.0, 800.0, 0.0);
    glVertex3d(2100.0, 800.0, 0.0);
    glVertex3d(1700.0, 1200.0, 0.0);
    glVertex3d(1600.0, 1200.0, 0.0);
    glEnd();


    // Hill Right
    glColor3f(0.3f, 0.5f, 0.3f);  // Set color to Darker Green

    glBegin(GL_QUADS);  // Draw a square Background
    glVertex3d(0.0, 800.0, 0.0);
    glVertex3d(820.0, 800.0, 0.0);
    glVertex3d(500.0, 1200.0, 0.0);
    glVertex3d(400.0, 1200.0, 0.0);
    glEnd();

    // Draw castle circle
    glColor3f(0.969, 0.725, 0.369);
    drawCircle(1000.0f, 1300.0f, 160.0f, 100);




    // ...Lower section... //
    // Lower Rectangle background
    glColor3f(0.0f, 0.5f, 0.8f);  // Set color to Blue

    glBegin(GL_QUADS);  // Draw a square Background
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(2000.0, 0.0, 0.0);
    glVertex3d(2000.0, 800.0, 0.0);
    glVertex3d(0.0, 800.0, 0.0);
    glEnd();

    // Hills Section //

    // Hill Middle
    glColor3f(0.3f, 0.4f, 0.1f);  // Set color to Darker Green

    glBegin(GL_TRIANGLES);  // Draw a square
    glVertex3d(400.0, 0.0, 0.0);
    glVertex3d(1600.0, 0.0, 0.0);
    glVertex3d(1000.0, 500.0, 0.0);
    glEnd();

    // Hill Left
    glColor3f(0.3f, 0.5f, 0.3f);  // Set color to Darker Green

    glBegin(GL_QUADS);  // Draw a square Background
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(820.0, 0.0, 0.0);
    glVertex3d(500.0, 400.0, 0.0);
    glVertex3d(400.0, 400.0, 0.0);
    glEnd();


    // Hill Right
    glColor3f(0.3f, 0.5f, 0.3f);  // Set color to Darker Green

    glBegin(GL_QUADS);  // Draw a square Background
    glVertex3d(980.0, 0.0, 0.0);
    glVertex3d(2100.0, 0.0, 0.0);
    glVertex3d(1700.0, 400.0, 0.0);
    glVertex3d(1600.0, 400.0, 0.0);
    glEnd();

    // Draw castle circle
    glColor3f(0.969, 0.725, 0.369);
    drawCircle(1000.0f, 500.0f, 160.0f, 100);


    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (2000, 1600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("08,09,18_Harry_potter_sceen");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
