/*
This file is a part of
QVGE - Qt Visual Graph Editor

(c) 2016-2018 Ars L. Masiuk (ars.masiuk@gmail.com)

It can be used freely, maintaining the information above.
*/

#pragma once

#include <QWidget>
#include <QList>

#include <QtVariantPropertyManager>
#include <QtVariantEditorFactory>

class CEditorScene;
class CItem;

namespace Ui {
class CClassAttributesEditorUI;
}

class CClassAttributesEditorUI : public QWidget
{
    Q_OBJECT

public:
    explicit CClassAttributesEditorUI(QWidget *parent = 0);
    ~CClassAttributesEditorUI();

    void setScene(CEditorScene* scene);

Q_SIGNALS:
	void colorSchemeApplied(CEditorScene* scene);

protected:
    void connectSignals(CEditorScene* scene);
    void onSceneAttached(CEditorScene* scene);
    void onSceneDetached(CEditorScene* scene);

    void rebuild();

protected Q_SLOTS:
    void onSceneChanged();
    void on_ClassId_currentIndexChanged(int);
	void on_Editor_currentItemChanged(QtBrowserItem*);

private Q_SLOTS:
    void on_AddButton_clicked();
	void on_RemoveButton_clicked();
    void onValueChanged(QtProperty *property, const QVariant &val);

private:
    Ui::CClassAttributesEditorUI *ui;

    QtVariantPropertyManager m_manager;
    QtVariantEditorFactory m_factory;

    CEditorScene *m_scene;

    class CColorSchemesUIController *m_schemesController;

    bool m_locked;
};

