/*
  statemodel.h

  This file is part of GammaRay, the Qt application inspection and
  manipulation tool.

  Copyright (C) 2010-2014 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Stephen Kelly <stephen.kelly@kdab.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef GAMMARAY_STATEMACHINEVIEWER_STATEMODEL_H
#define GAMMARAY_STATEMACHINEVIEWER_STATEMODEL_H

#include "objectmodelbase.h"

#include <QSet>

class QAbstractState;
class QAbstractTransition;
class QStateMachine;

namespace GammaRay {

class StateModel;
class StateMachineWatcher;

class StateModelPrivate
{
  StateModelPrivate(StateModel *qq);

  Q_DECLARE_PUBLIC(StateModel)
  StateModel * const q_ptr;
  QStateMachine *m_stateMachine;
  StateMachineWatcher * const m_stateMachineWatcher;
  QSet<QAbstractState*> m_lastConfiguration;

  QList<QObject*> children(QObject *parent) const;

  QObject *mapModelIndex2QObject(const QModelIndex &) const;
  QModelIndex indexForState(QAbstractState *state) const;

// private slots:
  void stateConfigurationChanged();
  void handleMachineDestroyed(QObject*);
};



class StateModel : public ObjectModelBase<QAbstractItemModel>
{
  Q_OBJECT

  public:
    enum Roles {
      TransitionsRole = ObjectModel::UserRole + 1,
      IsInitialStateRole,
      StateObjectRole = ObjectModel::UserRole + 11
    };
    explicit StateModel(QObject *parent = 0);
    ~StateModel();

    void setStateMachine(QStateMachine *stateMachine);
    QStateMachine *stateMachine() const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;

#ifdef QT5
    QHash<int,QByteArray> roleNames() const;
#endif

  protected:
    Q_DECLARE_PRIVATE(StateModel)
    StateModelPrivate * const d_ptr;

  private:
    Q_PRIVATE_SLOT(d_func(), void stateConfigurationChanged())
    Q_PRIVATE_SLOT(d_func(), void handleMachineDestroyed(QObject*))
};

}

#endif
