/*Using the concept of a Current Transformation Matrix (push/pop matrices), write the
OpenGL or using whichever language code to define the object as illustrated below. You may
assume that the object is composed of two squares and a circle of unit dimensions in
2D space.*/

#include<GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h> // for the circle calculations
void shape() {
    glColor3f(0.2f, 0.2f, 0.2f); // dark gray background colour
    glClear(GL_COLOR_BUFFER_BIT);
    int number = 40;  //number of vertices
    float radius = 0.2f;
    float twopi = 2.0 * 3.1452423;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_TRIANGLE_FAN); //using a triangle to draw a circle
      glColor3f(1.0f, 1.0f, 1.0f); //white
      glVertex2f(0.0f, 0.0f);
      for (int i = 0; i <= 40; i++)
          glVertex2f(radius * cosf(i * twopi / number), radius * sinf(i * twopi / number));
    glEnd();

    glBegin(GL_QUADS);
    //first square
      glColor3f(1.0f, 1.0f, 1.0f); // White
      glVertex2f(-0.6f, 0.2f);
      glVertex2f(-0.2f, 0.2f);
      glVertex2f(-0.2f, -0.2f);
      glVertex2f(-0.6f, -0.2f);


      //second square
      glColor3f(1.0f, 1.0f, 1.0f); // White
      glVertex2f(0.6f, 0.2f);
      glVertex2f(0.2f, 0.2f);
      glVertex2f(0.2f, -0.2f);
      glVertex2f(0.6f, -0.2f);
    glEnd();



    glFlush();      // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc,char **argv)
{
    glutInit(&argc,argv);  // Initialize GLUT
    glutInitWindowSize(640,480);  // Set the window's initial width & height
    glutInitWindowPosition(50,50); // Position the window's initial top-left corner
    glutCreateWindow("The shape");
    glutDisplayFunc(shape); // Register callback handler for window re-paint event
    glutMainLoop(); // Enter the event-processing loop
    
    return 0;




}