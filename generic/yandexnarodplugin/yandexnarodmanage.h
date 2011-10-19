/*
    yandexnarodManage

	Copyright (c) 2009 by Alexander Kazarin <boiler@co.ru>

 ***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************
*/

#ifndef YANDEXNARODMANAGE_H
#define YANDEXNARODMANAGE_H

#include <QListWidget>
#include <QDialog>

#include "yandexnarodnetman.h"

namespace Ui {
	class yandexnarodManageClass;
}


class ListWidget : public QListWidget
{
public:
	ListWidget(QWidget* p = 0);

protected:
	virtual QStringList mimeTypes() const;
	virtual QMimeData *mimeData(const QList<QListWidgetItem *> items) const;
};



class yandexnarodManage : public QDialog
{
	Q_OBJECT

public:
	yandexnarodManage(QWidget* p = 0);
	~yandexnarodManage();

private:
	QList<yandexnarodNetMan::FileItem> selectedItems() const;
	void newNetMan();
	void netmanPrepare();

private slots:
	void newFileItem(yandexnarodNetMan::FileItem);
	void on_btnDelete_clicked();
	void on_btnClipboard_clicked();
	void on_listWidget_pressed(QModelIndex index);
	void on_btnReload_clicked();
	void on_btnUpload_clicked();
	void on_btnProlong_clicked();
	void on_btnClearCookies_clicked();
	void netmanFinished();

private:
	Ui::yandexnarodManageClass* ui_;
	yandexnarodNetMan *netman;
	QList<QIcon> fileicons;
	QHash<QString, int> fileiconstyles;
	QList<yandexnarodNetMan::FileItem> fileitems;

};
#endif
