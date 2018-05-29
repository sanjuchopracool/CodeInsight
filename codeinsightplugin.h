#pragma once

#include "codeinsight_global.h"

#include <extensionsystem/iplugin.h>

namespace CodeInsight {
namespace Internal {

class CodeInsightPluginPrivate;

class CodeInsightPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "codeinsight.json")

public:
    CodeInsightPlugin();
    ~CodeInsightPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private:
    void triggerAction();

private:
    CodeInsightPluginPrivate *d = nullptr;
};

} // namespace Internal
} // namespace codeinsight
