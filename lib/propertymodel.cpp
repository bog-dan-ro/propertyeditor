/***************************************************************************
 *   This file is part of the propertyEditor project                       *
 *   Copyright (C) 2008 by BogDan Vatra                                    *
 *   bog_dan_ro@yahoo.com                                                  *
 **                   GNU General Public License Usage                    **
 *                                                                         *
 *   This library is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation, either version 3 of the License, or     *
 *   (at your option) any later version.                                   *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                         *
 **                  GNU Lesser General Public License                    **
 *                                                                         *
 *   This library is free software: you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License as        * 
 *   published by the Free Software Foundation, either version 3 of the    *
 *   License, or (at your option) any later version.                       *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library.                                      * 
 *   If not, see <http://www.gnu.org/licenses/>.                           *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 ****************************************************************************/

#include <QMetaProperty>
#include <QMetaEnum>
#include <QSize>
#include <QFontMetrics>

#include "propertymodel.h"
#include "propertyinterface.h"

namespace PropertyEditor
{

PropertyModel::PropertyModel(QObject* parent, QObject* object, QList<PropertyInterface*> * plugins): QAbstractItemModel(parent), m_object(object), m_plugins(plugins)
{
	refreshProperties();
}

PropertyModel::~PropertyModel()
{
	clearCreatedProperties();
}

void PropertyModel::clearCreatedProperties()
{
	foreach (QPointer<PropertyInterface> prop, m_createdProperties)
		delete prop;
	m_createdProperties.clear();
}

void PropertyModel::refreshProperties()
{
	for (int p = 0;p < m_properties.size();p++)
		delete m_properties[p];
	m_properties.clear();
	clearCreatedProperties();
	if (m_object && m_plugins)
		for (int i = 0;i < m_object->metaObject()->propertyCount();i++)
			if (m_object->metaObject()->property(i).isDesignable() && m_object->metaObject()->property(i).isValid() && m_object->metaObject()->property(i).isWritable() && m_object->metaObject()->property(i).isReadable())
				foreach(PropertyInterface* plugin, (*m_plugins))
					if (plugin->canHandle(m_object, i))
					{
						PropertyInterface* pi=plugin->createInstance(m_object, i, this);
						connect(pi,SIGNAL(propertyChanged(QObject*,QString,QVariant,QVariant)), QObject::parent(), SIGNAL(propertyChanged(QObject*,QString,QVariant,QVariant)));
						m_createdProperties.push_back(pi);
						m_properties.push_back(pi);
						break;
					}
}

PropertyInterface* PropertyModel::createPropery(QObject* object, int property) const
{
	PropertyInterface* pi = 0;
	if (object->metaObject()->property(property).isValid() && object->metaObject()->property(property).isWritable() && object->metaObject()->property(property).isReadable())
		foreach(PropertyInterface* plugin, (*m_plugins))
			if (plugin->canHandle(object, property))
			{
				pi = plugin->createInstance(object, property, this);
				break;
			}
	return pi;
}

void PropertyModel::setObject(QObject * object)
{
	m_object = object;
	refreshProperties();
	reset();
}

void PropertyModel::resetModel() 
{
	reset();
}

QModelIndex PropertyModel::index(int row, int column, const QModelIndex & parent) const
{
	if (parent.isValid())
	{
		if (row >= reinterpret_cast<PropertyInterface*>(parent.internalPointer())->rowCount(parent))
			return QModelIndex();
		reinterpret_cast<PropertyInterface*>(parent.internalPointer())->property(row)->setParentIndex(parent);
		return createIndex(row, column, reinterpret_cast<PropertyInterface*>(parent.internalPointer())->property(row));
	}
	if (row >= m_properties.size())
		return QModelIndex();
	if (0==column)
		m_properties[row]->setParentIndex(parent);
	return createIndex(row, column, m_properties[row]);
}


int PropertyModel::rowCount(const QModelIndex &parent) const
{
	if (parent.isValid())
		return reinterpret_cast<PropertyInterface*>(parent.internalPointer())->rowCount(parent);
	return m_properties.size();
}

int PropertyModel::columnCount(const QModelIndex & parent) const
{
	if (parent.isValid())
		return reinterpret_cast<PropertyInterface*>(parent.internalPointer())->columnCount(parent);
	return 2;
}

QVariant PropertyModel::data(const QModelIndex &index, int role) const
{
	if (index.isValid() && Qt::DisplayRole == role)
		return reinterpret_cast<PropertyInterface*>(index.internalPointer())->data(index);
	if (Qt::SizeHintRole == role)
	    return QSize(0,QFontMetrics(QFont()).lineSpacing()+6);
	return QVariant();
}

bool PropertyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (Qt::EditRole != role)
		return false;
	bool ret = false;
	if (index.isValid() && Qt::DisplayRole == role)
		ret = reinterpret_cast<PropertyInterface*>(index.internalPointer())->setData(value, index);
	if (ret)
		emit dataChanged(index, index);
	return ret;
}

QModelIndex PropertyModel::parent(const QModelIndex & index) const
{
	if (index.isValid())
		return reinterpret_cast<PropertyInterface*>(index.internalPointer())->parentIndex(index);
	return QModelIndex();
}

Qt::ItemFlags PropertyModel::flags(const QModelIndex &index) const
{
	if (index.isValid())
		return reinterpret_cast<PropertyInterface*>(index.internalPointer())->flags(index);
	return Qt::NoItemFlags;
}

QVariant PropertyModel::headerData(int section, Qt::Orientation orientation,
                                   int role) const
{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
		switch (section)
		{
			case 0:
				return tr("Property");

			case 1:
				return tr("Value");

			default:
				return QVariant();
		}

	return QVariant();
}

}
