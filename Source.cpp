#include <stdlib.h>
#include <GL/glut.h>
static int shoulder = 0, elbow = 0, fingerBase = 0, point = 0, middle = 0, ring = 0, fingerUp_base = 0, fingerUp_point = 0, fingerUp_ring = 0, fingerUp_middle = 0;
int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glPushMatrix();
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.6, 0.8);
    glutWireCube(1.0);
    glPopMatrix();
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();

    glPushMatrix(); 

    glScalef(2.0, 0.6, 0.8);
    glutWireCube(1.0);
    glPopMatrix();

    //finger base
    //Draw fingerbase flange 1 
    glTranslatef(1.0, -0.22, 0.0);
    glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.15, 0.15);
    glutWireCube(1);
    glPopMatrix();


    //Draw fingerbase flange 2
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp_base, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.15, 0.15);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix(); 
    glPushMatrix();  



    //pointer finger
    //Draw pointer finger flange 1 
   // glTranslatef(-0.45, 0.589, 0.32);
    glTranslatef(1.0, 0.225, 0.325);


    glRotatef((GLfloat)point, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.15, 0.15);
    glutWireCube(1);
    glPopMatrix();


    //Draw pointer finger flange 2 
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp_point, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.15, 0.15);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix(); 
    glPushMatrix();  

    //middle finger
    //Draw middle finger flange 1
    glTranslatef(1.0, 0.375, 0.0);
    glRotatef((GLfloat)middle, 0.0, 0.0, 1.0);
    glTranslatef(0.15, -0.15, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.15, 0.15);
    glutWireCube(1);
    glPopMatrix();


    //Draw middle finger flange 2
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp_middle, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.15, 0.15);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix(); 
    glPushMatrix(); 

    //ring finger
    //Draw ring finger flange 1
    glTranslatef(1.0, 0.375, -0.325);
    glRotatef((GLfloat)ring, 0.0, 0.0, 1.0);
    glTranslatef(0.15, -0.15, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.15, 0.15);
    glutWireCube(1);
    glPopMatrix();


    //Draw ring finger flang 2
    glTranslatef(0.15, 0.0, 0.0);
    glRotatef((GLfloat)fingerUp_ring, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.15, 0.15);
    glutWireCube(1);
    glPopMatrix();

    glPopMatrix(); 


    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 's':
        shoulder = (shoulder + 5) % 360;
        glutPostRedisplay();
        break;
    case 'S':
        shoulder = (shoulder - 5) % 360;
        glutPostRedisplay();
        break;
    case 'e':
        if (elbow < 180) {
            elbow = (elbow + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'E':
        if (elbow > 0) {
            elbow = (elbow - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'f':
        if (fingerBase < 90) {
            fingerBase = (fingerBase + 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'F':
        if (fingerBase > 0) {
            fingerBase = (fingerBase - 5) % 360;
        }
        glutPostRedisplay();
        break;


    case 'p':
        if (point >-90) {
            point = (point - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'P':
        if (point < 0) {
            point = (point + 5) % 360;
        }
        glutPostRedisplay();
        break;

    case 'm':
        if (middle >-90) {
            middle = (middle - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'M':
        if (middle <0) {
            middle = (middle + 5) % 360;
        }
        glutPostRedisplay();
        break;

    case 'r':
        if (ring >-90) {
            ring = (ring - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'R':
        if (ring < 0) {
            ring = (ring + 5) % 360;
        }
        glutPostRedisplay();
        break;

    case 'a':
        if (fingerUp_base < 90) {
            fingerUp_base = (fingerUp_base +5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'A':
        if (fingerUp_base > 0)
        {
            fingerUp_base = (fingerUp_base -5) % 360;
        }
        glutPostRedisplay();
        break;


    case 'b':
        if (fingerUp_point >-90) {
            fingerUp_point = (fingerUp_point - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'B':
        if (fingerUp_point < 0) {
            fingerUp_point = (fingerUp_point + 5) % 360;
        }
        glutPostRedisplay();
        break;

    case 'c':
        if (fingerUp_middle >-90) {

            fingerUp_middle = (fingerUp_middle - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'C':
        if (fingerUp_middle < 0) {
            fingerUp_middle = (fingerUp_middle + 5) % 360;
        }
        glutPostRedisplay();
        break;

    case 'd':
        if (fingerUp_ring >-90) {
            fingerUp_ring = (fingerUp_ring - 5) % 360;
        }
        glutPostRedisplay();
        break;
    case 'D':
        if (fingerUp_ring <0) {

            fingerUp_ring = (fingerUp_ring + 5) % 360;
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