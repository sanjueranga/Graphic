#include <GL/glut.h>
#include <math.h>

const double PI = 3.141592654;

int frameNumber = 0;
bool isFront = true; 
bool isCarried = false;
double itemPositionX = 5.8;  
double itemPositionY = 0.5;  

// Function to draw a disk for wheels and other circular elements
void drawDisk(double radius) {
    glBegin(GL_POLYGON);
    for (int d = 0; d < 32; d++) {
        double angle = 2 * PI / 32 * d;
        glVertex2d(radius * cos(angle), radius * sin(angle));
    }
    glEnd();
}

// Function to draw a square-shaped box
void drawBox(double size) {
    glBegin(GL_POLYGON);
    glVertex2f(-size / 2, -size / 2);
    glVertex2f(size / 2, -size / 2);
    glVertex2f(size / 2, size / 2);
    glVertex2f(-size / 2, size / 2);
    glEnd();
}

// Function to draw the item (box)
void drawItem(double size) {
    glColor3f(0.0f, 1.0f, 0.0f); 
    drawBox(size);  // Reduced the size to match the carried box
}

// Function to draw a wheel
void drawWheel() {
    glColor3f(0, 0, 0);
    drawDisk(1);
    glColor3f(0.75f, 0.75f, 0.75f);
    drawDisk(0.8);
    glColor3f(0, 0, 0);
    drawDisk(0.2);
    glRotatef(frameNumber * 20, 0, 0, 1);
    glBegin(GL_LINES);
    for (int i = 0; i < 15; i++) {
        glVertex2f(0, 0);
        glVertex2d(cos(i * 2 * PI / 15), sin(i * 2 * PI / 15));
    }
    glEnd();
}

// Function to draw a cart with two wheels and a red body
void drawCart() {
    glPushMatrix();
    glTranslatef(-1.5f, -0.1f, 0);
    glScalef(0.8f, 0.8f, 1);
    drawWheel();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.5f, -0.1f, 0);
    glScalef(0.8f, 0.8f, 1);
    drawWheel();
    glPopMatrix();

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(-2.5f, 0);
    glVertex2f(2.5f, 0);
    glVertex2f(2.5f, 2);
    glVertex2f(-2.5f, 2);
    glEnd();
}

// Function to draw the sun
void drawSun() {
    glColor3f(1, 1, 0);
    for (int i = 0; i < 13; i++) {
        glRotatef(360.0 / 13.0, 0, 0, 1);
        glBegin(GL_LINES);
        glVertex2f(0, 0);
        glVertex2f(0.75f, 0);
        glEnd();
    }
    drawDisk(0.5);
    glColor3f(0, 0, 0);
}

// Function to draw the robotic arm
void drawArm() {
    glColor3f(0.8f, 0.8f, 0.9f);
    drawDisk(0.2);

    glRotated(-frameNumber * (120.0 / 46.0), 0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.07f, 0);
    glVertex2f(0.07f, 0);
    glVertex2f(0.07f, 3);
    glVertex2f(-0.07f, 3);
    glEnd();
    glTranslatef(0, 3, 0);

    glColor3f(0.75f, 0.75f, 0.75f);
    drawDisk(0.2);

    glRotated(-frameNumber * (120.0 / 46.0), 0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-0.07f, 0);
    glVertex2f(0.07f, 0);
    glVertex2f(0.07f, 2);
    glVertex2f(-0.07f, 2);
    glEnd();

    // Draw item at the end of the second arm segment
    if (isCarried) {
        glTranslatef(0, 2, 0); // Move to the end of the second arm segment
        drawItem(0.5);
    }
}

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glPushMatrix();
    glTranslated(3.3, 0.4, 0);
    glScaled(0.6, 0.6, 1);
    drawArm();
    glPopMatrix();

    // Draw the ground
    glColor3f(0.4f, 0.4f, 0.5f);
    glBegin(GL_POLYGON);
    glVertex2f(0, -0.5f);
    glVertex2f(7, -0.5f);
    glVertex2f(7, 0.4f);
    glVertex2f(0, 0.4f);
    glEnd();

    // Draw the item if not being carried by the arm
    if (!isCarried) {
        glPushMatrix();
        glTranslated(itemPositionX, itemPositionY, 0);
        drawItem(0.3);
        glPopMatrix();
    }

    glutSwapBuffers();
}

// Function to handle frame-based animation
void doFrame(int v) {
    if (isFront) {
        frameNumber++;
        if (frameNumber * 0.5 >= 12) {
            isFront = false;
            isCarried = true;
        }
    } else {
        frameNumber--;
        if (frameNumber * 0.5 <= -12) {
            isFront = true;
            isCarried = false;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(30, doFrame, 0);
}

// Initialization function for OpenGL
void init() {
    glClearColor(0.5f, 0.5f, 1, 1);
}

// Reshape function to maintain aspect ratio
void reshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    GLfloat aspect = (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w >= h)
        gluOrtho2D(0 * aspect, 4.5 * aspect, -0.5, 4);
    else
        gluOrtho2D(0, 4.5, -0.5 / aspect, 4 / aspect);

    glMatrixMode(GL_MODELVIEW);
}

// Main function to set up the GLUT window and start the main loop
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(720, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Robot Arm with Item Pickup");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(200, doFrame, 0);
    glutMainLoop();
    return 0;
}
