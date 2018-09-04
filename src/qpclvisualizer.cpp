#include "qpclvisualizer.h"

QPCLVisualizer::QPCLVisualizer(QWidget* parent) : QVTKOpenGLWidget(parent)
{
  // Create renderer and window
  renderer_ = vtkSmartPointer<vtkRenderer>::New();
  renderWindow_ = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
  renderWindow_->AddRenderer(renderer_);

  // Create PCLVisualizer
  viewer_.reset(new pcl::visualization::PCLVisualizer(renderer_, renderWindow_, "viewer", true));

  // Set rendring window
  QVTKOpenGLWidget::SetRenderWindow(viewer_->getRenderWindow());

  // Add something on the viewer
  viewer_->addCoordinateSystem(1);
}
