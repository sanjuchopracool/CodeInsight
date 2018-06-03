#include "codeinsighteditorfactory.h"
#include "codeinsightconstants.h"

#include "codeinsighteditor.h"

#include <cppeditor/cppeditorconstants.h>
#include <cpptools/cpptoolsconstants.h>
#include <coreplugin/editormanager/ieditor.h>

#include <utils/algorithm.h>
#include <QCoreApplication>

namespace CodeInsight {
namespace Internal {

CodeInsightEditorFactory::CodeInsightEditorFactory()
{
    setId(Constants::CPPEDITOR_ID);
    setDisplayName(QCoreApplication::translate("OpenWith::Editors", Constants::CPPEDITOR_DISPLAY_NAME));
    addMimeType(CppTools::Constants::C_SOURCE_MIMETYPE);
    addMimeType(CppTools::Constants::CPP_SOURCE_MIMETYPE);

    m_cppEditorFactory = Utils::findOrDefault(IEditorFactory::allEditorFactories(),
                                                   Utils::equal(&IEditorFactory::id,
                                                                Core::Id(CppEditor::Constants::CPPEDITOR_ID)));
}

Core::IEditor *CodeInsightEditorFactory::createEditor()
{
    Q_ASSERT(m_cppEditorFactory);
    if ( m_cppEditorFactory )
    {
        Core::IEditor *editor = m_cppEditorFactory->createEditor();
        Q_ASSERT(editor);
        return new CodeInsightEditor(editor);
    }

    return nullptr;
}

} // namespace Internal
} // namespace codeinsight
