#include <QTableView>
#include <QDebug>
#include "venuewidget.h"
#include "addvenuedialog.h"

VenueWidget::VenueWidget(QWidget *parent)
    : QTabWidget(parent),
      model{new VenueModel(this)}
{
    auto allView = new QTableView;
    allView->setModel(this->model);
    allView->setSortingEnabled(true);

    //connect(allView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &VenueWidget::selectionChanged);

    addTab(allView, tr("All"));
}

void VenueWidget::addVenueDialog()
{
    AddVenueDialog a{model};

    if (a.exec()) {
        a.Persist();
        qDebug() << model->rowCount(model->index(0,0,QModelIndex()));
    }
}
