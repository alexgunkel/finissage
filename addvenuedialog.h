#ifndef ADDVENUEDIALOG_H
#define ADDVENUEDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include "venue.h"
#include "venuemodel.h"

class AddVenueDialog : public QDialog
{
    Q_OBJECT
public:
    AddVenueDialog(VenueModel *m, QWidget *parent = nullptr);

    void Persist() const;

private:
    VenueModel *m;

    QLineEdit *nameText;
    QLineEdit *streetText;
    QLineEdit *cityText;
    QLineEdit *zipCodeText;
    QLineEdit *numberText;

};

#endif // ADDVENUEDIALOG_H
