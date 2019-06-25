/*=========================================================================
  The Software is copyright (c) Commonwealth Scientific and Industrial Research Organisation (CSIRO)
  ABN 41 687 119 230.
  All rights reserved.

  Licensed under the CSIRO BSD 3-Clause License
  You may not use this file except in compliance with the License.
  You may obtain a copy of the License in the file LICENSE.md or at

  https://stash.csiro.au/projects/SMILI/repos/smili/browse/license.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
=========================================================================*/
#ifndef MILXQTMANAGER_H
#define MILXQTMANAGER_H

#include <QtGui/QtGui>
#include <QTabWidget>
#include <QAction>
//milxQt Specific
#include "milxQtAliases.h"

/**
    \class milxQtManager
    \brief A manager (tabbed) widget class for displaying information about data such as case ID etc.

    Plugins can utilise the class for case browsing etc.
*/
class MILXQT_EXPORT milxQtManager : public QTabWidget
{
    Q_OBJECT

public:
    /*!
        \fn milxQtManager::milxQtManager(QWidget *theParent = 0)
        \brief The standard constructor
    */
    milxQtManager(QWidget *theParent = 0);
    virtual ~milxQtManager();

public slots:
    /** \brief Creates a new tab in the manager with the title and headings provided
     *
     * \param tabTitle Title of the tab
     * \param headings Headings of the fields within the view
     * \return The index of the created tab
     */
    int newTab(QString tabTitle, QStringList headings);
    /** \brief Close the current tab
     */
    void closeTab(int index);
    /** \brief Clear the current tab
     */
    void clearTab();
    /** \brief Clear the tab given by index
     *
     * \param tabIndex index for the tab to be cleared
     */
    void clearTab(int tabIndex);
    /** \brief Clear the tab given by index
     *
     * \param tabIndex index for the tab to be cleared
     */
    void exportTab(QString filename = "");
    /** \brief Add all the entries in list to the view
     *
     * \param entries The entries for the current item or row to be add.
     * \param flags item properties, is it Qt::ItemIsEditable etc.
     */
    void addItem(QStringList entries, Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    /** \brief Add all the entries in list to the view
     *
     * \param index tab index of the entry to be inserted
     * \param entries The entries for the current item or row to be add.
     * \param flags item properties, is it Qt::ItemIsEditable etc.
     */
    void addItem(int tabIndex, QStringList entries, Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    /** \brief Add all the entries in list to the view, as well as the widget provided
     *
     * \param index tab index of the entry to be inserted
     * \param entries The entries for the current item or row to be add.
     * \param itemWidgetToAdd the widget to be added to the item
     * \param widgetColumn column where the widget is to go
     */
    void addItem(int tabIndex, QStringList entries, QWidget *itemWidgetToAdd, int widgetColumn);
    /** \brief Add all the entries in list to the view like a tree
    *
    * \param index tab index of the entry to be inserted
    * \param entries The entries for the current item or row to be add.
    * \param flags item properties, is it Qt::ItemIsEditable etc.
    */
    void addTreeItem(int tabIndex, QStringList topLevelName, QList<QStringList> entryList, Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable);

protected:
    QAction* actionExportTab; //!< export tab action
    QAction* actionClearTab; //!< clear tab action
    QAction* actionClear; //!< clear manager action 

    /*!
    \fn milxQtManager::createActions()
    \brief Create the actions for context menu etc.
    */
    void createActions();
    /*!
    \fn milxQtManager::createConnections()
    \brief Create the connections for context menu etc.
    */
    void createConnections();
    /*!
    \fn milxQtManager::contextMenuEvent(QContextMenuEvent *event)
    \brief The context menu setup member
    */
    void contextMenuEvent(QContextMenuEvent *event);

private:

};

#endif // MILXQTMANAGER_H
