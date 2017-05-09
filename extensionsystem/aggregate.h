/****************************************************************************
**
* @Project : Frameworks
* @File: aggregate.h
* @Description:
* @Copyright: Copyright (c) 2014
* @Company:
* @WebSite: http://www.zchx.com/
* @author:
* @Revision History
* <pre>
* ----------------------------------------------------------------------
*   Ver     Date       Who        Comments
* ----- ----------  --------  ------------------------------------------
*   1.0  2013/08/12    yeguoxiong      FOR QT 5.1.0
* ----------------------------------------------------------------------
**
****************************************************************************/

#ifndef AGGREGATE_H
#define AGGREGATE_H

#include "extensionsystem_global.h"
#include <QObject>
#include <QList>
#include <QHash>
#include <QReadWriteLock>
#include <QReadLocker>
#include <QWriteLocker>
#include <QDebug>

namespace ExtensionSystem {

class EXTENSIONSYSTEM_EXPORT Aggregate : public QObject
{
    Q_OBJECT

public:
    Aggregate(QObject *parent = 0);
    virtual ~Aggregate();

    void add(QObject *component);
    void remove(QObject *component);

    template <typename T> T *component()
    {
        QReadLocker(&lock());
        foreach (QObject *component, m_components)
        {
            if (T *result = qobject_cast<T *>(component))
            {
                return result;
            }
        }
        return (T *)0;
    }

    template <typename T> QList<T *> components()
    {
        QReadLocker(&lock());
        QList<T *> results;
        foreach (QObject *component, m_components)
        {
            if (T *result = qobject_cast<T *>(component))
            {
                results << result;
            }
        }
        return results;
    }
    static Aggregate *parentAggregate(QObject *obj);
    static QReadWriteLock &lock();
signals:
    void changed();
private slots:
    void deleteSelf(QObject *obj);

private:
    static QHash<QObject *, Aggregate *> &aggregateMap();

    QList<QObject *> m_components;
};

template <typename T> T *query(Aggregate *obj)
{
    if (!obj) return (T *)0;
    return obj->template component<T>();
}

template <typename T> T *query(QObject *obj)
{
    if (!obj)
        return (T *)0;
    T *result = qobject_cast<T *>(obj);
    if (!result)
    {
        QReadLocker(&lock());
        Aggregate *parentAggregation = Aggregate::parentAggregate(obj);
        result = (parentAggregation ? query<T>(parentAggregation) : 0);
    }
    return result;
}

template <typename T> QList<T *> query_all(Aggregate *obj)
{
    if (!obj)
        return QList<T *>();
    return obj->template components<T>();
}

template <typename T> QList<T *> query_all(QObject *obj)
{
    if (!obj)
        return QList<T *>();
    QReadLocker(&lock());
    Aggregate *parentAggregation = Aggregate::parentAggregate(obj);
    QList<T *> results;
    if (parentAggregation)
    {
        results = query_all<T>(parentAggregation);
    }else if (T *result = qobject_cast<T *>(obj))
    {
        results.append(result);
    }
    return results;
}

} // namespace ExtensionSystem

#endif // AGGREGATE_H
