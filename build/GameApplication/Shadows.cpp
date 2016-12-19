#include "Shadows.h"

float flag = 0.0;
double rx = 0.0;
double ry = 0.0;
static GLint fogMode;
GLfloat position[] = { 0.5, 0.5, 3.0, 0.0 }; 
float l[] = { 0.0, 80.0, 0.0 }; //Coordinates of the light source
float n[] = { 0.0, -1.0, 0.0 }; //Normal vector for the plane
float p[] = { 0.0, -60.0, 0.0 }; //Point of the plane

void init(void)
{

	glEnable(GL_DEPTH_TEST);

	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	{
		GLfloat mat[3] = { 0.1745,0.01175,0.01175 };
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat);
		mat[0] = 0.61424; mat[1] = 0.04136; mat[2] = 0.04136;
		glMaterialfv(GL_FRONT, GL_DIFFUSE, mat);
		mat[0] = 0.727811; mat[1] = 0.626959; mat[2] = 0.626959;
		glMaterialfv(GL_FRONT, GL_SPECULAR, mat);
		glMaterialf(GL_FRONT, GL_SHININESS, 0.6*128.0);
	}

	glEnable(GL_FOG);
	{
		GLfloat fogColor[4] = { 0.5,0.5,0.5,1.0 };

		fogMode = GL_EXP;
		glFogi(GL_FOG_MODE, fogMode);
		glFogfv(GL_FOG_COLOR, fogColor);
		glFogf(GL_FOG_DENSITY, flag);
		glHint(GL_FOG_HINT, GL_DONT_CARE);
		glFogf(GL_FOG_START, 1.0);
		glFogf(GL_FOG_END, 5.0);
	}
}

void draw()
{
	//Called whenever the object needs to be drawn and the shadow
}

void glShadowProjection(float * l, float * p, float * n)
{
	float d, c;
	float mat[16];

	// These are c and d (corresponding to the tutorial)   

	d = n[0] * l[0] + n[1] * l[1] + n[2] * l[2];
	c = p[0] * n[0] + p[1] * n[1] + p[2] * n[2] - d;

	// Create the matrix. OpenGL uses column by column   
	// ordering   

	mat[0] = l[0] * n[0] + c;
	mat[4] = n[1] * l[0];
	mat[8] = n[2] * l[0];
	mat[12] = -l[0] * c - l[0] * d;

	mat[1] = n[0] * l[1];
	mat[5] = l[1] * n[1] + c;
	mat[9] = n[2] * l[1];
	mat[13] = -l[1] * c - l[1] * d;

	mat[2] = n[0] * l[2];
	mat[6] = n[1] * l[2];
	mat[10] = l[2] * n[2] + c;
	mat[14] = -l[2] * c - l[2] * d;

	mat[3] = n[0];
	mat[7] = n[1];
	mat[11] = n[2];
	mat[15] = -d;

	// Finally multiply the matrices together *plonk*   
	glMultMatrixf(mat);
}

/**
* render - gets called whenever we want to redraw the scene
*/
void render()
{
	glClearColor(0.0, 0.6, 0.9, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLightfv(GL_LIGHT0, GL_POSITION, l);

	glDisable(GL_CULL_FACE);
	glDisable(GL_LIGHTING);

	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POINTS);
	glVertex3f(l[0], l[1], l[2]);
	glEnd();

	// First, we draw the plane onto which the shadow should fall   
	// The Y-Coordinate of the plane is reduced by 0.1 so the plane is   
	// a little bit under the shadow. We reduce the risk of Z-Buffer   
	// flittering this way.   
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_QUADS);
	glNormal3f(0.0, 1.0, 0.0);

	glVertex3f(-1300.0, p[1] - 0.1, 1300.0);
	glVertex3f(1300.0, p[1] - 0.1, 1300.0);
	glVertex3f(1300.0, p[1] - 0.1, -1300.0);
	glVertex3f(-1300.0, p[1] - 0.1, -1300.0);

	glEnd();


	// Draw the object that casts the shadow   
	glPushMatrix();
	glRotatef(ry, 0, 1, 0);
	glRotatef(rx, 1, 0, 0);
	glEnable(GL_LIGHTING);
	glColor3f(0.0, 0.0, 0.8);
	draw();
	glPopMatrix();

	// Now we draw the shadow   
	glPushMatrix();
	glShadowProjection(l, p, n);
	glRotatef(ry, 0, 1, 0);
	glRotatef(rx, 1, 0, 0);
	glDisable(GL_LIGHTING);
	glColor3f(0.4, 0.4, 0.4);
	draw();
	glPopMatrix();

	glFlush();
}