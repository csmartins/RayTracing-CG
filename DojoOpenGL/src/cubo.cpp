#include <QtOpenGL>
#include <QVector3D>
#include "cubo.h"

Cubo::Cubo(const QVector3D& center, QObject *parent):
    Object3D(center, parent)
{

}

void Cubo::drawGeometry()const
{
    origin();

    //glDisable(GL_LIGHTING);
    //glDisable(GL_CULL_FACE);

    glTranslatef(1.0, 1.0, 1.0);
    glBegin(GL_TRIANGLES);
    glNormal3f(0, 0, -1);
    glColor3f(1.0, 0, 0);
    glVertex3i(0, 0, 0);
    glVertex3i(1, 0, 0);
    glVertex3i(0,1, 0);
    glEnd();


}

void Cubo::origin()const
{
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
    glColor3f(1.0, 0, 0);
    glVertex3i(0, 0, 0);
    glVertex3i(1, 0, 0);

    glColor3f(0, 1.0, 0);
    glVertex3i(0, 0, 0);
    glVertex3i(0, 1, 0);

    glColor3f(0, 0, 1.0);
    glVertex3i(0, 0, 0);
    glVertex3i(0, 0, 1);
    glEnd();
    glEnable(GL_LIGHTING);
}
