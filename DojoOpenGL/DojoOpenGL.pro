QT       += core gui opengl

TARGET = DojoOpenGL
TEMPLATE = app

unix{
    LIBS += -lGLU
}
win32{

}

SOURCES += src/main.cpp\
    src/mainwindow.cpp\
    src/GLDisplay.cpp \
    src/rendercontroller.cpp \
    src/Object3D.cpp \
    src/Arcball.cpp \
    src/DirectionalLight.cpp \
    src/Scene3D.cpp \
    src/cubo.cpp


HEADERS  += src/mainwindow.h\
    src/GLDisplay.h \
    src/rendercontroller.h \
    src/Object3D.h \
    src/Arcball.h \
    src/DirectionalLight.h \
    src/Scene3D.h \
    src/cubo.h

FORMS    += src/mainwindow.ui
