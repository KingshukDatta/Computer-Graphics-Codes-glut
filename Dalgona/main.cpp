#include <GL/glut.h>
#include <cmath>

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

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw yellow face
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    drawCircle(0.0f, 0.0f, 0.8f, 100);

    // Draw eyes
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    drawCircle(-0.3f, 0.2f, 0.1f, 50); // Left eye
    drawCircle(0.3f, 0.2f, 0.1f, 50);  // Right eye

    // Draw happy mouth (smile)
    glColor3f(0.0f, 0.0f, 0.0f); // Black
    glLineWidth(7.0f);
    glBegin(GL_LINE_STRIP);
    for (float angle = 215; angle <= 325; angle += 18) {
        float rad = angle * 3.14159f / 180.0f;
        float x = 0.4f * cosf(rad);
        float y = 0.3f * sinf(rad) - 0.2f;
        glVertex2f(x, y);
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // white background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("Atika's Senti Emoji");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
