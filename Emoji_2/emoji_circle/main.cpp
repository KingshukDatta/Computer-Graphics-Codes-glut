#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

// A function to draw a filled circle/ellipse.
// We will use this for the face and the eyes.
void DrawCircle(float cx, float cy, float rx, float ry, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for(int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments); //get the current angle
		float x = rx * cosf(theta); //calculate the x component
		float y = ry * sinf(theta); //calculate the y component
		glVertex2f(x + cx, y + cy); //output vertex
	}
	glEnd();
}

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0); // Set background color to black
	// Set projection to have a 1:1 aspect ratio to avoid distortion
	glOrtho(-300.0, 300.0, -300.0, 300.0, -1.0, 1.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();

	// NOTE: The 180-degree rotation has been removed to make the face upright.

	// 1. Draw the face (a big yellow circle)
	glColor3f(1.0f, 0.84f, 0.0f); // Emoji yellow
	DrawCircle(0, 0, 200, 200, 100);

	// 2. Draw the eyes (two smaller black circles)
	glColor3f(0.0f, 0.0f, 0.0f); // Black color for features
	DrawCircle(-70, 50, 25, 25, 50);  // Left eye
	DrawCircle(70, 50, 25, 25, 50);   // Right eye

	// 3. Draw the mouth (an arc for the frown)
	glLineWidth(8.0f); // Make the frown line thicker
	glBegin(GL_LINE_STRIP);
	// We'll draw an arc for the frown below the center of the face.
	// This loop calculates points on the TOP half of a semicircle.
	for (int i = 0; i <= 20; i++)
	{
		// Angle goes from ~36 degrees to ~144 degrees to form a "∩" shape
		float angle = 3.14159f * 0.2f + (3.14159f * 0.6f * i) / 20.0f;
		float x = 80 * cosf(angle);
		float y = 80 * sinf(angle);
		glVertex2f(x, y - 60); // Position the frown in the lower part of the face
	}
	glEnd();

	glPopMatrix();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Supti_Frowning Face Emoji");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
