#ifndef _GLWIDGET_H
#define _GLWIDGET_H

#include "Utils/util.h"
#include <QtOpenGL/QGLWidget>
#include <QGLShaderProgram>
#include "camera.h"

#include "Scene/scene.h"
//#include "Cameras/sphericalcamera.h"

class GLWidget : public QGLWidget {

    Q_OBJECT // must include this if you use Qt signals/slots

public:
    GLWidget(QWidget *parent = NULL);
    ~GLWidget();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    Scene *_scene;

    QGLShaderProgram *shader;
    Camera *camera;

    Point2D posCam;

    void initializeShaders(QString filename);
    void releaseAllShaders();

};

#endif  /* _GLWIDGET_H */
