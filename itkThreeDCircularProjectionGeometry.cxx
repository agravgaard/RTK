#include "itkThreeDCircularProjectionGeometry.h"

void itk::ThreeDCircularProjectionGeometry::AddProjection(const double angle, const double offsetX, const double offsetY)
  {
  Superclass::MatrixType matrix;
  m_RotationAngles.push_back(angle);
  m_ProjOffsetsX.push_back(offsetX);
  m_ProjOffsetsY.push_back(offsetY);
  matrix = Get2DRigidTransformationHomogeneousMatrix(0, offsetX, offsetY).GetVnlMatrix() *
           GetProjectionMagnificationMatrix<3>(m_SourceToDetectorDistance, m_SourceToIsocenterDistance).GetVnlMatrix() *
           Get3DRigidTransformationHomogeneousMatrix(0, angle, 0, 0, 0, 0).GetVnlMatrix();
  this->AddMatrix(matrix);
  }

void itk::ThreeDCircularProjectionGeometry::PrintSelf( std::ostream& os, Indent indent ) const
{
  //TODO
}