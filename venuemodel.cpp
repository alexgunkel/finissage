#include "venuemodel.h"

VenueModel::VenueModel(QObject *parent):
    QAbstractTableModel(parent)
{
}

void VenueModel::addEntry(const Venue &newEntry)
{
    if (venues.contains(newEntry)) {
        return;
    }
}

int VenueModel::rowCount(const QModelIndex &idx) const
{
    if (idx.isValid()) {
        return 0;
    }

    return venues.size();
}

int VenueModel::columnCount(const QModelIndex &idx) const
{
    if (idx.isValid()) {
        return 0;
    }

    return VenueModel::Column::COUNT;
}

QVariant VenueModel::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole || !index.isValid() || index.row() >= venues.size() || index.row() < 0) {
        return QVariant();
    }

    auto v = venues.at(index.row());

    switch (index.column()) {
    case VenueModel::Column::Name:
        return QString::fromStdString(v.Name());
    case VenueModel::Column::Street:
        return QString::fromStdString(v.Address().street);
    case VenueModel::Column::Number:
        return QString::fromStdString(v.Address().number);
    case VenueModel::Column::City:
        return QString::fromStdString(v.Address().city);
    case VenueModel::Column::ZipCode:
        return QString::fromStdString(v.Address().zipCode);
    }

    return QVariant();
}

QVariant VenueModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole) {
        return QVariant();
    }

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case VenueModel::Column::Name:
            return tr("Name");
        case VenueModel::Column::Street:
            return tr("Street");
        case VenueModel::Column::Number:
            return tr("Number");
        case VenueModel::Column::City:
            return tr("City");
        case VenueModel::Column::ZipCode:
            return tr("Zip Code");
        }
    }

    return QVariant();
}

Qt::ItemFlags VenueModel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

bool VenueModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid() || role != Qt::EditRole) {
        return false;
    }

    const auto row = index.row();
    auto v = venues.value(row);
    auto a = v.Address();

    switch (index.column()) {
    case VenueModel::Column::Name:
        v.setName(value.toString().toStdString());
        break;
    case VenueModel::Column::Street:
        a.street = value.toString().toStdString();
        break;
    case VenueModel::Column::Number:
        a.number = value.toString().toStdString();
        break;
    case VenueModel::Column::City:
        a.city = value.toString().toStdString();
        break;
    case VenueModel::Column::ZipCode:
        a.zipCode = value.toString().toStdString();
        break;
    default:
        return false;
    }

    v.setAddress(a);
    venues.replace(row, v);

    emit dataChanged(index, index, {Qt::EditRole, Qt::DisplayRole});

    return true;
}

bool VenueModel::insertRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);

    beginInsertRows(QModelIndex(), position, position + rows - 1);

    for (int i = 0; i < rows; i++) {
        Venue v;
        venues.insert(i, v);
    }

    endInsertRows();

    return true;
}

bool VenueModel::removeRows(int position, int rows, const QModelIndex &index)
{
    Q_UNUSED(index);

    beginRemoveRows(QModelIndex(), position, position + rows - 1);

    for (int i = 0; i < rows; i++) {
        venues.removeAt(position);
    }

    endRemoveRows();
    return true;
}

const QVector<Venue> &VenueModel::getVenues() const
{
    return venues;
}
