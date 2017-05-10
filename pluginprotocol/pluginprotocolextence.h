/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    pluginprotocolextence.h
 * @brief
 *******************************************************************************
 */
#ifndef PLUGINPROTOCOLEXTENCE_H
#define PLUGINPROTOCOLEXTENCE_H

#include <QObject>
#include <QMutex>
namespace PluginProtoco {
class PluginProtocolExtence : public QObject
{
    Q_OBJECT
public:

    virtual ~PluginProtocolExtence();
    static PluginProtocolExtence *instance();

signals:
    void signalPluginsName(const QString &name);
public slots:

private:
    explicit PluginProtocolExtence(QObject *parent = 0);

private:
    static QMutex m_mutex;
    static PluginProtocolExtence   *m_instance;
    class DestryInstance
    {
    public:
        ~DestryInstance();
    };
    static DestryInstance m_destry;
};

}
#endif // PLUGINPROTOCOLEXTENCE_H
