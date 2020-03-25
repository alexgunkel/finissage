#ifndef VENUEWIDGET_H
#define VENUEWIDGET_H

#include <QTabWidget>
#include <QItemSelection>
#include "venuemodel.h"

class VenueWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit VenueWidget(QWidget *parent = nullptr);

    void addVenueDialog();

signals:
    void selectionChanged(const QItemSelection &selected);

private:
    VenueModel *model;
};

#endif // VENUEWIDGET_H
