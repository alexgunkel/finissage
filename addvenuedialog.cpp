#include "addvenuedialog.h"
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>

AddVenueDialog::AddVenueDialog(VenueModel *m, QWidget *parent)
    : QDialog(parent)
    , m(m)
    , nameText(new QLineEdit)
    , streetText(new QLineEdit)
    , cityText(new QLineEdit)
    , zipCodeText(new QLineEdit)
    , numberText(new QLineEdit)
{
    //
    auto nameLabel = new QLabel(tr("Name"));
    auto streetLabel = new QLabel(tr("Street"));
    auto cityLabel = new QLabel(tr("City"));
    auto zipCodeLabel = new QLabel(tr("Zip Code"));
    auto numberLabel = new QLabel(tr("Number"));
    //
    auto layout = new QGridLayout;
    layout->addWidget(nameLabel, 0, 0);
    layout->addWidget(nameText, 0, 1);
    //
    layout->addWidget(streetLabel, 1, 0);
    layout->addWidget(streetText, 1, 1);
    //
    layout->addWidget(numberLabel, 2, 0);
    layout->addWidget(numberText, 2, 1);
    //
    layout->addWidget(cityLabel, 3, 0);
    layout->addWidget(cityText, 3, 1);
    //
    layout->addWidget(zipCodeLabel, 4, 0);
    layout->addWidget(zipCodeText, 4, 1);

    auto okButton = new QPushButton(tr("OK"));
    auto cancelButton = new QPushButton(tr("Cancel"));
    auto buttons = new QHBoxLayout;
    buttons->addWidget(okButton);
    buttons->addWidget(cancelButton);
    connect(okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);

    layout->addLayout(buttons, 5, 1, Qt::AlignRight);
    setLayout(layout);

    setWindowTitle(tr("Add a venue"));
}

void AddVenueDialog::Persist() const
{
    m->insertRows(0, 1, QModelIndex());

    m->setData(m->index(0, VenueModel::Column::Name, QModelIndex()), nameText->text(), Qt::EditRole);
    m->setData(m->index(0, VenueModel::Column::Street, QModelIndex()), streetText->text(), Qt::EditRole);
    m->setData(m->index(0, VenueModel::Column::Number, QModelIndex()), numberText->text(), Qt::EditRole);
    m->setData(m->index(0, VenueModel::Column::City, QModelIndex()), cityText->text(), Qt::EditRole);
    m->setData(m->index(0, VenueModel::Column::ZipCode, QModelIndex()), zipCodeText->text(), Qt::EditRole);
}
