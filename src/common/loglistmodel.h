// loglistmodel.h
//
// Remote data model for the Rivendell Log List
//
//   (C) Copyright 2017 Fred Gleason <fredg@paravelsystems.com>
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License as
//   published by the Free Software Foundation; either version 2 of
//   the License, or (at your option) any later version.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License for more details.
//
//   You should have received a copy of the GNU General Public
//   License along with this program; if not, write to the Free Software
//   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//

#ifndef LOGLISTMODEL_H
#define LOGLISTMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QPixmap>
#include <QStringList>

class LogListModel : public QAbstractTableModel
{
  Q_OBJECT
 public:
  LogListModel(QObject *parent=0);
  QString serviceName() const;
  QString logName(int row) const;
  QString description(int row) const;
  QModelIndex index(const QString &logname) const;
  void update(const QString &filter,bool recent);
  int rowCount(const QModelIndex &parent=QModelIndex()) const;
  int columnCount(const QModelIndex &parent=QModelIndex()) const;
  QVariant data(const QModelIndex &index,int role=Qt::DisplayRole) const;
  QVariant headerData(int section,Qt::Orientation orient,
		      int role=Qt::DisplayRole) const;

 signals:
  void capiError(int err,const QString &err_msg);

 public slots:
  void setServiceName(const QString &str);

 private:
  bool LogReady(struct rd_log *log) const;
  int MusicLinked(struct rd_log *log) const;
  int TrafficLinked(struct rd_log *log) const;
  QVariant model_greencheckmark_map;
  QVariant model_redx_map;
  QVariant model_greenball_map;
  QVariant model_redball_map;
  QVariant model_whiteball_map;
  QString model_service_name;
  QList<QVariant> model_column_titles;
  QList<QVariant> model_column_alignments;
  QList<QStringList> model_column_fields;
  QStringList model_log_names;
  QString model_filter;
  bool model_recent;
};


#endif  // LOGLISTMODEL_H
