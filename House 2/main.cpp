#include <GL/glut.h>
#include <stdlib.h>

// Initialization.
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // Background color
    glOrtho(0, 20, 0, 20, -5, 5);  // Set up an orthogonal view
}

// Display function.
void myDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the screen

    // Draw the house as a square (yellow)
    glColor3f(1.0f, 1.0f, 0.0f);  // Set color to yellow
    glBegin(GL_QUADS);  // Draw a square
        glVertex3d(8.0, 8.0, 0.0);   // Bottom-left
        glVertex3d(16.0, 8.0, 0.0);  // Bottom-right
        glVertex3d(16.0, 16.0, 0.0); // Top-right
        glVertex3d(8.0, 16.0, 0.0);  // Top-left
    glEnd();

    // Draw the door (centered at bottom).
    glColor3f(0.5f, 0.25f, 0.0f);  // Brown color for the door
    glBegin(GL_QUADS);
        glVertex3d(10.0, 8.0, 0.0);   // Bottom-left of the door
        glVertex3d(14.0, 8.0, 0.0);  // Bottom-right of the door
        glVertex3d(14.0, 12.0, 0.0); // Top-right of the door
        glVertex3d(10.0, 12.0, 0.0);  // Top-left of the door
    glEnd();

    // Draw square box (Left side of the main box)
    glColor3f(0.8f, 0.7f, 0.2f);  // Orange Yellow color for the wall
    glBegin(GL_QUADS);
        glVertex3d(7.0, 9.0, 0.0);   // Bottom-left of the wall
        glVertex3d(8.0, 8.0, 0.0);  // Bottom-right of the wall
        glVertex3d(8.0, 16.0, 0.0); // Top-right of the wall
        glVertex3d(7.0, 17.0, 0.0);  // Top-left of the wall
    glEnd();

    // Draw the first window (top-left of the house)
    glColor3f(0.2f, 0.6f, 0.9f);  // Light Blue color for the window
    glBegin(GL_QUADS);
        glVertex3d(10.0, 13.0, 0.0);  // Bottom-left of the window
        glVertex3d(11.0, 13.0, 0.0);  // Bottom-right of the window
        glVertex3d(11.0, 15.0, 0.0);  // Top-right of the window
        glVertex3d(10.0, 15.0, 0.0);  // Top-left of the window
    glEnd();

    // Draw the second window (top-right of the house)
    glBegin(GL_QUADS);
        glVertex3d(13.0, 13.0, 0.0);  // Bottom-left of the window
        glVertex3d(14.0, 13.0, 0.0);  // Bottom-right of the window
        glVertex3d(14.0, 15.0, 0.0);  // Top-right of the window
        glVertex3d(13.0, 15.0, 0.0);  // Top-left of the window
    glEnd();

    // Draw the roof (triangle)
    glColor3f(0.4f, 0.6f, 0.6f);  // Red color for the roof
    glBegin(GL_TRIANGLES);
        glVertex2d(8.0, 16.0);  // Left bottom of the triangle
        glVertex2d(16.0, 16.0); // Right bottom of the triangle
        glVertex2d(11.5, 18.0); // Top point of the triangle
    glEnd();

     // Draw the roof (triangle right side)
    glColor3f(0.3f, 0.4f, 0.4f);  // reddish-purple/pink color for the roof
    glBegin(GL_TRIANGLES);
        glVertex3d(7.0, 17.0, 0.0);  // Left bottom of the triangle
        glVertex3d(8.0, 16.0, 0.0); // Right bottom of the triangle
        glVertex3d(11.5, 18.0, 0.0); // Top point of the triangle
    glEnd();

    glFlush();  // Force execution of OpenGL commands
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);  // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // Set display mode
    glutInitWindowSize(600, 600);  // Set window size
    glutInitWindowPosition(400, 200);  // Set window position
    glutCreateWindow("Supti_08_CSE-18");  // Create the window

    init();  // Initialize OpenGL settings
    glutDisplayFunc(myDisplay);  // Register display function

    glutMainLoop();  // Enter the GLUT event loop
    return 0;
}
