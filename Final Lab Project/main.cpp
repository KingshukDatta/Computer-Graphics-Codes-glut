#include <GL/glut.h>  // Include GLUT header here
#include <stdlib.h>
#include <math.h>


//float p=-2.3;
void DrawCircle(float cx, float cy, float rx,float ry, int num_segments)
{
    glBegin(GL_TRIANGLE_FAN);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

        float x = rx * cosf(theta);//calculate the x component
        float y = ry * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex

    }
    glEnd();
}
void init(void)
{
    glClearColor (0.6, 0.7, 0.7, 0.0);
    glOrtho(0.0, 1950.0, 0.0, 800.0, -8.0, 8.0);
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    //glPushMatrix();

    // Hill-1 (Middle-Triangle)
    glColor3f(0.631f, 0.62f, 0.616f);  // Set color to light grey

    glBegin(GL_TRIANGLES);  // Draw hill-1 (Triangle)
    glVertex3d(200.0, 0.0, 0.0);
    glVertex3d(1050.0, 0.0, 0.0);
    glVertex3d(550.0, 250.0, 0.0);
    glEnd();

    // Hill-2 (left-rectangle)
    glColor3f(0.0f, 0.4f, 0.1f);  // Set color to hill left.
    glBegin(GL_QUADS);  // Draw a hill-2 (square).
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(850.0, 0.0, 0.0);
    glVertex3d(350.0, 300.0, 0.0);
    glVertex3d(0.0, 210.0, 0.0);
    glEnd();

    // Hill-2 (Middle-Triangle)
    glColor3f(0.631f, 0.62f, 0.616f);  // Set color to light grey

    glBegin(GL_TRIANGLES);  // Draw hill-2 (Triangle)
    glVertex3d(0.0, 0.0, 0.0);
    glVertex3d(60.0, 0.0, 0.0);
    glVertex3d(0.0, 20.0, 0.0);
    glEnd();

    // Bottom Triangle right
    glColor3f(0.7f, 0.7f, 0.7f);  // Set color to dark grey

    glBegin(GL_TRIANGLES);  // Draw a square
    glVertex3d(40.0, 0.0, 0.0);
    glVertex3d(300.0, 0.0, 0.0);
    glVertex3d(300.0, 70.0, 0.0);
    glEnd();

    // Bottom left rectangle
    glColor3f(0.6f, 0.6f, 0.6f);  // Set color to dark grey

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(35.0, 0.0, 0.0);
    glVertex3d(40.0, 0.0, 0.0);
    glVertex3d(40.0, 90.0, 0.0);
    glVertex3d(35.0, 90.0, 0.0);
    glEnd();

    // Bottom left rectangle circle
    glColor3f(0.6f, 0.6f, 0.6f);

    DrawCircle(37.5,110,20,20,100);
    glPopMatrix();

    // Bottom left rectangle middle circle
    glColor3f(0.6f, 0.7f, 0.7f);

    DrawCircle(37.5,110,18,18,100);
    glPopMatrix();

    // Bottom right rectangle
    glColor3f(0.6f, 0.6f, 0.6f);  // Set color to dark grey

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(100.0, 0.0, 0.0);
    glVertex3d(105.0, 0.0, 0.0);
    glVertex3d(105.0, 70.0, 0.0);
    glVertex3d(100.0, 70.0, 0.0);
    glEnd();

    // Bottom right rectangle circle
    glColor3f(0.6f, 0.6f, 0.6f);

    DrawCircle(102.5,90,20,20,100);
    glPopMatrix();

    // Bottom right rectangle middle circle
    glColor3f(0.6f, 0.7f, 0.7f);

    DrawCircle(102.5,90,18,18,100);
    glPopMatrix();


    // Tent
    // Bottom left rectangle for tent
    glColor3f(0.788f, 0.78f, 0.204f);  // Set color to dark yellow

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(120.0, 0.0, 0.0);
    glVertex3d(140.0, 0.0, 0.0);
    glVertex3d(140.0, 37.5, 0.0);
    glVertex3d(120.0, 35.0, 0.0);
    glEnd();

    // Bottom right rectangle for tent
    glColor3f(0.0f, 0.0f, 0.0f);  // Set color to Black

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(140.0, 0.0, 0.0);
    glVertex3d(160.0, 0.0, 0.0);
    glVertex3d(160.0, 40.0, 0.0);
    glVertex3d(140.0, 37.5, 0.0);
    glEnd();

    // Upper left rectangle for tent
    glColor3f(0.0f, 0.0f, 0.0f);  // Set color to Black

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(120.0, 35.0, 0.0);
    glVertex3d(140.0, 37.5, 0.0);
    glVertex3d(140.0, 77.5, 0.0);
    glVertex3d(120.0, 75.0, 0.0);
    glEnd();

    // Upper right rectangle for tent
    glColor3f(0.788f, 0.78f, 0.204f);  // Set color to dark yellow

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(140.0, 37.5, 0.0);
    glVertex3d(160.0, 40.0, 0.0);
    glVertex3d(160.0, 80.0, 0.0);
    glVertex3d(140.0, 77.5, 0.0);
    glEnd();

    // Bottom right  left rectangle for tent
    glColor3f(0.788f, 0.78f, 0.204f);  // Set color to dark yellow

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(160.0, 0.0, 0.0);
    glVertex3d(180.0, 0.0, 0.0);
    glVertex3d(180.0, 32.5, 0.0);
    glVertex3d(160.0, 40.0, 0.0);
    glEnd();

    // Bottom right right rectangle for tent
    glColor3f(0.0f, 0.0f, 0.0f);  // Set color to Black

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(180.0, 0.0, 0.0);
    glVertex3d(190.0, 0.0, 0.0);
    glVertex3d(190.0, 30.0, 0.0);
    glVertex3d(180.0, 32.5, 0.0);
    glEnd();

    // Upper right left rectangle for tent
    glColor3f(0.0f, 0.0f, 0.0f);  // Set color to Black

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(160.0, 40.0, 0.0);
    glVertex3d(180.0, 32.5, 0.0);
    glVertex3d(180.0, 72.5, 0.0);
    glVertex3d(160.0, 80.0, 0.0);
    glEnd();

    // Upper right right rectangle for tent
    glColor3f(0.788f, 0.78f, 0.204f);  // Set color to dark yellow

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(180.0, 32.5, 0.0);
    glVertex3d(190.0, 30.0, 0.0);
    glVertex3d(190.0, 65.0, 0.0);
    glVertex3d(180.0, 72.5, 0.0);
    glEnd();

    // Lower deck rectangle for tent
    glColor3f(0.62f, 0.255f, 0.043f);  // Set color to light brown

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(120.0, 75.0, 0.0);
    glVertex3d(160.0, 80.0, 0.0);
    glVertex3d(165.0, 100.0, 0.0);
    glVertex3d(130.0, 95.0, 0.0);
    glEnd();

    // Upper right left up rectangle for tent
    glColor3f(0.788f, 0.78f, 0.204f);  // Set color to dark yellow

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(160.0, 80.0, 0.0);
    glVertex3d(180.0, 72.5, 0.0);
    glVertex3d(180.0, 85.0, 0.0);
    glVertex3d(165.0, 100.0, 0.0);
    glEnd();

    // Upper right right up rectangle for tent
    glColor3f(0.0f, 0.0f, 0.0f);  // Set color to Black

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(180.0, 72.5, 0.0);
    glVertex3d(190.0, 65.0, 0.0);
    glVertex3d(190.0, 75.0, 0.0);
    glVertex3d(180.0, 85.0, 0.0);
    glEnd();

    // Upper deck rectangle for tent
    glColor3f(0.329f, 0.129f, 0.016f);  // Set color to light brown

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(130.0, 95.0, 0.0);
    glVertex3d(165.0, 100.0, 0.0);
    glVertex3d(160.0, 120.0, 0.0);
    glVertex3d(125.0, 110.0, 0.0);
    glEnd();

    // Upper right left up up left rectangle for tent
    glColor3f(0.0f, 0.0f, 0.0f);  // Set color to Black

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(165.0, 100.0, 0.0);
    glVertex3d(180.0, 85.0, 0.0);
    glVertex3d(175.0, 115.0, 0.0);
    glVertex3d(160.0, 120.0, 0.0);
    glEnd();

    // Upper right right up up right rectangle for tent
    glColor3f(0.788f, 0.78f, 0.204f);  // Set color to dark yellow

    glBegin(GL_QUADS);  // Draw a square
    glVertex3d(180.0, 85.0, 0.0);
    glVertex3d(190.0, 75.0, 0.0);
    glVertex3d(190.0, 110.0, 0.0);
    glVertex3d(175.0, 115.0, 0.0);
    glEnd();

    // Tent front left
    glColor3f(0.788f, 0.78f, 0.204f);  // Set color to dark yellow

    glBegin(GL_TRIANGLES);  // Draw a square
    glVertex3d(125.0, 110.0, 0.0);
    glVertex3d(140.0, 114.0, 0.0);
    glVertex3d(150.0, 140.0, 0.0);
    glEnd();

    // Tent front right
    glColor3f(0.0f, 0.0f, 0.0f);  // Set color to Black

    glBegin(GL_TRIANGLES);  // Draw a square
    glVertex3d(140.0, 114.0, 0.0);
    glVertex3d(160.0, 120.0, 0.0);
    glVertex3d(150.0, 140.0, 0.0);
    glEnd();

    // Tent side left
    glColor3f(0.788f, 0.78f, 0.204f);  // Set color to dark yellow

    glBegin(GL_TRIANGLES);  // Draw a square
    glVertex3d(160.0, 120.0, 0.0);
    glVertex3d(175.0, 115.0, 0.0);
    glVertex3d(150.0, 140.0, 0.0);
    glEnd();

    // Tent side right
    glColor3f(0.0f, 0.0f, 0.0f);  // Set color to Black

    glBegin(GL_TRIANGLES);  // Draw a square
    glVertex3d(175.0, 115.0, 0.0);
    glVertex3d(190.0, 110.0, 0.0);
    glVertex3d(150.0, 140.0, 0.0);
    glEnd();

    // Golden snitch
    glColor3f(0.827f, 0.686f, 0.216f);

    DrawCircle(175.5,135,15,15,100);
    glPopMatrix();

    // Golden snitch wings right
    glColor3f(1.0f, 1.0f, 1.0f);  // Set color to white

    glBegin(GL_TRIANGLES);  // Draw a square
    glVertex3d(180.0, 140.0, 0.0);
    glVertex3d(200.0, 140.0, 0.0);
    glVertex3d(210.0, 160.0, 0.0);
    glEnd();
    // Golden snitch wings inside right
    glColor3f(1.0f, 1.0f, 1.0f);  // Set color to white

    glBegin(GL_TRIANGLES);  // Draw a square
    glVertex3d(190.0, 145.0, 0.0);
    glVertex3d(200.0, 140.0, 0.0);
    glVertex3d(195.0, 135.0, 0.0);
    glEnd();

    // Golden snitch wings left
    glColor3f(1.0f, 1.0f, 1.0f);  // Set color to white

    glBegin(GL_TRIANGLES);  // Draw a square
    glVertex3d(170.0, 140.0, 0.0);
    glVertex3d(150.0, 140.0, 0.0);
    glVertex3d(140.0, 160.0, 0.0);
    glEnd();
    // Golden snitch wings inside left
    glColor3f(1.0f, 1.0f, 1.0f);  // Set color to white

    glBegin(GL_TRIANGLES);  // Draw a square
    glVertex3d(150.0, 140.0, 0.0);
    glVertex3d(155.0, 135.0, 0.0);
    glVertex3d(160.0, 140.0, 0.0);
    glEnd();



    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("08,09_Final_Project");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
