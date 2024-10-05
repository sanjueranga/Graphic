// #include <GL/glut.h>
// #include <GL/gl.h>
// #include <math.h>

// float PI = 3.14;

// void init() {
//     glClearColor(0.8, 0.9, 1.0, 1.0);  // Light blue background
//     glClear(GL_COLOR_BUFFER_BIT);
// }

// void drawDisk(double radius, int n) {
//     double angle = 0;

//     glBegin(GL_POLYGON);
//     for (int c = 0; c <= n; c++) {
//         double x = radius * cos(angle);
//         double y = radius * sin(angle);
//         glVertex2d(x, y);
//         angle = angle + ((2 * PI) / n);
//     }
//     glEnd();
// }

// void drawWheel() {
//     glColor3f(0.4, 0.4, 0.4);  // Dark gray for tire
//     drawDisk(1.0, 32);
//     glColor3f(0.7, 0.7, 0.7);  // Light gray for rim
//     drawDisk(1.8, 32);
//     glColor3f(0.4, 0.4, 0.4);  // Dark gray for hub
//     drawDisk(0.5, 32);

    
//     glEnd();
// }

// void drawRectangle() {
//     glColor3f(1.0, 0.5, 0.0);  // Orange color for cart body
//     glBegin(GL_POLYGON);
//     glVertex2f(-3.0, -1.0);
//     glVertex2f(8.0, -1.0);
//     glVertex2f(10.0, 6.0);
//     glVertex2f(-5.0, 6.0);
//     glEnd();

   
//     glVertex2f(5.0, 2.0);
//     glVertex2f(7.0, 4.0);
//     glVertex2f(9.0, 2.0);
//     glEnd();
// }

// void drawCart() {
//     // Draw wheels
//     glPushMatrix();
//     glTranslatef(-1.0, -2.5, 0.0);  // Adjust wheel position
//     drawWheel();
//     glPopMatrix();

//     glPushMatrix();
//     glTranslatef(6.0, -2.5, 0.0);  // Adjust wheel position
//     drawWheel();
//     glPopMatrix();

//     // Draw rectangle above the wheels
//     drawRectangle();

// }

// void reshape(GLsizei w, GLsizei h) {
//     glViewport(0, 0, w, h);
//     if (h == 0) h = 1;
//     GLfloat aspect = (GLfloat)w / (GLfloat)h;

//     glMatrixMode(GL_PROJECTION);
//     glLoadIdentity();
//     if (w >= h)
//         gluOrtho2D(-10 * aspect, 10 * aspect, -10, 10);
//     else
//         gluOrtho2D(-10, 10, -10 / aspect, 10 / aspect);
// }

// void display() {
//     glClear(GL_COLOR_BUFFER_BIT);
//     glLineWidth(2.0);

//     glMatrixMode(GL_MODELVIEW);
//     glLoadIdentity();

//     drawCart();

//     glFlush();
// }

// int main(int argc, char** argv) {
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE);

//     glutInitWindowPosition(100, 100);
//     glutInitWindowSize(720, 480);
//     glutCreateWindow("Cart");

//     init();

//     glutDisplayFunc(display);
//     glutReshapeFunc(reshape);
//     glutMainLoop();
//     return 0;
// }