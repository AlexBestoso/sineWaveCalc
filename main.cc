#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <string>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

GLfloat a = 0.15;
GLfloat h = 0.0;
GLfloat b = 0.25;
GLfloat k = 0.0;

float gfPosX = -1.0; //time
int timesXChanged = 0;
float gfPosY = 0.25;	//amplitude GLfloat lastYVal;
float holder = 0;

int loopCount = 0;	bool loopCountMax = false;

int bSize = 1000;
GLfloat vtxMtrx[2][1000];

bool loop_wait = false;

GLfloat rateOfChange = .01; //gfDeltaX
	
void gridLines(void){
	glBegin(GL_LINES);
		glColor3f(0.0, 1.0, 0.0);
		
		glVertex3f(-1.0, 0.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);
		glVertex3f(0.0, -1.0, 0.0);
	glEnd();
}
	
void sineWave(void){
	if(gfPosX >= 1.0){
		gfPosX = -1.0;
		vtxMtrx[0][loopCount] = gfPosX;
		vtxMtrx[1][loopCount] = gfPosY;
		timesXChanged++;
		
	}else{
		gfPosX += rateOfChange;
		vtxMtrx[0][loopCount] = gfPosX;
		gfPosY = a * sin(((gfPosX + timesXChanged) - h) / b) + k;
		vtxMtrx[1][loopCount] = gfPosY;
	}
	glBegin(GL_LINE_STRIP);
		glColor3f(0.0, 0.0, 1.0);	
	        for(int i=0; i<loopCount; i++){  
			gfPosY = vtxMtrx[1][i];
			glVertex3f(vtxMtrx[0][i], vtxMtrx[1][i], 0.0);
			if(vtxMtrx[0][i] >= 1.0){
				loopCount = 0;
				loop_wait = true;
			}
		}
       	glEnd();
	if(!loop_wait){
		loopCount++;
	}else{
		loop_wait = false;
	}
	glutPostRedisplay();
}
 
void render(void){//This made me happy c:
	glClear(GL_COLOR_BUFFER_BIT);
	gridLines();
	sineWave();
	glutSwapBuffers();
}

void ValueSetup(void){
	system("clear");
	std::cout<<"Welcome, we need some values if we are to continue.\n";
	std::cout<<"Enter float a\n#> ";
	std::cin>>a;
	std::cout<<"Enter float h\n#> ";
	std::cin>>h;
	std::cout<<"Enter float b\n#> ";
	std::cin>>b;
	std::cout<<"Enter float k\n#> "; 
	std::cin>>k;
}

int main(int argc, char **argv){
	ValueSetup();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(500, 100);
	glutCreateWindow("A Square");
	glutDisplayFunc(render);
	glutMainLoop();

	return 0;
}
