#include "MainWindow.hpp"


/***************************************************************************************************
 * PUBLIC METHODS
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_DAT(),
    m_DATPath(""),
    m_treeViewModel(new QStandardItemModel())
{
    setupUi(this);

    treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    treeView->setModel(m_treeViewModel);
    
    updateMenuBar();
    connect(this, SIGNAL(DAT_Loaded()), this, SLOT(updateMenuBar()));
    connect(this, SIGNAL(DAT_Loaded()), this, SLOT(updateTreeViewModel()));
    connect(this, SIGNAL(DAT_Closed()), this, SLOT(updateMenuBar()));
    connect(this, SIGNAL(DAT_Closed()), this, SLOT(updateTreeViewModel()));
    connect(this, SIGNAL(DAT_Modified()), this, SLOT(updateTreeViewModel()));
}


/***************************************************************************************************
 * PRIVATE METHODS
 */
bool MainWindow::closeCurrentDATFile()
{
    if(m_DATPath.isEmpty())
        return true;
    else
    {
        int user_select = QMessageBox::question(this, "Save DAT File ?",
                                                "Do you want to save the DAT file ?",
                                                QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        
        if(user_select == QMessageBox::Yes)
        {
            if(m_DAT.saveToFile(m_DATPath.toStdString()))
            {
                m_DAT.clear();
                m_DATPath = "";
                
                setWindowTitle("[GNB] DAT");
                
                emit DAT_Closed();
                return true;
            }
            else
            {
                QMessageBox::warning(this, "DAT File",
                                      "Unable to save file:"+m_DATPath);
                
                return false;
            }
        }
        else if(user_select == QMessageBox::No)
        {
            m_DAT.clear();
            m_DATPath = "";
            
            setWindowTitle("[GNB] DAT");
            
            emit DAT_Closed();
            return true;   
        }
        else
            return false;
    }
}


std::string MainWindow::getFilePathByRow(int row)
{
    std::string filename("");
    if(row < m_treeViewModel->rowCount())
    {
        filename += m_treeViewModel->index(row, 0).data().toString().toStdString();
        filename += m_treeViewModel->index(row, 1).data().toString().toStdString();
    }


    return filename;
}


std::vector<std::string> MainWindow::getSelectedFilePath()
{
    std::vector<std::string> selectedFilePath;

    QModelIndexList selectedRows = treeView->selectionModel()->selectedRows();
    for(int i=0; i<selectedRows.size(); ++i)
        selectedFilePath.push_back(getFilePathByRow(selectedRows.at(i).row()));

    return selectedFilePath;
}


/***************************************************************************************************
 * PRIVATE SLOTS
 */
////////////////////////////////////////////////////////////////////////////////////////////////////
/// TREE VIEW
void MainWindow::updateTreeViewModel()
{
    QLocale qlocale;
    m_treeViewModel->clear();

    m_treeViewModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
    m_treeViewModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Type")));
    m_treeViewModel->setHorizontalHeaderItem(2, new QStandardItem(QString("Size (octets)")));

    QFileInfo fileInfo;
    QStandardItem* item(nullptr);
    for(unsigned int i=0; i<m_DAT.count(); ++i)
    {
        fileInfo.setFile(QString(m_DAT.fileNameByIndex(i).c_str()));

        item = new QStandardItem(fileInfo.baseName()); // Name
        m_treeViewModel->setItem(i, 0, item);

        item = new QStandardItem(QString(".")+fileInfo.completeSuffix()); // Type
        m_treeViewModel->setItem(i, 1, item);

        item = new QStandardItem(qlocale.toString(m_DAT.fileSize(m_DAT.fileNameByIndex(i)))); // Size
        m_treeViewModel->setItem(i, 2, item);
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// MENU BAR
void MainWindow::updateMenuBar()
{
    if(m_DATPath.isEmpty())
    {
        actionSave_As->setEnabled(false);
        actionSave->setEnabled(false);
        actionClose->setEnabled(false);
        
        treeView->setEnabled(false);
    }
    else
    {
        actionSave_As->setEnabled(true);
        actionSave->setEnabled(true);
        actionClose->setEnabled(true);
        
        treeView->setEnabled(true);        
    }
}


void MainWindow::on_actionNew_triggered()
{
    if(closeCurrentDATFile())
    {
        QString selectedFilter("DAT (*.dat)");
        QString path(QFileDialog::getSaveFileName(this, "New DAT file", "", "All (*.*);;DAT (*.dat)", &selectedFilter));
    
        if(!path.isEmpty())
        {
            if(m_DAT.saveToFile(path.toStdString()))
            {
                m_DATPath = path; 
                
                setWindowTitle("[GNB] DAT ("+path+")");
                emit DAT_Loaded();
            }
            else
                QMessageBox::warning(this, "DAT File", "Unable to create the file: "+path+"\nTry again.");
        }
    }
}


void MainWindow::on_actionLoad_triggered()
{
    if(closeCurrentDATFile())
    {
        QString selectedFilterDat("DAT (*.dat)");
        QString path(QFileDialog::getOpenFileName(this, "Open DAT file", "", "All (*.*);;DAT (*.dat)", &selectedFilterDat));
    
        if(!path.isEmpty())
        {
            if(m_DAT.loadFromFile(path.toStdString()))
            {
                m_DATPath = path;
                
                setWindowTitle("[GNB] DAT ("+path+")");
                emit DAT_Loaded();
            }
            else
                QMessageBox::warning(this, "DAT File", "Unable to read file: "+path+"\nTry again.");
        }
    }
}


void MainWindow::on_actionSave_triggered()
{
    if(m_DAT.saveToFile(m_DATPath.toStdString()))
        QMessageBox::information(this, "DAT File", m_DATPath+" saved !");
    else
        QMessageBox::warning(this, "DAT File", "Unable to save: "+m_DATPath);
}


void MainWindow::on_actionSave_As_triggered()
{
    QString selectedFilter("DAT (*.dat)");
    QString path(QFileDialog::getSaveFileName(this, "Save As...", m_DATPath, "All (*.*);;DAT (*.dat)", &selectedFilter));
    
    if(!path.isEmpty())
    {
        if(m_DAT.saveToFile(path.toStdString()))
            m_DATPath = path; 
        else
            QMessageBox::warning(this, "DAT File", "Unable to save: "+path+"\nTry again.");
    }
}


void MainWindow::on_actionClose_triggered()
{
    if(closeCurrentDATFile())
    {
        setWindowTitle("[GNB] DAT");
    }
}


void MainWindow::on_actionQuit_triggered()
{
    close();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::aboutQt(this);
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// CUSTOM CONTEXT MENU
void MainWindow::on_treeView_customContextMenuRequested(const QPoint &pos)
{
    // [Context Menu: Global]
    QMenu customContextMenu;
    customContextMenu.addAction("Add file...", this, SLOT(s_addFile()));

    // Set selected the current row
    QModelIndex index = treeView->indexAt(pos);
    if(index.isValid())
    {
        treeView->selectionModel()->select(QItemSelection(treeView->model()->index(index.row(), 0),
                                                          treeView->model()->index(index.row(),
                                                                                   treeView->model()->columnCount()-1)),
                                            QItemSelectionModel::Select);
    }

    QModelIndexList selected = treeView->selectionModel()->selectedRows();
    if(selected.size() >= 1)
    {
        // [Context Menu: Selected]
        customContextMenu.addSeparator();
        QMenu* customContextMenuSelected = customContextMenu.addMenu(QString::number(selected.size())+QString(" file(s) selected"));
            customContextMenuSelected->addAction("Rename...", this, SLOT(s_renameSelected()));
            customContextMenuSelected->addAction("Extract...", this, SLOT(s_extractSelected()));
            customContextMenuSelected->addAction("Remove...", this, SLOT(s_removeSelected()));
        customContextMenu.addSeparator();
    }


    customContextMenu.exec(treeView->mapToGlobal(pos));
}


// Add files into the current DAT file
void MainWindow::s_addFile()
{
    QStringList filePathToAdd_list(QFileDialog::getOpenFileNames(this, "Select file(s) to add"));

    if(filePathToAdd_list.size() >= 1)
    {
        for(int i=0; i<filePathToAdd_list.size(); ++i)
        {
            if(!m_DAT.add(filePathToAdd_list.at(i).toStdString()))
            {
                if(m_DAT.exists(DAT::fileName(filePathToAdd_list.at(i).toStdString())))
                    QMessageBox::warning(this, "DAT (Add: File exists)",
                                         "Unable to add file: "+filePathToAdd_list.at(i)+"\nFile with this name already exists !");
                else
                    QMessageBox::warning(this, "DAT (Add error)",
                                         "Unable to open file: "+filePathToAdd_list.at(i));
            }
            else
                emit DAT_Modified();
        }
    }
}


// Extract all selected files
void MainWindow::s_extractSelected()
{
    QString directoryToExtract(QFileDialog::getExistingDirectory(this, "Select a folder to extract"));
    QFileInfo fileInfo;
    int user_select(QMessageBox::Yes);
    int extractCount(0);

    if(!directoryToExtract.isEmpty())
    {
        std::vector<std::string> selectedFile(getSelectedFilePath());
        for(unsigned int i=0; i<selectedFile.size(); ++i)
        {
            fileInfo.setFile(directoryToExtract, QString(selectedFile.at(i).c_str()));
            if(fileInfo.exists() && user_select != QMessageBox::YesToAll)
            {
                user_select = QMessageBox::question(this, "DAT (Extract: File exists)",
                                                        "File: "+fileInfo.filePath()+" already exists.\n"+
                                                        "Do you want to extract (file will be erased) ?",
                                                        QMessageBox::Yes | QMessageBox::YesToAll | QMessageBox::No);
            }

            if(user_select == QMessageBox::Yes || user_select == QMessageBox::YesToAll)
            {
                std::fstream file(std::string(directoryToExtract.toStdString()+"/"+selectedFile.at(i)).c_str(),
                                  std::fstream::out | std::fstream::binary | std::fstream::trunc);
                if(file.is_open())
                {
                    std::string data = m_DAT.file(selectedFile.at(i));
                    for(unsigned int i=0; i<data.size(); ++i)
                        file.put(data[i]);

                    file.close();
                    extractCount++;
                }
            }
        }

        QMessageBox::information(this, "DAT (Extraction)",
                                 QString::number(extractCount)+" file(s) extracted !");
    }
}


// Rename all selected file
void MainWindow::s_renameSelected()
{
    RenameFileDialog dialogRenameFile(this);

    std::vector<std::string> selectedFile(getSelectedFilePath());
    for(size_t i=0; i<selectedFile.size(); ++i)
    {
        dialogRenameFile.setFilename(selectedFile.at(i).c_str());
        if(dialogRenameFile.exec() == QDialog::Accepted)
        {
            if(!m_DAT.rename(selectedFile.at(i), dialogRenameFile.getFilename()))
            {
                if(m_DAT.exists(dialogRenameFile.getFilename()))
                {
                    QMessageBox::warning(this, "DAT (Rename fail)",
                                         "Unable to rename file: "+QString(selectedFile.at(i).c_str())+
                                         "\nTo file: "+QString(dialogRenameFile.getFilename().c_str())+
                                         "\nFile with this name already exists !");                    
                }
                else
                    QMessageBox::warning(this, "DAT (Rename fail)",
                                         "Unable to rename file: "+QString(selectedFile.at(i).c_str())+
                                         "\nTry again or reload DAT file. If problems persists DAT file may be corrupted.");
            }
            else
                emit DAT_Modified();
        }
    }
}


// Remove all selected files
void MainWindow::s_removeSelected()
{
    std::vector<std::string> selectedFile(getSelectedFilePath());
    int user_select(QMessageBox::question(this,
                                          "DAT (Remove "+QString::number(selectedFile.size())+" selected file(s))",
                                          "You will permanently delete all selected files. Do you want to continue ?"));
    
    if(user_select == QMessageBox::Yes)
    {
        for(unsigned int i=0; i<selectedFile.size(); ++i)
        {
            if(!m_DAT.remove(selectedFile.at(i)))
                QMessageBox::warning(this, "DAT (Remove file)",
                                     "Unable to remove file: "+QString(selectedFile.at(i).c_str())+
                                     "\nTry again or reload DAT file. If problems persists DAT file may be corrupted.");
            else
                emit DAT_Modified();
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////
/// Handle close event (avoid data loss)
void MainWindow::closeEvent(QCloseEvent* e)
{
    int user_select(QMessageBox::Yes);
    if(!m_DATPath.isEmpty())
    {
        user_select = QMessageBox::question(this, "DAT (Exit)",
                                            "Save the current DAT before exit ?",
                                            QMessageBox::Yes | QMessageBox::No | QMessageBox::Abort);
        
        switch(user_select)
        {
            // Save & Exit
            case QMessageBox::Yes:
                if(!m_DAT.saveToFile(m_DATPath.toStdString()))
                {
                    QMessageBox::critical(this, "DAT (Saving error)",
                                          "Unable to save file: "+m_DATPath+"\nQuit aborted.");
                    e->ignore();
                }                
            break;
            
            // Abort exit
            case QMessageBox::Abort:
                e->ignore();
            break;
                
            default: ;
        }
    }
}
