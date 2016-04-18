#ifndef CUBO_H
#define CUBO_H

#include "Object3D.h"

class Cubo : public Object3D
{
    Q_OBJECT

    int indexList;
public:
    explicit Cubo(const QVector3D& center = QVector3D(),
                    QObject *parent = 0);
private:
    void origin()const;

protected:
    virtual void drawGeometry()const;



};

#endif // CUBO_H
