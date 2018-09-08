#ifndef PIE2D_H
#define PIE2D_H

#include <QObject>
#include "../3rdparty/qcustomplot/qcustomplot.h"
#include "Axis2D.h"

class Column;

class QCP_LIB_DECL Pie2D : public QCPAbstractItem {
  Q_OBJECT
 public:
  Pie2D(AxisRect2D *axisrect);
  ~Pie2D();

  void setGraphData(Column *xData, int from, int to);
  // reimplemented virtual methods:
  double selectTest(const QPointF &pos, bool onlySelectable,
                            QVariant *details = nullptr) const;

  QCPItemPosition *const topLeft;
  QCPItemPosition *const bottomRight;

 protected:
  //void draw(QCPPainter *painter);
  void draw(QCPPainter *painter);
  QPointF anchorPixelPosition(int anchorId);

 private:
  AxisRect2D *axisrect_;
  QVector<double> *pieData_;
  QVector<QColor> *pieColors_;
  QPen mPen;
  QBrush mBrush;
};

#endif  // PIE2D_H