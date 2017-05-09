/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    pluginprotocolextence.cpp
 * @brief
 *******************************************************************************
 */
#include "pluginprotocolextence.h"
#include <QDebug>
namespace PluginProtoco {
QMutex PluginProtoco::PluginProtocolExtence::m_mutex;
PluginProtocolExtence::DestryInstance PluginProtocolExtence::m_destry;
PluginProtocolExtence *PluginProtocolExtence::m_instance = Q_NULLPTR;
PluginProtocolExtence *PluginProtocolExtence::instance()
{
    if(Q_NULLPTR == m_instance)
    {
        QMutexLocker locker(&m_mutex);
        if(Q_NULLPTR == m_instance)
        {
            m_instance = new PluginProtocolExtence();
        }
    }
    return m_instance;
}
PluginProtocolExtence::PluginProtocolExtence(QObject *parent) : QObject(parent)
{

}

PluginProtocolExtence::~PluginProtocolExtence()
{
    qDebug()<<"PluginProtocolExtence xigou";
}


PluginProtocolExtence::DestryInstance::~DestryInstance()
{
    if(PluginProtocolExtence::m_instance)
    {
        qDebug()<<"PluginProtocolExtence::DestryInstance::~DestryInstance";
        delete PluginProtocolExtence::m_instance;
        PluginProtocolExtence::m_instance = Q_NULLPTR;
    }
}

//name space end
}
