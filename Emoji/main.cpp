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

	// To create the "upside-down face" 🙃, we draw a regular
	// smiley face and then rotate the entire view by 180 degrees.
	glRotatef(180.0f, 0.0f, 0.0f, 1.0f); // Rotate around the Z-axis

	// 1. Draw the face (a big yellow circle)
	glColor3f(1.0f, 0.84f, 0.0f); // Emoji yellow
	DrawCircle(0, 0, 200, 200, 100);

	// 2. Draw the eyes (two smaller black circles)
	glColor3f(0.0f, 0.0f, 0.0f); // Black color for features
	DrawCircle(-70, 50, 25, 25, 50);  // Left eye
	DrawCircle(70, 50, 25, 25, 50);   // Right eye

	// 3. Draw the mouth (a simple arc for the smile)
	glLineWidth(8.0f); // Make the smile line thicker
	glBegin(GL_LINE_STRIP);
	// We'll draw an arc for the smile below the center of the face.
	// This loop calculates points on a semicircle.
	for (int i = 0; i <= 20; i++)
	{
		// Angle goes from ~210 degrees to ~330 degrees to form a "U" shape
		float angle = 3.14159f * 1.2f + (3.14159f * 0.6f * i) / 20.0f;
		float x = 100 * cosf(angle);
		float y = 100 * sinf(angle);
		glVertex2f(x, y - 40); // Position the smile's center below the face's center
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
	glutCreateWindow ("Kingshuk_Upside-Down Face Emoji");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
