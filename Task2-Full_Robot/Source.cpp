#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
static int body = 0, right_shoulder = 0, right_elbow = 0, left_shoulder = 0, left_elbow = 0, right_hip = 0, right_knee = 0, left_hip = 0, left_knee = 0;
static int right_foot = 0, left_foot = 0, head = 0;
static int right_hip2 = 0, left_hip2 = 0, right_elbow2 = 0, left_elbow2 = 0, left_hip3 = 0, right_hip3 = 0;
//static int left_elbow3 = 0, right_elbow3 = 0;
int moving, startx, starty;

double eye[] = { 0 , 0, -1 };//POSITION of camera 
double look[] = { 0, 0, 4 };//man location 
double up[] = { 0, 1, 0 };//camera's vertical
double perpendicularAxis[] = { 0, 0, 0 };
GLfloat Znear = 100.0;
int windowWidth;
int windowHeight;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */

void rotatePoint(double a[], double theta, double p[])//rotation matrix 
{

    double temp[3];
    temp[0] = p[0];
    temp[1] = p[1];
    temp[2] = p[2];

    temp[0] = -a[2] * p[1] + a[1] * p[2];
    temp[1] = a[2] * p[0] - a[0] * p[2];
    temp[2] = -a[1] * p[0] + a[0] * p[1];

    temp[0] *= sin(theta);
    temp[1] *= sin(theta);
    temp[2] *= sin(theta);

    temp[0] += (1 - cos(theta)) * (a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
    temp[1] += (1 - cos(theta)) * (a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
    temp[2] += (1 - cos(theta)) * (a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

    temp[0] += cos(theta) * p[0];
    temp[1] += cos(theta) * p[1];
    temp[2] += cos(theta) * p[2];

    p[0] = temp[0];
    p[1] = temp[1];
    p[2] = temp[2];

}
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}
void crossProduct(double a[], double b[], double c[])
{
    c[0] = a[1] * b[2] - a[2] * b[1];
    c[1] = a[2] * b[0] - a[0] * b[2];
    c[2] = a[0] * b[1] - a[1] * b[0];
}
void normalize(double a[])
{
    double norm;
    norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
    norm = sqrt(norm);
    a[0] /= norm;
    a[1] /= norm;
    a[2] /= norm;
}

void display(void)
{


    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();             /* DRAWING STACK */
    gluLookAt(eye[0], eye[1], eye[2], look[0], look[1], look[2], up[0], up[1], up[2]);
    //create and allocate camera
    glScalef(0.7, 0.7, 0.7);
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(0.0, 2.0, 1.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPushMatrix(); //I
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);

    // the body
    glTranslatef(-0.6, 0.0, 0.0);
    glRotatef((GLfloat)body, 0.0, 0.0, 1.0);
    glTranslatef(0.6, 0.0, 0.0);

    glPushMatrix(); //push body -> stack = I matrix * body

    glScalef(1.2, 3.2, 0.4);
    glutWireCube(1);

    glPopMatrix(); //pop body
    glPushMatrix(); //push body for later
    glPushMatrix(); //pushing body for later


    //The right shoulder
    glTranslatef(0.6, 1.6, 0.0);
    glRotatef((GLfloat)right_shoulder, 0.0, 0.0, 1.0);
    glTranslatef(0.1, -0.5, 0.0);
    glPushMatrix(); //push rs
    glScalef(0.2, 1.0, 0.4);                             //scale
    glutWireCube(1.0);
    glPopMatrix(); //pop rs

    //right elbow
    glTranslatef(-0.1, -0.5, 0.0);
    glRotatef((GLfloat)right_elbow, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)right_elbow2, 0.0, 0.0, 1.0);

    glTranslatef(0.1, -0.5, 0.0);//

    glPushMatrix(); //push re

    glScalef(0.2, 1.0, 0.4);                      //scale
    glutWireCube(1.0);
    glPopMatrix(); //popping re
    glPopMatrix(); //popping body


    // The left shoulder
    glTranslatef(-0.8, 1.6, 0.0);
    glRotatef((GLfloat)left_shoulder, 0.0, 0.0, 1.0);
    glTranslatef(0.1, -0.5, 0.0);
    glPushMatrix(); //pushing ls
    glScalef(0.2, 1.0, 0.4);                             //scale
    glutWireCube(1.0);
    glPopMatrix(); //popping ls

    //the left elbow
    glTranslatef(-0.1, -0.5, 0.0);
    glRotatef((GLfloat)left_elbow, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)left_elbow2, 0.0, 0.0, 1.0);

    glTranslatef(0.1, -0.5, 0.0);
    glPushMatrix(); //push le
    glScalef(0.2, 1.0, 0.4);                      //scale
    glutWireCube(1.0);
    glPopMatrix(); //popping le
    glPopMatrix(); //popping body
    glPushMatrix(); //pushing body for later

    // The left hip  
    glTranslatef(0.2, -1.6, 0.0);
    glRotatef((GLfloat)left_hip, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)left_hip2, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)left_hip3, 1.0, 0.0, 0.0);


    glTranslatef(0.2, -0.8, 0.0);
    glPushMatrix(); //push lh
    glScalef(0.4, 1.6, 0.4);                      //scale
    glutWireCube(1.0);
    glPopMatrix(); //pop lh

    //the left knee
    glTranslatef(0.0, -0.8, 0.0);
    glRotatef((GLfloat)left_knee, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -0.8, 0.0);
    glPushMatrix(); //push lk
    glScalef(0.4, 1.6, 0.4);                      //scale
    glutWireCube(1.0);
    glPopMatrix(); //pop lk

     // The left foot
    glTranslatef(-0.2, -0.55, 0.0);
    glRotatef((GLfloat)left_foot, 0.0, 0.0, 1.0);
    glTranslatef(0.2, -0.15, 0.0);
    glPushMatrix(); //push lf
    glScalef(0.4, 0.3, 0.6);                      //scale
    glutSolidCube(1.0);
    glPopMatrix(); //pop lf
    glPopMatrix(); //popping body
    glPushMatrix(); //pushing body for later


    // The right hip
    glTranslatef(-0.2, -1.6, 0.0);
    glRotatef((GLfloat)right_hip, 0.0, 0.0, 1.0);
    glRotatef((GLfloat)right_hip2, 1.0, 0.0, 0.0);
    glRotatef((GLfloat)right_hip3, 1.0, 0.0, 0.0);


    glTranslatef(-0.2, -0.8, 0.0);
    glPushMatrix(); //push rh
    glScalef(0.4, 1.6, 0.4);                      //scale
    glutWireCube(1.0);
    glPopMatrix(); //pop rh

    //the right knee
    glTranslatef(0.0, -0.8, 0.0);
    glRotatef((GLfloat)right_knee, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -0.8, 0.0);
    glPushMatrix(); //push rk
    glScalef(0.4, 1.6, 0.4);                      //scale
    glutWireCube(1.0);
    glPopMatrix();//pop rk



    // The right foot
    glTranslatef(-0.2, -0.55, 0.0);
    glRotatef((GLfloat)right_foot, 0.0, 0.0, 1.0);
    glTranslatef(0.2, -0.15, 0.0);
    glPushMatrix(); //push rf
    glScalef(0.4, 0.3, 0.6);                     //scale
    glutSolidCube(1.0);
    glPopMatrix(); //pop rf

    glPopMatrix(); //popping body
    //glPushMatrix(); //pushing body for later


    //shpere
    glTranslatef(-0.2, 2.2, 0.0);
    glRotatef((GLfloat)head, 0.0, 0.0, 1.0);
    glTranslatef(0.2, 0.0, 0.0);
    glPushMatrix(); //pushing sphere
    glutWireSphere(0.4, 10, 10);
    glPopMatrix(); //popping sphere

    glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{

    windowWidth = w;
    windowHeight = h;
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(Znear, (GLfloat)w / (GLfloat)h, 0.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        crossProduct(up, look, perpendicularAxis);
        normalize(perpendicularAxis);
        rotatePoint(perpendicularAxis, 0.05, look);
        rotatePoint(perpendicularAxis, 0.05, up);
        glutPostRedisplay();
        break;
    case 'W':
        crossProduct(up, look, perpendicularAxis);
        normalize(perpendicularAxis);
        rotatePoint(perpendicularAxis, -0.05, look);
        rotatePoint(perpendicularAxis, -0.05, up);
        glutPostRedisplay();
        break;
    case 'x':
        //I gave the rotatepoint function 3 parameters 
        //1) up -> which is the vertical that the camera will rotate about it
        //2) -0.05 -> angle of rotation (-ve angle to rotate in the left direction)
        //3) look -> which is the center point (man)
        rotatePoint(up, -0.05, look);
        glutPostRedisplay();
        break;
    case 'X':
        //the same as case'x' but with +ve angle to rotate in right direction
        rotatePoint(up, 0.05, look);
        glutPostRedisplay();
        break;
    case 'z':
        if (Znear > 100) { Znear = 100; }
        else if (Znear <= 30) { Znear = 30; }
        else
            Znear -= 1.0;

        reshape(windowWidth, windowHeight);
        glutPostRedisplay();
        break;
    case 'Z':
        if (Znear >= 100) { Znear = 100; }
        else if (Znear < 30) { Znear = 30; }
        else
            Znear += 1.0;
        reshape(windowWidth, windowHeight);
        glutPostRedisplay();
        break;
    case 's':
        if (right_shoulder < 180) {

            right_shoulder = (right_shoulder + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'S':
        if (right_shoulder > 0) {

            right_shoulder = (right_shoulder - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'h':
        if (left_shoulder > -180) {

            left_shoulder = (left_shoulder - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'H':
        if (left_shoulder < 0) {

            left_shoulder = (left_shoulder + 5) % 360;
        }
        glutPostRedisplay();
        break;

        break;
    case 'e':
        if (right_elbow < 180) {
            right_elbow = (right_elbow + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'E':
        if (right_elbow > 0) {
            right_elbow = (right_elbow - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'l':
        if (left_elbow > -180) {
            left_elbow = (left_elbow - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'L':
        if (left_elbow < 0) {
            left_elbow = (left_elbow + 5) % 360;
        }
        glutPostRedisplay();
        break;

    case 'f':
        if (left_elbow2 < 90) {
            left_elbow2 = (left_elbow2 + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'F':
        if (left_elbow2 > 0) {
            left_elbow2 = (left_elbow2 - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'g':
        if (right_elbow2 > -90) {
            right_elbow2 = (right_elbow2 - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'G':
        if (right_elbow2 < 0) {
            right_elbow2 = (right_elbow2 + 5) % 360;
        }
        glutPostRedisplay();
        break;

    case 'i':
        if (right_hip > -90)
        {
            right_hip = (right_hip - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'I':
        if (right_hip < 0)

            right_hip = (right_hip + 5) % 360;
        glutPostRedisplay();
        break;

    case 'a':
        if (right_hip2 < 180)
        {
            right_hip2 = (right_hip2 + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'A':
        if (right_hip2 > 0)

        {
            right_hip2 = (right_hip2 - 5) % 360;
        }
        glutPostRedisplay();
        break;

    case 'c':
        if (right_hip3 > -90)
        {
            right_hip3 = (right_hip3 - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'C':
        if (right_hip3 < 0)

        {
            right_hip3 = (right_hip3 + 5) % 360;
        }
        glutPostRedisplay();
        break;

    case 'p':
        if (left_hip < 90) {
            left_hip = (left_hip + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'P':
        if (left_hip > 0) {

            left_hip = (left_hip - 5) % 360;
        }
        glutPostRedisplay();
        break;

    case 'b':
        if (left_hip2 < 180)
        {
            left_hip2 = (left_hip2 + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'B':
        if (left_hip2 > 0)

        {
            left_hip2 = (left_hip2 - 5) % 360;
        }
        glutPostRedisplay();
        break;

    case 'd':
        if (left_hip3 > -90)
        {
            left_hip3 = (left_hip3 - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'D':
        if (left_hip3 < 0)

        {
            left_hip3 = (left_hip3 + 5) % 360;
        }
        glutPostRedisplay();
        break;

    case 'k':
        if (right_knee > -180) {
            right_knee = (right_knee - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'K':
        if (right_knee < 0) {
            right_knee = (right_knee + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'n':
        if (left_knee > -180) {
            left_knee = (left_knee - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'N':
        if (left_knee < 0) {
            left_knee = (left_knee + 5) % 360;
        }
        glutPostRedisplay();
        break;

    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

static void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving = 0;
        }
    }
}


static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}