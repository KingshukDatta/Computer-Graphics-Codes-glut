#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

// Initial positions and speeds
static float car1_tx = -80.0;   // Car 1 (slower)
static float car2_tx = -80.0;   // Car 2 (faster)
float car1_speed = 5.0;
float car2_speed = 8.0;

// Function to draw circle (for wheels)
void drawCircle(float cx, float cy, float r)
{
    int num_segments = 100;
    float angle;
    glBegin(GL_POLYGON);
    for (int i = 0; i < num_segments; i++)
    {
        angle = 2.0f * 3.1416f * i / num_segments;
        glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
    }
    glEnd();
}

// Draw background (sky + grass + road)
void drawBackground()
{
    // Sky
    glColor3f(0.5, 0.8, 1.0);
    glBegin(GL_POLYGON);
        glVertex2f(-100.0, 100.0);
        glVertex2f(100.0, 100.0);
        glVertex2f(100.0, 0.0);
        glVertex2f(-100.0, 0.0);
    glEnd();

    // Grass
    glColor3f(0.0, 0.7, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-100.0, 15.0);
        glVertex2f(100.0, 15.0);
        glVertex2f(100.0, -50.0);
        glVertex2f(-100.0, -50.0);
    glEnd();

    // Road
    glColor3f(0.2, 0.2, 0.2);
    glBegin(GL_POLYGON);
        glVertex2f(-100.0, -0.0);
        glVertex2f(100.0, -0.0);
        glVertex2f(100.0, -55.0);
        glVertex2f(-100.0, -55.0);
    glEnd();

    // Road divider lines
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(3);
    glBegin(GL_LINES);
    for (float i = -100.0; i < 100.0; i += 25.0)
    {
        glVertex2f(i, -32.5);
        glVertex2f(i + 10.0, -32.5);
    }
    glEnd();
}

// Draw a car (body + wheels)
void drawCar(float x, float y, float r, float g, float b)
{
    // Car body
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(x - 10, y - 10);
        glVertex2f(x - 10, y + 10);
        glVertex2f(x + 30, y + 10);
        glVertex2f(x + 30, y - 10);
    glEnd();

    // Car top
    glBegin(GL_POLYGON);
        glVertex2f(x, y + 10);
        glVertex2f(x + 20, y + 10);
        glVertex2f(x + 15, y + 20);
        glVertex2f(x + 5, y + 20);
    glEnd();

    // Wheels
    glColor3f(0.0, 0.0, 0.0);
    drawCircle(x, y - 10, 3.0);
    drawCircle(x + 20, y - 10, 3.0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Background and road
    drawBackground();

    // Car 1 (Red)
    drawCar(car1_tx, -10.0, 1.0, 0.0, 0.0);

    // Car 2 (Blue)
    drawCar(car2_tx, -35.0, 0.0, 0.0, 1.0);

    glFlush();
}

// Initialization
void init(void)
{
    glClearColor(0.6, 0.9, 1.0, 0.0);
    glOrtho(-100.0, 100.0, -50.0, 100.0, -1.0, 1.0);
}

// Car 1 control (R/L)
void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 'l':
        case 'L':
            car1_tx -= car1_speed;
            break;

        case 'r':
        case 'R':
            car1_tx += car1_speed;
            break;

        case 27:
            exit(0);
            break;

        default:
            break;
    }
    glutPostRedisplay();
}

// Car 2 control (Arrow keys)
void spe_key(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
            car2_tx -= car2_speed;
            break;

        case GLUT_KEY_RIGHT:
            car2_tx += car2_speed;
            break;

        default:
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(90, 60);
    glutCreateWindow("Two Cars user input");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(spe_key);
    glutMainLoop();

    return 0;
}
