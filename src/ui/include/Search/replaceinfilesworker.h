#ifndef REPLACEINFILESWORKER_H
#define REPLACEINFILESWORKER_H

#include <QObject>
#include <QMutex>
#include "include/Search/filesearchresult.h"

class ReplaceInFilesWorker : public QObject
{
    Q_OBJECT
public:
    explicit ReplaceInFilesWorker(const FileSearchResult::SearchResult &searchResult, const QString &replacement);
    ~ReplaceInFilesWorker();

signals:
    void finished(bool stopped);
    void error(QString string);
    void progress(QString file);

public slots:
    void run();
    void stop();

private:
    FileSearchResult::SearchResult m_searchResult;
    QString m_replacement;
    QMutex m_resultMutex;
    bool m_stop = false;
    QMutex m_stopMutex;
};

#endif // REPLACEINFILESWORKER_H