#include <GL/glut.h>
#include <stdlib.h>

int animate=1;

void display(void);
void init_texture(void);
void affiche_metal(void);

extern float xRotation;
extern float yRotation;
extern float zTranslate;
extern float ex;
extern float ez;

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   
   glClear (GL_COLOR_BUFFER_BIT);
   glClear (GL_DEPTH_BUFFER_BIT);
   glLoadIdentity ();
   gluLookAt (0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
   init_texture();
}


void my_timer(int v)
{
   if (animate)
       glutTimerFunc(40, my_timer, 1);

   glutPostRedisplay();
}



void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(120,w/h,0.1,120);
   glMatrixMode (GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
      case 'a':
         animate=!animate;
	 if (animate)
   		glutTimerFunc(40, my_timer, 1);
         break;
      case 'x':
	 xRotation = xRotation - 2.0;
	 break;
      case 'X':
        xRotation = xRotation + 2.0;
 	break; 
      case 'y':
	 yRotation = yRotation - 0.7;
	break;
      case 'Y':
	 yRotation = yRotation + 0.7;
 	 break;
      case 'z':
	 zTranslate = zTranslate - 1;
	 break;
      case 'Z':
	 zTranslate = zTranslate + 1;
	 break;
      case 'g':
	 animate = 0;
	 break;
      case 'd':
	 ex = ex + 0.5;
	 break;
      case 'D':
	 ex = ex - 0.5;
	 break;
      case 'f':
	 ez = ez + 0.5;
	 break;
      case 'F':
	 ez = ez - 0.5;
	 break;
      case 'A':
         ez = 5;
	 ex = 1.5;
	 break;
     case 'b':
	  glClearColor (0.0, 0.0, 0.0, 0.0);
	  break;
    case 'B':
	 glClearColor (0.0, 0.0, 1.0, 0.8);
	  break;
   }
	glutPostRedisplay();

}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DEPTH|GLUT_DOUBLE| GLUT_RGB);
   glutInitWindowSize (600, 600); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutTimerFunc(40, my_timer, 1);

   glutMainLoop();
   return 0;
}



