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
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 ****************************************************************************/

#ifndef PROPERTYEDITORPROPERTYEDITOR_H
#define PROPERTYEDITORPROPERTYEDITOR_H

#include <QTreeView>
#include <QList>
#include "propertyvalidator.h"

#ifdef WIN32
#ifdef LIB_EXPORTS
#define PROPERTYEDITOR_EXPORTS __declspec(dllexport)
#else
#define PROPERTYEDITOR_EXPORTS __declspec(dllimport)
#endif
#else
#define PROPERTYEDITOR_EXPORTS
#endif

namespace PropertyEditor
{

class PropertyInterface;
class PropertyModel;
class PropertyDelegate;
class PROPERTYEDITOR_EXPORTS PropertyEditor : public QTreeView
{
	Q_OBJECT

public:
	PropertyEditor(QWidget *parent = 0);
	~PropertyEditor();

	QObject *object() const;
	void setValidator(QVariant::Type type, PropertyValidator * validator);
	PropertyValidator* validator(QVariant::Type type);
	void clearValidators();

private:
	void loadPlugins();

public slots:
	void setObject(QObject * object);
	void resetProperties();

private:
	QObject *m_object;
	QList<PropertyInterface*> m_plugins;
	PropertyModel* m_model;
	PropertyDelegate* m_delegate;
	QMap<int, PropertyValidator*> m_validators;

signals:
	void propertyChanged(QObject * obj, const QString & propertyName, const QVariant & old_value, const QVariant & new_value);
	void objectChanged(QObject * obj);

};

}

#endif
