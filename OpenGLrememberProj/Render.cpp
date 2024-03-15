#define GREEN 0, 1, 0
#define PURPLE 1, 0, 1
#define BASE_COLOR 0.5, 0.5, 0.5

#include "Render.h"
#include <math.h>
#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>

void Render(double delta_time)
{
	//GLdouble GreenColor[] = {0, 1, 0}; - попытка безуспешна
	double A[] = {3,2,1};
	double B[] = { 2, 4, 5};
	double C[] = { 7,9,2 };
	double D[] = { 8,3,2 };

	// 2 линии
	//glBegin(GL_LINES);
	//	glVertex3d(3, 2, 1);
	//	glVertex3d(2, 4, 5);

	//	glVertex3d(2, 4, 5);
	//	glVertex3d(7, 9, 2);

	//	glVertex3d(7, 9, 2);
	//	glVertex3d(3, 2, 1);
	//glEnd();

	// треугольник и градиент
	//glBegin(GL_TRIANGLES);
	//	glColor3d(0, 0.8, 0.8);
	//	glVertex3dv(A);
	//	glColor3d(0.8, 0, 0);
	//	glVertex3dv(B);
	//	glColor3d(0, 1, 0);
	//	glVertex3dv(C);
	//glEnd();

	//9 точек
	double Points[8][3] = { { 4,  0,  0},
							{ 11, 1,  0},
							{ 9,  8,  0},
							{ 13, 8,  0},
							{ 12, 15, 0},
							{ 7,  16, 0},
							{ 6,  9,  0},
							{ 0,  7,  0} };
	
	//3-4 - green; 7-0 - purple ;

	double PointsHigher[8][3] = { { 4,  0,  10},
								  { 11, 1,  10},
								  { 9,  8,  10},
								  { 13, 8,  10},
								  { 12, 15, 10},
								  { 7,  16, 10},
								  { 6,  9,  10},
								  { 0,  7,  10} };

	double Circle[] = { 0, 10, 0 };

	glBegin(GL_TRIANGLES);
		glColor3d(BASE_COLOR);

		//main "square"
		//1st
		for (int i = 0; i < 3; i++)
			glVertex3dv(Points[i]);

		for (int i = 0; i < 3; i++)
			glVertex3dv(PointsHigher[i]);

		//2nd - special
		glVertex3dv(Points[3]);
		double PastCirPoint[3];
		for (double j = -0.14; j < 3.14; j += 0.06)
		{
			double NextCirPoint[] = {12.5 + 3.53 * sin(j) , 11.5 + 3.53 * cos(j) , 0};
			glVertex3dv(Points[2]);
			glVertex3dv(NextCirPoint);

			for(int i = 0; i < 3; i++)
				PastCirPoint[i] = NextCirPoint[i];

			glVertex3dv(PastCirPoint);
		}
		glVertex3dv(Points[4]);
		glVertex3dv(Points[2]);

		glVertex3dv(PointsHigher[3]);
		for (double j = -0.14; j < 3.14; j += 0.06)
		{
			double NextCirPoint[] = { 12.5 + 3.53 * sin(j) , 11.5 + 3.53 * cos(j) , 10 };
			glVertex3dv(PointsHigher[2]);
			glVertex3dv(NextCirPoint);

			for (int i = 0; i < 3; i++)
				PastCirPoint[i] = NextCirPoint[i];

			glVertex3dv(PastCirPoint);
		}
		glVertex3dv(PointsHigher[2]);
		glVertex3dv(PointsHigher[4]);

		//3rd
		for (int i = 4; i < 6; i++)
			glVertex3dv(Points[i]);
		glVertex3dv(Points[2]);

		for (int i = 4; i < 6; i++)
			glVertex3dv(PointsHigher[i]);
		glVertex3dv(PointsHigher[2]);

		//4th
		for (int i = 5; i < 7; i++)
			glVertex3dv(Points[i]);
		glVertex3dv(Points[2]);

		for (int i = 5; i < 7; i++)
			glVertex3dv(PointsHigher[i]);
		glVertex3dv(PointsHigher[2]);

		//5th
		for (int i = 6; i < 8; i++)
			glVertex3dv(Points[i]);
		glVertex3dv(Points[2]);

		for (int i = 6; i < 8; i++)
			glVertex3dv(PointsHigher[i]);
		glVertex3dv(PointsHigher[2]);

		//6th - spedcial
		glVertex3dv(Points[7]);
		for (double j = 0.7; j < 1.5; j += 0.04)
		{
			double NextCirPoint[] = { -5 + 9.01 * sin(j) , -0.5 + 9.01 * cos(j) , 0};
			glVertex3dv(NextCirPoint);
			glVertex3dv(Points[2]);

			for (int i = 0; i < 3; i++)
				PastCirPoint[i] = NextCirPoint[i];

			glVertex3dv(PastCirPoint);
		}
		glVertex3dv(Points[0]);
		glVertex3dv(Points[2]);

		glVertex3dv(PointsHigher[7]);
		for (double j = 0.7; j < 1.5; j += 0.04)
		{
			double NextCirPoint[] = { -5 + 9.01 * sin(j) , -0.5 + 9.01 * cos(j) , 10 };
			glVertex3dv(NextCirPoint);
			glVertex3dv(PointsHigher[2]);

			for (int i = 0; i < 3; i++)
				PastCirPoint[i] = NextCirPoint[i];

			glVertex3dv(PastCirPoint);
		}
		glVertex3dv(PointsHigher[0]);
		glVertex3dv(PointsHigher[2]);

	glEnd();

	glBegin(GL_QUADS);
		for (int i = 0; i < 7; i++)
		{
			if (i == 3)
				glColor3d(GREEN);

			glVertex3dv(Points[i]);
			glVertex3dv(PointsHigher[i]);

			if (i == 3)
			{
				double PastCirPoint[3];
				for (double j = -0.139; j < 3.1; j += 0.06)
				{
					double NextCirPoint[] = { 12.5 + 3.53 * sin(j) , 11.5 + 3.53 * cos(j) , 10 };
					glVertex3dv(NextCirPoint);

					NextCirPoint[2] = 0;
					glVertex3dv(NextCirPoint);
					glVertex3dv(NextCirPoint);
					NextCirPoint[2] = 10;
					glVertex3dv(NextCirPoint);
				}

			}
			glVertex3dv(PointsHigher[i + 1]);
			glVertex3dv(Points[i + 1]);
			glColor3d(BASE_COLOR);
		}

		glColor3d(PURPLE);
		glVertex3dv(Points[7]);
		glVertex3dv(PointsHigher[7]);

		for (double j = 0.7; j < 1.5; j += 0.04)
		{
			double NextCirPoint[] = { -5 + 9.01 * sin(j) , -0.5 + 9.01 * cos(j) , 10 };
			glVertex3dv(NextCirPoint);

			NextCirPoint[2] = 0;
			glVertex3dv(NextCirPoint);
			glVertex3dv(NextCirPoint);
			NextCirPoint[2] = 10;
			glVertex3dv(NextCirPoint);
		}

		glVertex3dv(PointsHigher[0]);
		glVertex3dv(Points[0]);
	glEnd();
}   

