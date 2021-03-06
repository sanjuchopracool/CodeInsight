#include "codeinsightplugin.h"
#include "codeinsightconstants.h"
#include "codeinsighteditorfactory.h"

#include <coreplugin/icore.h>
#include <coreplugin/icontext.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/coreconstants.h>

#include <QAction>
#include <QMessageBox>
#include <QMainWindow>
#include <QMenu>

namespace CodeInsight {
namespace Internal {

class CodeInsightPluginPrivate : public QObject
{
public:
    CodeInsightEditorFactory m_cppEditorFactory;
};

CodeInsightPlugin::CodeInsightPlugin()
{
    // Create your members
}

CodeInsightPlugin::~CodeInsightPlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

bool CodeInsightPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.

    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    d = new CodeInsightPluginPrivate;

    auto action = new QAction(tr("codeinsight Action"), this);
    Core::Command *cmd = Core::ActionManager::registerAction(action, Constants::ACTION_ID,
                                                             Core::Context(Core::Constants::C_GLOBAL));
    cmd->setDefaultKeySequence(QKeySequence(tr("Ctrl+Alt+Meta+A")));
    connect(action, &QAction::triggered, this, &CodeInsightPlugin::triggerAction);

    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(tr("codeinsight"));
    menu->addAction(cmd);
    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

    return true;
}

void CodeInsightPlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag CodeInsightPlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

#include <cppeditor/cppeditorconstants.h>
void CodeInsightPlugin::triggerAction()
{
    QString theCppEditorFactory( CppEditor::Constants::CPPEDITOR_ID );
    QMessageBox::information(Core::ICore::mainWindow(),
                             tr("Action Triggered"),
                             "CPP_EDITOR : " + theCppEditorFactory);
}

} // namespace Internal
} // namespace codeinsight
