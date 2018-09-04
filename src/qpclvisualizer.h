#ifndef QPCLVISUALIZER_H
#define QPCLVISUALIZER_H

// VTK
#include <QVTKOpenGLWidget.h>
#include <vtkGenericOpenGLRenderWindow.h>

// PCL
#include <pcl/visualization/pcl_visualizer.h>

class QPCLVisualizer : public QVTKOpenGLWidget
{
  Q_OBJECT
public:
  QPCLVisualizer(QWidget* parent = nullptr);

protected:
  pcl::visualization::PCLVisualizer::Ptr viewer_;
  vtkSmartPointer<vtkRenderer> renderer_;
  vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow_;
};

#endif  // QPCLVISUALIZER_H
