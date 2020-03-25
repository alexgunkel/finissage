#ifndef VENUEMODEL_H
#define VENUEMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include "venue.h"

class VenueModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    enum Column {
        Name,
        Street,
        Number,
        City,
        ZipCode,
        COUNT,
    };

    VenueModel(QObject *parent = nullptr);
    VenueModel(const QVector<Venue> venues, QObject *parent = nullptr);

    void addEntry(const Venue &newEntry);

    int rowCount(const QModelIndex &idx) const override;
    int columnCount(const QModelIndex &idx) const override;

    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex()) override;
    const QVector<Venue> &getVenues() const;

private:
    QVector<Venue> venues;
};

#endif // VENUEMODEL_H
